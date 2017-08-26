#include <stdio.h>
#include <math.h>

#define LIMITX 2000
#define LIMITY 2000
#define TARGET 2000000

int main(void) {
	int solution[3] = { 0, 0, 0 };
	for (int x = 1; x <= LIMITX; x++) {
		for (int y = 1; y <= LIMITY; y++) {
			int sum = 0;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					sum += (x - i) * (y - j);
				}
				if (sum > 2 * TARGET)
					break;
			}

			if (abs(TARGET - sum) < abs(TARGET - solution[2])) {
				solution[0] = x;
				solution[1] = y;
				solution[2] = sum;
			}
		}
	}

	printf("Solution:\nX: %4d Y: %4d Number: %10d Area: %d\n", solution[0], solution[1], solution[2], solution[0] * solution[1]);

	return 0;
}