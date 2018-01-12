%module BinarySearch
%{
#include "binarySearch.h"
%}
%include "carrays.i"int
%array_class(double, intArray);
int binary_search(int* array, int size, int search_val);