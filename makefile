LIB_DIR = baghchal_c_code

default: pybaghchal

baghchal: $(LIB_DIR)/baghchal
	make -C $(LIB_DIR) shell py
	#make -C $(LIB_DIR) -I $(LIB_DIR)shell py

pybaghchal: setup.py pybaghchal.pyx $(LIB_DIR)/libbc.a
	python3 setup.py build_ext --inplace && rm -f pybaghchal.c && rm -Rf build

$(LIB_DIR)/libbc.a:
	make -C $(LIB_DIR) libbc.a
	#make -C $(LIB_DIR) -I $(LIB_DIR) libbc.a

clean:
	rm -f *.so
	make -C $(LIB_DIR) clean

