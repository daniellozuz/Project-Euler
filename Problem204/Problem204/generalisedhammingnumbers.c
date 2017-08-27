#include <stdio.h>
#include <stdbool.h>

//#define TYPE 5
#define LIMIT 1000000000
#define PRIMES 25

//bool isGenHam(int number);
int generate(long long number, int max);

int main(void) {
	/*
	int amount = 0;

	for (int h = LIMIT; h <= LIMIT; h++) {
		if (isGenHam(h)) {
			//printf("%d is a generalised Hamming number.\n", h);
			amount++;
		}
	}

	printf("There are %d generalised Hamming numbers of type %d below %d\n", amount, TYPE, LIMIT);
	*/

	//int primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

	printf("%d\n", generate(1, PRIMES - 1) + 1);

	return 0;
}
/*
bool isGenHam(int number) {
	int i = 2;
	while (number > 1) {
		if (number % i == 0) {
			number /= i;
			//printf("Divided by %d\n", i);
			if (i > TYPE)
				return false;
		}
		else
			i++;
	}

	return true;
}
*/
int generate(long long number, int max) {
	int primes[PRIMES] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	static int sol = 0;

	for (int i = 0; i <= max; i++) {
		if (number * primes[i] <= LIMIT) {
			sol++;
			generate(number * primes[i], i);
		}
	}

	return sol;
}