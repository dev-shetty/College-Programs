import cv2
import numpy as np

img = cv2.imread("image.jpg")

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
edges = cv2.Canny(gray, 100, 200)

contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

mask = np.zeros_like(gray)

cv2.drawContours(mask, contours, -1, (255), thickness=cv2.FILLED)
segmented_image = cv2.bitwise_and(img, img, mask=mask)

cv2.imshow("Original Image", img)
cv2.imshow("Segmented Image", segmented_image)

cv2.waitKey(0)
cv2.destroyAllWindows()