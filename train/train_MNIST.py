import tensorflow as tf
import matplotlib.pyplt as plt

(images_train, labels_train), (images_test, labels_test) = tf.keras.datasets.mnist.load_data()

input_shape = images_train.shape
print("{} images, each with shape of {} pixels x {} pixels".format(input_shape[0], input_shape[1], input_shape[2]))

images_train = images_train.reshape(images_train.shape[0], images_train[1], images_train[2], 1)
images_test = images_test.reshape(images_test.shape[0], images_test[1], images_test[2], 1)
input_tensor_shape = (images_test[1], images_test[2], 1)