#include <stdio.h>
#include <stdbool.h>

#define LIMIT 100000000

int reverse(int number);
bool oddDigits(int number);

int main(void) {
	int amount = 0;


	// For some reason, there are no 5 and 9 digit solutions to the problem. Thus it can be only checked for LIMIT value of 100'000'000
	for (int i = 1; i < LIMIT; i++) {
		if (i % 10 != 0) {
			if (oddDigits(i + reverse(i))) {
				//printf("%d + %d = %d\n", i, reverse(i), i + reverse(i));
				amount++;
			}
		}
	}

	printf("There are %d reversible numbers below %d.\n", amount, LIMIT);

	return 0;
}

int reverse(int number) {
	int dig[10];
	int i = 0;

	while (number >= 1) {
		dig[i++] = number % 10;
		number /= 10;
	}

	int result = 0;
	for (int j = 0; j < i; j++) {
		result *= 10;
		result += dig[j];
	}

	return result;
}

bool oddDigits(int number) {
	int i = 0;

	while (number >= 1) {
		if (number % 2 == 0)
			return false;
		number /= 10;
	}

	return true;
}