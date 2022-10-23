import cv2
import numpy as np
import matplotlib.pyplot as plt
import math

def CDF(pmf): # 傳回所選機率的累加函數
    cdf = []
    for i in range (256):
        sum = 0
        for j in range (0,i+1):
            sum = sum + pmf[j]
        cdf.append(sum)
    return cdf
def Histogram(image,copy):

    rows, cols= image.shape  
    size = (rows * cols) # 總 pixel 值
    count = np.zeros(256) # 存放每個像素值出現的次數
    pmf = [] # 存放每個像素值出現的機率
    
    create = np.zeros((rows, cols, 1), np.uint8) # 新的畫布
    for i in range (size):
        index = copy[i] # 每個像素值設為索引
        count[index] = count[index]+1 # 利用索引存放出現的次數
    for i in range (256):
        pmf.append((count[i]/size)) # 存放出現次數的機率
    cdf = CDF(pmf)  # 傳回所選機率的累加函數
    for x in range(cols):
        for y in range(rows):
            index = image[y,x] # 以向素值為索引
            create[y, x] = round(cdf[index]*255) # 計算轉換函數並返回值給新的畫布

    return create
if __name__ == '__main__':

    image = cv2.imread('img/heros.jpeg')  # 讀取要處理的檔案
    
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    image_B, image_G, image_R = cv2.split(image)
    # Gray
    # init
    cv2.imwrite("img/heros_gray.jpeg", gray) # 一開始的圖
    plt.hist(gray.ravel(), 256, [0, 256]) # 一開始的直方圖
    plt.savefig("img/heros_gray_init.png")
    plt.close()
    plt.hist(gray.ravel(), bins="auto", density=True, cumulative=True) # 一開始的累加直方圖
    plt.savefig("img/heros_gray_init_cumulative.png")
    plt.close()

    #process
    copy = gray.ravel()
    create_gray = Histogram(gray, copy)
    
    cv2.imwrite("img/heros_create_gray.jpeg", create_gray)  # 處理後的圖
    plt.hist(create_gray.ravel(), 256, [0, 256])  # 處理後的直方圖
    plt.savefig("img/heros_create_gray_process.png")
    plt.close()   
    plt.hist(create_gray.ravel(), bins="auto",
             density=True, cumulative=True)  # 處理後的直方圖
    plt.savefig("img/heros_gray_process_cumulative.png")
    plt.close()
 
    # R
    # init
    cv2.imwrite("img/heros_image_R.jpeg", image_R)
    plt.hist(image_R.ravel(), 256, [0, 256])
    plt.savefig("img/heros_image_R_init.png")
    plt.close()
    plt.hist(image_R.ravel(), bins="auto", density=True, cumulative=True)
    plt.savefig("img/heros_image_R_init_cumulative.png")
    plt.close()
    # process
    copy = image_R.ravel()
    create_R = Histogram(image_R, copy)
    cv2.imwrite("img/heros_create_R.jpeg", create_R)
    plt.hist(create_R.ravel(), 256, [0, 256])
    plt.savefig("img/heros_create_R_process.png")
    plt.close()
    plt.hist(create_R.ravel(), bins="auto", density=True, cumulative=True)
    plt.savefig("img/heros_create_R_process_cumulative.png")
    plt.close()

    # G
    #init
    cv2.imwrite("img/heros_image_G.jpeg", image_G)
    plt.hist(image_G.ravel(), 256, [0, 256])
    plt.savefig("img/heros_image_G_init.png")
    plt.close()
    plt.hist(image_G.ravel(), bins="auto", density=True, cumulative=True)
    plt.savefig("img/heros_image_G_init_cumulative.png")
    plt.close()
    # process
    copy = image_G.ravel()
    create_G = Histogram(image_G, copy)
    cv2.imwrite("img/heros_create_G.jpeg", create_G)
    plt.hist(create_G.ravel(), 256, [0, 256])
    plt.savefig("img/heros_create_G_process.png")
    plt.close()
    plt.hist(create_G.ravel(), bins="auto", density=True, cumulative=True)
    plt.savefig("img/heros_create_G_process_cumulative.png")
    plt.close()
   
    # B
    # init
    cv2.imwrite("img/heros_image_B.jpeg", image_B)
    plt.hist(image_B.ravel(), 256, [0, 256])
    plt.savefig("img/heros_image_B_init.png")
    plt.close()
    plt.hist(image_B.ravel(), bins="auto", density=True, cumulative=True)
    plt.savefig("img/heros_image_B_init_cumulative.png")
    plt.close()
    # process
    copy = image_B.ravel()
    create_B = Histogram(image_B, copy)
    cv2.imwrite("img/heros_create_B.jpeg", create_B)
    plt.hist(create_B.ravel(), 256, [0, 256])
    plt.savefig("img/heros_create_B_process.png")
    plt.close()
    plt.hist(create_B.ravel(), bins="auto", density=True, cumulative=True)
    plt.savefig("img/heros_create_B_process_cumulative.png")
    plt.close()

    # RGB
    create_RGB = cv2.merge([create_B, create_G, create_R]) # 合併三個通道的圖
    cv2.imwrite("img/heros_create_RGB.jpeg", create_RGB)
