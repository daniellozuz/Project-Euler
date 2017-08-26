#include <stdio.h>
#include <stdbool.h>

bool isSquare(int number);


int main(void) {

	for (int a = 1; a <= 1000; a++) {
		for (int b = 1; b <= 1000; b++) {
			for (int c = 1; c <= 1000; c++) {
				int a2 = a*a;
				int b2 = b*b;
				if (!((a2 + b2) % 2 == 0) || !((a2 + a2) % 2 == 0))
					break;

				int x = (a2 + b2) / 2;
				int y = (b2 - a2) / 2;
				int c2 = c*c;
				int z = c2 - x;

				if (x > 0 && y > 0 && z > 0 && x - z > 0 && y - z > 0) {
					if (isSquare(x - z) && isSquare(y + z) && isSquare(y - z)) {
						printf("Solution found! x = %d, y = %d, z = %d (a = %d, b = %d, c = %d)   Sum: %d\n", x, y, z, a, b, c, x + y + z);
						break;
					}
				}
			}
		}
		if (a % 10 == 0)
			printf("%d%%\n", a / 10);
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