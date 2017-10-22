#include <stdlib.h>
#include <stdio.h>
#include <map>

void print_array(int* arr, int size) {
	for(int i = 0; i < size; ++i) {
		printf("%i", arr[i]);

		if(i < size - 1) {
			printf(", ");
		}
	}

	printf("\n");
}

// @note: this could take advantage of the fact that I know
//        the array will be sorted and incremented by one
//        everytime, but that feels like cheating so I 
//        won't do that. 
void remove_duplicates(int** arr, int *size) {
	std::map<int, bool> map;

	// find non duplicates
	for(int i = 0; i < *size; ++i) {
		map[(*arr)[i]] = true;
	}
	// set up memory for new array
	free(*arr);
	*arr = (int *) malloc(sizeof(int) * map.size());
	*size = map.size();

	// set up array with the non duplicates
	int i = 0;
	for(std::map<int, bool>::const_iterator iterator = map.begin(); iterator != map.end(); ++iterator) {
		(*arr)[i] = iterator->first;
		++i;
	}
}

int main(int argc, char* argv[]) {
	int duplicate_size = 10;
	int* array_with_duplicates = (int*) malloc(sizeof(int) * duplicate_size);

	int ideal_size    = 5;
	int* ideal_array = (int*) malloc(sizeof(int) * ideal_size);

	// set some default values
	for(int i = 0; i < ideal_size; ++i) {
		array_with_duplicates[i] = i;
		array_with_duplicates[i + ideal_size] = i;

		ideal_array[i] = i;
	}

	printf("Removing duplicates from: ");
	print_array(array_with_duplicates, duplicate_size);
	printf("Expecting:                ");
	print_array(ideal_array, ideal_size);

	remove_duplicates(&array_with_duplicates, &duplicate_size);

	printf("Result:                   ");
	print_array(array_with_duplicates, duplicate_size);

	free(ideal_array);
	free(array_with_duplicates);
	return 0;
}
