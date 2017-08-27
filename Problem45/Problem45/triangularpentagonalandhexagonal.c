#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 5000000000

bool isPent(long long number);
bool isTri(long long number);

int main(void) {
	long long n, hex;

	for (n = 143; (hex = n*(2 * n - 1)) <= LIMIT; n++) {
		if (isTri(hex) && isPent(hex))
			printf("%d is triangular, pentagonal and hexagonal.\n", hex);		
	}

	return 0;
}

bool isPent(long long number) {
	long long n = (1 + sqrt(1 + 24 * number)) / 6;

	return ((n*(3 * n - 1)) / 2 == number);
}

bool isTri(long long number) {
	long long n = (-1 + sqrt(1 + 8 * number)) / 2;

	return ((n*(n + 1)) / 2 == number);
}