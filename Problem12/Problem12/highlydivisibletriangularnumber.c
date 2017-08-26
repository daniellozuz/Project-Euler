#include <stdio.h>

int divisors(int number);

int main(void) {
	for (int i = 1; i <= 100000; i++) {
		int number = ((i + 1) * i) / 2;
		if (divisors(number) > 500) {
			printf("%d triangular number: %d has %d divisors.\n", i, number, divisors(number));
			break;
		}
	}

	return 0;
}

int divisors(int number) {
	int div = 0;

	for (int i = 1; i*i <= number; i++) {
		if (number % i == 0) {
			div += 2;
			if (i*i == number)
				div--;
		}
	}

	return div;
}