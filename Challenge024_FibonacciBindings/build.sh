#!/bin/bash

swig -c++ -python fib.i
python setup.py build_ext --inplace
