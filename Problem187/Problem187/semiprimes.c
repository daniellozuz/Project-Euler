#include <stdio.h>
#include <stdbool.h>

#define LIMIT 100000000
#define N 2262

bool isprime(int number);
bool isprime2(int number, int primes[]);

int main(void) {
	int primes[N];
	int prime = 0;

	for (int i = 2; i < 20000; i++) {
		if (isprime(i)){
			primes[prime++] = i;
			printf("%d\n", i);
		}
	}

	printf("There are %d primes below %d\n", prime, 20000);

	int result = 0;
	for (int n = 1; n < LIMIT; n++) {
		for (int j = 0; primes[j]*primes[j] <= n; j++) {
			if (n % primes[j] == 0 && isprime2(n / primes[j], primes))
				result++;
		}
		if (n % 100000 == 0)
			printf("%d results below %d\n", result, n);
	}

	printf("There are %d such composite integers.\n", result);

	return 0;
}

bool isprime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}

bool isprime2(int number, int primes[]) {
	for (int i = 0; primes[i] * primes[i] <= number; i++) {
		if (number % primes[i] == 0)
			return false;
	}

	return true;
}