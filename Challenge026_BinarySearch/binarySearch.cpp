#include "binarySearch.h"

int binary_search(int* array, int size, int search_val) {
	int min   = 0;
	int max   = size - 1;
	int index = max / 2; 

	while(array[index] != search_val) {
		if(max == min) {
			index = -1;
			break;
		}

		if(search_val > array[index]) min = index;
		else                          max = index;

		index = (min + max) / 2;
	}

	return index;
}	
