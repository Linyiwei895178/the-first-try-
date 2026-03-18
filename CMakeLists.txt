cmake_minimum_required(VERSION 3.20)
project(course)

set(CMAKE_CXX_STANDARD 17)

# 【核心：一劳永逸代码】自动搜索当前目录下所有 .cpp 文件并分别为它们创建运行配置
file(GLOB SOURCES *.cpp)

foreach(source_file ${SOURCES})
    get_filename_component(exe_name ${source_file} NAME_WE)
    add_executable(${exe_name} ${source_file})
endforeach()