#!/usr/bin/python
# @author: Colan Biemer

from q_learning import *
from storage import *
import argparse
import gym

# simulation paramaters
episodes		  = 1000
simulation_steps  = 1000
solved_limit      = 499

def create_environment():
	env = gym.make('CartPole-v1')
	input_dimension = env.observation_space.shape[0]
	num_actions = env.action_space.n

	return env, input_dimension, num_actions

def load_and_view(file_name):
	env, input_dimension, num_actions = create_environment()
	qnn = load_model(input_dimension, num_actions, file_name=file_name)
	view(qnn)

def view(qnn):
	env, input_dimension, num_actions = create_environment()

	done = False
	state = reshape_state(env.reset(), input_dimension)
	time_steps = 0
	while not done:
		env.render()
		action = get_action(qnn, state, input_dimension, num_actions)
		next_state, reward, done, info = env.step(action)
		state = reshape_state(next_state, input_dimension)
		time_steps += 1

	print("ran for " + str(time_steps) + " time steps")

def train(save_file, should_render):
	env, input_dimension, num_actions = create_environment()
	qnn = build_qnn(input_dimension, num_actions)
	solved = False

	for i_episode in range(episodes):
		state = reshape_state(env.reset(), input_dimension)

		for t in range(simulation_steps):
			if should_render:
				env.render()

			# get action and run on environemnt
			action = get_learning_action(qnn, state, input_dimension, num_actions)
			next_state, reward, done, info = env.step(action)

			# use results to reinforce agent
			next_state = reshape_state(next_state, input_dimension)
			reward = reward if not done else -10 # negatively reinforce on fail

			remember(qnn, state, next_state, action, reward, done)

			# set shape up for next iteration
			state = next_state

			if done:
				print("Episode {} finished after {} timesteps with e={}".format(i_episode, t+1, qnn.epsilon))
				
				if t >= solved_limit:
					solved = True
				break

		if solved:
			break

		update_epsilon(qnn)
		learn(qnn)


	view(qnn)
	if save_file:
		store_model(qnn, file_name=save_file)

if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='Q Learning for OpenAI Gym - CartPole-v1')
	parser.add_argument('--save', help='save final model as pickle')
	parser.add_argument('--load', help='load model and view result')
	parser.add_argument('--render', help='render results while training', action="store_true")
	parser.add_argument('--viewactionspace', help='view action space for game', action='store_true')
	args = parser.parse_args()

	if args.viewactionspace:
		 env, input_dimension, num_actions = create_environment()
		 print(env)
		 print(input_dimension)
		 print(num_actions)
	elif args.load:
		load_and_view(args.load)
	else:
		train(args.save, args.render)

