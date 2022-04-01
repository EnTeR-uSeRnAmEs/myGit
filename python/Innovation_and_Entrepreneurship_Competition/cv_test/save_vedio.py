import numpy as np
import cv2

cap = cv2.VideoCapture("c://Users//24798//Desktop//test_360.mp4")

#fourcc是一种编码格式，我们保存视频时要指定文件名、编码格式、FPS、输出尺寸、颜色模式
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))   #输出文件名、FourCC、帧率、大小
while(cap.isOpened()):
    ret, frame = cap.read()
    if ret==True:
        #cv2.flip(img,flag)  翻转图像（1水平翻转、0垂直翻转、-1水平垂直翻转）
        frame = cv2.flip(frame,1)

        # 写入视频帧
        out.write(frame)

        # cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break

cap.release()
out.release()
cv2.destroyAllWindows()