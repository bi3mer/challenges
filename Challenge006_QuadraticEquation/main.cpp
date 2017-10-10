#include <iostream>
#include <stdlib.h>
#include <regex.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

const int MAX_SIZE = 100;

float* quadratic_equation(float a, float b, float c) {
	float* results = (float *) malloc(sizeof(float) * 2);
	float root = sqrt(pow(b, 2.0) - (4 * a * c));

	results[0] = ((-1 * b) + root) / (2.0 * a);
	results[1] = ((-1 * b) - root) / (2.0 * a);

	return results;  
}

bool matches_regex(const char *str, const char* pattern) {
	regex_t regex;

	if(regcomp(&regex, pattern, REG_EXTENDED) != 0) {
		printf("Error converting regex\n");
		exit(-1);
	}

	int status = regexec(&regex, str,  (size_t) 0, NULL, 0);
	regfree(&regex);

	return status == 0 ? true : false;
}

bool is_int(const char *num) {
	const char* regex_pattern = "-?[0-9]+";
	return matches_regex(num, regex_pattern);
}

bool is_decimal(const char* num) {
	const char* regex_pattern = "-?[0-9]+.?[0-9]+";
	return matches_regex(num, regex_pattern);
}

float get_float(std::string prompt) {
	char user_response[MAX_SIZE];
	float result;
	bool valid_response = false;

	while(valid_response == false) {
		printf("%s: ", prompt.c_str());
		fgets(user_response, MAX_SIZE, stdin);
		
		if(is_int(user_response) == true || is_decimal(user_response) == true) {
			result = (float) atof(user_response);
			valid_response = true;
		}
	}

	return result;
}

int main() {
	float a, b, c;

	a = get_float("Enter valid float for a");
	b = get_float("Enter valid float for b");
	c = get_float("Enter valid float for c");

	printf("Solving for the following: (a=%f, b=%f, c=%f)\n", a, b, c);

	float* results = quadratic_equation(a, b, c);
	printf("+: %f\n", results[0]);
	printf("-: %f\n", results[1]);

	free(results);
	return 0;
}
