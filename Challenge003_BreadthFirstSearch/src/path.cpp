struct Path {
	Move** moves;
	int size;
};

void free_path(Path* path) {
	for(int i = 0; i < path->size; ++i) {
		free(path->moves[i]);
	}

	free(path->moves);
	free(path);
}