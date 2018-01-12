from BinarySearch import binary_search
import ctypes

size = 100
int_array_type = ctypes.c_int*size
array = int_array_type()
for i in range(100):
	array[i] = i

binary_search.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
binary_search.restype = ctypes.c_int

binary_search(array, len(a), 20)