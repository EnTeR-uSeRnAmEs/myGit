#!/usr/bin/python
# -*- coding: GBK -*-
from selenium import webdriver
# from selenium import webdriver
import time,socket
# import os
from smtplib import SMTP_SSL
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header

def isNetOK(testserver = ('www.baidu.com',443)):
    s = socket.socket()
    s.settimeout(3)
    try:
        status = s.connect_ex(testserver)
        if status == 0:
            s.close()
            return 0
        else:
            return 1
    except Exception as e:
        return 1

# try:
#     from selenium import webdriver
# except:
#     i = ''
#     while i != 'Y' or 'N':
#         print("您的python缺少selenium模块，是否要现在为您安装？")
#         i = input("Y: 请帮我安装selenium\nN: 我要自己安装\n")
#         if i == 'Y':
#             print("正在为您安装selenium模块...\n")
#             try:
#                 os.system(f'pip install selenium')
#                 time.sleep(10)
#                 from selenium import webdriver
#             except:
#                 print("出现未知错误，未能成功安装selenium模块，请您在python.exe中使用'pip install selenium'命令手动为其安装selenium模块后重新运行此程序\n")
#                 time.sleep(20)
#                 exit()
#         elif i == 'N':
#             print("请您在python.exe中使用'pip install selenium'命令手动为其安装selenium模块后重新运行此程序\n")
#             time.sleep(20)
#             exit()

def Search_ID():    
    try:
        with open("message.txt","r", encoding="utf-8") as key:
            global ID,Password,Email
            file = key.readlines()
            ID = file[0][3:11]
            Password = file[1][9:]
            Email = file[2][6:]
    except:
        with open("message.txt","w") as key:
            idtmp = input('请输入ID：')
            pwtmp = input('请输入密码：')
            Email = input('请输入您的邮箱号：')
            key.write("ID=" + idtmp + "\nPassword=" + pwtmp + '\nE-mail=' + Email)
        Search_ID()


def login():
    print("正在打开Chrome浏览器...\n")   
    global driver
    try:
        # option=webdriver.ChromeOptions()
        # option.add_argument('headless')
        # driver = webdriver.Chrome(chrome_options=option)
        driver = webdriver.Chrome()
        print("已成功打开Chrome浏览器\n")
    except:
        print("未能打开Chrome浏览器，请检查当前文件夹是否有chromedriver.exe\n")
        time.sleep(20)
        exit()
    print("正在跳转健康之路网页...\n")
    driver.get('https://selfreport.shu.edu.cn')
    time.sleep(0.1)
    print("正在填写账号密码...\n")
    driver.find_element_by_xpath('//*[@id="username"]').send_keys(ID)   
    driver.find_element_by_xpath('//*[@id="password"]').send_keys(Password) 
    time.sleep(0.1)
    try:
        driver.find_element_by_xpath('//button[text() = "登录"]').click()
    except:
        pass
    print("登陆成功！\n")
    time.sleep(0.1)
    driver.find_element_by_xpath('//*[@id="lnkReportHistory"]').click()

def Search_Unreported():
    Unreported_Flag = 0
    print("正在检索未填报项目...\n")
    for t in range (1,30):
        i = 30 - t
        try:
            temp=driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li['+str(i)+']')
            temp_str = temp.text
            str_len = len(temp_str)
            for j in range(0, str_len):
                if temp_str[j] == '(':
                    left_index = j
                elif temp_str[j] == ')':
                    right_index = j
                    state_str = temp_str[left_index+1 : right_index]
                    if state_str == '未填报，请点击此处补报':
                        Unreported_Flag = 1
                        answer = ""
                        print("已定位到未填报项目，正在进行填报...\n")
                        try:
                            driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li[' + str(i) + ']').click()   
                            # driver.find_element_by_xpath('//*[text() = "我承诺，以下报送内容真实有效并可用于学校管理需要！"]').click()
                        except:
                            pass
                        try:
                            driver.find_element_by_xpath('//a[text() = "答案提示点击这里"]').click()
                            time.sleep(1)
                            answer = driver.find_element_by_xpath('//td/div[contains(text(), "参考答案")]').text
                            tmp = ""
                            for k in answer:
                                if (k >= "a" and k <= "z") or (k >= "A" and k <= "Z"):
                                    tmp += k
                            driver.find_element_by_xpath('//*[text() = "确定"]').click()
                            for k in tmp:
                                driver.find_element_by_xpath('//*[contains(text(), "' + str(k) + '.")]').click()
                        except:
                            # send_message()
                            pass
                        choice1 = "在上海（进过校内）"
                        # choice1 = "在上海（未进过校内）"
                        # choice1 = "不在上海"
                        choice2 = "住校"
                        # choice2 = "不住校"
                        choice3 = "不是家庭地址"
                        # choice3 = "家庭地址"
                        choice4 = "提交"
                        try:
                            driver_elements = driver.find_elements('class name', 'f-field-fileupload-fileinput')
                            try:
                                driver_elements[0].send_keys('C:\\Users\\24798\\Desktop\\Daily_Report\\健康码.png')
                                time.sleep(5)
                            except:
                                pass
                            try:
                                driver_elements[1].send_keys('C:\\Users\\24798\\Desktop\\Daily_Report\\行程码.png')
                                time.sleep(5)
                            except:
                                pass
                        except:
                            pass
                        # driver.find_element_by_xpath('//*[@id="p1_ChengNuo-inputEl"]').click()
                        try:
                            driver.find_element_by_xpath('//*[text() = "我承诺，以下报送内容真实有效并可用于学校管理需要！"]').click()
                        except:
                            pass
                        time.sleep(0.2)
                        try:
                            driver.find_element_by_xpath('//*[text() = "' + choice1 + '"]').click()
                            time.sleep(1)
                        except:
                            # driver.find_element_by_xpath('//*[text() = "在上海（校内）"]').click()
                            pass
                        try:
                            driver.find_element_by_xpath('//*[text() = "' + choice2 + '"]').click()
                            time.sleep(0.2)
                        except:
                            pass
                        try:
                            driver.find_element_by_xpath('//*[text() = "' + choice3 + '"]').click()
                            time.sleep(0.2)
                        except:
                            pass
                        try:
                            driver.find_element_by_xpath('//*[text() = "' + choice4 + '"]').click()
                            time.sleep(0.2)
                        except:
                            pass
                        driver.find_element_by_xpath('//*[text() = "确定"]').click()
                        time.sleep(0.2)
                        driver.find_element_by_xpath('//a[text() = "确定"]').click()
                        time.sleep(0.2)
                        driver.find_element_by_xpath('//*[@id="lnkReportHistory"]').click()
                        time.sleep(0.2)
        except:
            driver.find_element_by_xpath('//*[text() = "首页"]').click()
            driver.find_element_by_xpath('//*[@id="lnkReportHistory"]').click()
            send_message()
    if Unreported_Flag == 0:
        print("您没有未填报的记录！\n")

def send_message():
    host_server = 'smtp.163.com'
    sender = 'python_test2003@163.com' 
    pwd = 'CSTMAZZIUUOPHHIZ'
    receiver = [Email]
    mail_title = '每日一报提醒' 
    mail_content = "今日每日一报失败，请手动提交！" #邮件正文内容
    msg = MIMEMultipart()
    msg["Subject"] = Header(mail_title,'utf-8')
    msg["From"] = sender
    msg['To'] = ";".join(receiver)
    msg.attach(MIMEText(mail_content,'plain','utf-8'))
    smtp = SMTP_SSL(host_server) # ssl登录
    smtp.login(sender,pwd)
    smtp.sendmail(sender,receiver,msg.as_string())
    smtp.quit()

#main:
flag = 1
while True:
    if not isNetOK():
        Search_ID()
        login()
        Search_Unreported()
        print('您已完成填报！\n')
        time.sleep(5)
        driver.quit()
        break
    else:
        if flag:
            print('网络连接失败，请查看您的网络连接。\n')
            # send_message()
            flag = 0