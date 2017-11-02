#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension


fib_module = Extension(
   '_BinarySearch',
   sources=['BinarySearch.cxx', 'BinarySearch.cpp'],
)

setup (
	name        = 'BinarySearch',
	version     = '0.0',
	author      = "Colan Biemer",
	description = "BinarySearch swig",
	ext_modules = [fib_module],
	py_modules  = ["BinarySearch"],
)
