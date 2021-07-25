from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from imutils import paths
import argparse
import numpy as np
import cv2
import os

def createImageFeatures(image, size=(32, 32)):
    # resize the image
    image = cv2.resize(image, size)
    # flatten the image
    pixel_list = image.flatten()
    return pixel_list

print("Leyendo Imagenes")
ap = argparse.ArgumentParser()
ap.add_argument("-d", "--dataset", required=True, help="path to input dataset")
ap.add_argument("-j", "--jobs", type=int, default=-1, help="# of jobs for k-NN distance (-1 uses all available cores)")
args = vars(ap.parse_args())
image_paths = list(paths.list_images(args["dataset"]))
raw_images = []
labels = []

# loop over the input images
for (i, image_path) in enumerate(image_paths):
    image = cv2.imread(image_path)
    label = image_path.split(os.path.sep)[-1].split(".")[0]
    # extract raw pixel intensity "features
    pixels = createImageFeatures(image)
    raw_images.append(pixels)
    labels.append(label)

raw_images = np.array(raw_images)
labels = np.array(labels)

(train_X, test_X, train_y, test_y) = train_test_split(
    raw_images, labels, test_size=0.25, random_state=0)
    
model = KNeighborsClassifier(n_neighbors=5)
model.fit(train_X, train_y)
acc = model.score(test_X, test_y)
print("Pixel precision: {:.2f}%".format(acc * 100))

test = r'C:\Users\David\Desktop\UNSA\EDA\Repos\EDA-M\EDA-M4\CLassifKnn\kaggle_dogs_vs_cats\test\dog.jpg'
image = cv2.imread(test)
dog = createImageFeatures(image)
dog = np.array([dog])
print(model.predict(dog))