#!/usr/bin/python
#-*- coding: GBK -*-

import cv2
 
vc = cv2.VideoCapture(r'C://Users//24798//Desktop//test_360.mp4')  # ������Ƶ�ļ�������cv
n = 1  # ����
 
if vc.isOpened():  # �ж��Ƿ�������
    rval, frame = vc.read()
else:
    rval = False
 
timeF = 1  # ��Ƶ֡�������Ƶ��
 
i = 0
while rval:  # ѭ����ȡ��Ƶ֡
    rval, frame = vc.read()
    if (n % timeF == 0):  # ÿ��timeF֡���д洢����
        i += 1
        print(i)
        cv2.imwrite(r'F://test//360-30//{}.jpg'.format(i), frame)  # �洢Ϊͼ��
    n = n + 1
    cv2.waitKey(1)
vc.release()
# ԭ�����ӣ�https://blog.csdn.net/qq_36535414/article/details/109143968