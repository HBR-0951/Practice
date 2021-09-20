import cv2
from DetectFace_by_Image import detect

cv2.namedWindow("Detect")
cap = cv2.VideoCapture(0)
while(cap.isOpened()):
    ret, image = cap.read()
    if ret == True:
        cv2.imshow("Detect", image)
        k = cv2.waitKey(100)
        if k == ord("z") or k == ord("Z"):
            cv2.imwrite("img/capture.jpg",image)
            
            break

cap.release()
cv2.destroyAllWindows()
