#!usr/bin/python
#-*- coding: GBK -*-
from selenium import webdriver
from time import sleep

account = input('请输入学号：')
password = input('请输入密码：')
classes = []

while True:
    tmp = input('请输入（课程号 教师号）与回车，以0作为输入完毕：').split()
    if tmp == ['0']:
        break
    else:
        classes.append(tmp)

driver = webdriver.Chrome()
sleep(1)
driver.get('http://xk.autoisp.shu.edu.cn/')
sleep(1)
input("请输入回车以开始选课...")
driver.find_element_by_xpath('//*[@id = "username"]').send_keys(account)
driver.find_element_by_xpath('//*[@id = "password"]').send_keys(password)
driver.find_element_by_xpath('//button[text() = "登录"]').click()
for i in classes:
    driver.find_element_by_xpath('//span[text() = "选课"]').click()
    driver.find_element_by_xpath('//button[@type = "submit"]').click()
    driver.find_element_by_xpath('//*[@id = "CourseSelectionStudentFuzzyQuery"]').click()
    driver.find_element_by_xpath('//*[@name = "CID"]').send_keys(i[0])
    driver.find_element_by_xpath('//*[@name = "TeachNo"]').send_keys(i[1])
    driver.find_element_by_xpath('//button[@id="QueryAction"]').click()
    driver.find_element_by_xpath('//*[@name = "checkclass"]').click()
    driver.find_element_by_xpath('//button[@id = "CourseCheckAction"]').click()
    driver.find_element_by_xpath('//span[text() = "关闭"]').click()
    sleep(0.5)
input()

driver.quit()