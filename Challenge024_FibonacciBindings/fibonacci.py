import Fibonacci
import time

fib_num_to_find = 40 # 40 is really solid

# compare recursion implementation
def fib_r(n):
	if n <= 1:
		return n
	return fib_r(n-1) + fib_r(n-2)

c_start = time.time()
Fibonacci.fib_recursion(fib_num_to_find)
c_end = time.time()

py_start = time.time()
fib_r(fib_num_to_find)
py_end = time.time()

print "Recursion Method (n = " + str(fib_num_to_find) + "):"
print "c++:", (c_end - c_start)
print "py: ", (py_end - py_start)
print

fib_num_to_find = 500000 # not sure about this one yet

# compare for loop implementation
def fib_for(n):
	l    = [0]*(n+1)
	l[0] = 0
	l[1] = 1

	for i in range(2, n):
		l[i] = l[i-1] + l[i-2]

	return l[n - 1] + l[n-2]

c_start = time.time()
Fibonacci.fib_for(fib_num_to_find)
c_end = time.time()

py_start = time.time()
fib_for(fib_num_to_find)
py_end = time.time()

print "For Method (n = " + str(fib_num_to_find) + "):"
print "c++:", (c_end - c_start)
print "py: ", (py_end - py_start)
print