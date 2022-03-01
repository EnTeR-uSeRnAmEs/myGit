ID = '21122782'
Password = '20030307Love' 
from selenium import webdriver
import time,os
def Search_ID():    
    try:
        with open("test.txt","r") as key:
            print(key.readlines())
    except:
        with open("test.txt","w") as key:
            idtmp=input('请输入ID：')
            pwtmp=input('请输入密码：')
            key.write("ID="+idtmp+"\nPassword="+pwtmp)
option=webdriver.ChromeOptions()
option.add_argument('headless')
driver = webdriver.Chrome(chrome_options=option)
# driver = webdriver.Chrome()
driver.get('https://selfreport.shu.edu.cn')
driver.find_element_by_xpath('//*[@id="username"]').send_keys(ID)   
driver.find_element_by_xpath('//*[@id="password"]').send_keys(Password) 
driver.find_element_by_xpath('//*[@id="submit"]').click()
time.sleep(0.5)
driver.find_element_by_xpath('//*[@id="lbReportHistory"]').click()
def Serch_Unreported():
    Unreported_Flag = 0
    print("正在检索未填报项目...\n")
    # for i in range (1,30):    
    try:
        time.sleep(0.2)
        temp=driver.find_element_by_xpath('//*[@id="Panel1_DataList1"]/ul/li[1]')
        # #print(temp.text)
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
    except:
        print('您已完成填报！')



Serch_Unreported()
time.sleep(1)
driver.quit()