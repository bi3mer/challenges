#include <queue> 
#include "move.cpp"

struct Node {
	int** graph;
	int move;
	Position* position;
	Node* parent;
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

// @note: must free moves
Move** possible_moves(int** matrix, Position* pos, Dimensions *dim) {
	int possible_moves_count = 0;

	Move* left  = move_left();
	Move* right = move_right();
	Move* up    = move_up();
	Move* down  = move_down();

	bool left_valid  = false;
	bool right_valid = false;
	bool up_valid    = false;
	bool down_valid  = false;

	if(valid_move(matrix, dim, pos, left)) {
		left_valid = true;
		++possible_moves_count;
	}

	if(valid_move(matrix, dim, pos, right)) {
		right_valid = true;
		++ possible_moves_count;
	}

	if(valid_move(matrix, dim, pos, up)) {
		up_valid = true;
		++possible_moves_count;
	}

	if(valid_move(matrix, dim, pos, down)) {
		down_valid = true;
		++possible_moves_count;
	}

	Move** moves = (Move**) malloc((sizeof(Move*) * possible_moves_count));

	int i = 0;
	if(left_valid) {
		moves[i] = left;
		++i;
	} else {
		free(left);
	}

	if(right_valid) {
		moves[i] = right;
		++i;
	} else {
		free(right);
	}

	if(down_valid) {
		moves[i] = down;
		++i;
	} else {
		free(down);
	}

	if(up_valid) {
		moves[i] = up;
		++i;
	} else {
		free(up);
	}
	printf("size: %d\n", i);

	return moves;
}

// @note: in the future check to make sure moves is actually 
//        bigger than 0 before doing the division to get the 
//        size
//
// pointer to 2d matrix
Move** breadth_first_search(int **matrix, Dimensions *dim) {
	Position** positions = get_start_and_end_position(matrix, dim);
	Position* start = positions[0];
	Position* end   = positions[1];


	Move** moves = possible_moves(matrix, start, dim);
	int size = sizeof(moves) / sizeof(Move*) + 1; 
	printf("size2: %d\n", size);
	for(int i = 0; i < size; ++i) {
		printf("right: %d, up: %d\n", moves[i]->right, moves[i]->up);
		free(moves[i]);
	}
	free(moves);


	// std::queue<


	free(start);
	free(end);
	free(positions);

	return NULL;
}