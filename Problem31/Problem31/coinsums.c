#include <stdio.h>

#define AMOUNT 200

int divide(int number, int min);

int main(void) {
	printf("There are %d ways to divide %dp into 1p, 2p, 5p, 10p, 20p, 50p, 100p, 200p coins.\n", divide(AMOUNT, 0), AMOUNT);

	return 0;
}

int divide(int number, int min) {
	int coins[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };

	static int possib = 0;

	for (int i = min; i < 8; i++) {
		if (number - coins[i] >= 0)
			divide(number - coins[i], i);

		if (number - coins[i] == 0)
			possib++;
	}

	return possib;
}