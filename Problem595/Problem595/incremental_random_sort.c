#include <stdio.h>

#define SIZE 10

void show(double coeff[][SIZE], int size);
double factorial(int n);

int main(void) {
	double coefficients[SIZE][SIZE] = { 1, 0 };
	double S[SIZE] = { 1, 0 };

	for (int n = 1; n < SIZE; n++) {
		// Vertical adding
		for (int x = 1; x < n + 1; x++) {
			coefficients[n][x - 1] += coefficients[n - 1][x - 1] / ((double)n + 1.0);
		}
		// Inclined 1 adding
		for (int x = 1; x < n + 1; x++) {
			coefficients[n][x] += coefficients[n - 1][x - 1] * (double)x / ((double)n + 1.0);
		}
		// Inclined 2 adding
		for (int x = 1; x < n; x++) {
			coefficients[n][x + 1] += coefficients[n - 1][x - 1] * ((double)n - (double)x) / ((double)n + 1.0);
		}
	}

	show(coefficients, SIZE);

	for (int i = 2; i <= SIZE; i++) {
		// Calculate S
		for (int j = 1; j < i; j++) {
			S[i - 1] += coefficients[i - 1][j - 1] * S[j - 1];
		}
		S[i - 1] += 1.0 - 1.0 / factorial(i);
	}
	for (int i = 1; i <= SIZE; i++) {
		printf("S[%d] = %f\n", i - 1, S[i - 1]);
	}
	
	return 0;
}

void show(double coeff[][SIZE], int size) {
	printf("Table of coefficients:\n      ");
	for (int i = 0; i < SIZE; i++) {
		printf("   x = %-2d ", i + 1);
	}
	putchar('\n');

	for (int i = 0; i < SIZE; i++) {
		printf("n = %-2d", i + 1);
		for (int j = 0; j < SIZE; j++) {
			printf("%9.4f ", coeff[i][j]);
		}
		putchar('\n');
	}

	puts("\n");
}

double factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}