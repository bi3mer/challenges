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

// Could do more special case checking here, but i'd rather not
//
// Also, i'm assuimng the difference between these two will always
// be the same.and they will be next to eachother.
void merge(int* arr, int start1, int start2, int end2)
{
	if(start1 > start2)
	{
		std::swap(start1, start2);
	}

	for(; start1 < end2; ++start1)
	{
		if(arr[start1] > arr[start2])
		{
			std::swap(arr[start1], arr[start2]);
		}

		if(start1 + 1 == start2)
		{
			++start2;
		}
	}
}

void mergeSort(int* arr, int low, int high)
{

}


int main(int argc, char* argv[]) 
{
	srand(time(NULL));

	// int a[] = {0,-1,3,10,100,3};
	// int b[] = {-1};
	// int c[] = {0,0,0,1235,-1};
	// int d[] = {};
	// int e[100];

	// int len_a = 6;
	// int len_b = 1;
	// int len_c = 5;
	// int len_d = 0;
	// int len_e = 100;

	// for(int i = 0; i < len_e; ++i)
	// {
	// 	e[i] = i;
	// }
	// randomizeArray(e, len_e);

	// mergeSort(a, 0, len_a - 1);
	// mergeSort(b, 0, len_b - 1);
	// mergeSort(c, 0, len_c - 1);
	// mergeSort(d, 0, len_d - 1);
	// mergeSort(e, 0, len_e - 1);

	// printArray(a, len_a);
	// printArray(b, len_b);
	// printArray(c, len_c);
	// printArray(d, len_d);
	// printArray(e, len_e);

	return 0;
}
