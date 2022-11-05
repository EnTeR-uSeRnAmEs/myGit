# coding=utf-8
import cv2
import numpy as np


def getExtrema(A, B, C, thresh):
    height, width = A.shape
    resu = np.ones((height, width), A.dtype) * 100
    for row in range(1, height-1):
        for col in range(1, width-1):
            center = B[row, col]
            if center < thresh:
                continue
            B[row, col] = B[row, col - 1]
            minValue = np.vstack(
                [A[row-1:row+2, col-1:col+2], B[row-1:row+2, col-1:col+2], C[row-1:row+2, col-1:col+2]]).min()
            maxValue = np.vstack([A[row - 1:row + 2, col - 1:col + 2], B[row - 1:row + 2, col - 1:col + 2],
                                  C[row - 1:row + 2, col - 1:col + 2]]).max()
            if center < minValue:
                resu[row, col] = 0
            if center > maxValue:
                resu[row, col] = 255
            B[row, col] = center
    return resu


def addPoint(image, image_point):
    height, width, dvim = image.shape
    for row in range(0, height):
        for col in range(0, width):
            if image_point[row, col] == 255:
                cv2.circle(image, (row, col), 5,
                           thickness=1, color=[0, 0, 255])
            elif image_point[row, col] == 0:
                cv2.circle(image, (row, col), 5,
                           thickness=1, color=[0, 255, 0])


if __name__ == "__main__":
    image = cv2.imread('1.jpg')
    r, g, b = cv2.split(image)
    image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    image_gray_blur1 = cv2.GaussianBlur(image_gray, (3, 3), 0.3)
    image_gray_blur2 = cv2.GaussianBlur(image_gray, (3, 3), 0.4)
    image_gray_blur3 = cv2.GaussianBlur(image_gray, (3, 3), 0.5)
    image_gray_blur4 = cv2.GaussianBlur(image_gray, (3, 3), 0.6)
    image_gray_blur5 = cv2.GaussianBlur(image_gray, (3, 3), 0.7)
    image_gray_blur6 = cv2.GaussianBlur(image_gray, (3, 3), 0.8)
    image_gray_dog1 = image_gray_blur2 - image_gray_blur1
    image_gray_dog2 = image_gray_blur4 - image_gray_blur3
    image_gray_dog3 = image_gray_blur6 - image_gray_blur5
    image_point = getExtrema(
        image_gray_dog1, image_gray_dog2, image_gray_dog3, 2)
    # 反过来的gbr
    cv2.namedWindow("image_DOG", flags=cv2.WINDOW_NORMAL)
    cv2.moveWindow("image_DOG", 300, 200)
    addPoint(image, image_point)
    cv2.imshow("image", cv2.imread("./lena.jpg"))
    cv2.imshow("image_gray", image_gray)
    cv2.imshow("image_gray_blur1", image_gray_blur1)
    cv2.imshow("image_gray_blur2", image_gray_blur2)
    cv2.imshow("image_gray_blur3", image_gray_blur3)
    cv2.imshow("image_gray_blur4", image_gray_blur4)
    cv2.imshow("image_gray_blur5", image_gray_blur5)
    cv2.imshow("image_gray_blur6", image_gray_blur6)
    cv2.imshow("image_gray_dog1", image_gray_dog1)
    cv2.imshow("image_gray_dog2", image_gray_dog2)
    cv2.imshow("image_gray_dog3", image_gray_dog3)
    cv2.imshow("image_DOG", image)

    cv2.imwrite("image_gray.jpg", image_gray, [
                int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_blur1.jpg", image_gray_blur1,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_blur2.jpg", image_gray_blur2,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_blur3.jpg", image_gray_blur3,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_blur4.jpg", image_gray_blur4,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_blur5.jpg", image_gray_blur5,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_blur6.jpg", image_gray_blur6,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_dog1.jpg", image_gray_dog1,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_dog2.jpg", image_gray_dog2,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_gray_dog3.jpg", image_gray_dog3,
                [int(cv2.IMWRITE_JPEG_QUALITY), 100])
    cv2.imwrite("image_DOG.jpg", image, [int(cv2.IMWRITE_JPEG_QUALITY), 100])

    cv2.waitKey(0)
    cv2.destroyAllWindows()
