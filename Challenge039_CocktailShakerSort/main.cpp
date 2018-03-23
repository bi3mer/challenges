#include <stdlib.h>
#include <stdio.h>
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

void cocktailShakerSort(int *arr, int size)
{
	int startIndex = 0;
	int endIndex   = size - 1;

	while(startIndex <= endIndex)
	{
		bool swapped = false;

		for(int i = startIndex; i < endIndex; ++i)
		{
			if(arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i+1]);
				swapped = true;
			}
		}

		startIndex += 1;


		for(int i = endIndex; i >= startIndex; --i)
		{
			if(arr[i] < arr[i - 1])
			{
				std::swap(arr[i], arr[i-1]);
				swapped = true;
			}
		}

		endIndex -= 1;

		if(swapped)
		{
			break;
		}
	}
}


int main(int argc, char* argv[]) {
	int a[] = {0,-1,3,10,100,3};
	int b[] = {-1};
	int c[] = {0,0,0,1235,-1};
	int d[] = {};

	int len_a = 6;
	int len_b = 1;
	int len_c = 5;
	int len_d = 0;

	cocktailShakerSort(a, len_a);
	cocktailShakerSort(b, len_b);
	cocktailShakerSort(c, len_c);
	cocktailShakerSort(d, len_d);

	printArray(a, len_a);
	printArray(b, len_b);
	printArray(c, len_c);
	printArray(d, len_d);
	
	return 0;
}
