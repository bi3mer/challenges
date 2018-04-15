#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include "ArrayVisualizer.cpp"

int partition(int* a, int low, int high)
{
	int lowIndex = low - 1;
	int pivot    = a[high];

	for(int i = low; i < high; ++i)
	{
		if(a[i] <= pivot)
		{
			++lowIndex;
			swap(lowIndex, i);
		}
	}

	++lowIndex;
	swap(lowIndex, high);

	return lowIndex;
}

void quickSort(int* a, int low, int high)
{
	if(low < high)
	{
		int pi = partition(a, low, high);

		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

void visualizeQuickSort(int* a, int length)
{
	quickSort(a, 0, length - 1);
} 

int main(int argc, char* argv[]) 
{
	srand(time(NULL));

	length = 500;
	setUpGlutAndArray(argc, argv, visualizeQuickSort);
	free(arr);

	return 0;
}
