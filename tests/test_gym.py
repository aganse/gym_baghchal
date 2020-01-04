#from gym import envs
#print(envs.registry.all())

import gym_tic_tac_toe

import gym
#env = gym.make('FrozenLake8x8-v0')
env = gym.make('tic_tac_toe-v1')
env.reset()
for _ in range(1000):
    env.render()
    env.step(env.action_space.sample()) # take a random action
env.close()
