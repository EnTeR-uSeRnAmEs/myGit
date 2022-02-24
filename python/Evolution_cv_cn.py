import cv2
import numpy as np
from os import listdir
import os
import random

POPULATION = 30 #基因个数
MIN_LOSS = 1000 #允许最大损失

def Create_Generation(width, height, path):
    for k in range(POPULATION):
        img = np.ones((width, height), dtype = np.uint8)
        img = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
        for i in range(width):
            for j in range(height):
                
                img[i, j, 0] = random.randint(0,255)
                img[i, j, 1] = random.randint(0,255)
                img[i, j, 2] = random.randint(0,255)

        cv2.imwrite(path + "\\Environment\\" + str(k + 1) + ".jpg", img)

def Calculate_Loss_Function(width, height, img, god):
    loss = 0
    for i in range(width):
        for j in range(height):
            for k in range(3):
                loss = loss + abs(int(img[i, j, k]) - int(god[i, j, k]))
    return loss

def Calculate_Loss_Function_of_Each_Picture(width, height, god, img_list):
    Loss = []
    for k in range(POPULATION):
        img = img_list[k]
        Loss.append(Calculate_Loss_Function(width, height, img, god))
    return Loss

def Read_Picture():
    img_list = []
    for k in range(POPULATION):
        img = cv2.imread(path + "\\Environment\\" + str(k + 1) + ".jpg")
        img_list.append(img)
    return img_list

Gene_Mutation_Number = 50 #基因突变像素数为 该系数
Gene_Exchange_Factor = 0.05 #基因交换次数期望为 总像素数*该系数

def Gene_Mutation(width, height, img, rate, Loss):
    for k in range(int(rate)):
        i = random.randint(0, width - 1)
        j = random.randint(0, height - 1)
        tmp0 = tmp1 = tmp2 = -1
        x = int(Loss / (width * height))
        while (tmp0 < 0 or tmp0 > 255):
            tmp0 = img[i, j, 0] + random.randint(-x,x)
        while (tmp1 < 0 or tmp1 > 255):
            tmp1 = img[i, j, 1] + random.randint(-x,x)
        while (tmp2 < 0 or tmp2 > 255):
            tmp2 = img[i, j, 2] + random.randint(-x,x)
        img[i, j, 0] = tmp0
        img[i, j, 1] = tmp1
        img[i, j, 2] = tmp2
    return img

def Exchange_Gene(width, height, img1, img2, god):
    flag = 0
    imgl = np.ones((width, height), dtype = np.uint8)
    imgl = cv2.cvtColor(imgl, cv2.COLOR_GRAY2BGR)
    imgr = np.ones((width, height), dtype = np.uint8)
    imgr = cv2.cvtColor(imgr, cv2.COLOR_GRAY2BGR)
    for i in range(width):
        for j in range(height):
            is_change_flag = random.random()
            if is_change_flag <= Gene_Exchange_Factor:
                flag = abs(flag - 1)
            if flag == 1:
                imgl[i,j,0] = img2[i,j,0]
                imgl[i,j,1] = img2[i,j,1]
                imgl[i,j,2] = img2[i,j,2]

                imgr[i,j,0] = img1[i,j,0]
                imgr[i,j,1] = img1[i,j,1]
                imgr[i,j,2] = img1[i,j,2]
            else:
                imgr[i,j,0] = img2[i,j,0]
                imgr[i,j,1] = img2[i,j,1]
                imgr[i,j,2] = img2[i,j,2]

                imgl[i,j,0] = img1[i,j,0]
                imgl[i,j,1] = img1[i,j,1]
                imgl[i,j,2] = img1[i,j,2]
    if Calculate_Loss_Function(width, height, imgl, god) < Calculate_Loss_Function(width, height, imgr, god):
        return imgl
    return imgr

def Find_Location(Probability, P):
    T = 0
    for i in range(POPULATION):
        T += Probability[i]
        if P <= T:
            return i

def Write_Picture(img, path):
    for k in range(POPULATION):
        cv2.imwrite(path + "\\Environment\\" + str(k + 1) + ".jpg", img[k])

def Evolution(width, height, god, path):
    Generation = 1
    img_list = Read_Picture()
    TIME = 0
    rate = min(Gene_Mutation_Number, 0.05 * width * height)
    while(1):
        print("第", Generation, "代:\n")
        Generation += 1
        TIME += 1
        Loss = Calculate_Loss_Function_of_Each_Picture(width, height, god, img_list)
            
        Son_list = []
        Probability = []
        TOT_Probability = 0
        for i in range(POPULATION):
            if Loss[i] <= MIN_LOSS:
                print(i)
                return img_list[i]
            Probability.append(width * height * 3 * 255 - Loss[i])
            #TOT_Probability += Probability[i]
        
        MIN_Probability = min(Probability)
        MAX_Probability = max(Probability)

        for i in range(POPULATION):
            Probability[i] = (Probability[i] - MIN_Probability)/(MAX_Probability - MIN_Probability)
            TOT_Probability += Probability[i]

        for i in range(POPULATION):
            Probability[i] = Probability[i] / TOT_Probability
            #print(Probability[i], ", ", Loss[i], ",", TOT_Probability)
        print(Probability[0], ", ", Loss[0], ",", TOT_Probability)
        min_location = Loss.index(min(Loss))
        Son_list.append(img_list[min_location]) #保留最相似的一张图片
        print(min_location)
        a = Calculate_Loss_Function(width, height, Son_list[0], god)
        print(a)
        
        if min_location != 0:
            TIME = 0

        if TIME == 25:
            rate /= 2
            TIME = 0 

        print("rate = ", rate)

        for k in range(POPULATION - 1):
            #随机抽取两张图片进行像素交换
            img_location_probability1 = random.random()
            img_location1 = Find_Location(Probability, img_location_probability1)
            img_location_probability2 = random.random()
            img_location2 = Find_Location(Probability, img_location_probability2)
            while img_location1 == img_location2:
                img_location_probability2 = random.random()
                img_location2 = Find_Location(Probability, img_location_probability2)

            
            img_1 = img_list[img_location1]
            img_2 = img_list[img_location2]
            img_re = Exchange_Gene(width, height, img_1, img_2, god)
            img_re = Gene_Mutation(width, height, img_re, rate, Loss[0])
            Son_list.append(img_re)
            
            #print(Calculate_Loss_Function(width, height, Son_list[0], god))
        
        img_list = Son_list
        Write_Picture(img_list, path)


path = os.path.abspath(os.path.dirname(__file__))
God_Name = path + "\\god.jpg"
#print(God_Name)
god = cv2.imread(God_Name)
width = god.shape[0]
height = god.shape[1]




Create_Generation(width, height, path)



'''
img_number = Evolution(width, height, god, path)
img = cv2.imread(path + "\\Environment\\" + str(img_number + 1) + ".jpg")
'''
img = Evolution(width, height, god, path)
cv2.imwrite(path + "\\result.jpg", img)
print("结束")
#print(width, height)
#cv2.imwrite(path + "\\xxx.jpg", god)



