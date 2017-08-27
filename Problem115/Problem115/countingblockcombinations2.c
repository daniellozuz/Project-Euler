#include <stdio.h>
#include <time.h>

#define LEN 168
#define MIN 50

long long ways(int fields);

int main(void) {
	clock_t start, end;

	for (int i = 1; i <= LEN; i++) {
		start = clock();
		printf("For the total length of %2d, there are %11lld solutions   ", i, ways(i));
		end = clock();
		printf("Calculated in %.2fs.\n", (float)(end - start) / CLOCKS_PER_SEC);
	}

	return 0;
}

long long ways(int fields) {
	static long long tab[LEN+10] = { 0 };
	long long solutions = 0;

	for (int l = MIN; l <= fields; l++) {
		for (int p = 0; p <= fields - l; p++) {
			if (tab[fields - l - p - 1] == 0) {
				solutions += ways(fields - l - p - 1);
				tab[fields - l - p - 1] = solutions;
			}
			else {
				solutions += tab[fields - l - p - 1];
			}

		}
	}

	return solutions + 1;
}

void show(long long tab[]) {
	for (int i = 0; i < 60; i++)
		printf("%d ", tab[i]);
	printf("\n");
}