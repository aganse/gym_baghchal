LIB_DIR = baghchal_c_code
CY_DIR = rl_bagh_chal
DOC_DIR = docs

default: pybaghchal install test doc

baghchal: $(LIB_DIR)/baghchal
	make -C $(LIB_DIR) shell py

pybaghchal: setup.py $(CY_DIR)/pybaghchal.pyx $(LIB_DIR)/libbc.a
	python3 setup.py build_ext --inplace && rm -f $(CY_DIR)/pybaghchal.c && rm -Rf build

install:
	pip install -e .

$(LIB_DIR)/libbc.a:
	make -C $(LIB_DIR) libbc.a

doc: docs/_build
	make -C $(DOC_DIR) html

test: tests/*
	python -m unittest discover

clean:
	rm -rf rl_bagh_chal/*.so rl_bagh_chal/*.c rl_bagh_chal/*.pyc
	rm -rf rl_bagh_chal/__pycache__ tests/__pycache__ build *.egg-info
	make -C $(LIB_DIR) clean
	make -C $(DOC_DIR) clean
