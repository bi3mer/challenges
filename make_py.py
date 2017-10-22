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

main_py_file = """#!/usr/bin/python
# @author: Colan Biemer

print "Hello, World!"
"""

file = open(directory + "/main.py", 'w')
file.write(main_py_file)
file.close()

os.chmod(directory + "/main.py", 0755)