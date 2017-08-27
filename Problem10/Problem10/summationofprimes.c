#include <stdio.h>
#include <stdbool.h>

#define LIMIT 2000000

bool is_prime(long long number);

int main(void) {
	long long sum = 0;

	for (long long num = 1; num < LIMIT; num++) {
		if (is_prime(num))
			sum += num;
	}
	
	printf("The sum of all the primes below %d is %lld.\n", LIMIT, sum);

	return 0;
}

bool is_prime(long long number) {
	if (number < 2)
		return false;

	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}