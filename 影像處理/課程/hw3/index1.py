import cv2
import numpy as np
import math


def Canny_Edge_Detection(image, sign):  # 
    # h = int(input("h(高度):"))
    # w = int(input("w(寬度):"))
    
    rows, cols, _c = image.shape  # (640,640,3)
    degree = np.zeros((rows,cols))
    edge = np.zeros((rows, cols))
    create = np.zeros((rows, cols, 1), np.uint8)  # 建立一個所選範圍的影像矩陣
    create2 = np.zeros((rows, cols, 1), np.uint8)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # print(cols,rows)
    image = cv2.GaussianBlur(image, (5, 5), 0)
    create_final = cv2.Canny(image,30,150)
    cv2.imwrite("img/canny_final.jpeg",create_final)
    for x in range(cols):
        for y in range (rows):
            if (x > 0 and y > 0 and x < (cols - 1) and y < (rows - 1)):
                # 取x方向
                pixel_x = abs((int(image[y+1][x-1]) + (int(image[y+1][x])*2) + int(image[y+1][x+1])) -
                            (int(image[y-1][x-1]) + (int(image[y-1][x])*2) + int(image[y-1][x+1])))
                # 取y方向
                pixel_y = abs((int(image[y-1][x+1]) + (int(image[y][x+1])*2) + int(image[y+1][x+1])) -
                            (int(image[y-1][x-1]) + (int(image[y][x-1])*2) + int(image[y+1][x-1])))
                create[y][x] = pixel_x + pixel_y # M(x,y)

                # 判斷角度取梯度方向
                if(pixel_x==0 and pixel_y==0):
                    degree[y][x] = -1.0
                elif(pixel_x==0):
                    degree[y][x]=0.0

                elif (pixel_y==0):
                    degree[y][x]= 90.0
                else:
                    degree[y][x] = math.degrees(math.atan(pixel_y/pixel_x))
                    if((-22.5 <= degree[y][x] <= 22.5) or (-157.5 <= degree[y][x] <= 157.5)):
                        degree[y][x] = 0.0
                    elif((22.5 <= degree[y][x] <= 67.5) or (-157.5 <= degree[y][x] <= -112.5)):
                        degree[y][x] = -45.0
                    elif((67.5 <= degree[y][x] <= 112.5) or (-112.5 <= degree[y][x] <= -67.5)):
                        degree[y][x] = 90.0
                    elif((112.5 <= degree[y][x] <= 157.5) or (-67.5 <= degree[y][x] <= -22.5)):
                        degree[y][x] = 45.0
                    else:
                        print("wrong")
            else:
                create[y][x] = image[y][x]
                degree[y][x] = -1.0
                
    cv2.imwrite("img/M(x,y).jpg",create)
    for x in range(cols):
        for y in range(rows):
            if (x > 0 and y > 0 and x < (cols - 1) and y < (rows - 1)):
                # 從角度去使用最大抑制
                if(degree[y][x] == 0.0):
                    if ((create[y][x] > create[y-1][x]) or (create[y][x] > create[y-1][x])) == False:
                        
                        create[y,x] = 0
                if(degree[y][x] == 45.0):
                    if ((create[y][x] > create[y-1][x+1]) or (create[y][x] > create[y+1][x-1])) == False:

                        create[y, x] = 0
                if(degree[y][x] == 90.0):
                    if ((create[y][x] > create[y][x+1]) or (create[y][x] > create[y][x-1])) == False:

                        create[y, x] = 0
                if(degree[y][x] == -45.0):
                    if ((create[y][x] > create[y-1][x-1]) or (create[y][x] > create[y+1][x+1])) == False:
                        create[y, x] = 0
                        
    cv2.imwrite("img/Non-Maximum.jpg", create)
    
    # 雙門檻
    for x in range(cols):
        for y in range(rows):
            if(create[y][x] >= 128) :
                edge[y][x] = 1
            elif(create[y][x] >= 64):
                edge[y][x] = 0
            else:
                edge[y][x] =-1
                
    create2 = create
    for x in range(cols):
        for y in range(rows):
            if(edge[y][x]< 1):
                create2[y][x] = 0
    cv2.imwrite("img/threshold.jpeg", create2)
    
    # keep=0
    # check=0
    # while(check==0):
    #     for x in range(cols):
    #         if(keep == 1):
    #             keep = 0
    #             break
    #         for y in range(rows):
    #             if(x>(cols/2)):
    #                 print("half")
    #             if(edge[y][x] == 0):
    #                 count = 0
    #                 for i in range(x-1,x+2):
    #                     for j in range(y-1,y+2):
    #                         if(cols>i>=0) and (rows>j>=0):
    #                             if(edge[j][i] == 1):
    #                                 count=count+1
    #                 if(count >= 2):
    #                     edge[y][x]=1
    #                     keep=1
    #             if(keep==1): 
    #                 break
    #             if(x==(cols-1) and y==(rows-1)):
    #                 check=1
                    

    # while(1):
    #     for x in range(cols):
    #         for y in range(rows):
    #             if(edge[y][x] == 1):
    #                 while(1):
    #                     for i in range(x-1,x+2):
                                            
    for x in range(cols):
        for y in range(rows):
            if(edge[y][x] < 1):
                create[y][x] = 0
    cv2.imwrite("img/Canny.jpeg", create)
    # cv2.imshow("test", create)
    # cv2.waitKey(0)
    
    # 加上簽名
    # sign = cv2.cvtColor(sign, cv2.COLOR_BGR2GRAY)
    # rows, cols, _c = create.shape  # (640,640,3)
    # resize_sign = cv2.resize(sign, dsize=(100, 50))
    # create[(rows-50):(rows), (cols-100):(cols)] = resize_sign
    # cv2.imwrite("img/Canny_fin.jpeg", create)
 
    # create = create.astype(np.uint8)  # 把目標矩陣轉成特定的dtype，不然有機會跑錯
# def test(edge):
#     if(edge[y][x] == 1):
#         for i in range(x-1, x+2):
#             for j in range(y-1, y+2):
#                 if(cols > i >= 0) and (rows > j >= 0):
#                     if(edge[j][i] == 0):
#                         edge[j][i] == 1

if __name__ == '__main__':
    image = cv2.imread('img/self_picture.jpg')  # 讀取要處理的檔案
    sign = cv2.imread('img/sign.jpeg')  # 讀取簽名的檔案
    Canny_Edge_Detection(image,sign)
