from setuptools import setup
from setuptools import find_packages
from distutils.extension import Extension
from Cython.Build import cythonize

examples_extension = Extension(
    name="gym_baghchal.pybaghchal",
    sources=["gym_baghchal/pybaghchal.pyx"],
    libraries=["bc"],
    library_dirs=["baghchal_c_code"],
    include_dirs=["baghchal_c_code", "."]
)
setup(
    name="gym_baghchal",
    version="0.0.1",
    ext_modules=cythonize([examples_extension], compiler_directives={'language_level' : "3"}),
    install_requires=[
        'numpy',
        'gym',
    ],
    url="https://github.com/aganse/gym_baghchal",
    packages=find_packages()
)
