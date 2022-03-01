# from selenium import webdriver
import time,os

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
            idtmp=input('请输入ID：')
            pwtmp=input('请输入密码：')
            key.write("ID="+idtmp+"\nPassword="+pwtmp)
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
Search_ID()
login()
Search_Unreported()
print('您已完成填报！\n')
time.sleep(5)
driver.quit()