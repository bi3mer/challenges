from keras.models import Sequential
from keras.optimizers import Adam
from keras.layers import Dense
from collections import deque
import numpy as np
import random

gamma         = 0.950 # decay rate
epsilon       = 1.000 # exploration rate
epsilon_decay = 0.950 # decerease exploration over time
epsilon_min	  = 0.010 # prevent agent from stopping exploration
learning_rate = 0.001 # learning per round for the agent
batch_size	  = 32

class QNN:
	def __init__(self, ):
		self.model   = None
		self.epsilon = epsilon
		self.memory  = deque()

def build_qnn(input_dimension, num_actions):
	model = Sequential()

	model.add(Dense(24, input_dim=input_dimension, activation='relu'))
	model.add(Dense(24, activation='relu'))
	model.add(Dense(num_actions, activation='linear'))

	model.compile(loss='mse', optimizer=Adam(lr=learning_rate))
	
	qnn = QNN()
	qnn.model = model

	return qnn

def get_action(qnn, state, input_dimension, num_actions):
	state = reshape_state(state, input_dimension)
	action_values = qnn.model.predict(state)
	return np.argmax(action_values[0])

def get_learning_action(qnn, state, input_dimension, num_actions):
	action = 0

	if random.random() <= qnn.epsilon:
		action = random.randrange(0, num_actions)
	else:
		action = get_action(qnn, state, input_dimension, num_actions)

	return action 

def remember(qnn, state, next_state, action, reward, done):
	qnn.memory.append((state, next_state, action, reward, done))

def learn(qnn):
	if len(qnn.memory) > batch_size:
		sample = random.sample(qnn.memory, batch_size)

		for state, next_state, action, reward, done in sample:
			if not done:
				reward = (reward + gamma * np.amax(qnn.model.predict(next_state)[0]))

			target_f = qnn.model.predict(state)
			target_f[0][action] = reward

			qnn.model.fit(state, target_f, epochs=1, verbose=0)

def update_epsilon(qnn):
	if qnn.epsilon > epsilon_min:
		qnn.epsilon *= epsilon_decay

def reshape_state(state, input_dimensions):
	return np.reshape(state, [1, input_dimensions])