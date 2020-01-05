LIB_DIR = baghchal_c_code
BC_DIR = gym_baghchal
DOC_DIR = docs
TEST_DIR = tests

default: pybaghchal install test doc

baghchal: $(LIB_DIR)/baghchal
	make -C $(LIB_DIR) shell py

pybaghchal: setup.py $(BC_DIR)/pybaghchal.pyx $(LIB_DIR)/libbc.a
	python3 setup.py build_ext --inplace && rm -f $(BC_DIR)/pybaghchal.c && rm -Rf build

install:
	pip install --upgrade -e .

$(LIB_DIR)/libbc.a:
	make -C $(LIB_DIR) libbc.a

doc: docs/_build
	make -C $(DOC_DIR) html

test: tests/*
	python -m unittest discover

clean:
	make -C $(BC_DIR) clean
	make -C $(TEST_DIR) clean
	make -C $(LIB_DIR) clean
	make -C $(DOC_DIR) clean
