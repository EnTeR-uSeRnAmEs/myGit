#!/usr/bin/python
# -*- coding: GBK -*-

# from selenium import webdriver
from socket import socket
from time import sleep
import os
import sys
import msvcrt
from smtplib import SMTP_SSL
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header


def curdir():
    return os.path.realpath(os.path.dirname(sys.argv[0]))


def schtask_com():
    # cd2curdir()
    import win32com.client

    # A constant that specifies a time-based trigger.
    TriggerTypeTime = 1
    # A constant that specifies an executable action.
    ActionTypeExec = 0
    # ********************************************************
    # Create the TaskService object.
    service = win32com.client.Dispatch("Schedule.Service")
    service.Connect()
    # ********************************************************
    # Get a folder to create a task definition in.
    # Dim rootFolder
    rootFolder = service.GetFolder("\\")
    taskDefinition = service.NewTask(0)
    # Define information about the task.
    # Set the registration info for the task by
    # creating the RegistrationInfo object.
    regInfo = taskDefinition.RegistrationInfo
    regInfo.Description = "Start Daily_Report_2.2 at a certain time"
    regInfo.Author = "����"

    # ********************************************************
    # Set the principal for the task
    principal = taskDefinition.Principal

    # Set the logon type to interactive logon
    principal.LogonType = 3

    # Set the task setting info for the Task Scheduler by
    # creating a TaskSettings object.
    # http://msdn.microsoft.com/en-us/library/windows/desktop/aa383480(v=VS.85).aspx
    settings = taskDefinition.Settings
    settings.Enabled = True  # If True, the task is enabled.
    settings.StartWhenAvailable = True
    # If False, the task will be visible in the UI. The default is False.
    settings.Hidden = False
    # Starts a new instance while an existing instance of the task is running.
    settings.MultipleInstances = 0
    settings.RunOnlyIfNetworkAvailable = True
    settings.WakeToRun = True
    settings.StopIfGoingOnBatteries = False
    settings.DisallowStartIfOnBatteries = False

    # ********************************************************
    # Create a time-based trigger.
    triggers = taskDefinition.Triggers
    trigger = triggers.Create(TriggerTypeTime)

    # Trigger variables that define when the trigger is active.
    trigger.StartBoundary = "2022-03-04T02:00:00"
    trigger.EndBoundary = "2025-09-01T02:00:00"
    trigger.ExecutionTimeLimit = "PT5M"  # Five minutes
    trigger.Id = "Daily_Report_2.2_for_SHU"
    trigger.Enabled = True

    # ***********************************************************
    # Create the action for the task to execute.

    # Add an action to the task to run notepad.exe.
    Action = taskDefinition.Actions.Create(ActionTypeExec)
    Action.Path = curdir() + '\\Daily_Report_2.2.exe'

    print("Task definition created. About to submit the task...")
    rootFolder.RegisterTaskDefinition(
        "Daily_Report", taskDefinition, 6, None, None, 3)
    print("Task submitted.")


def get_password():
    li = []
    while True:
        ch = msvcrt.getch()
        # �س�
        if ch == b'\r':
            msvcrt.putch(b'\n')
            return b''.join(li).decode()
        # �˸�
        elif ch == b'\x08':
            if li:
                li.pop()
                msvcrt.putch(b'\b')
                msvcrt.putch(b' ')
                msvcrt.putch(b'\b')
        # Esc
        elif ch == b'\x1b':
            break
        else:
            li.append(ch)
            msvcrt.putch(b'*')


def isNetOK(testserver=('www.baidu.com', 443)):
    s = socket()
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


try:
    from selenium import webdriver
    from selenium.webdriver.common.by import By
    from selenium.webdriver.chrome.options import Options
except:
    i = ''
    while i != 'Y' or 'N':
        print("����pythonȱ��seleniumģ�飬�Ƿ�Ҫ����Ϊ����װ��")
        i = input("Y: ����Ұ�װselenium\nN: ��Ҫ�Լ���װ\n")
        if i == 'Y':
            print("����Ϊ����װseleniumģ��...\n")
            try:
                os.system(f'pip install selenium')
                sleep(10)
                from selenium import webdriver
                from selenium.webdriver.common.by import By
                from selenium.webdriver.chrome.options import Options
            except:
                print("����δ֪����δ�ܳɹ���װseleniumģ�飬������python.exe��ʹ��'pip install selenium'�����ֶ�Ϊ�䰲װseleniumģ����������д˳���\n")
                sleep(20)
                exit()
        elif i == 'N':
            print("������python.exe��ʹ��'pip install selenium'�����ֶ�Ϊ�䰲װseleniumģ����������д˳���\n")
            sleep(20)
            exit()


def Search_ID():
    if not os.path.exists(curdir() + '\\data'):
        os.mkdir(curdir() + '\\data')
    try:
        with open(curdir() + "\\data\\message.txt", "r", encoding="utf-8") as key:
            global ID, Password, Email
            file = key.readlines()
            ID = file[0][3:11]
            Password = file[1][9:]
            Email = file[2][6:]
    except:
        with open(curdir() + "\\data\\message.txt", "w") as key:
            idtmp = input('������ID��')
            print('���������룺', end='', flush=True)
            # pwtmp = input('���������룺')
            pwtmp = get_password()
            Email = input('��������������ţ�')
            key.write("ID=" + idtmp + "\nPassword=" +
                      pwtmp + '\nE-mail=' + Email)
            schtask_com()
        Search_ID()


def login():
    print("���ڴ�Chrome�����...\n")
    global driver
    try:
        chrome_options = Options()
        # chrome_options.add_argument('--headless')
        chrome_options.add_argument('--incognito')
        chrome_options.add_experimental_option(
            "excludeSwitches", ['enable-automation', 'enable-logging'])
        driver = webdriver.Chrome(options=chrome_options)
        # driver = webdriver.Chrome()
        print("�ѳɹ���Chrome�����\n")
    except:
        print("δ�ܴ�Chrome����������鵱ǰ�ļ����Ƿ���chromedriver.exe\n")
        sleep(20)
        exit()
    print("������ת����֮·��ҳ...\n")
    driver.get('https://selfreport.shu.edu.cn')
    sleep(0.1)
    print("������д�˺�����...\n")
    driver.find_element(By.XPATH, '//*[@id="username"]').send_keys(ID)
    driver.find_element(By.XPATH, '//*[@id="password"]').send_keys(Password)
    sleep(0.1)
    try:
        driver.find_element(By.XPATH, '//button[text() = "��¼"]').click()
    except:
        pass
    print("��½�ɹ���\n")
    sleep(0.1)
    try:
        driver.find_element(By.XPATH, '//span[text() = "ȡ��"]').click()
    except:
        pass
    try:
        driver.find_element(By.XPATH, '//*[@id="lnkReportHistory"]').click()
    except:
        driver.find_element(By.XPATH,
                            '//*[text() = "ȷ�����Ķ�"]').click()
        driver.find_element(By.XPATH, '//*[@id="lnkReportHistory"]').click()


def Search_Unreported():
    Unreported_Flag = 0
    print("���ڼ���δ���Ŀ...\n")
    for t in range(1, 30):
        i = 30 - t
        try:
            temp = driver.find_element(By.XPATH,
                                       '//*[@id="Panel1_DataList1"]/ul/li['+str(i)+']')
            temp_str = temp.text
            str_len = len(temp_str)
            for j in range(0, str_len):
                if temp_str[j] == '(':
                    left_index = j
                elif temp_str[j] == ')':
                    right_index = j
                    state_str = temp_str[left_index+1: right_index]
                    if state_str == 'δ��������˴�����':
                        Unreported_Flag = 1
                        answer = ""
                        print("�Ѷ�λ��δ���Ŀ�����ڽ����...\n")
                        try:
                            driver.find_element(By.XPATH,
                                                '//*[@id="Panel1_DataList1"]/ul/li[' + str(i) + ']').click()
                            # driver.find_element(By.XPATH, '//*[text() = "�ҳ�ŵ�����±���������ʵ��Ч��������ѧУ������Ҫ��"]').click()
                        except:
                            pass
                        try:
                            driver.find_element(By.XPATH,
                                                '//a[text() = "����ʾ�������"]').click()
                            sleep(1)
                            answer = driver.find_element(By.XPATH,
                                                         '//td/div[contains(text(), "�ο���")]').text
                            tmp = ""
                            for k in answer:
                                if (k >= "a" and k <= "z") or (k >= "A" and k <= "Z"):
                                    tmp += k
                            driver.find_element(By.XPATH,
                                                '//*[text() = "ȷ��"]').click()
                            for k in tmp:
                                driver.find_element(By.XPATH,
                                                    '//*[contains(text(), "' + str(k) + '.")]').click()
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
                            driver_elements = driver.find_elements(
                                'class name', 'f-field-fileupload-fileinput')
                            try:
                                driver_elements[0].send_keys(
                                    curdir() + '\\data\\������.png')
                                sleep(3)
                            except:
                                pass
                            try:
                                driver_elements[1].send_keys(
                                    curdir() + '\\data\\�г���.png')
                                sleep(3)
                            except:
                                pass
                        except:
                            pass
                        # driver.find_element(By.XPATH, '//*[@id="p1_ChengNuo-inputEl"]').click()
                        try:
                            driver.find_element(By.XPATH,
                                                '//*[text() = "�ҳ�ŵ�����±���������ʵ��Ч��������ѧУ������Ҫ��"]').click()
                        except:
                            pass
                        sleep(0.2)
                        try:
                            driver.find_element(By.XPATH,
                                                '//*[text() = "' + choice1 + '"]').click()
                            sleep(1)
                        except:
                            # driver.find_element(By.XPATH, '//*[text() = "���Ϻ���У�ڣ�"]').click()
                            pass
                        try:
                            driver.find_element(By.XPATH,
                                                '//*[text() = "' + choice2 + '"]').click()
                            sleep(0.2)
                        except:
                            pass
                        try:
                            driver.find_element(By.XPATH,
                                                '//*[text() = "' + choice3 + '"]').click()
                            sleep(0.2)
                        except:
                            pass
                        try:
                            driver.find_element(By.XPATH,
                                                '//*[text() = "' + choice4 + '"]').click()
                            sleep(0.2)
                        except:
                            pass
                        driver.find_element(By.XPATH,
                                            '//*[text() = "ȷ��"]').click()
                        sleep(0.2)
                        driver.find_element(By.XPATH,
                                            '//span[text() = "ȷ��"]').click()
                        sleep(0.2)
                        driver.find_element(By.XPATH,
                                            '//*[@id="lnkReportHistory"]').click()
                        sleep(0.2)
                        try:
                            driver.find_element(
                                By.XPATH, '//span[text() = "ȡ��"]').click()
                        except:
                            pass
                        try:
                            driver.find_element(
                                By.XPATH, '//*[@id="lnkReportHistory"]').click()
                        except:
                            driver.find_element(By.XPATH,
                                                '//*[text() = "ȷ�����Ķ�"]').click()
        except:
            try:
                send_message()
                driver.find_element(By.XPATH, '//*[text() = "��ҳ"]').click()
                driver.find_element(
                    By.XPATH, '//*[@id="lnkReportHistory"]').click()
            except:
                pass
    if Unreported_Flag == 0:
        print("��û��δ��ļ�¼��\n")


def send_message():
    host_server = 'smtp.163.com'
    sender = 'python_test2003@163.com'
    pwd = 'CSTMAZZIUUOPHHIZ'
    receiver = [Email]
    mail_title = 'ÿ��һ������'
    mail_content = "����ÿ��һ��ʧ�ܣ����ֶ��ύ��"  # �ʼ���������
    msg = MIMEMultipart()
    msg["Subject"] = Header(mail_title, 'utf-8')
    msg["From"] = sender
    msg['To'] = ";".join(receiver)
    msg.attach(MIMEText(mail_content, 'plain', 'utf-8'))
    smtp = SMTP_SSL(host_server)  # ssl��¼
    smtp.login(sender, pwd)
    smtp.sendmail(sender, receiver, msg.as_string())
    smtp.quit()


# main:
if __name__ == '__main__':
    flag = 1
    while True:
        if not isNetOK():
            # cd2curdir()
            print(curdir())
            Search_ID()
            login()
            Search_Unreported()
            print('����������\n')
            sleep(5)
            driver.quit()
            break
        else:
            if flag:
                print('��������ʧ�ܣ���鿴�����������ӡ�\n')
                # send_message()
                flag = 0
