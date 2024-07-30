import cv2
import numpy as np

def on_change(value):
    img = cv2.rectangle(image, (0, 0), (550, 500), (0, 0, 0), -1)
    cv2.imshow("Shape", img)
    return

cv2.namedWindow("Shape Properties")
image = np.zeros((550, 550, 3), np.uint8)

initial_width = 200
initial_height = 100
initial_color = (0, 255, 0)
choice = 1

cv2.createTrackbar("Width", "Shape Properties", initial_width, 500, on_change)
cv2.createTrackbar("Height", "Shape Properties", initial_height, 500, on_change)
cv2.createTrackbar("Blue", "Shape Properties", initial_color[0], 255, on_change)
cv2.createTrackbar("Green", "Shape Properties", initial_color[1], 255, on_change)
cv2.createTrackbar("Red", "Shape Properties", initial_color[2], 255, on_change)

while True:
    width = cv2.getTrackbarPos("Width", "Shape Properties")
    height = cv2.getTrackbarPos("Height", "Shape Properties")
    blue = cv2.getTrackbarPos("Blue", "Shape Properties")
    green = cv2.getTrackbarPos("Green", "Shape Properties")
    red = cv2.getTrackbarPos("Red", "Shape Properties")

    shape = (width, height)
    color = (blue, green, red)

    img = cv2.rectangle(image, (0, 0), shape, color, -1)
    cv2.imshow("Shape", img)

    key = cv2.waitKey(1) & 0xFF;
    if key == ord("q"):
        break
cv2.destroyAllWindows()
