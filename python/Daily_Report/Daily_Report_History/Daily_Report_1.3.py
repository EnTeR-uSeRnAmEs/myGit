# coding=gbk
# from selenium import webdriver
import time,socket
# import os
from selenium import webdriver

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
        with open("test.txt","r", encoding="utf-8") as key:
            # print(key.readlines())
            global ID,Password
            file = key.readlines()
            ID = file[0][3:11]
            Password = file[1][9:]
            # print(ID,Password)
    except:
        with open("test.txt","w") as key:
            idtmp=input('������ID��')
            pwtmp=input('���������룺')
            key.write("ID="+idtmp+"\nPassword="+pwtmp)
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
    time.sleep(0.5)
    print("������д�˺�����...\n")
    driver.find_element_by_xpath('//*[@id="username"]').send_keys(ID)   
    driver.find_element_by_xpath('//*[@id="password"]').send_keys(Password) 
    time.sleep(0.5)
    driver.find_element_by_xpath('//*[@id="submit"]').click()
    print("��½�ɹ���\n")
    time.sleep(0.5)
    driver.find_element_by_xpath('//*[@id="lbReportHistory"]').click()

def Search_Unreported():
    Unreported_Flag = 0
    print("���ڼ���δ���Ŀ...\n")
    for i in range (1,32):    
        try:
            time.sleep(0.2)
            temp=driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li['+str(i)+']')
            # print(temp.text)
            temp_str = temp.text
            str_len = len(temp_str)
            for j in range(0, str_len):
                if temp_str[j] == '(':
                    left_index = j
                elif temp_str[j] == ')':
                    right_index = j
                    state_str = temp_str[left_index+1 : right_index]
                    # print(state_str)
                    if state_str == 'δ��������˴�����':
                        Unreported_Flag = 1
                        print("�Ѷ�λ��δ���Ŀ�����ڽ����...\n")
                        try:
                            driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li[1]').click()   
                        except:
                            pass
                        driver.find_element_by_xpath('//*[@id="p1_ChengNuo-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_0-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_8-inputEl-icon"]').click()
                        time.sleep(0.5)
                        driver.find_element_by_xpath('//*[@id="fineui_10-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_13-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="p1_ctl02_btnSubmit"]').click()
                        time.sleep(0.5)
                        # driver.find_element_by_xpath('//*[@id="fineui_41-inputEl-icon"]').click()
                        # driver.find_element_by_xpath('//*[@id="fineui_51-inputEl-icon"]').click()
                        for psb_num in range(0, 1024):
                                temp_xpath = '//*[@id="fineui_' + str(psb_num) + '"]'
                                try:
                                    YorN = driver.find_element_by_xpath(temp_xpath)
                                    temp_str = YorN.text
                                    #print(temp_str)
                                    if temp_str == 'ȷ��':
                                        driver.find_element_by_xpath(temp_xpath).click()
                                        #print("�����1��ȷ����")
                                        break
                                except:
                                    pass
                        # break
        except:
            pass
        
    if Unreported_Flag == 0:
        print("��û��δ��ļ�¼��\n")

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
            flag = 0