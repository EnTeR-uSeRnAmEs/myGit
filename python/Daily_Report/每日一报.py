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

'''
def F_SendAsBots_QQ():
    
    import win32gui
    import win32con
    import win32clipboard as w
    import win32api
    import time
    #from pandas import read_excel 
    
    
    print("未能成功切换WiFi，已调用SendAsBots_QQ消息自动发送工具向手机发送提醒消息！\nProduction Name: SendAsBots_QQ Steve's Customized Edition\nCopyright (c) 2020 Steve D. J..All rights reserved.\n")
    
    name_list = ['我的iPhone']
    
    def setText(massage):   #设定剪贴板文本
        w.OpenClipboard()
        w.EmptyClipboard()
        w.SetClipboardData(win32con.CF_UNICODETEXT, massage)
        w.CloseClipboard()
    
    
    def send_qq(massage):
        setText(massage)
        
        hwnd_title = dict()    
        def get_all_hwnd(hwnd,mouse):
            if win32gui.IsWindow(hwnd) and win32gui.IsWindowEnabled(hwnd) and win32gui.IsWindowVisible(hwnd):
                hwnd_title.update({hwnd:win32gui.GetWindowText(hwnd)})
        
        win32gui.EnumWindows(get_all_hwnd, 0)
        for h,t in hwnd_title.items():
            if t != "":                    
                hwnd = win32gui.FindWindow('TXGuiFoundation', t)    # 获取qq窗口句柄    
                if hwnd != 0:
                    #win32gui.SendMessage(hwnd, win32con.WM_SYSCOMMAND, win32con.SC_RESTORE, 0)    #虽然可以还原最小化的会话窗口，但经过测试发现并不能解决还原后不发送消息的问题。
                    win32gui.ShowWindow(hwnd,win32con.SW_SHOW)
                    time.sleep(0.1)
                    win32gui.SetForegroundWindow(hwnd)
                    win32gui.SetActiveWindow(hwnd)
                    time.sleep(0.1)
                    win32gui.SendMessage(hwnd,770, 0, 0)    # 将剪贴板文本发送到QQ窗体
                    win32gui.SendMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)  #模拟按下回车键
                    win32gui.SendMessage(hwnd, win32con.WM_KEYUP, win32con.VK_RETURN, 0)  #模拟松开回车键
    
    
    def open_windows():     #打开QQ会话窗口
        qq_hwnd = win32gui.FindWindow(None, 'QQ') 
        print("捕捉到QQ主窗体的句柄为:"+str(qq_hwnd))
        win32gui.ShowWindow(qq_hwnd,win32con.SW_SHOW)
        print("正在打开会话窗口...\n")
        time.sleep(1)
        for i in name_list:
            massage = i
            setText(massage)
            win32gui.SetForegroundWindow(qq_hwnd)
            win32gui.SetActiveWindow(qq_hwnd)
            time.sleep(1)
            win32gui.SendMessage(qq_hwnd,770, 0, 0)
            time.sleep(1)
            win32gui.SetForegroundWindow(qq_hwnd)
            win32gui.SetActiveWindow(qq_hwnd)
            win32api.keybd_event(0x0D, win32api.MapVirtualKey(0x0D, 0), 0, 0)   
            win32api.keybd_event(0x0D, win32api.MapVirtualKey(0x0D, 0), win32con.KEYEVENTF_KEYUP, 0)
    
    
    open_windows()
    
    massage = '[来自Auto_SelfReport的消息]请将iPhone切换至“个人热点”设置页面帮助Windows连接手机热点！'
    
    ct = 1
    
    print("发送信息中...\n")
    
    time.sleep(1)
    
    while ct > 0:
        send_qq(massage)
        ct = ct - 1
        print("消息已发出！\n")
        time.sleep(1)


#获取当前连接的WIFI名称 - 方法来源: https://cloud.tencent.com/developer/news/311861
def Get_CurrentSSID():
    from subprocess import check_output
    print("正在调用'showssid.cmd'获取当前网络信息...")
    scanoutput = check_output([r"C:/showSSID.cmd"])    #须将"showSSID.cmd"文件置于同一文件路径下
    currentSSID = scanoutput.decode()
    currentSSID = currentSSID[0:3]
    print(currentSSID)
    return currentSSID


#获取现在时刻的时间戳
def Get_LocalTime():
    return int(time.mktime(time.strptime(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()), "%Y-%m-%d %H:%M:%S")))  


#计算00:00时间戳
def Find_00():
    stamp_localTime = int(time.mktime(time.strptime(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()), "%Y-%m-%d %H:%M:%S")))
    stamp_next_zero = stamp_localTime + 86400
    temp_array = time.localtime(stamp_next_zero)
    str_next_zero = time.strftime('%Y-%m-%d', temp_array) + ' 00:00:00'
    temp_array = time.strptime(str_next_zero, '%Y-%m-%d %H:%M:%S')
    stamp_next_zero = int(time.mktime(temp_array))
    return stamp_next_zero

 
#计算次日00:00时间戳（参考时间）
stamp_standard = Find_00()

#检查网络连接
Wifi_Change_Flag = 0    #0：程序未修改过WiFi设置；1：修改过了
Change_Success_Flag = 0
try:
    if Get_CurrentSSID() == Banned_Wifi_Name:
        print("您目前连接的无线网络为" + Banned_Wifi_Name + "，无法进行每日一报，将为您自动连接到" + Spare_Wifi_Name + "...\n")
        #自动改连其他网络
        os.system('netsh wlan connect name=' + '"' + Spare_Wifi_Name + '"')
        Wifi_change_flag = 1
        time.sleep(10)
        while Get_CurrentSSID() == Banned_Wifi_Name:
            F_SendAsBots_QQ()
            os.system('netsh wlan connect name=' + '"' + Spare_Wifi_Name + '"')
            Wifi_change_flag = 1
            time.sleep(10)

except:
    print("由于未知原因，未能成功连接备用网络！\n请检查设置后重试\n")
    time.sleep(20)
    exit()
 
#每秒核验时间准时启动主进程
print("脚本已做好准备，即将于00:00准时为您填报...\n")
while True:
    stamp_localtime = Get_LocalTime()
    if stamp_standard <= stamp_localtime:
        break
    elif stamp_standard - stamp_localtime > 60:
        time.sleep(60)
    else:
        time.sleep(1)
'''
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
'''                   
#检查并恢复WiFi设置
if Wifi_Change_Flag == 1:
    try:
        os.system('netsh wlan connect name=' + '"' + Banned_Wifi_Name + '"')
    except:
        print("由于未知原因未能恢复WiFi设置，请您手动恢复！\n")

print("已为您完成每日两报！\n")
'''



#通过当前时间戳与唤醒时间戳的差值判断是否执行休眠（不可行，因为无法获取唤醒时间戳）
"""
#获取系统开机时间 - 方法来源: https://www.cnblogs.com/hushaojun/p/8202850.html
def Get_OSStartTime():
    import psutil
    return int(time.mktime(time.strptime(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(psutil.boot_time())), "%Y-%m-%d %H:%M:%S")))
    psutil.memoize_when_activated

#获取现在时刻的时间
def Get_LocalTime():
    return int(time.mktime(time.strptime(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()), "%Y-%m-%d %H:%M:%S")))  
               
#判断是否是为每日两报而自动唤醒，从而确定是否要执行完程序自动睡眠
try:
    local_time = Get_LocalTime()
    OS_StartTime = Get_OSStartTime()
    
    if  local_time - OS_StartTime <= 300:   #如果当前时间与开机时间的差值小于5min，则倒计时30s后"shutdown -h"
        i = 0
        while i <= 30:
            print(str(30 - i) + '秒后将执行休眠命令"shutdown -h"，现在关闭此程序可阻止休眠执行...\n')
            time.sleep(1)
        driver.close()
        #执行休眠命令
        os.system(f'shutdown -h')
        exit()            
    else:
        driver.close()
        exit()            
except:
    driver.close()
    exit()            
"""                    

'''
#完成填报后的等待一段时间，若用户不执行特定操作则执行休眠
time_remained = 600 #预留10分钟
while time_remained >= 0:
    print("请关闭程序窗口，否则将于" + str(time_remained) + "秒后自动休眠电脑")
    time.sleep(60)
    time_remained = time_remained - 60
#执行休眠命令
os.system(f'shutdown -h')
'''