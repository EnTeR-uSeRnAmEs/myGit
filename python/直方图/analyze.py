import os
from matplotlib import rcParams
import pandas as pd  # pandas是一个强大的分析结构化数据的工具集
import numpy as np  # numpy是Python中科学计算的核心库
from matplotlib.pyplot import *  # matplotlib数据可视化神器
from pprint import pprint

dataType = ["int(顺序)", "int(逆序)", "int(均匀分布)", "int(正态分布)",
            "int(结构体)", "int(重复)"]  # 数据类型
# dataType = ["double(顺序)", "double(逆序)", "double(均匀分布)", "double(正态分布)",
#             "double(结构体)", "double(重复)"]  # 数据类型
# dataInfo = ["时间", "比较次数", "赋值次数"]  # 数据内容
dataInfo = ["时间"]  # 数据内容
dataInfo_lable = {"时间": "时间/(秒)", "比较次数": "比较次数/(次)", "赋值次数": "赋值次数/(次)"}
dataSize = [1024, 2048, 4096, 8192, 16384, 32768, 65536]
# filenames = ["InsertionSort", "QuickSort", "BubbleSort", "SelectSort"]
filenames = ["BubbleSort"]
color = ["#FF6C6C", "#FFA657", "#FFFA57",
         "#C8FF57", "#087200", "#57D3FF",
         "#4A53FF", "#D957FF", "#9100FF"]


def mkdir(path):
    os.chdir(os.path.dirname(__file__))
    folder = os.path.exists(path)
    if not folder:  # 判断是否存在文件夹如果不存在则创建为文件夹
        os.makedirs(os.getcwd() + "/" + path)  # makedirs 创建文件时如果路径不存在会创建这个路径


def getdata(filename):
    data = {}
    file = open(".\data\\" + filename + ".xlsx", "r")
    filelines = file.readlines()
    global algoNames
    algoNames = filelines[1].split()[1:]  # 算法类型 [算法A, 算法B, 算法C]
    algoNum = len(algoNames)  # 算法数量
    Type = ""
    Info = ""
    Size = 0

    for Type in dataType:
        data[Type] = {}
        for Info in dataInfo:
            data[Type][Info] = {}
            for Size in dataSize:
                data[Type][Info][Size] = []

    for line in range(len(filelines)):
        if line % 10 == 0:
            Type = filelines[line].split()[1]
            Info = filelines[line].split()[3]
        elif line % 10 >= 2 and line % 10 <= 8:
            Size = int(filelines[line].split()[0])
            tmpdata = list(map(eval, filelines[line].split()[1: algoNum + 1]))
            data[Type][Info][Size].extend(tmpdata)

    return data


def main():
    rcParams['font.sans-serif'] = ['SimHei']
    rcParams['axes.unicode_minus'] = False
    for filename in filenames:
        data = getdata(filename)
        for Type in dataType:
            for Info in dataInfo:
                figure(figsize=(6, 4))
                minimum = []
                x_value = data[Type][Info]
                pprint(x_value)
                # print(len([x_value[keys][0]
                #            for keys in x_value.keys()]))
                x = list(range(len([x_value[keys][0]
                         for keys in x_value.keys()])))
                # print(x)
                total_width, algoNums = 0.8, len(algoNames)
                width = total_width / algoNums
                for algo in range(algoNums):
                    tmp = [x_value[keys][algo] for keys in x_value.keys()]
                    if algo == algoNums // 2:
                        bar(x, tmp, width=width,
                            color=color[algo % algoNums], tick_label=dataSize)
                    else:
                        bar(x, tmp, width=width, color=color[algo % algoNums])
                    for i in range(len(x)):
                        text(x[i], tmp[i], "  " + str(tmp[i]), rotation=90,
                             fontsize=width * 40, fontweight="light", horizontalalignment="center", color="#303030")
                    x = [num + width for num in x]
                    minimum.append(max(tmp))

                title(Type + " " + algoNames[0] + " " + Info)
                # title(Type + " " + "联合测试" + " " + Info)
                ylabel(dataInfo_lable[Info])
                xlabel("数据总量")
                legend(algoNames)
                mkdir("./output/" + filename + "/" + Type)
                savefig("./output/" + filename + "/" +
                        Type + "/" + Info, dpi=1000)
                # show()
                mini = 0
                while mini == 0 and minimum != []:
                    mini = min(minimum)
                    minimum.remove(mini)
                if mini != 0:
                    ylim(0, mini * 1.05)
                    minimum.clear()
                    legend(frameon=False)
                    savefig("./output/" + filename + "/" +
                            Type + "/" + Info + " 放大", dpi=1000)
                    # show()
                close()


if __name__ == "__main__":
    main()
