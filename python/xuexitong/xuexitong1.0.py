# coding=gbk
from time import sleep
# import os
from selenium import webdriver

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
        driver = webdriver.Chrome()
    except:
        print("δ�ܴ�Chrome����������鵱ǰ�ļ����Ƿ���chromedriver.exe\n")
        sleep(20)
        exit()
    print("������תѧϰͨƽ̨...\n")
    # driver.get('http://passport2.chaoxing.com/login?loginType=3&newversion=true&fid=35480&hidecompletephone=0&refer=http%3A%2F%2Fmooc1-1.chaoxing.com%2Fvisit%2Finteraction%3Fs%3Df5d44c1282b4bbf136c371a769a1979b&accounttip=&pwdtip=')
    driver.get('https://mooc2-ans.chaoxing.com/mycourse/stu?courseid=221822828&clazzid=48889926&cpi=197561990&enc=e3afd67176866fc7e299557dbfb52562&t=1639033411312&pageHeader=1')
    sleep(0.5)
    print("������д�˺�����...\n")
    # driver.find_element_by_xpath('//*[@class = "fr beforLogin"]').click
    # ID = input("Enter ID: ")
    # Password = input("Enter Password: ")
    ID = "21122782"
    Password = "20030307Love"
    driver.find_element_by_xpath('//*[@id = "uname"]').send_keys(ID)   
    driver.find_element_by_xpath('//*[@id = "password"]').send_keys(Password)
    vercode = input("Enter vercode: ")
    driver.find_element_by_xpath('//*[@id = "vercode"]').send_keys(vercode)
    sleep(10)
    try:
        driver.find_element_by_xpath('//*[@id="loginBtn"]').click()
        print("��½�ɹ���\n")
    except:
        pass
    driver.find_element_by_xpath('//*[text() = "�Ͷ��������ۿ�"]').click()
    
    sleep(5)
    driver.quit()

# Search_ID()
login()