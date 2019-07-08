from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

examples_extension = Extension(
    name="pybaghchal",
    sources=["pybaghchal.pyx"],
    libraries=["bc"],
    library_dirs=["baghchal_c_code"],
    include_dirs=["baghchal_c_code"]
)
setup(
    name="pybaghchal",
    ext_modules=cythonize([examples_extension])
)

