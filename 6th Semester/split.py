import cv2

img = cv2.imread('image.jpg')
w, h, channels = img.shape

half1 = w // 2
half2 = h // 2

upper_left = img[:half1, :half2]
upper_right = img[:half1, half2:]
lower_left = img[half1:, :half2]
lower_right = img[half1:, half2:]

cv2.imshow("Original", img)
cv2.imshow("Upper left", upper_left)
cv2.imshow("Upper right", upper_right)
cv2.imshow("Lower left", lower_left)
cv2.imshow("Lower right", lower_right)

cv2.waitKey(0)
cv2.destroyAllWindows()

cv2.imwrite("Original.jpg", img)
cv2.imwrite("Upper left.jpg", upper_left)
cv2.imwrite("Upper right.jpg", upper_right)
cv2.imwrite("Lower left.jpg", lower_left)
cv2.imwrite("Lower right.jpg", lower_right)

