#!usr/bin/python
#-*- coding: GBK -*-
from selenium import webdriver
from time import sleep

account = input('������ѧ�ţ�')
password = input('���������룺')
classes = []

while True:
    tmp = input('�����루�γ̺� ��ʦ�ţ���س�����0��Ϊ������ϣ�').split()
    if tmp == ['0']:
        break
    else:
        classes.append(tmp)

driver = webdriver.Chrome()
sleep(1)
driver.get('http://xk.autoisp.shu.edu.cn/')
sleep(1)
input("������س��Կ�ʼѡ��...")
driver.find_element_by_xpath('//*[@id = "username"]').send_keys(account)
driver.find_element_by_xpath('//*[@id = "password"]').send_keys(password)
driver.find_element_by_xpath('//button[text() = "��¼"]').click()
for i in classes:
    driver.find_element_by_xpath('//span[text() = "ѡ��"]').click()
    driver.find_element_by_xpath('//button[@type = "submit"]').click()
    driver.find_element_by_xpath('//*[@id = "CourseSelectionStudentFuzzyQuery"]').click()
    driver.find_element_by_xpath('//*[@name = "CID"]').send_keys(i[0])
    driver.find_element_by_xpath('//*[@name = "TeachNo"]').send_keys(i[1])
    driver.find_element_by_xpath('//button[@id="QueryAction"]').click()
    driver.find_element_by_xpath('//*[@name = "checkclass"]').click()
    driver.find_element_by_xpath('//button[@id = "CourseCheckAction"]').click()
    driver.find_element_by_xpath('//span[text() = "�ر�"]').click()
    sleep(0.5)
input()

driver.quit()