#!/usr/bin/env python

from distutils.core import setup, Extension


BinarySearch_module = Extension(
   '_BinarySearch',
   sources=['binarySearch_wrap.cxx', 'binarySearch.cpp'],
)

setup (
	name        = 'BinarySearch',
	version     = '0.0',
	author      = "Colan Biemer",
	description = "BinarySearch Swig",
	ext_modules = [BinarySearch_module],
	py_modules  = ["BinarySearch"],
)
