#include <stdio.h>

#include "dimensions.cpp"

void print_matrix_regular(int** matrix, Dimensions* dim) {
	for(int y = 0; y < dim->height; ++y) {
		for(int x = 0; x < dim->width; ++x) {
			printf("%d", matrix[y][x]);
		}

		printf("\n");
	}
}