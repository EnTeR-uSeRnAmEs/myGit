import os,time

try:
    from selenium import webdriver
except:
    i = ''
    while i != 'Y' or 'N':
        print("您的python缺少selenium模块，是否要现在为您安装？")
        i = input("Y: 请帮我安装selenium\nN: 我要自己安装\n")
        if i == 'Y':
            print("正在为您安装selenium模块...\n")
            try:
                os.system(f'pip install selenium')
                time.sleep(10)
                from selenium import webdriver
            except:
                print("出现未知错误，未能成功安装selenium模块，请您在python.exe中使用'pip install selenium'命令手动为其安装selenium模块后重新运行此程序\n")
                time.sleep(20)
                exit()
        elif i == 'N':
            print("请您在python.exe中使用'pip install selenium'命令手动为其安装selenium模块后重新运行此程序\n")
            time.sleep(20)
            exit()