## Fibonacci: C++ vs Python

Mainly I just wanted to finally see how hard, or not, it was to create c++ functions with bindings to python. I ended up using a [swig tutorial](http://www.swig.org/Doc1.3/Python.html#Python_nn10) to help me figure out how it worked. Once I got past the initial headache, it turned out to be quite easy. To run you first have to build:

```
./build.sh
```

Once you've built you can run:

```
python fibonacci.py
```

and you will see similar results to below, depending on the specs of your computer. The recursion one may take a bit so it may be wise to lower `fib_num_to_find` in [fibonacci.py](./fibonacci.py) at the top to save you some time. Also, I have only tested this on Ubuntu 16.04 with 2.7 and can't guarantee similar results for other platforms.

```
> python fibonacci.py 
Recursion Method (n = 40):
c++: 0.276295900345
py:  25.3467931747

For Method (n = 500000):
c++: 0.00125002861023
py:  4.48233509064

```