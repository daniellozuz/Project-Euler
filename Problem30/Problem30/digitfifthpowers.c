#include <stdio.h>

int power(int base, int exponent);

int main(void) {
	int sum = 0;

	for (int i = 2; i <= 354294; i++) {
		if (i < 10) {
			if (power(i, 5) == i) {
				printf("%d\n", i);
				sum += i;
			}
		}
		else if (i < 100) {
			if (power(i % 10, 5) + power((i / 10) % 10, 5) == i) {
				printf("%d\n", i);
				sum += i;
			}
		}
		else if (i < 1000) {
			if (power(i % 10, 5) + power((i / 10) % 10, 5) + power((i / 100) % 10, 5) == i) {
				printf("%d\n", i);
				sum += i;
			}
		}
		else if (i < 10000) {
			if (power(i % 10, 5) + power((i / 10) % 10, 5) + power((i / 100) % 10, 5) + power((i / 1000) % 10, 5) == i) {
				printf("%d\n", i);
				sum += i;
			}
		}
		else if (i < 100000) {
			if (power(i % 10, 5) + power((i / 10) % 10, 5) + power((i / 100) % 10, 5) + power((i / 1000) % 10, 5) + power((i / 10000) % 10, 5) == i) {
				printf("%d\n", i);
				sum += i;
			}
		}
		else {
			if (power(i % 10, 5) + power((i / 10) % 10, 5) + power((i / 100) % 10, 5) + power((i / 1000) % 10, 5) + power((i / 10000) % 10, 5) + power((i / 100000) % 10, 5) == i) {
				printf("%d\n", i);
				sum += i;
			}
		}		
	}

	printf("Sum of the above numbers is: %d\n\n", sum);

	return 0;
}

int power(int base, int exponent) {
	int result = 1;
	
	for (int i = 0; i < exponent; i++)
		result *= base;

	return result;
}