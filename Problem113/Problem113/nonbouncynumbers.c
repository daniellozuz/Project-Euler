#include <stdio.h>
#include <time.h>

#define L 20

long long genIncr(int first, int length);
long long genDecr(int first, int length);

long long genIncrFast(int first, int length);
long long genDecrFast(int first, int length);

int main(void) {
	clock_t start = clock();

	long long inc;
	long long dec;

	for (int l = 1; l <= L; l++) {
		for (int i = 1; i <= 9; i++)
			inc = genIncr(i, l);
	}
	printf("There are %lld increasing numbers consisting of %d-digits or less.\n", inc, L);
	
	for (int l = 1; l <= L; l++) {
		for (int i = 9; i >= 1; i--)
			dec = genDecr(i, l);
	}
	printf("There are %lld decreasing numbers consisting of %d-digits or less.\n", dec, L);

	printf("There are %lld non-bouncy numbers consisting of %d-digits or less.\n", inc + dec - 9 * L, L);

	clock_t end = clock();

	printf("Elapsed time: %.1fs\n", (float)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

long long genIncr(int first, int length) {
	static long long amount = 0;

	if (length == L)
		amount++;
	else {
		for (int i = first; i <= 9; i++)
			genIncr(i, length + 1);
	}

	return amount;
}

long long genDecr(int first, int length) {
	static long long amount = 0;

	if (length == L)
		amount++;
	else {
		for (int i = first; i >= 0; i--)
			genDecr(i, length + 1);
	}

	return amount;
}