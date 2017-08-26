#include <stdio.h>
#include <stdbool.h>

#define PRIMES 908
#define MAX 50000000

bool isprime(int number);
bool distinct(int number, int nuu[][200000], int amount);

int main(void) {
	int prime = 0;
	int primes[PRIMES];

	for (int i = 2; i <= 7072; i++) {
		if (isprime(i))
			primes[prime++] = i;
	}

	printf("%d\n", prime);

	int numbers[10] = { 0 };

	int nuu[10][200000];
	
	int number;
	int a, b, c;
	for (int k = 0; (c = primes[k] * primes[k] * primes[k] * primes[k]) < MAX; k++) {
		for (int j = 0; (b = primes[j] * primes[j] * primes[j]) < MAX - c; j++) {
			for (int i = 0; (a = primes[i] * primes[i]) <= MAX - c - b; i++) {
				if ((number = a + b + c) < 50000000 && distinct(number, nuu, numbers[number/5000000]))
					nuu[number/5000000][numbers[number/5000000]++] = number;
			}
		}

		for (int i = 0; i < 10; i++)
			printf("%d ", numbers[i]);

		printf("k = %d\n", k);
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
		result += numbers[i];

	printf("There are %d such numbers.\n", result);
	
	return 0;
}

bool isprime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}

bool distinct(int number, int nuu[][200000], int amount) {
	for (int i = 0; i < amount; i++) {
		if (nuu[number/5000000][i] == number)
			return false;
	}

	return true;
}