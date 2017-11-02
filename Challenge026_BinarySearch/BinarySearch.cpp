#include <stdlib.h>
#include <stdio.h>
#include "BinarySearch.h"

int binary_search(int* array, int size, int search_val) {
	int min   = 0;
	int max   = size - 1;
	int index = max / 2; 

	while(array[index] != search_val) {
		if(max == min) {
			index = -1;
			break;
		}

		if(search_val > array[index]) {
			min = index;
		} else {
			max = index;
		}
		index = (min + max) / 2;
	}

	return index;
}

int main(int argc, char* argv[]) {
	const int size = 100;

	int* array = (int*) malloc(sizeof(int) * size);
	for(int i = 0; i < size; ++i) {
		array[i] = i;
	}

	int search_for = 20;
	int index = binary_search(array, size, search_for);
	printf("%i found at %i\n", array[index], index);
	free(array);

	return 0;
}
