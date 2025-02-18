import numpy as np
import cv2 as cv        # 导入opencv包
import numpy as np      # 导入numpy包，图像处理中的矩阵运算需要用到
from pprint import pprint

# 检测图像的SIFT关键特征点


def sift_keypoints_detect(image):
    # 处理图像一般很少用到彩色信息，通常直接将图像转换为灰度图
    gray_image = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

    # 获取图像特征sift-SIFT特征点,实例化对象sift
    sift = cv.xfeatures2d.SIFT_create()

    # keypoints:特征点向量,向量内的每一个元素是一个KeyPoint对象，包含了特征点的各种属性信息(角度、关键特征点坐标等)
    # features:表示输出的sift特征向量，通常是128维的
    keypoints, features = sift.detectAndCompute(image, None)

    # cv.drawKeyPoints():在图像的关键特征点部位绘制一个小圆圈
    # 如果传递标志flags=cv.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS,它将绘制一个大小为keypoint的圆圈并显示它的方向
    # 这种方法同时显示图像的坐标，大小和方向，是最能显示特征的一种绘制方式
    keypoints_image = cv.drawKeypoints(
        gray_image, keypoints, None, flags=cv.DRAW_MATCHES_FLAGS_NOT_DRAW_SINGLE_POINTS)

    # 返回带关键特征点的图像、关键特征点和sift的特征向量
    return keypoints_image, keypoints, features


# 使用KNN检测来自左右图像的SIFT特征，随后进行匹配
def get_feature_point_ensemble(features_right, features_left):
    # 创建BFMatcher对象解决匹配
    bf = cv.BFMatcher()
    # knnMatch()函数：返回每个特征点的最佳匹配k个匹配点
    # features_right为模板图，features_left为匹配图
    matches = bf.knnMatch(features_right, features_left, k=2)
    # 利用sorted()函数对matches对象进行升序(默认)操作
    matches = sorted(matches, key=lambda x: x[0].distance / x[1].distance)
    # x:x[]字母可以随意修改，排序方式按照中括号[]里面的维度进行排序，[0]按照第一维排序，[2]按照第三维排序
    # pprint([(i[0].distance, i[1].distance) for i in matches])

    # 建立列表good用于存储匹配的点集
    good = []
    for m, n in matches:
        # ratio的值越大，匹配的线条越密集，但错误匹配点也会增多
        ratio = 0.6
        if m.distance < ratio * n.distance:
            good.append(m)

    # 返回匹配的关键特征点集
    return good


# 计算视角变换矩阵H，用H对右图进行变换并返回全景拼接图像
def Panorama_stitching(image_right, image_left, display=0):
    _, keypoints_right, features_right = sift_keypoints_detect(image_right)
    _, keypoints_left, features_left = sift_keypoints_detect(image_left)
    goodMatch = get_feature_point_ensemble(features_right, features_left)

    # 当筛选项的匹配对大于4对(因为homography单应性矩阵的计算需要至少四个点)时,计算视角变换矩阵
    if len(goodMatch) > 4:
        # 获取匹配对的点坐标
        ptsR = np.float32(
            [keypoints_right[m.queryIdx].pt for m in goodMatch]).reshape(-1, 1, 2)
        ptsL = np.float32(
            [keypoints_left[m.trainIdx].pt for m in goodMatch]).reshape(-1, 1, 2)

        # ransacReprojThreshold：将点对视为内点的最大允许重投影错误阈值(仅用于RANSAC和RHO方法时),若srcPoints和dstPoints是以像素为单位的，该参数通常设置在1到10的范围内
        ransacReprojThreshold = 4

        # cv.findHomography():计算多个二维点对之间的最优单映射变换矩阵 H(3行x3列),使用最小均方误差或者RANSAC方法
        # 函数作用:利用基于RANSAC的鲁棒算法选择最优的四组配对点，再计算转换矩阵H(3*3)并返回,以便于反向投影错误率达到最小
        Homography, status = cv.findHomography(
            ptsR, ptsL, cv.RANSAC, ransacReprojThreshold)

        # cv.warpPerspective()：透视变换函数，用于解决cv2.warpAffine()不能处理视场和图像不平行的问题
        # 作用：就是对图像进行透视变换，可保持直线不变形，但是平行线可能不再平行
        Panorama = cv.warpPerspective(
            image_right, Homography, (image_right.shape[1] + image_left.shape[1], image_right.shape[0]))
        if display:
            cv.imwrite("changed_right.jpg", Panorama)
            cv.imshow("扭曲变换后的右图", Panorama)
            cv.waitKey(0)
            cv.destroyAllWindows()
        # 将左图加入到变换后的右图像的左端即获得最终图像
        Panorama[0:image_left.shape[0], 0:image_left.shape[1]] = image_left
        Panorama = ClearBackGround(Panorama)
        # 返回全景拼接的图像
        return Panorama


# 清除黑色背景
def ClearBackGround(img):
    threshold = 40  # 阈值
    gray = cv.cvtColor(img, cv.COLOR_RGB2GRAY)  # 转换为灰度图像

    nrow = gray.shape[0]  # 获取图片尺寸
    ncol = gray.shape[1]

    rowc = gray[:, int(1/2*nrow)]  # 无法区分黑色区域超过一半的情况
    colc = gray[int(1/2*ncol), :]

    rowflag = np.argwhere(rowc > threshold)
    colflag = np.argwhere(colc > threshold)

    left, bottom, right, top = rowflag[0,
                                       0], colflag[-1, 0], rowflag[-1, 0], colflag[0, 0]
    return img[left:right, top:bottom]


def image_stiching(image_left, image_right, display=0):
    # 读取需要拼接的图像,需要注意图像左右的顺序
    # image_left = cv.imread("./Left.jpg")
    # image_right = cv.imread("./Right.jpg")

    # 通过调用cv2.resize()使用插值的方式来改变图像的尺寸，保证左右两张图像大小一致
    # cv.resize()函数中的第二个形参dsize表示输出图像大小尺寸，当设置为0(None)时，则表示按fx与fy与原始图像大小相乘得到输出图像尺寸大小
    # padding = image_left.shape[1] - image_right.shape[1]
    # if padding > 0:
    #     image_right = cv.copyMakeBorder(image_right, 0, 0, 0, padding,
    #                                     cv.BORDER_CONSTANT, value=[0, 0, 0])
    # else:
    #     image_left = cv.copyMakeBorder(image_left, 0, 0, 0, -padding,
    #                                    cv.BORDER_CONSTANT, value=[0, 0, 0])
    if display:
        f = 1
    else:
        f = 1
    image_right = cv.resize(image_right, None, fx=f, fy=f)
    image_left = cv.resize(
        image_left, (image_right.shape[1], image_right.shape[0]))

    # 获取检测到关键特征点后的图像的相关参数
    keypoints_image_right, keypoints_right, features_right = sift_keypoints_detect(
        image_right)
    keypoints_image_left, keypoints_left, features_left = sift_keypoints_detect(
        image_left)

    # 利用np.hstack()函数同时将原图和绘有关键特征点的图像沿着竖直方向(水平顺序)堆叠起来
    if display:
        cv.imwrite("left_keypoint.jpg", np.hstack(
            (image_left, keypoints_image_left)))
        cv.imshow("左图关键特征点检测", np.hstack((image_left, keypoints_image_left)))
    # 一般在imshow后设置 waitKey(0) , 代表按任意键继续
        cv.waitKey(0)
    # 删除先前建立的窗口
        cv.destroyAllWindows()
    if display:
        cv.imwrite("right_keypoint.jpg", np.hstack(
            (image_right, keypoints_image_right)))
        cv.imshow("右图关键特征点检测", np.hstack((image_right, keypoints_image_right)))
        cv.waitKey(0)
        cv.destroyAllWindows()
    goodMatch = get_feature_point_ensemble(features_left, features_right)

    # cv.drawMatches():在提取两幅图像特征之后，画出匹配点对连线
    # matchColor – 匹配的颜色（特征点和连线),若matchColor==Scalar::all(-1),颜色随机
    all_goodmatch_image = cv.drawMatches(
        image_left, keypoints_left, image_right, keypoints_right, goodMatch, None, None, None, None, flags=2)
    if display:
        cv.imwrite("goodkeypoint_match.jpg", all_goodmatch_image)
        cv.imshow("所有匹配的SIFT关键特征点连线", all_goodmatch_image)
        cv.waitKey(0)
        cv.destroyAllWindows()

    # 把图片拼接成全景图并保存
    Panorama = Panorama_stitching(image_right, image_left)
    if display:
        cv.namedWindow("全景图", cv.WINDOW_AUTOSIZE)
        cv.imshow("全景图", Panorama)
    cv.imwrite("0.jpg", Panorama)
    cv.waitKey(0)
    cv.destroyAllWindows()


if __name__ == "__main__":
    # for i in range(1, 13):
    #     try:
    #         image_left = cv.imread("(0).jpg")
    #     except:
    #         image_left = cv.imread("(1).jpg")
    #     image_right = cv.imread("(" + str(i) + ").jpg")
    #     image_stiching(image_left, image_right)
    # cv.namedWindow("全景图", cv.WINDOW_AUTOSIZE)
    image_left = cv.imread("1.jpg")
    image_right = cv.imread("2.jpg")
    image_stiching(image_left, image_right, display=0)
    # image = cv.imread("(1).jpg")
    # image = cv.copyMakeBorder(image, 0, 0, 0, 50,
    #                           cv.BORDER_CONSTANT, value=[0, 0, 0])
    # cv.imshow("name", image)
    # cv.imwrite("(0).jpg", image)
    # cv.waitKey(0)
    # cv.destroyAllWindows()
