struct Dimensions {
	int width;
	int height;
};

void build_dimensions(Dimensions *dim, std::string *line) {
	// TODO: should be updated to parse the string to get
	//       the width and height so it will work with 
	//       matrices that arent 4x4
	dim->width  = 4;
	dim->height = 4;
}

void print_dimensions(Dimensions *dim) {
	printf("(W, H): %d, %d\n", dim->width, dim->height);
}