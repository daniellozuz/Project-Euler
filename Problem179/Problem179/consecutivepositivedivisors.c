#include <stdio.h>

#define LIMIT 10000000

int divisors(int number);

int main(void) {
	int amount = 0;

	// The code may be 2x faster if I calculate divisors(n) and remember divisors(n-1).
	for (int n = 1; n < LIMIT; n++) {
		if (divisors(n) == divisors(n + 1)) {
			printf("Number %d and %d both have %d positive divisors.\n", n, n + 1, divisors(n));
			amount++;
		}
	}

	printf("There are %d such numbers.\n", amount);

	return 0;
}

int divisors(int number) {
	int i = 2;
	int amount = 0;
	int primes[23] = { 0 };

	while (number > 1 && i*i <= number) {
		if (number % i == 0) {
			number /= i;
			primes[amount] = i;
			i--;
			amount++;
		}
		i++;
	}
	if (number > 1)
		primes[amount] = number;

	int pamounts[23] = { 0 };
	for (int i = 0; i < 23;) {
		if (primes[i] != 0) {
			int j = 1;
			while (primes[i] == primes[i + j]) {
				j++;
			}
			pamounts[i] += j;
			i = i + j;
		}
		else
			break;
	}

	int result = 1;
	for (int i = 0; i < 23; i++) {
		result *= (pamounts[i] + 1);
	}

	return result;
}