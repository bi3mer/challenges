#include <stdio.h>

template<class T>
void reverse_array(T* arr, int size) {
	// nothing to reverse
	if(size <= 1) return;

	// divide by 2 casts it to an integer so 3/2=1
	// and 4/2 gives us 2
	int swaps_required = size / 2;

	for(int swaps = 0; swaps < swaps_required; ++swaps) {
		int swap_index_1 = swaps;
		int swap_index_2 = size - 1 - swaps;

		T temp = arr[swap_index_1];
		arr[swap_index_1] = arr[swap_index_2];
		arr[swap_index_2] = temp;
	}
}

// @note: assumes arrays are the same size so the function name
//        is misleading.
template<class T>
bool arrays_equal(T* arr1, T* arr2, int size) {
	bool are_equal = true;

	for(int i = 0; i < size; ++i) {
		if(arr1[i] != arr2[i]) {
			are_equal = false;
			break;
		}
	}

	return are_equal;
}

int main() {
	int array1[]       = {0,1,2,3,4,5,6,7,8,9};
	int arr1_correct[] = {9,8,7,6,5,4,3,2,1,0};
	int arr1_size      = 10;
	
	char array2[]       = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	char arr2_correct[] = {'g', 'f', 'e', 'd','c','b','a'};
	int arr2_size       = 7;

	double empty[]         = {};
	double empty_correct[] = {};
	int empty_size         = 0;

	reverse_array(array1, arr1_size);
	reverse_array(array2, arr2_size);
	reverse_array(empty, empty_size);

	bool correct_res1 = arrays_equal(array1, arr1_correct, arr1_size);
	bool correct_res2 = arrays_equal(array2, arr2_correct, arr2_size);
	bool correct_res3 = arrays_equal(empty, empty_correct, empty_size);

	printf("Valid reverse for array1: %s\n", correct_res1 ? "true": "false");
	printf("Valid reverse for array2: %s\n", correct_res2 ? "true": "false");
	printf("Valid reverse for empty:  %s\n", correct_res3 ? "true": "false");
}
