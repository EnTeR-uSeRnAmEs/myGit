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
#         print("����pythonȱ��seleniumģ�飬�Ƿ�Ҫ����Ϊ����װ��")
#         i = input("Y: ����Ұ�װselenium\nN: ��Ҫ�Լ���װ\n")
#         if i == 'Y':
#             print("����Ϊ����װseleniumģ��...\n")
#             try:
#                 os.system(f'pip install selenium')
#                 time.sleep(10)
#                 from selenium import webdriver
#             except:
#                 print("����δ֪����δ�ܳɹ���װseleniumģ�飬������python.exe��ʹ��'pip install selenium'�����ֶ�Ϊ�䰲װseleniumģ����������д˳���\n")
#                 time.sleep(20)
#                 exit()
#         elif i == 'N':
#             print("������python.exe��ʹ��'pip install selenium'�����ֶ�Ϊ�䰲װseleniumģ����������д˳���\n")
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
            idtmp = input('������ID��')
            pwtmp = input('���������룺')
            Email = input('��������������ţ�')
            key.write("ID=" + idtmp + "\nPassword=" + pwtmp + '\nE-mail=' + Email)
        Search_ID()


def login():
    print("���ڴ�Chrome�����...\n")   
    global driver
    try:
        # option=webdriver.ChromeOptions()
        # option.add_argument('headless')
        # driver = webdriver.Chrome(chrome_options=option)
        driver = webdriver.Chrome()
        print("�ѳɹ���Chrome�����\n")
    except:
        print("δ�ܴ�Chrome����������鵱ǰ�ļ����Ƿ���chromedriver.exe\n")
        time.sleep(20)
        exit()
    print("������ת����֮·��ҳ...\n")
    driver.get('https://selfreport.shu.edu.cn')
    time.sleep(0.1)
    print("������д�˺�����...\n")
    driver.find_element_by_xpath('//*[@id="username"]').send_keys(ID)   
    driver.find_element_by_xpath('//*[@id="password"]').send_keys(Password) 
    time.sleep(0.1)
    try:
        driver.find_element_by_xpath('//button[text() = "��¼"]').click()
    except:
        pass
    print("��½�ɹ���\n")
    time.sleep(0.1)
    driver.find_element_by_xpath('//*[@id="lnkReportHistory"]').click()

def Search_Unreported():
    Unreported_Flag = 0
    print("���ڼ���δ���Ŀ...\n")
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
                    if state_str == 'δ��������˴�����':
                        Unreported_Flag = 1
                        answer = ""
                        print("�Ѷ�λ��δ���Ŀ�����ڽ����...\n")
                        try:
                            driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li[' + str(i) + ']').click()   
                            # driver.find_element_by_xpath('//*[text() = "�ҳ�ŵ�����±���������ʵ��Ч��������ѧУ������Ҫ��"]').click()
                        except:
                            pass
                        try:
                            driver.find_element_by_xpath('//a[text() = "����ʾ�������"]').click()
                            time.sleep(1)
                            answer = driver.find_element_by_xpath('//td/div[contains(text(), "�ο���")]').text
                            tmp = ""
                            for k in answer:
                                if (k >= "a" and k <= "z") or (k >= "A" and k <= "Z"):
                                    tmp += k
                            driver.find_element_by_xpath('//*[text() = "ȷ��"]').click()
                            for k in tmp:
                                driver.find_element_by_xpath('//*[contains(text(), "' + str(k) + '.")]').click()
                        except:
                            # send_message()
                            pass
                        choice1 = "���Ϻ�������У�ڣ�"
                        # choice1 = "���Ϻ���δ����У�ڣ�"
                        # choice1 = "�����Ϻ�"
                        choice2 = "סУ"
                        # choice2 = "��סУ"
                        choice3 = "���Ǽ�ͥ��ַ"
                        # choice3 = "��ͥ��ַ"
                        choice4 = "�ύ"
                        try:
                            driver_elements = driver.find_elements('class name', 'f-field-fileupload-fileinput')
                            try:
                                driver_elements[0].send_keys('C:\\Users\\24798\\Desktop\\Daily_Report\\������.png')
                                time.sleep(5)
                            except:
                                pass
                            try:
                                driver_elements[1].send_keys('C:\\Users\\24798\\Desktop\\Daily_Report\\�г���.png')
                                time.sleep(5)
                            except:
                                pass
                        except:
                            pass
                        # driver.find_element_by_xpath('//*[@id="p1_ChengNuo-inputEl"]').click()
                        try:
                            driver.find_element_by_xpath('//*[text() = "�ҳ�ŵ�����±���������ʵ��Ч��������ѧУ������Ҫ��"]').click()
                        except:
                            pass
                        time.sleep(0.2)
                        try:
                            driver.find_element_by_xpath('//*[text() = "' + choice1 + '"]').click()
                            time.sleep(1)
                        except:
                            # driver.find_element_by_xpath('//*[text() = "���Ϻ���У�ڣ�"]').click()
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
                        driver.find_element_by_xpath('//*[text() = "ȷ��"]').click()
                        time.sleep(0.2)
                        driver.find_element_by_xpath('//a[text() = "ȷ��"]').click()
                        time.sleep(0.2)
                        driver.find_element_by_xpath('//*[@id="lnkReportHistory"]').click()
                        time.sleep(0.2)
        except:
            driver.find_element_by_xpath('//*[text() = "��ҳ"]').click()
            driver.find_element_by_xpath('//*[@id="lnkReportHistory"]').click()
            send_message()
    if Unreported_Flag == 0:
        print("��û��δ��ļ�¼��\n")

def send_message():
    host_server = 'smtp.163.com'
    sender = 'python_test2003@163.com' 
    pwd = 'CSTMAZZIUUOPHHIZ'
    receiver = [Email]
    mail_title = 'ÿ��һ������' 
    mail_content = "����ÿ��һ��ʧ�ܣ����ֶ��ύ��" #�ʼ���������
    msg = MIMEMultipart()
    msg["Subject"] = Header(mail_title,'utf-8')
    msg["From"] = sender
    msg['To'] = ";".join(receiver)
    msg.attach(MIMEText(mail_content,'plain','utf-8'))
    smtp = SMTP_SSL(host_server) # ssl��¼
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
        print('����������\n')
        time.sleep(5)
        driver.quit()
        break
    else:
        if flag:
            print('��������ʧ�ܣ���鿴�����������ӡ�\n')
            # send_message()
            flag = 0