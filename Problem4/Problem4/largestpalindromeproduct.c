#include <stdio.h>
#include <stdbool.h>

#define LEN 10

bool isPalindromic(int number);

int main(void) {
	int largest = 0;

	for (int a = 100; a <= 999; a++) {
		for (int b = 100; b <= 999; b++) {
			int number = a*b;
			if (number > largest && isPalindromic(number))
				largest = number;
		}
	}

	printf("The largest palindrome is: %d\n", largest);

	return 0;
}

bool isPalindromic(int number) {
	int digits[LEN] = { 0 };
	int len = 0;
	int n = number;

	while (n >= 1) {
		digits[len] = n % 10;
		n /= 10;
		len++;
	}

	for (int i = 0; i < len / 2; i++) {
		if (digits[i] != digits[len - i - 1])
			return false;
	}

	return true;
}