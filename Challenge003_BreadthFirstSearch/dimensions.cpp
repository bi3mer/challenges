struct Dimensions {
	int width;
	int height;
};

void build_dimensions(Dimensions *dim, std::string *line) {
	// TODO: should be updated to parse the string to get
	//       the width and height so it will work with 
	//       matrices that arent 4x4
	// "4,4"
	std::string part_1 = "";
	std::string part_2 = "";
	bool is_part_1 = true;

	for(int i = 0; i < (*line).length(); ++i) {
		if((*line)[i] == ',') {
			is_part_1 = false;
		} else {
			if(is_part_1 == true) {
				part_1 += (*line)[i];
			} else {
				part_2 += (*line)[i];
			}
		}
	}

	dim->width  = atoi(part_1.c_str());
	dim->height = atoi(part_2.c_str());
}

void print_dimensions(Dimensions *dim) {
	printf("(W, H): %d, %d\n", dim->width, dim->height);
}