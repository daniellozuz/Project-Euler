#include <stdio.h>
#include <stdbool.h>

#define LIMIT 1009000

bool isSquare(int number);


int main(void) {

	int a = 1;
	int b = 1;
	int c = 1;

	for (a = 1; a*a <= LIMIT; a++) {
		for (b = 1; b*b - a*a <= LIMIT; b++) {
			for (c = 1; c*c - (a*a + b*b) / 2 <= LIMIT; c++) {
				int a2 = a*a;
				int b2 = b*b;
				if (!((a2 + b2) % 2 == 0) || !((a2 + a2) % 2 == 0))
					break;

				int x = (a2 + b2) / 2;
				int y = (b2 - a2) / 2;
				int c2 = c*c;
				int z = c2 - x;

				if (x + y + z > LIMIT)
					break;

				if (x > 0 && y > 0 && z > 0 && x - z > 0 && y - z > 0) {
					if (isSquare(x - z) && isSquare(y + z) && isSquare(y - z)) {
						printf("Solution found! x = %d, y = %d, z = %d (a = %d, b = %d, c = %d)   Sum: %d\n", x, y, z, a, b, c, x + y + z);
						break;
					}
				}
			}
		}
	}

	return 0;
}

bool isSquare(int number) {
	for (int i = 1; i*i <= number; i++) {
		if (i*i == number)
			return true;
	}

	return false;
}