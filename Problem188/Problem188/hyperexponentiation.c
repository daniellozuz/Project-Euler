#include <stdio.h>
#include <stdbool.h>

#define SIZE 100000000
#define REP 1250000

bool included(int number, int ends[]);

int main(void) {

	long long start = 1777;

	long long number = 1777*1777;
	for (int i = 1; i < SIZE; i++) {
		number *= 1777;
		number %= 100000000;
		if (start == number) {
			printf("Sequence repetition: %lld at index: %d \n", number, i);
			break;
		}
	}
	// Test
	start = 1777;
	number = start;
	for (int i = 0; i < 1250000; i++) {
		number *= 1777;
		number %= 100000000;
	}

	printf("After %d multiplications the result is: %lld\n", 1250000, number);

	long long exponent = 1777;
	for (int step = 0; step < 1855-2; step++) {
		// Raise 1777 to some power (mod 1250000)
		long long newexponent = 1;
		for (int i = 0; i < exponent; i++) {
			newexponent *= 1777;
			newexponent %= REP;
		}
		printf("Exponent: %lld\n", newexponent);

		exponent = newexponent;
	}

	long long solution = 1777;
	for (int step = 1; step < exponent; step++) {
		// Raise 1777 to some power (mod 1250000)
		solution *= 1777;
		solution %= SIZE;
	}

	printf("Solution: %lld\n", solution);
	
	return 0;
}