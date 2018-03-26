#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>

void printArray(int* arr, int size)
{
	for(int i = 0; i < size; ++i)
	{
		printf("%i", arr[i]);

		if(i < size - 1)
		{
			printf(",");
		}
	}

	printf("\n");
}

template<class T>
void randomizeArray(T* arr, int length)
{
	for(int i = length - 1; i > 0; --i)
	{
		std::swap(arr[i], arr[rand() % (i+1)]);
	}
}

int partition(int* arr, int low, int high)
{
	int lowIndex = low - 1;
	int pivot    = arr[high];

	for(int i = low; i < high; ++i)
	{
		if(arr[i] <= pivot)
		{
			++lowIndex;
			std::swap(arr[lowIndex], arr[i]);
		}
	}

	++lowIndex;
	std::swap(arr[lowIndex], arr[high]);
	return lowIndex;
}

void quickSort(int* arr, int low, int high)
{
	if(low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int main(int argc, char* argv[]) 
{
	srand(time(NULL));

	int a[] = {0,-1,3,10,100,3};
	int b[] = {-1};
	int c[] = {0,0,0,1235,-1};
	int d[] = {};
	int e[100];

	int len_a = 6;
	int len_b = 1;
	int len_c = 5;
	int len_d = 0;
	int len_e = 100;

	for(int i = 0; i < len_e; ++i)
	{
		e[i] = i;
	}
	randomizeArray(e, len_e);

	quickSort(a, 0, len_a - 1);
	quickSort(b, 0, len_b - 1);
	quickSort(c, 0, len_c - 1);
	quickSort(d, 0, len_d - 1);
	quickSort(e, 0, len_e - 1);

	printArray(a, len_a);
	printArray(b, len_b);
	printArray(c, len_c);
	printArray(d, len_d);
	printArray(e, len_e);

	return 0;
}
