int FREE  = 0;
int WALL  = 1;
int START = 2;
int END   = 3;

// (1,0), (-1,0), (0,1), and (0,-1) are possible 
// values for this struct and only enforced by 
// the user, i.e. me.
struct Move {
	int x;
	int y;
};

struct Position {
	int x;
	int y;
};

// @note: nothing is done if a start and an end aren't found
//        and an error will occur
Position** get_start_and_end_position(int **matrix, Dimensions *dim) {
	bool start_found = false;
	bool end_found   = false;

	// returning array of 2 positions
	Position** positions = (Position**) malloc(sizeof(Position*) * 2);
	positions[0] = (Position*) malloc(sizeof(Position));
	positions[1] = (Position*) malloc(sizeof(Position));

	for(int y = 0; y < dim->height; ++y) {
		for(int x = 0; x < dim->width; ++x) {
			if(matrix[y][x] == START) {
				positions[0]->x = x;
				positions[0]->y = y;
				start_found = true;

				if(end_found) {
					x = dim->width;
					y = dim->height;
				}
			} else if(matrix[y][x] == END) {
				positions[1]->x = x;
				positions[1]->y = y;
				end_found = true;

				if(start_found) {
					x = dim->width;
					y = dim->height;
				}
			}
		}
	}

	return positions;
}

// pointer to 2d matrix
Move** breadth_first_search(int **matrix, Dimensions *dim) {
	Position** positions = get_start_and_end_position(matrix, dim);
	Position* start = positions[0];
	Position* end   = positions[1];

	printf("start: %d, %d\n", start->x, start->y);
	printf("end:   %d, %d\n", end->x,   end->y);

	free(start);
	free(end);
	free(positions);

	return NULL;
}