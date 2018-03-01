#include <stdlib.h>
#include <stdio.h>


void printArray(int a[], int length)
{
	for(int i = 0; i < length; ++i)
	{
		printf("%i", a[i]);

		if(i < length - 1)
		{
			printf(",");
		}
	}

	printf("\n");
}

int* concatenate(int* a, int* b, int* aLength, int* bLength)
{
	int length = *aLength + *bLength;
	int* array = (int*)malloc(sizeof(int) * length);

	for(int i = 0; i < length; ++i)
	{
		if(i < *aLength)
		{
			array[i] = a[i];
		}
		else
		{
			int index = i - *aLength;
			array[i] = b[index];
		}
	}

	return array;
}

int main(int argc, char* argv[]) 
{
	int a[5] = {1,2,3,4,5};
	int b[5] = {6,7,8,9,10};
	int c[2] = {11,12};

	int aLength = 5;	
	int bLength = 5;
	int cLength = 2;

	int* ab = concatenate(a, b, &aLength, &bLength);
	printArray(ab, aLength + bLength);
	free(ab);

	int* ac = concatenate(a, c, &aLength, &cLength);
	printArray(ac, aLength + cLength);
	free(ac);

	int* bc = concatenate(b, c, &bLength, &cLength);
	printArray(bc, bLength + cLength);
	free(bc);

	return 0;
}
