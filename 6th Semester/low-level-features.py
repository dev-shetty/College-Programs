import cv2
import numpy as np

img = cv2.imread("image.jpg")

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
canny = cv2.Canny(gray, 100, 200)

kernel = np.ones((5, 5), np.float32) / 25
filter = cv2.filter2D(gray, -1, kernel)

cv2.imshow("Original", img)
cv2.imshow("Gray", gray)
cv2.imshow("Canny", canny)
cv2.imshow("Filter", filter)

cv2.waitKey(0)
cv2.destroyAllWindows()