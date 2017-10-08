#include <list> 
#include "move.cpp"
#include "path.cpp"

struct Node {
	int** graph;
	Move* move;
	Position* position;
	Node* parent;
};

struct QueueNode {
	Move *move;
	Node *node;
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
Move **possible_moves(int** matrix, Position* pos, Dimensions *dim) {
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

	return moves;
}

// @note: hasn't made the move
void bfs_populate_queue(int **matrix, Dimensions *dim, Move *move, std::list<QueueNode*> *queue, Node *parent) {
	Node *node     = (Node*) malloc(sizeof(Node));
	node->graph    = matrix;
	node->move     = move;
	node->position = parent->position;
	node->parent   = parent;

	Move **moves = possible_moves(matrix, parent->position, dim);
	int size = (sizeof(moves) / sizeof(Move*)) + 1;

	for(int i = 0; i < size; ++i) {
		QueueNode *q_node = (QueueNode*) malloc(sizeof(QueueNode));
		q_node->move = moves[i];
		q_node->node = node;
		queue->push_back(q_node);
	}
}

// @note: I left this with memory leaks, I may come back to this challenge
//        and implement it without said leaks. But for now, I just want to
//        be done.
Path* breadth_first_search(int **matrix, Dimensions *dim) {
	Position** positions = get_start_and_end_position(matrix, dim);
	Position* start      = positions[0];
	Position* end        = positions[1];
	std::list<QueueNode*> queue;

	Node start_node;
	start_node.position = start;
	start_node.graph   = NULL;
	
	// @todo: needs to be freed
	Move** moves = possible_moves(matrix, start, dim);
	int size = (sizeof(moves) / sizeof(Move*)) + 1; 

	bfs_populate_queue(matrix, dim, moves[0], &queue, &start_node);
	// discovered

	// while queue is not empty
	// 		get from queue
	// 		run move onto board
	// 		if board not seen before:
	// 			if board is solved:
	// 				reconstruct path
	// 				append move
	// 				free stuff
	// 				return path
	//			
	// 			add to discovered
	// 			populate queue

	Path* path = (Path*) malloc(sizeof(Path));
	path->moves = moves;
	path->size  = size;

	free(positions[0]);
	free(positions[1]);
	free(positions);

	// return null
	return path;
}