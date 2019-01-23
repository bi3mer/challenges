from rl.memory import SequentialMemory
from rl.policy import BoltzmannQPolicy
from rl.agents import DQNAgent

from keras.models import Sequential
from keras.layers import Dense, Activation, Flatten
from keras.optimizers import Adam

import argparse
import gym
import sys
import os

def build_model(env, ignore_previous_model):
	model = Sequential()
	model.add(Flatten(input_shape=(1,) + env.observation_space.shape))
	model.add(Dense(128))
	model.add(Activation('relu'))
	model.add(Dense(64))
	model.add(Activation('relu'))
	model.add(Dense(32))
	model.add(Activation('relu'))
	model.add(Dense(env.action_space.n))
	model.add(Activation('linear'))

	print(model.summary())

	if not ignore_previous_model:
		if os.path.isfile('model.mdl'):
			model.load_weights('model.mdl')
		else:
			print('No previous model found. Starting from scratch.')

	return model

def build_arg_parser():
	parser = argparse.ArgumentParser(description="Mountain Car Trainer")

	parser.add_argument('--reset-weights', action='store_true', help='reset weights on current model')
	parser.add_argument('--train', action='store_true', help='train with existing model')
	parser.add_argument('--visualize', action='store_true', help='visualize model')

	return parser.parse_args()

if __name__ == '__main__':
	args = build_arg_parser()
	env = gym.make('MountainCar-v0')
	model = build_model(env, args.reset_weights)

	dqn = DQNAgent(
		model=model, 
		nb_actions=env.action_space.n, 
		memory=SequentialMemory(limit=50000, window_length=1), 
		nb_steps_warmup=10,
		target_model_update=1e-2, 
		policy=BoltzmannQPolicy())
	dqn.compile(Adam(lr=1e-3), metrics=['mae'])

	if args.train:
		dqn.fit(env, nb_steps=150000, visualize=False, verbose=2)
		dqn.save_weights('model.mdl', overwrite=True)

	if args.visualize:
		dqn.test(env, nb_episodes=5, visualize=True)