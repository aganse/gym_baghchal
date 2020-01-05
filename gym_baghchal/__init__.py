from gym.envs.registration import register

register(
    id='baghchal-v1',
    entry_point='gym_baghchal.envs:BaghChalEnv',
)
