#include <stdio.h>

int main() {
	for(int i = 1; i <= 100; ++i) {
		bool mod_three = (i % 3 == 0);
		bool mod_five  = (i % 5 == 0);

		if(mod_three && mod_five) {
			printf("FizzBuzz\n");
		} else if(mod_three) {
			printf("Fizz\n");
		} else if(mod_five) {
			printf("Buzz\n");
		} else {
			printf("%d\n", i);
		}
	}

	return 0;
}