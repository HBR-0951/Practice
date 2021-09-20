import cv2

def detect(image):
    casc_path = cv2.data.haarcascades + "haarcascade_frontalface_default.xml"  # 偵測特徵路徑


    faceCascade = cv2.CascadeClassifier(casc_path)  # 偵測物件變數
    #image = cv2.imread("img/person1.jpeg", 0)
    _, threshold = cv2.threshold(image, 100, 255, cv2.THRESH_BINARY_INV)
    # 偵測結果變數
    faces = faceCascade.detectMultiScale(image,
                                        scaleFactor=1.1, minNeighbors=5, minSize=(30, 30), flags=cv2.CASCADE_SCALE_IMAGE)

    imageheight = faces.shape[0]
    imagewidth = faces.shape[1]

    cv2.rectangle(image, (10, imageheight-20), (110, imageheight), (0, 0, 0), -1)
    cv2.putText(image, "Find " + str(len(faces)) + " face!", (10,
                imageheight-5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)

    for (x, y, w, h) in faces:
        cv2.rectangle(image, (x, y), (x+w, y+h), (128, 255, 0), 2)
    cv2.namedWindow("facedetect")
    cv2.imshow("facedetect", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
if __name__ == "__main__":
    image = cv2.imread("img/person1.jpeg", 0)
    detect(image)
