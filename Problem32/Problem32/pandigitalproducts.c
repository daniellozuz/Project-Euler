// Max 4-digit number

#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

bool panId(int n, int m1, int m2);
bool distinct(int n, int ids[]);

int main(void) {
	int sum = 0;
	int amount = 0;
	int ids[SIZE] = { 0 };

	for (int n = 1; n <= 9999; n++) {
		for (int m1 = 1; m1 <= 100; m1++) {
			if (n % m1 == 0) {
				int m2 = n / m1;
				if (panId(n, m1, m2)) {
					if (distinct(n, ids)) {
						printf("Hurray. %d = %d x %d is a distinct pandigital identity.\n", n, m1, m2);
						ids[amount++] = n;
						sum += n;
					}
					else
						printf("                                      %d = %d x %d is a pandigital identity, but it is not distinct.\n", n, m1, m2);		
				}
			}
		}
	}

	printf("Sum: %d (%d distinct identities)\n", sum, amount);

	return 0;
}

bool panId(int n, int m1, int m2) {
	int digits[10] = { 0 };

	while (n >= 1) {
		int digit = n % 10;
		digits[digit]++;
		n /= 10;
	}

	while (m1 >= 1) {
		int digit = m1 % 10;
		digits[digit]++;
		m1 /= 10;
	}

	while (m2 >= 1) {
		int digit = m2 % 10;
		digits[digit]++;
		m2 /= 10;
	}

	for (int i = 1; i <= 9; i++) {
		if (digits[i] != 1)
			return false;
	}

	return true;
}

bool distinct(int n, int ids[]) {
	for (int i = 0; i < SIZE; i++) {
		if (n == ids[i])
			return false;
	}

	return true;
}