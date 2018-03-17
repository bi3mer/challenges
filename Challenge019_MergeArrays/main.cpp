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

// this assumes base array has enough memory allocated and doesn't care about thecking
void mergeArrayIntoBase(int *baseArray, int *array, int *baseLength, int *arrayLength)
{
	for(int i = 0; i < *arrayLength; ++i)
	{
		bool addToArray = true;

		for(int j = 0; j < *baseLength; ++j)
		{
			if(baseArray[i] == array[j])
			{
				addToArray = false;
				break;
			}
		}

		if(addToArray == true)
		{
			baseArray[*baseLength] = array[i];
			++(*baseLength);
		}
	}
}

// we asssume that neither of the arrays are sorted and will not return
// a sorted array either. Duplicates will not be included in the merge
void merge(int* a, int* b, int* aLength, int* bLength, int** out_a, int* out_length)
{
	int max_length  = *aLength + *bLength;
	*out_a           = (int*)malloc(sizeof(int) * max_length);
	*out_length     = 0;

	mergeArrayIntoBase(*out_a, a, out_length, aLength);
	mergeArrayIntoBase(*out_a, b, out_length, bLength);
}

int main(int argc, char* argv[]) 
{
	int a[5] = {1,2,3,4,5};
	int b[5] = {6,7,8,9,10};
	int c[7] = {11,12,1,3,6,9,5};

	int aLength = 5;	
	int bLength = 5;
	int cLength = 2;

	int* ab; int ab_length;
	int* ac; int ac_length;
	int* bc; int bc_length;

	merge(a, b, &aLength, &bLength, &ab, &ab_length);
	printArray(ab, ab_length);
	free(ab);

	merge(a, c, &aLength, &cLength, &ac, &ac_length);
	printArray(ac, ac_length);
	free(ac);

	merge(b, c, &bLength, &cLength, &bc, &bc_length);
	printArray(bc, bc_length);
	free(bc);

	return 0;
}
