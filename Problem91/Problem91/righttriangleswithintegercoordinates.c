#include <stdio.h>
#include <stdbool.h>

#define LIMIT 50

bool isRight(int a2, int b2, int c2);

int main(void) {
	int amount = 0;

	for (int xp = 0; xp <= LIMIT; xp++) {
		for (int yp = 0; yp <= LIMIT; yp++) {
			for (int xq = 0; xq <= LIMIT; xq++) {
				for (int yq = 0; yq <= LIMIT; yq++) {
					if ((xp == 0 && yp == 0) || (xq == 0 && yq == 0) || (xp == xq && yp == yq))
						continue;

					int a2 = xp*xp + yp*yp;
					int c2 = xq*xq + yq*yq;
					int b2 = (xq - xp)*(xq - xp) + (yp - yq)*(yp - yq);
					if (isRight(a2, b2, c2)) {
						//printf("Triangle:  O(0,0) P(%d,%d) Q(%d,%d) is right.\n", xp, yp, xq, yq);
						amount++;
					}
				}
			}
		}
	}

	printf("There are %d such trangles.\n", amount / 2);

	return 0;
}

bool isRight(int a2, int b2, int c2) {
	if (a2 >= b2 && a2 >= c2)
		return (a2 == b2 + c2);

	if (b2 >= a2 && b2 >= c2)
		return (b2 == a2 + c2);

	if (c2 >= a2 && c2 >= b2)
		return (c2 == a2 + b2);
}