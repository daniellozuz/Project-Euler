#include <stdio.h>

double factorial(int n);

int main(void) {

	int amount = 0;

	for (int n = 1; n <= 100; n++) {
		for (int r = 0; r <= n; r++) {
			double result = (factorial(n) / (factorial(r)) / factorial(n - r));

			if (result > 1000000) {
				amount++;
				printf("%e\n", result);
			}
		}
	}

	printf("%d such numbers.\n", amount);

	return 0;
}

double factorial(int n) {
	if (n < 2)
		return 1;
	else
		return n * factorial(n - 1);
}