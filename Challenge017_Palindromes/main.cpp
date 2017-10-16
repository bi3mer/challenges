#include <string.h>
#include <stdio.h>

bool is_palindrome(char* str) {
	// cast down because on odd length cases the middle most
	// character can be anything
	int size                = strlen(str);
	int required_iterations = size / 2;
	bool palindrome = true;

	for(int i = 0; i < required_iterations; ++i) {
		int start = i;
		int end   = size - 1 - i;

		if(str[start] != str[end]) {
			palindrome = false;
			break;
		}
	}

	return palindrome;
}

int main(int argc, char* argv[]) {
	for(int i = 1; i < argc; ++i) {
		const char* result = is_palindrome(argv[i]) ? "true" : "false";
		printf("\"%s\" is a palindrome: %s\n", argv[i], result);
	}

	return 0;
}
