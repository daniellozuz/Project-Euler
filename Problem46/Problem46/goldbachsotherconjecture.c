#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

bool isprime(int number);

int main(void) {
	int primes[MAX] = { 0 };
	bool stop;

	int numberofprimes = 0;

	for (int i = 2; i <= MAX; i++) {
		if (isprime(i))
			primes[numberofprimes++] = i;
	}

	for (int i = 5; i <= MAX; i+=2) {
		for (int j = 2; j*j <= i; j++) {
			if (i % j == 0) {
				// The number is odd and composite
				//printf("%d\n", i);
				stop = false;
				for (int x = 0; x < numberofprimes; x++) {
					for (int n = 1; n * n <= MAX; n++) {
						if (primes[x] + 2 * n * n == i) {
							//printf("Confirmed. %d = %d + 2 * %d ^ 2\n", i, primes[x], n);
							stop = true;
							break;
						}
					}
					if (stop)
						break;
				}
				if (!stop)
					printf("The conjecture does not hold for %d\n", i);

				break;
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