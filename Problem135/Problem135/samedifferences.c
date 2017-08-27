#include <stdio.h>

#define LIMIT 1000000

int main(void) {
	char results[LIMIT] = { 0 };
	int amount = 0;

	for (long long z = 1; z <= LIMIT; z++) {
		for (long long r = z / 3; (z + 2 * r)*(z + 2 * r) < LIMIT + (z + r)*(z + r) + z*z; r++) {
			long long n = (z + 2 * r)*(z + 2 * r) - (z + r)*(z + r) - z*z;

			if (n > 0)
				results[n - 1]++;
		}
	}

	for (int i = 0; i < LIMIT; i++) {
		if (results[i] == 10)
			amount++;
	}

	printf("There are %d solutions.\n", amount);

	return 0;
}