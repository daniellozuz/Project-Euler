#include <stdio.h>
#include <stdbool.h>

#define PRIME_LIMIT 100000

bool isprime(int number);
bool divisible(long zeros, int n);
bool divisibleby2or5only(int number);

int main(void) {
	int amount = 0;
	int primes[9673] = { 0 };

	for (int i = 2; i <= PRIME_LIMIT + 1000; i++) {
		if (isprime(i))
			primes[amount++] = i;
	}

	printf("%d primes found.\n", amount);

	amount = 0;
	int sum = 0;
	for (int i = 3; primes[i] < PRIME_LIMIT; i++) {
		if (!divisible(1000000000, primes[i])) {
			amount++;
			sum += primes[i];
			printf("%d works. Primes found so far: %d. Sum: %d\n", primes[i], amount, sum);
		}
	}

	printf("Add 2+3+5 as I ommited those primes in calculations.\n");

	return 0;
}

bool divisible(long zeros, int n) {
	long i = 0;
	int temp = 0;
	int r;
	int prev = -1;
	int recurence = -1;

	while (i < zeros) {
		temp += 1;
		if (temp >= n) {
			r = temp / n;
			temp = temp - r * n;
			temp = temp * 10;
		}
		else {
			r = 0;
			temp = temp * 10;
		}
		i++;

		if (temp == 0) {
			if (prev == -1)
				prev = i;
			else
				recurence = i - prev;
		}
		
		if (recurence != -1) {
			// Because i%recurence always == 0, 10^n must be divisible by recurence. Thus if recurence is of the form rec = 2^x * 5^y - it will divide some number 10^n.
			return divisibleby2or5only(recurence);
		}
	}

	if (temp == 0)
		return true;

	return false;
}

bool isprime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}

bool divisibleby2or5only(int number) {
	while (number > 1) {
		if (number % 2 == 0)
			number /= 2;
		else if (number % 5 == 0)
			number /= 5;
		else
			return false;
	}

	return true;
}