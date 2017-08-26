#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define D 5500000

bool isPent(int number);

int main(void) {

	int j, k, Pj, Pk;
	
	// Pk > Pj
	for (j = 1; ((j*(3 * j - 1)) / 2 - ((j - 1)*(3 * (j - 1) - 1)) / 2) <= D; j++) {
		Pj = (j*(3 * j - 1)) / 2;
		for (k = j + 1; (Pk = (k*(3 * k - 1)) / 2) - Pj <= D; k++) {
			if (Pk <= Pj)
				break;

			if (isPent(Pk + Pj) && isPent(Pk - Pj))
				printf("Success. Pk = %d (k = %d); Pj = %d (j = %d). D = %d\n", Pk, k, Pj, j, Pk - Pj);
		}
	}

	return 0;
}

bool isPent(int number) {
	int n = (1 + sqrt(1 + 24 * number)) / 6;

	return ((n*(3 * n - 1)) / 2 == number);
}