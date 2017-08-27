#include <stdio.h>
#include <stdbool.h>

#define PRIMES 78498

bool isprime(int number);

int main(void) {
	int primes = 0;
	int pr[PRIMES] = { 0 };
	int best = 0;

	for (int i = 2; i < 1000000; i++) {
		if (isprime(i))
			pr[primes++] = i;
	}

	for (int i = 0; i < PRIMES - 1; i++) {
		int sum = pr[i];
		int j = i + 1;
		while (sum < 1000000) {
			if (isprime(sum)) {
				if (j - i > best) {
					best = j - i;
					printf("%d is a prime, which is a sum of %d primes.\n", sum, j - i);
				}
			}
			sum += pr[j++];
		}
	}

	printf("The most consecutive primes: %d\n", best);

	return 0;
}

bool isprime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}