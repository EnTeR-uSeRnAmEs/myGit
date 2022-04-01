import cv2
 
vc = cv2.VideoCapture(r'E://out.mp4')  # 读入视频文件，命名cv
n = 1  # 计数
 
if vc.isOpened():  # 判断是否正常打开
    rval, frame = vc.read()
else:
    rval = False
 
timeF = 1  # 视频帧计数间隔频率
 
i = 0
while rval:  # 循环读取视频帧
    rval, frame = vc.read()
    if (n % timeF == 0):  # 每隔timeF帧进行存储操作
        i += 1
        print(i)
        # cv2.imwrite(r'F://test//360-30//{}.jpg'.format(i), frame)  # 存储为图像
        cv2.imshow("frame", frame)
    n = n + 1
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    else:
        cv2.imwrite(r'C://Users//24798//Desktop//test//{}.jpg'.format(i), frame)
vc.release()
cv2.destroyAllWindows()
# 原文链接：https://blog.csdn.net/qq_36535414/article/details/109143968