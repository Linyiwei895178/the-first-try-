# douban_top250_spider.py
import csv
import random
import re
import time
from dataclasses import dataclass, asdict
from typing import List, Optional

import requests
from bs4 import BeautifulSoup
from requests.adapters import HTTPAdapter
from urllib3.util.retry import Retry


@dataclass
class Movie:
    rank: int
    title: str
    rating: str
    votes: str
    detail_url: str


def build_session() -> requests.Session:
    session = requests.Session()

    # 常见反爬对策：UA + 语言 + Referer + 连接复用
    session.headers.update({
        "User-Agent": (
            "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 "
            "(KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36"
        ),
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
        "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8",
        "Referer": "https://movie.douban.com/",
        "Connection": "keep-alive",
    })

    # 重试策略：网络抖动/5xx 情况下自动重试
    retry = Retry(
        total=5,
        backoff_factor=1.0,  # 指数退避
        status_forcelist=[429, 500, 502, 503, 504],
        allowed_methods=["GET"],
        raise_on_status=False,
    )
    adapter = HTTPAdapter(max_retries=retry)
    session.mount("http://", adapter)
    session.mount("https://", adapter)
    return session


def safe_text(el) -> str:
    if not el:
        return ""
    return el.get_text(strip=True)


def parse_votes(votes_text: str) -> str:
    # 例： "123456人评价" -> "123456"
    m = re.search(r"([\d,]+)", votes_text)
    return m.group(1).replace(",", "") if m else ""


def parse_top250_page(html: str, start_rank: int) -> List[Movie]:
    soup = BeautifulSoup(html, "html.parser")
    items = soup.select("ol.grid_view li")

    movies: List[Movie] = []
    for i, li in enumerate(items):
        rank = start_rank + i + 1

        try:
            title_el = li.select_one("div.item div.info div.hd span.title")
            rating_el = li.select_one("div.item div.star span.rating_num")
            # 豆瓣页面里“人评价”通常是 star 区块里最后一个 span
            votes_el = li.select_one("div.item div.star span:last-child")

            a_el = li.select_one("div.item div.info div.hd a")
            href = a_el.get("href", "") if a_el else ""

            title = safe_text(title_el)
            rating = safe_text(rating_el)

            votes_text = safe_text(votes_el)
            votes = parse_votes(votes_text)

            # detail_url 可能是相对路径，尽量补全
            if href and href.startswith("/"):
                detail_url = "https://movie.douban.com" + href
            else:
                detail_url = href or ""

            # 基本健壮性：至少要有标题，否则通常是结构变化导致
            if not title:
                continue

            movies.append(Movie(
                rank=rank,
                title=title,
                rating=rating,
                votes=votes,
                detail_url=detail_url
            ))
        except Exception:
            # 单条解析失败就跳过，不让整页崩
            continue

    return movies


def fetch_page(session: requests.Session, url: str, timeout: int = 15) -> str:
    resp = session.get(url, timeout=timeout)
    # 遇到验证码/被拦，HTML 可能仍是 200，这里用一个简单标志检测
    resp.raise_for_status()
    return resp.text


def main():
    session = build_session()
    all_movies: List[Movie] = []

    base_url = "https://movie.douban.com/top250"
    starts = list(range(0, 250, 25))  # 0,25,...,225

    for page_start in starts:
        url = f"{base_url}?start={page_start}&filter="
        print(f"Fetching: {url}")

        # 延时避免过于频繁（再加点随机抖动）
        sleep_s = random.uniform(1.2, 2.8)
        time.sleep(sleep_s)

        try:
            html = fetch_page(session, url)
            start_rank = page_start
            movies = parse_top250_page(html, start_rank=start_rank)
            print(f"  Parsed {len(movies)} movies from start={page_start}")
            all_movies.extend(movies)
        except requests.exceptions.RequestException as e:
            print(f"  Request error at start={page_start}: {e}")
            # 继续下一个页面
            continue
        except Exception as e:
            print(f"  Unexpected error at start={page_start}: {e}")
            continue

    # 去重（以 title+detail_url 为准，防止结构变化导致重复）
    seen = set()
    deduped: List[Movie] = []
    for m in all_movies:
        key = (m.title, m.detail_url)
        if key in seen:
            continue
        seen.add(key)
        deduped.append(m)

    out_file = "douban_top250.csv"
    fieldnames = ["rank", "title", "rating", "votes", "detail_url"]

    with open(out_file, "w", newline="", encoding="utf-8-sig") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        for m in deduped:
            writer.writerow(asdict(m))

    print(f"Saved {len(deduped)} rows to {out_file}")


if __name__ == "__main__":
    main()