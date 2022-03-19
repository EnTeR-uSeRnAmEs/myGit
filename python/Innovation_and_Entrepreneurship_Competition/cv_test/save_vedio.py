#!/usr/bin/python
#-*- coding: GBK -*-

import numpy as np
import cv2

cap = cv2.VideoCapture("c://Users//24798//Desktop//test_360.mp4")

#fourcc��һ�ֱ����ʽ�����Ǳ�����ƵʱҪָ���ļ����������ʽ��FPS������ߴ硢��ɫģʽ
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))   #����ļ�����FourCC��֡�ʡ���С
while(cap.isOpened()):
    ret, frame = cap.read()
    if ret==True:
        #cv2.flip(img,flag)  ��תͼ��1ˮƽ��ת��0��ֱ��ת��-1ˮƽ��ֱ��ת��
        frame = cv2.flip(frame,1)

        # д����Ƶ֡
        out.write(frame)

        # cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break

cap.release()
out.release()
cv2.destroyAllWindows()