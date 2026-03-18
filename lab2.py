# #动物识别系统
# #自定义函数，判断有无重复元素
# def judge_repeat(value,list=[]):
#     for i in range(0,len(list)):
#         if(list[i]==value):
#             return 1
#         else:
#             if(i!=len(list)-1):
#                 continue
#             else:
#                 return 0
# #自定义函数，对已经整理好的综合数据库real_list进行最终的结果判断           
# def judge_last(list):
#     for i in list:
#         if(i=='23'):
#             for i in list:
#                 if(i=='12'):
#                     for i in list:
#                         if(i=='21'):
#                             for i in list:
#                                 if(i=='13'):
#                                     print("黄褐色，有斑点,哺乳类，食肉类->金钱豹\n")
#                                     print("所识别的动物为金钱豹")
#                                     return 0
#                                 elif(i=='14'):
#                                     print("黄褐色，有黑色条纹，哺乳类，食肉类->虎\n")
#                                     print("所识别的动物为虎")
#                                     return 0

        
#         elif(i=='14'):
#             for i in list:
#                 if(i=='24'):
#                     print("有黑色条纹，蹄类->斑马\n")
#                     print("所识别的动物为斑马")
#                     return 0   
#         elif(i=='24'):
#             for i in list:
#                 if(i=='13'):
#                     for i in list:
#                         if(i=='15'):
#                             for i in list:
#                                 if(i=='16'):
#                                     print("有斑点，有黑色条纹，长脖，蹄类->长颈鹿\n")
#                                     print("所识别的动物为长颈鹿")
#                                     return 0
#         elif(i=='20'):
#             for i in list:
#                 if(i=='22'):
#                     print("善飞，鸟类->信天翁\n")
#                     print("所识别的动物为信天翁")
#                     return 0

#         elif(i=='22'):
#             for i in list:
#                 if(i=='4'):
#                     for i in list:
#                         if(i=='15'):
#                             for i in list:
#                                 if(i=='16'):
#                                     print("不会飞，长脖，长腿，鸟类->鸵鸟\n")
#                                     print("所识别的动物为鸵鸟")
#                                     return 0
#         elif(i=='4'):
#             for i in list:
#                 if(i=='22'):
#                     for i in list:
#                         if(i=='18'):
#                             for i in list:
#                                 if(i=='19'):
#                                     print("不会飞，会游泳，黑白二色，鸟类->企鹅\n")
#                                     print("所识别的动物企鹅")
#                                     return 0
                                
#         else:
#             if(list.index(i) != len(list)-1):
#                 continue
#             else:
#                 print("\n根据所给条件无法判断为何种动物")
    
# dict_before={'1':'有毛发','2':'产奶','3':'有羽毛','4':'不会飞','5':'会下蛋','6':'吃肉','7':'有犬齿',
#             '8':'有爪','9':'眼盯前方','10':'有蹄','11':'反刍','12':'黄褐色','13':'有斑点','14':'有黑色条纹',
#             '15':'长脖','16':'长腿','17':'不会飞','18':'会游泳','19':'黑白二色','20':'善飞','21':'哺乳类',
#             '22':'鸟类','23':'食肉类','24':'蹄类','25':'金钱豹','26':'虎','27':'长颈鹿','28':'斑马',
#             '29':'鸵鸟','30':'企鹅','31':'信天翁'}
# print('''输入对应条件前面的数字:
#                                 *******************************************************
#                                 *1:有毛发  2:产奶  3:有羽毛  4:不会飞  5:会下蛋          *
#                                 *6:吃肉  7:有犬齿  8:有爪  9:眼盯前方  10:有蹄         *
#                                 *11:反刍  12:黄褐色  13:有斑点  14:有黑色条纹  15:长脖 *
#                                 *16:长腿  17:不会飞  18:会游泳  19:黑白二色  20:善飞   *
#                                 *21：哺乳类  22:鸟类  23:食肉类  24：蹄类              *
#                                 *******************************************************
#                                 *******************当输入数字0时!程序结束***************
#         ''' )
# #综合数据库
# list_real=[]
# while(1):
# #循环输入前提条件所对应的字典中的键
#     num_real=input("请输入：")
#     list_real.append(num_real)
#     if(num_real=='0'):
#         break
# print("\n")
# print("前提条件为：")
# #输出前提条件
# for i in range(0,len(list_real)-1):
#     print(dict_before[list_real[i]],end=" ")
# print("\n")
# print("推理过程如下：")
# #遍历综合数据库list_real中的前提条件
# for i in list_real:
#     if(i=='1'):
#         if(judge_repeat('21',list_real)==0):
#             list_real.append('21')
#             print("有毛发->哺乳类")
#     elif(i=='2'):
#         if(judge_repeat('21',list_real)==0):
#             list_real.append('21')
#             print("产奶->哺乳类")
#     elif(i=='3'):
#         if(judge_repeat('22',list_real)==0):
#             list_real.append('22')
#             print("有羽毛->鸟类")
#     else:
#         if(list_real.index(i) !=len(list_real)-1):
#             continue
#         else:
#             break
# for i in list_real:
#     if(i=='4'):
#         for i in list_real:
#             if(i=='5'):
#                 if(judge_repeat('22',list_real)==0):
#                     list_real.append('22')
#                     print("不会飞，会下蛋->鸟类")
#     elif(i=='6'):
#         for i in list_real:
#             if(i=='21'):
#                 if(judge_repeat('21',list_real)==0):
#                     list_real.append('21')
#                     print("食肉->哺乳类")
#     elif(i=='7'):
#         for i in list_real:
#             if(i=='8'):
#                 for i in list_real:
#                     if(i=='9'):
#                         if(judge_repeat('23',list_real)==0):
#                             list_real.append('23')
#                             print("有犬齿,有爪,眼盯前方->食肉类")
#     elif(i=='10'):
#         for i in list_real:
#             if(i=='21'):
#                 if(judge_repeat('24',list_real)==0):
#                     list_real.append('24')
#                     print("有蹄，哺乳类->蹄类")
                    
#     elif(i=='11'):
#         for i in list_real:
#             if(i=='21'):
#                 if(judge_repeat('24',list_real)==0):
#                     list_real.append('24')
#                     print("反刍，哺乳类->哺乳类")
                    
#     else:
#         if(i !=len(list_real)-1):
#             continue
#         else:
#             break
# judge_last(list_real)
    

# 水果识别产生式系统
# ===================== 核心工具函数 =====================
# 修复原去重函数的缺陷（默认参数用None，避免列表内存泄漏）

def judge_repeat(value, input_list):
    """
    判断元素是否在列表中重复
    :param value: 待判断的值
    :param input_list: 目标列表
    :return: 1（存在）/0（不存在）
    """
    return 1 if value in input_list else 0

# ===================== 规则推理函数 =====================
def infer_category(feat_list, full_dict):
    """
    第一步推理：从基础特征推导水果类别特征（如「核果类」「浆果类」）
    :param feat_list: 用户输入的特征列表
    :param full_dict: 特征字典
    """
    # 规则1：有果核 + 肉质果肉 → 核果类（新增类别特征31）
    if '1' in feat_list and '8' in feat_list and judge_repeat('31', feat_list) == 0:
        feat_list.append('31')
        print(f"{full_dict['1']} + {full_dict['8']} → {full_dict['31']}")
    
    # 规则2：无核 + 多汁果肉 → 浆果类（新增类别特征32）
    if '2' in feat_list and '9' in feat_list and judge_repeat('32', feat_list) == 0:
        feat_list.append('32')
        print(f"{full_dict['2']} + {full_dict['9']} → {full_dict['32']}")
    
    # 规则3：硬果皮 + 分瓣果肉 → 柑果类（新增类别特征33）
    if '3' in feat_list and '10' in feat_list and judge_repeat('33', feat_list) == 0:
        feat_list.append('33')
        print(f"{full_dict['3']} + {full_dict['10']} → {full_dict['33']}")

def infer_fruit(feat_list, full_dict):
    """
    第二步推理：从基础特征+类别特征推导具体水果
    :param feat_list: 包含推导特征的完整列表
    :param full_dict: 特征字典
    :return: 0（识别成功）/1（识别失败）
    """
    # 规则1：核果类 + 红色 + 圆形 + 甜 → 苹果
    if '31' in feat_list and '4' in feat_list and '11' in feat_list and '14' in feat_list:
        print(f"\n{full_dict['31']} + {full_dict['4']} + {full_dict['11']} + {full_dict['14']} → 苹果")
        print("✅ 识别结果：苹果")
        return 0
    
    # 规则2：核果类 + 黄色 + 椭圆形 + 酸甜 → 芒果
    elif '31' in feat_list and '5' in feat_list and '12' in feat_list and '15' in feat_list:
        print(f"\n{full_dict['31']} + {full_dict['5']} + {full_dict['12']} + {full_dict['15']} → 芒果")
        print("✅ 识别结果：芒果")
        return 0
    
    # 规则3：浆果类 + 紫色 + 圆形 + 甜 → 葡萄
    elif '32' in feat_list and '6' in feat_list and '11' in feat_list and '14' in feat_list:
        print(f"\n{full_dict['32']} + {full_dict['6']} + {full_dict['11']} + {full_dict['14']} → 葡萄")
        print("✅ 识别结果：葡萄")
        return 0
    
    # 规则4：柑果类 + 橙色 + 圆形 + 酸甜 → 橙子
    elif '33' in feat_list and '7' in feat_list and '11' in feat_list and '15' in feat_list:
        print(f"\n{full_dict['33']} + {full_dict['7']} + {full_dict['11']} + {full_dict['15']} → 橙子")
        print("✅ 识别结果：橙子")
        return 0
    
    # 规则5：无类别特征但有核心基础特征 → 香蕉（特殊规则）
    elif '5' in feat_list and '13' in feat_list and '14' in feat_list:
        print(f"\n{full_dict['5']} + {full_dict['13']} + {full_dict['14']} → 香蕉")
        print("✅ 识别结果：香蕉")
        return 0
    
    # 无匹配规则
    else:
        print("\n❌ 根据输入的特征无法识别具体水果")
        return 1

# ===================== 主程序 =====================
if __name__ == "__main__":
    # 特征字典：基础特征（1-20）+ 推导类别特征（31-33）
    fruit_dict = {
        # 结构特征
        '1': '有果核', '2': '无核', '3': '硬果皮', '8': '肉质果肉', 
        '9': '多汁果肉', '10': '分瓣果肉',
        # 颜色特征
        '4': '红色', '5': '黄色', '6': '紫色', '7': '橙色',
        # 形状特征
        '11': '圆形', '12': '椭圆形', '13': '长条形',
        # 口感特征
        '14': '甜', '15': '酸甜',
        # 推导的类别特征
        '31': '核果类', '32': '浆果类', '33': '柑果类'
    }

    # 打印特征输入提示
    print("===== 水果识别系统 =====")
    print("请输入以下特征对应的数字（输入0结束）：")
    print("------------------------")
    for idx, (key, val) in enumerate(fruit_dict.items()):
        if idx % 5 == 0 and idx != 0:
            print()  # 每5个特征换行，提升可读性
        print(f"{key}:{val}", end="  ")
    print("\n------------------------")

    # 收集用户输入的特征
    feat_list = []
    while True:
        user_input = input("请输入特征编号：").strip()
        if user_input == '0':
            break
        # 校验输入合法性
        if user_input not in fruit_dict.keys():
            print(f"❌ 输入无效！请输入特征列表中的数字（如1-7、8-15、31-33）")
            continue
        # 去重后添加
        if judge_repeat(user_input, feat_list) == 0:
            feat_list.append(user_input)
    
    # 空输入判断
    if not feat_list:
        print("\n⚠️ 未输入任何特征，无法识别")
    else:
        # 输出用户输入的特征
        print("\n📋 你输入的特征：")
        print(" + ".join([fruit_dict[feat] for feat in feat_list]))

        # 第一步：推导类别特征
        print("\n🔍 推理过程（基础特征→类别特征）：")
        infer_category(feat_list, fruit_dict)

        # 第二步：推导具体水果
        print("\n🔍 推理过程（类别特征→具体水果）：")
        infer_fruit(feat_list, fruit_dict)