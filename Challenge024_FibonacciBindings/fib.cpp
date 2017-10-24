#include <stdlib.h>
#include "fib.h"

int fib_recursion(int n) {
	if(n <= 1) return n;
	return fib_recursion(n-1) + fib_recursion(n-2);
}

int fib_for(int n) {
	int* l = (int*) malloc(sizeof(int) * n);

	l[0] = 0;
	l[1] = 1;

	for(int i = 2; i < n; ++i) {
		l[i] = l[i-1] + l[i-2];
	}

	int result = l[n - 1] + l[n-2];
	free(l);
	return result;
}