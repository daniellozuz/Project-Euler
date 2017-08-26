// First digit of x must be 9 (solution 918 273 645 is given). x must be at most 4 digits long (I need at least 1 concatenation, concatenating 2 5-digit numbers is not valid).
#include <stdio.h>
#include <stdbool.h>

int firstDig(int number);
void checkConc(int number);
int length(int number);
bool pandigital(int number[]);

int main(void) {
	for (int x = 1; x <= 9999; x++) {
		if (firstDig(x) == 9)
			checkConc(x);
	}

	return 0;
}

int firstDig(int number) {
	int first = 0;

	while (number >= 1) {
		first = number % 10;
		number /= 10;
	}

	return first;
}

void checkConc(int number) {
	int digits = 0;
	int digs[9] = { 0 };
	int len = 0;
	int m = 1;

	while (digits < 9) {
		int p = number * m;
		len = length(p);
		if (digits + len <= 9) {
			for (int i = len-1; i >= 0; i--) {
				digs[digits + i] = p % 10;
				p /= 10;
			}
		}
		digits += len;
		m += 1;
	}

	if (digits == 9 && pandigital(digs)) {
		for (int i = 0; i < 9; i++)
			printf("%d", digs[i]);
		printf("\n");
	}
}

int length(int number) {
	int len = 0;

	while (number >= 1) {
		len++;
		number /= 10;
	}

	return len;
}

bool pandigital(int number[]) {
	int digits[10] = { 0 };

	for (int i = 0; i < 9; i++)
		digits[number[i]]++;

	for (int i = 1; i <= 9; i++) {
		if (digits[i] != 1)
			return false;
	}

	return true;
}