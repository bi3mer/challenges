#!/usr/bin/python
# @author: Colan Biemer

import gym

env = gym.make('CartPole-v0')
env.reset()
for i in range(100):
    env.render()
    env.step(env.action_space.sample()) # take a random action
