from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

examples_extension = Extension(
    name="rl_bagh_chal.pybaghchal",
    sources=["rl_bagh_chal/pybaghchal.pyx"],
    libraries=["bc"],
    library_dirs=["baghchal_c_code"],
    include_dirs=["baghchal_c_code", "."]
)
setup(
    name="rl_bagh_chal",
    version="0.0.1",
    ext_modules=cythonize([examples_extension], compiler_directives={'language_level' : "3"}),
    #install_requires=[
    #    'numpy',
    #],
)

# from setuptools import setup
# from setuptools import find_packages
# 
# setup(name='gym_tic_tac_toe',
#       version='0.0.2',
#       install_requires=['gym'],
#       url="https://github.com/nczempin/gym-tic-tac-toe",
#       packages=find_packages()
# )  
