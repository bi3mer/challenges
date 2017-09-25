#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>

#include "matrix.cpp"
#include "breadth_first_search.cpp"

void fill_row(int* row, std::string *line, Dimensions *dim) {
	if(line->length() != dim->width) {
		printf("Error converting line of length %zu for dimension width %i\n", line->length(), dim->width);
	} else {
		for(int i = 0; i < dim->width; ++i) {
			row[i] = line->at(i) - '0'; // convert character to int
		}
	}
}

int main() {
	// build matrix
	std::string file_name = "maps/test_small_map.map";
	int **matrix;

	Dimensions *dim = (Dimensions*)malloc(sizeof(Dimensions));

	std::ifstream matrix_file(file_name.c_str());

	if(matrix_file.is_open()) {
		std::string line;
		bool first_line = true;
		int row_index = 0;

		while(getline(matrix_file, line)) {
			if(first_line) {
				first_line = false;
				build_dimensions(dim, &line);

				// initialize matrix with correct dimmensions
				matrix = (int**) malloc(dim->height * sizeof(matrix));

				for(int y = 0; y < dim->height; ++y) {
					matrix[y] = (int*) malloc(dim->width * sizeof(matrix[y]));
				}
			} else {
				fill_row(matrix[row_index], &line, dim);
				++row_index;
			}
		}
	} else {
		printf("Map file unable to be found\n");
		matrix_file.close();
		return -1;
	}

	matrix_file.close();

	// just print the matrix for now
	printf("Matrix:\n");
	print_matrix_regular(matrix, dim);
	
	// Free variables
	for(int y = 0; y < dim->height; ++y) {
		free(matrix[y]);
	}

	free(matrix);
	free(dim);

	return 0;
}