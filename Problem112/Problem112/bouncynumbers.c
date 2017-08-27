#include <stdio.h>
#include <stdbool.h>

#define LIMIT 10000000

bool isIncreasing(int number);
bool isDecreasing(int number);

int main(void) {
	int bouncy = 0;
	int all = 0;

	for (int n = 1; n <= LIMIT; n++) {
		if (!isDecreasing(n) && !isIncreasing(n))
			bouncy++;

		all++;

		if (100 * bouncy == 99 * all)
			printf("For n = %d the proportion is exactly 99%\n", n);

		if (n % (LIMIT/10) == 0)
			printf("For the first %6d numbers proportion (bouncy/all) is %.2f%% (Bouncy = %d, All = %d)\n", n, 100 * (double)bouncy / (double)all, bouncy, all);
	}

	return 0;
}

bool isIncreasing(int number) {
	if (number < 10)
		return true;

	int prev = 10;
	while (number >= 1) {
		if (prev < number % 10)
			return false;

		prev = number % 10;
		number /= 10;
	}

	return true;
}

bool isDecreasing(int number) {
	if (number < 10)
		return true;

	int prev = 0;
	while (number >= 1) {
		if (prev > number % 10)
			return false;

		prev = number % 10;
		number /= 10;
	}

	return true;
}