#include <stdio.h>
#include <stdbool.h>

#define LIMIT 1000000000
#define SIZE 100000
#define LEN 15

bool exists(int numbers[], int amounts[], int number);
bool isPalindromic(int number);

int main(void) {
	int numbers[SIZE] = { 0 };
	int amounts[SIZE] = { 0 };
	int amount = 0;
	int result = 0;

	if (isPalindromic(10))
		printf("Works");

	for (int s = 1; s*s <= LIMIT; s++) {
		for (int c = 0; c*c*c <= LIMIT; c++) {
			int number = s*s + c*c*c;
			if (isPalindromic(number)) {
				if (!exists(numbers, amounts, number)) {
					numbers[amount] = number;
					amounts[amount++]++;
				}
			}			
		}
	}

	printf("There are %d numbers in an array.\n", amount);

	for (int i = 0; i < amount; i++) {
		if (amounts[i] >= 4) {
			printf("%d\n", numbers[i]);
			result += numbers[i];
		}
	}

	printf("Sum of the palindromic numbers above: %d\n", result);

	return 0;
}

bool exists(int numbers[], int amounts[], int number) {
	int i = 0;

	while (numbers[i] != 0) {
		if (number == numbers[i]) {
			amounts[i]++;
			return true;
		}
		i++;
	}

	return false;
}

bool isPalindromic(int number) {
	int length = 0;
	int digits[LEN] = { 0 };
	int n = number;

	while (n >= 1) {
		digits[length] = n % 10;
		n /= 10;
		length++;
	}

	for (int i = 0; i < length/2; i++) {
		if (digits[i] != digits[length - i - 1])
			return false;
	}

	return true;
}