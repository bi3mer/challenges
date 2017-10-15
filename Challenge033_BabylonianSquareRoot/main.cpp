#include <stdlib.h>
#include <stdio.h>

const int iterations = 20;

float babylonian_square_root(float num) {
	// value in the direction of the square root
	float xN = num / 2.0; // x of N

	for(int i = 0 ; i < iterations; ++i) {
		xN = 0.5 * (xN + (num / xN));
	}

	return xN;
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Invalid arguments given. Must provide one float to calculate the square root\n");
		return -1;
	}

	float num = atof(argv[1]);
	printf("The square root of %f is approximately %f\n", num, babylonian_square_root(num));

	return 0;
}
