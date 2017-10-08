#!/usr/bin/python
# @author: Colan Biemer

from keras.models import Sequential
from keras.layers import Dense
import numpy as np

EPOCHS = 1000

# set seed so we get the same result every time
np.random.seed(9)

# 0 false, 1 true
X = np.array([[0,0], [0,1], [1,0], [1,1]])
Y = np.array([[0], [1], [1], [0]])

# create and compile model
model = Sequential();
model.add(Dense(3, input_dim=2, activation='tanh'))
model.add(Dense(1, activation='tanh'))

model.compile(optimizer='rmsprop',
              loss='binary_crossentropy',
              metrics=['accuracy'])

# fit data
model.fit(X, Y, epochs=EPOCHS)

#print results
scores = model.evaluate(X, Y)
print
print model.metrics_names[1] + ": " + str(scores[1]*100) + "%"