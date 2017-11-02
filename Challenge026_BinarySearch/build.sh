#!/bin/bash

swig -c++ -python BinarySearch.i
python setup.py build_ext --inplace
