#include <stdlib.h>
#include <stdio.h>
#include <algorithm> 
#include "ArrayVisualizer.cpp"

void bubbleSort(int* a, int size)
{
	bool swapped;

	for(int i = 0; i < size - 1; ++i)
	{
		swapped = false;	

		for(int j = 0; j < size - i - 1; ++j)
		{
			if(a[j] > a[j+1])
			{
				swapped = true;
				swap(j, j+1);
			}
		}

		if(swapped == false)
		{
			break;
		}
	}
}

int main(int argc, char* argv[]) 
{
	length = 500;
	setUpGlutAndArray(argc, argv, bubbleSort);
	free(arr);

	return 0;
}
