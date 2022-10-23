import cv2 as cv
import cv2
import numpy as np
import math
import cmath
import matplotlib.pyplot as plt


# def Hough_Transform(image, sign):

#  #直線檢測
#  #使用霍夫直線變換做直線檢測，前提條件：邊緣檢測已經完成

#  #標準霍夫線變換


#直線檢測
#使用霍夫直線變換做直線檢測，前提條件：邊緣檢測已經完成
import cv2 as cv
import numpy as np

#標準霍夫線變換


def line_detection(image):
    print(1)
    gray = cv.cvtColor(image, cv.COLOR_RGB2GRAY)
    edges = cv.Canny(gray, 50, 150, apertureSize=3)  # apertureSize引數預設其實就是3
    cv2.imshow("edges", edges)
    cv2.waitKey(0)
    lines = cv.HoughLines(edges, 1, np.pi/180, 80)
    for line in lines:
        rho, theta = line[0]  # line[0]儲存的是點到直線的極徑和極角，其中極角是弧度表示的。
        a = np.cos(theta)  # theta是弧度
        b = np.sin(theta)
        x0 = a * rho  # 代表x = r * cos（theta）
        y0 = b * rho  # 代表y = r * sin（theta）
        x1 = int(x0 + 1000 * (-b))  # 計算直線起點橫座標
        y1 = int(y0 + 1000 * a)  # 計算起始起點縱座標
        x2 = int(x0 - 1000 * (-b))  # 計算直線終點橫座標
        # 計算直線終點縱座標 注：這裡的數值1000給出了畫出的線段長度範圍大小，數值越小，畫出的線段越短，數值越大，畫出的線段越長
        y2 = int(y0 - 1000 * a)
        cv2.line(image, (x1, y1), (x2, y2), (0, 255,0), 2)  # 點的座標必須是元組，不能是列表。
        cv2.imshow("image-lines", image)
        cv2.waitKey(0)
#統計概率霍夫線變換


# def line_detect_possible_demo(image):
#  gray = cv.cvtColor(image, apertureSize=3)  # apertureSize引數預設其實就是3
#  lines = cv.HoughLinesP(edges, np.pi / 180, 60, minLineLength=60, maxLineGap=5)
#  for line in lines:
#     x1, y1, x2, y2 = line[0]
#  cv.line(image, 2)
#  cv.imshow("line_detect_possible_demo", image)


# src = cv.imread('E:/imageload/louti.jpg')
# print(src.shape)
# cv.namedWindow('input_image', cv.WINDOW_AUTOSIZE)
# cv.imshow('input_image', src)
# line_detection(src)
# # 呼叫上一個函式後，會把傳入的src陣列改變，所以呼叫下一個函式時，要重新讀取圖片
# src = cv.imread('E:/imageload/louti.jpg')
# line_detect_possible_demo(src)

    # rows, cols, _c = image.shape
    
    # angle = [0] * (8*rows*cols)
    # long = [0] * (8*rows*cols)
    # count = 0
    # L = math.hypot((cols-1), (rows-1))
    # #print(L)
    # # print(cols,rows)
    # L = math.ceil(L)
    # an = math.radians(90/4)
    # for x in range(cols):
    #     for y in range(rows):
    #         for i in range(8):
    #             long[count],angle[count] = Angle(x,y,i,an)
    #             count = count +1
        
    # # print(count)
    # plt.figure(figsize=(10, 10), dpi=100)
    # plt.scatter(angle, long, c='red', s=1, label='Point')
    # plt.xticks(range(-90, 90, 10))
    # plt.yticks(range(-L,L,50))
    # plt.legend(loc='best')
    # plt.savefig("img/Hough_Transform.jpeg")
    # # plt.show()
    
    # for i in range(count):
    #     long[i] = math.round(long[i])
    #     angle[i] = math.round(angle[i])
    # check = np.zeros((count, count, 1))
    
    # create = np.zeros((rows, cols, 1), np.uint8)  # 建立一個所選範圍的影像矩陣
    
    

# def Angle(x,y,i,an):
#     # 求極座標
#     cn = complex(x, y)
#     _l, angle = cmath.polar(cn)
#     angle = angle + (an * i)
#     long = x * math.sin(angle) + \
#         y * math.cos(angle)
#     angle = math.degrees(angle)
#     print()
#     print(angle)
#     if(180 >= angle > 90):
#         angle = (-1) * (180 - angle)
#     elif(270 >= angle > 180):
#         angle = angle - 180
#     elif(360 >= angle > 270):
#         angle = (-1)*(360 - angle) 
#     print(angle)
#     return long,angle
if __name__ == '__main__':
    image = cv2.imread('img/building.jpeg')  # 讀取要處理的檔案
    sign = cv2.imread('img/sign.jpeg')  # 讀取簽名的檔案
    # Hough_Transform(image, sign)
    line_detection(image)
