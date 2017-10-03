int FREE  = 0;
int WALL  = 1;
int START = 2;
int END   = 3;

struct Position {
	int x;
	int y;
};

// (1,0), (-1,0), (0,1), and (0,-1) are possible 
// values for this struct and only enforced by 
// the user, i.e. me.
struct Move {
	int right;
	int up;
};

Move* move_left() {
	Move* move = (Move*) malloc(sizeof(Move));
	move->right = -1;
	move->up = 0;
}

Move* move_right() {
	Move* move = (Move*) malloc(sizeof(Move));
	move->right = 1;
	move->up = 0;
}

Move* move_up() {
	Move* move = (Move*) malloc(sizeof(Move));
	move->right = 0;
	move->up = -1;
}

Move* move_down() {
	Move* move = (Move*) malloc(sizeof(Move));
	move->right = 0;
	move->up = 1;
}

bool valid_move(int** matrix, Dimensions* dim, Position* position, Move *move) {
	int new_y = position->y + move->up;
	int new_x = position->x + move->right;

	// check dimensiosn and that the new spot is free
	if(new_y < 0 || new_y >= dim->height) return false;
	if(new_x < 0 || new_x >= dim->width)  return false;
	if(matrix[new_y][new_x] != FREE) return false;

	return true;
}

// @note: this should actually do validation in making sure 
//        the position received is really the a piece that 
//        can be moved and it should also guarantee that the
//        new position is empty or the goal.
int** copy_move(int** matrix, Dimensions* dim, Position* position, Move *move) {
	int w = dim->width;
	int h = dim->height;

	int** new_matrix = (int**) malloc(h * sizeof(matrix));

	for(int y = 0; y < h; ++y) {
		new_matrix[y] = (int*) malloc(w * sizeof(matrix[y]));
	}

	// set to free and start
	new_matrix[position->y][position->x] = FREE;
	new_matrix[position->y + move->up][position->x + move->right] = START;

	return new_matrix;
}