#include <stdio.h>

#define LIMIT 10000000

int generate(int number);

int main(void) {
	int amount1 = 0;
	int amount89 = 0;

	for (int n = 1; n < LIMIT; n++) {
		int next = n;
		while (next != 1 && next != 89) {
			next = generate(next);
		}

		if (next == 1)
			amount1++;
		else if (next == 89)
			amount89++;
		else
			printf("Error. Next = %d\n", next);
	}

	printf("There are %d numbers below %d which arrive at 89\n", amount89, LIMIT);

	return 0;
}

int generate(int number) {
	int sum = 0;

	while (number >= 1) {
		sum += ((number % 10)*(number % 10));
		number /= 10;
	}

	return sum;
}