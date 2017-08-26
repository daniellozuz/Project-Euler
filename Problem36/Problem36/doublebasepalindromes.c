#include <stdio.h>
#include <stdbool.h>

#define LEN 20
#define LIMIT 1000000

bool isPalindromic(int number, int base);

int main(void) {
	int sum = 0;

	for (int i = 1; i < LIMIT; i++) {
		if (isPalindromic(i, 2) && isPalindromic(i, 10)) {
			printf("%d\n", i);
			sum += i;
		}
	}

	printf("Sum of the numbers: %d\n", sum);

	return 0;
}

bool isPalindromic(int number, int base) {
	int digits[LEN] = { 0 };
	int n = number;
	int len = 0;

	while (n >= 1) {
		digits[len++] = n % base;
		n /= base;
	}

	for (int i = 0; i <= len/2; i++) {
		if (digits[i] != digits[len - i - 1])
			return false;
	}

	return true;
}