/*
#include <stdlib.h>
#include <stdio.h>
#include "binarySearch.cpp"

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
*/
