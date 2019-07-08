LIB_DIR = baghchal_c_code

default: pybaghchal

pybaghchal: setup.py pybaghchal.pyx $(LIB_DIR)/libbc.a
	python3 setup.py build_ext --inplace && rm -f pybaghchal.c && rm -Rf build

$(LIB_DIR)/libbc.a:
	make -C $(LIB_DIR) libbc.a

clean:
	rm *.so

