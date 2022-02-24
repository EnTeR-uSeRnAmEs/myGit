# -*- coding: utf-8 -*-
"""
Auto Self Report v3.1

Created on Fri Feb 26 16:34:04 2021

Copyright (c) 2020-2021 Steve D. J.. All rights reserved.
"""


"""
3.1 更新：

支持“提前唤醒 - 准时填报”功能
"""


#**********
#使用须知
#1. 使用此脚本需先安装Chrome浏览器，然后下载"chromedriver.exe"并将其添加至系统变量中，具体方法见'https://blog.csdn.net/qq_30583611/article/details/108932842'
#2. 当然，尽管Steve在编写程序时已经尽量考虑到用户适配性进而减少了该脚本所依赖的python模块并大量使用try-except来避免可能存在的运行报错，但是想要使该脚本实现其基本功能，你至少需要准备好python 3，并在python.exe中使用"pip install selenium"命令为其安装selenium模块 
#3. 设置定时任务的方法见'https://www.baidu.com/link?url=8oBylDtTMNyin0UJff5LVeMdYhi1wyZ5SpWyDmB5VOXkd0c73cpMuzX_SwETvsASEVLUi8beTCzQepLyumjyMa&wd=&eqid=b2c95c6a0004c09d0000000460019850'
#4. 使用前请先填写下方的四个变量
#**********


#在''中填入学号
ID = '21122782'

#在''中填入密码
Password = '20030307Love'

#在''中填入已知不可访问健康之路网站的wifi名称
Banned_Wifi_Name = ''

#在''中填入备用wifi名称（此wifi需要曾经连过且不需要额外登陆操作）
Spare_Wifi_Name = 'Shu(ForAll)'


print("Copyright (c) 2020-2021 Steve D. J.. All rights reserved.\n")
print("正在执行Auto Self Report v3.1...\n")


import time
#import random
import os

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

#检索未填报项目，并进行填报
def Search_Unreported():
    print("正在检索未填报项目...\n")
    Unreported_Flag = 0
    for i in range(1,63):
        try:
            temp = driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li[' + str(i) + ']')
            #print(temp.text)
            temp_str = temp.text
            str_len = len(temp_str)
            for j in range(0, str_len):
                if temp_str[j] == '(':
                    left_index = j
                elif temp_str[j] == ')':
                    right_index = j
                    state_str = temp_str[left_index+1 : right_index]
                    #print(state_str)
                    if state_str == '未填报，请点击此处补报':
                        Unreported_Flag = 1
                        print("已定位到未填报项目，正在进行填报...\n")
                        try:
                            driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li[' + str(i) + ']').click()
                        except:
                            pass
                        #勾选"我承诺..." //*[@id="p1_ChengNuo-inputEl-icon"]
                        driver.find_element_by_xpath('//*[@id="p1_ChengNuo-inputEl-icon"]').click()
                        """#新版"每日一报"系统无需填写具体体温
                        #生成体温并填写
                        tempreture = '%.1f'%(random.uniform(36.0,36.9))
                        driver.find_element_by_xpath('//*[@id="p1_TiWen-inputEl"]').send_keys(str(tempreture))
                        """ 
                        #勾选"良好（体温不高于37.3）" //*[@id="fineui_0-inputEl-icon"]
                        driver.find_element_by_xpath('//*[@id="fineui_0-inputEl-icon"]').click()
                        #勾选"国内" //*[@id="fineui_5-inputEl-icon"]
                        driver.find_element_by_xpath('//*[@id="fineui_5-inputEl-icon"]').click()
                        #勾选"在上海" //*[@id="fineui_7-inputEl-icon"]
                        driver.find_element_by_xpath('//*[@id="fineui_7-inputEl-icon"]').click()
                        #勾选"住校" //*[@id="fineui_9-inputEl-icon"]
                        time.sleep(0.5)
                        driver.find_element_by_xpath('//*[@id="fineui_9-inputEl-icon"]').click()
                        time.sleep(0.5)
                        #勾选"不是家庭地址" //*[@id="fineui_12-inputEl-icon"]
                        driver.find_element_by_xpath('//*[@id="fineui_12-inputEl-icon"]').click()
                        """
                        #勾选"不在校"
                        driver.find_element_by_xpath('//*[@id="fineui_5-inputEl-icon"]').click()
                        #勾选"不到校" 
                        driver.find_element_by_xpath('//*[@id="fineui_10-inputEl-icon"]').click()
                        #勾选"国内"
                        driver.find_element_by_xpath('//*[@id="fineui_17-inputEl-icon"]').click()
                        time.sleep(0.1)
                        #勾选"不在上海"
                        driver.find_element_by_xpath('//*[@id="fineui_8-inputEl-icon"]').click()
                        
                        """
                        """#网页会按照以前的记录默认勾选
                        #勾选"否"
                        driver.find_element_by_xpath('//*[@id="fineui_21-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_27-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_17-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_19-inputEl-icon"]').click()
                        """
                        #点击提交按钮 //*[@id="p1_ctl00_btnSubmit"]
                        driver.find_element_by_xpath('//*[@id="p1_ctl00_btnSubmit"]').click()                
                        #确认对话框-点击"确定"
                        #driver.find_element_by_xpath('//*[@id="fineui_32"]').click() #//*[@id="fineui_42"]
                        for psb_num in range(0, 1024):
                            temp_xpath = '//*[@id="fineui_' + str(psb_num) + '"]'
                            try:
                                YorN = driver.find_element_by_xpath(temp_xpath)
                                temp_str = YorN.text
                                #print(temp_str)
                                if temp_str == '确定':
                                    driver.find_element_by_xpath(temp_xpath).click()
                                    #print("点击了1号确定！")
                                    break
                            except:
                                pass
                        time.sleep(0.2)
                        #提交成功-"确定" 或 "现在还没到晚报时间"-确定
                        for psb_num in range(0, 1024):
                            temp_xpath = '//*[@id="fineui_' + str(psb_num) + '"]'
                            try:
                                YorN = driver.find_element_by_xpath(temp_xpath)
                                temp_str = YorN.text
                                #print(temp_str)
                                if temp_str == '确定':
                                    driver.find_element_by_xpath(temp_xpath).click()
                                    break
                            except:
                                pass

                        #print("点击了2号确定！")
                        time.sleep(0.2)
                        try:
                            #提交成功-"确定"后会回到首页，再次进入"报送历史"进行确认
                            driver.find_element_by_xpath('//*[@id="lnkReportHistory"]').click()
                            i = 1
                            #print("已为您填报: " + temp_str[0 : left_index] + " 使用的体温为" + str(tempreture) + "\n")
                            print("已为您填报: " + temp_str[0 : left_index] + "\n")                        
                        except:
                            """
                            #"现在还没到晚报时间"-确定后返回上一页
                            driver.back()
                            print(temp_str[0 : left_index] + ' 由于"现在还没到晚报时间"原因，未能填报\n')
                            """
                            pass
        except:
            pass
    if Unreported_Flag == 0:
        print("您没有未填报的记录！\n")

#打开Chrome浏览器
print("正在打开Chrome浏览器...\n")
try:
    driver = webdriver.Chrome()
    print("已成功打开Chrome浏览器\n")
except:
    print("未能打开Chrome浏览器，请根据本文件前的'使用须知'第一条检查无误后重新运行此程序\n")
    time.sleep(20)
    exit()

#访问健康之路网页
print("正在跳转健康之路网页...\n")
driver.get('https://selfreport.shu.edu.cn')

#填写账号密码
print("正在填写账号密码...\n")
driver.find_element_by_xpath('//*[@id="username"]').send_keys(ID)   
driver.find_element_by_xpath('//*[@id="password"]').send_keys(Password) 
time.sleep(0.5)

#点击"登陆"
driver.find_element_by_xpath('//*[@id="submit"]').click()
print("登陆成功！\n")
time.sleep(0.5)

#进入"报送历史"
driver.find_element_by_xpath('//*[@id="lnkReportHistory"]').click()
time.sleep(0.5)

#检索未填报项目，并进行填报
Search_Unreported()