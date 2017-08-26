// N = x ^ n; x may not be greater than 9 (too many digits), and n may not be greater than 21 (too few digits - even for x = 9)
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool distinct_number(double number, double numbers[][21]);
bool n_digit(double number, int n);

int main(void) {
	double numbers[9][21] = { 0 };
	double number;
	int solutions = 0;

	for (int x = 1; x <= 9; x++) {
		for (int n = 1; n <= 21; n++) {
			number = pow(x, n);
			if (distinct_number(number, numbers) && n_digit(number, n)) {
				numbers[x - 1][n - 1] = pow(x, n);
				printf("%d ^ %d = %g\n", x, n, numbers[x - 1][n - 1]);
				solutions++;
			}
		}
	}

	printf("There are %d n-digit positive integers which are also an n-th power.\n", solutions);

	return 0;
}

bool distinct_number(double number, double numbers[][21]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 21; j++) {
			if (number == numbers[i][j])
				return false;
		}
	}

	return true;
}

bool n_digit(double number, int n) {
	if (pow(10, n - 1) <= number && number < pow(10, n))
		return true;
	else
		return false;
}