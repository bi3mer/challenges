#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension


fib_module = Extension(
   '_Fibonacci',
   sources=['fib_wrap.cxx', 'fib.cpp'],
)

setup (
	name        = 'Fibonacci',
	version     = '0.0',
	author      = "SWIG Docs",
	description = "Fibonacci swig",
	ext_modules = [fib_module],
	py_modules  = ["Fibonacci"],
)