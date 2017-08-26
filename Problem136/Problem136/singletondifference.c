#include <stdio.h>
#include <stdbool.h>

#define LIMIT 50000000
#define INTERVALS 50
#define SIZE (LIMIT/INTERVALS)

int main(void) {
	int amount = 0;

	for (int g = 0; g < INTERVALS; g++) {
		char results[SIZE] = { 0 };

		for (long long z = 1; z <= LIMIT; z++) {
			for (long long r = z / 3; (z + 2 * r)*(z + 2 * r) <= (g+1)*SIZE + (z + r)*(z + r) + z*z; r++) {
				long long n = (z + 2 * r)*(z + 2 * r) - (z + r)*(z + r) - z*z;

				if (n > g*SIZE) {
					results[n - g*SIZE - 1]++;
					//printf("X: %lld, Y: %lld, Z: %lld, n: %lld\n", z + 2 * r, z + r, z, n);
				}
			}
		}

		for (int i = 0; i < SIZE; i++) {
			if (results[i] == 1)
				amount++;
		}

		printf("Progress: %d/%d\n", g + 1, INTERVALS);
	}

	printf("There are %d solutions (remember to remove last n if it has only 1 solution - %d).\n", amount, LIMIT);

	return 0;
}