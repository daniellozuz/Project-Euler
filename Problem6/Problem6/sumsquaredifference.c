#include <stdio.h>

#define LIMIT 100

int main(void) {
	int sum_sq = 0;
	for (int i = 1; i <= LIMIT; i++) {
		sum_sq += i * i;
	}
	printf("The sum of the squares of the first %d natural numbers is %d\n\n", LIMIT, sum_sq);

	int sq_sum = 0;
	for (int i = 1; i <= LIMIT; i++) {
		sq_sum += i;
	}
	printf("The square of the sum of the first %d natural numbers is %d\n\n", LIMIT, sq_sum * sq_sum);

	printf("The difference: %d\n\n", sq_sum * sq_sum - sum_sq);

	return 0;
}