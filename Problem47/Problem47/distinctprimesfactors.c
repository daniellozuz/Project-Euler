#include <stdio.h>
#include <stdbool.h>

#define SIZE 6
#define DISTINCT 4
#define LIMIT 100000000

bool distinct(int number);
bool included(int number, int tab[]);
bool isPrime(int number);

int main(void) {
	int first = 0;
	int second = 0;
	int third = 0;
	int fourth = 0;
	int amount = 0;

	for (int i = 2; i <= LIMIT; i++) {
		if (distinct(i)) {
			//printf("%d has %d distinct prime factors.\n", i, DISTINCT);
			first = second;
			second = third;
			third = fourth;
			fourth = i;
			amount++;
			if (first + 1 == second && second + 1 == third && third + i == fourth)
				printf("I found the solution %d\n", i);
		}
		if (i % 1000000 == 0)
			printf("%d%%   (so far %d solutions)\n", i / 1000000, amount);
	}

	return 0;
}

bool distinct(int number) {
	int factors[SIZE] = { 0 };
	int amount = 0;

	for (int i = 2; i <= number; i++) {
		if (i*i > number && isPrime(number)) {
			amount++;
			break;
		}
		if (number % i == 0) {
			number /= i;
			if (!included(i, factors))
				factors[amount++] = i;
			i--;
		}
		if (amount > 4)
			break;
	}

	return (amount == DISTINCT);
}

bool included(int number, int tab[]) {
	for (int i = 0; i < SIZE; i++) {
		if (number == tab[i])
			return true;
	}

	return false;
}

bool isPrime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}