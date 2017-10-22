#!/usr/bin/python
# @author: Colan Biemer

'''
NOTE: this script isn't meant for use and does nothing to 
      prevent mistakes by users. For example, this will not
      run on windows.
'''

import sys
import os

directory = sys.argv[1]

if os.path.exists(directory):
	print "Error: " + directory + " already exists"
	exit(-1)

os.makedirs(directory)

main_cpp_file = """#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("Hello, World!\\n");
	return 0;
}
"""

run_file = """#!/bin/bash
g++ main.cpp
./a.out
"""

file = open(directory + "/main.cpp", 'w')
file.write(main_cpp_file)
file.close()

file = open(directory + "/run.sh", 'w')
file.write(run_file)
file.close()

os.chmod(directory + "/run.sh", 0755)
