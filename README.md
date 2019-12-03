# rl-bagh-chal
Reinforcement learning applied to Bagh Chal board game


# installing
```bash
# first you may want to install more recent python on Ubuntu 16.04 than it has built in:
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt update
sudo apt install python3.7

# in any case, then create a python3 virtual env and install cython in it:
cd rl-bagh-chal
python3 -m venv .venv 
source .venv/bin/activate
pip install cython  # unfortunately must be done manually first before installing rl-bagh-chal
make                # build the rl-bagh-chal C and cython code
pip install .       # now install py_bagh_chal and the rest of its dependencies
python run_unit_tests.py   # run the unit tests to ensure all ready to go
```


with thanks for getting started by:
<https://medium.com/@shamir.stav_83310/making-your-c-library-callable-from-python-by-wrapping-it-with-cython-b09db35012a3>

