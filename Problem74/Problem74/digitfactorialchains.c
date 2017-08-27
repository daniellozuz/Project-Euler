#include <stdio.h>
#include <stdbool.h>

#define NUMBER 169

int sumFactorials(int number);
int factorial(int number);
bool belongs(int sum, int numbers[]);
void showChain(int amount, int numbers[]);

int main(void) {
	int result = 0;

	for (int i = 1; i < 1000000; i++) {
		int numbers[60] = { 0 };
		int amount = 0;

		int sum = sumFactorials(i);

		while (!belongs(sum, numbers)) {
			numbers[amount++] = sum;
			sum = sumFactorials(sum);
		}

		if (amount >= 59) {
			printf("Number: %6d ", i);
			showChain(amount, numbers);
			result++;
		}
	}

	printf("There are %d results shown.\n", result);

	return 0;
}

int sumFactorials(int number) {
	int sum = 0;

	while (number > 0) {
		sum += factorial(number % 10);
		number /= 10;
	}

	return sum;
}

int factorial(int number) {
	if (number > 1)
		return number * factorial(number - 1);
	else
		return 1;
}

bool belongs(int sum, int numbers[]) {
	for (int i = 0; i < 60; i++) {
		if (numbers[i] == sum)
			return true;
	}

	return false;
}

void showChain(int amount, int numbers[]) {
	printf("Chain length: %2d   ", amount);
	for (int i = 0; i < 60; i++) {
		if (numbers[i] != 0) {
			printf("%7d ", numbers[i]);
			if (i % 10 == 9)
				printf("\n                                  ");
		}
	}
	printf("\n\n");
}