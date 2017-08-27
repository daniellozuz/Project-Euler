// There are only 11 primes

// 5 of which were given at the beginning
// 3797
// 797
// 379
// 97
// 37

// Obvious 2-digit truncatable primes
// 11
// 13
// 31
// 17
// 71

// There is only 1 more truncatable prime
// It has to be an expansion of what we have above (1 digit glued to one of the primes)
// Solution: 1|31

// 131

// Sum: 5381

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number);

int main(void) {
	for (int i = 100; i < 200; i++) {
		if (isPrime(i)) {
			if (isPrime((i/10) % 10))
				printf("%d\n", i);
		}
		printf("%d\n", i);
	}

	return 0;
}

bool isPrime(int number) {
	if (number < 2)
		return false;

	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}