#!/bin/bash

swig -c++ -python fib.i
python setup.py build_ext --inplace
# g++ $(pkg-config --cflags --libs python2)-O2 -fPIC -c fib.cxx
# g++ -O2 -fPIC -c fib_interface_wrap.cxx  $(pkg-config --cflags --libs python2)
# g++ -shared fibonacci.o fib_interface_wrap.o -o _fibonacci.so

# g++ $(pkg-config --cflags --libs python2) -c fib_interface_wrap.cxx
# g++ -c fib_interface_wrap.cxx $(pkg-config --cflags --libs python2)
# g++ -G fib_interface_wrap.o -L/opt/SUNWspro/lib -o _fibonacci.so -lCrun