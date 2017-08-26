#include <stdio.h>
#include <stdbool.h>

bool isprime(int number);

int main(void) {
	int best = 0;

	for (int a = -999; a <= 999; a++) {
		for (int b = -1000; b <= 1000; b++) {
			int n = 0;

			while ((n*n + a*n + b >= 2) && isprime(n*n + a*n + b))
				n++;
			
			if (n > best) {
				best = n;
				printf("a: %5d b: %5d n: %5d Product: %d\n", a, b, n, a*b);
			}
		}
	}

	return 0;
}

bool isprime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}