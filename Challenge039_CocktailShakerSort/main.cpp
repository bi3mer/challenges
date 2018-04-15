#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "ArrayVisualizer.cpp"

void cocktailShakerSort(int *a, int size)
{
	int startIndex = 0;
	int endIndex   = size - 1;
	bool swapped = true;

	while(swapped)
	{
		swapped = false;

		for(int i = startIndex; i < endIndex; ++i)
		{
			if(a[i] > a[i + 1])
			{
				swap(i, i+1);
				swapped = true;
			}
		}

		startIndex += 1;

		for(int i = endIndex; i >= startIndex; --i)
		{
			if(a[i] < a[i - 1])
			{
				swap(i, i-1);
				swapped = true;
			}
		}

		endIndex -= 1;
	}
}

int main(int argc, char* argv[]) 
{
	delay  = 100;
	length = 500;
	setUpGlutAndArray(argc, argv, cocktailShakerSort);
	free(arr);

	return 0;
}
