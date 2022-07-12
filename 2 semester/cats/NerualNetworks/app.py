from pickletools import optimize
import numpy as np
import tensorflow as tf
import tensorflow_datasets as tfds
import matplotlib.pyplot as plt
from keras_preprocessing.image import load_img, img_to_array
from keras.layers import Dense, GlobalAveragePooling2D, Dropout
from PIL import Image

SIZE = 224

train,_ = tfds.load('cats_vs_dogs', split=['train[:100%]'], with_info=True, as_supervised=True)

for img, _ in train[0].take(1):
    plt.figure()
    plt.imshow(img)


def resize_image(img, label):
    img = tf.cast(img, tf.float32)
    img = tf.image.resize(img, (SIZE, SIZE))
    img = img / 255.0
    return img, label


train_resized = train[0].map(resize_image)
train_batches = train_resized.shuffle(1000).batch(16)

base_layers = tf.keras.applications.MobileNetV2(input_shape = (SIZE, SIZE, 3), include_top = False)
base_layers.trainable = False

ai = tf.keras.Sequential([
    base_layers, GlobalAveragePooling2D(), Dropout(0.25), Dense(1)
])
ai.compile(optimizer = 'adam', loss = tf.keras.losses.BinaryCrossentropy(from_logits = True), metrics = ['accuracy'])

#ai.fit(train_batches, epochs = 1)

img = Image.open('/Users/fanfurick/Downloads/dog.jpg')
img.show()

img_array = img_to_array(img)
img_resized, _ = resize_image(img_array, _)
img_expended = np.expand_dims(img_resized, axis = 0)
predict =  ai.predict(img_expended)

if predict < 0.5:
    print("Cats")
else:
    print("Dog")