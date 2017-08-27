#include <stdio.h>
#include <stdbool.h>

#define LIMIT 28123
#define SIZE 6965

bool isAbundant(int number);
bool sumof2(int number, int abundant[]);

int main(void) {
	int amount = 0;
	int abundant[SIZE] = { 0 };

	for (int i = 1; i <= LIMIT; i++) {
		if (isAbundant(i)) {
			abundant[amount] = i;
			printf("%d is an abundant number (%d)\n", i, ++amount);
		}
	}

	int sum = 0;
	for (int i = 1; i <= LIMIT; i++) {
		if (!sumof2(i, abundant))
			printf("%d may not be written as a sum of 2 abundant numbers. Sum = %d\n", i, sum += i);
	}

	return 0;
}

bool isAbundant(int number) {
	int sum = 0;
	
	for (int div = 1; div < number; div++) {
		if (number % div == 0)
			sum += div;
	}

	return (sum > number);
}

bool sumof2(int number, int abundant[]) {
	for (int i = 0; abundant[i] <= number && i < SIZE; i++) {
		for (int j = i; abundant[j] <= number && j < SIZE; j++) {
			if (abundant[i] + abundant[j] == number)
				return true;
		}
	}

	return false;
}