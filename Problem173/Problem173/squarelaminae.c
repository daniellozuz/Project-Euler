#include <stdio.h>

#define LIMIT 1000000

int main(void) {
	int tiles;
	int amount = 0;

	for (int x = 1; 4*(x + 1) <= LIMIT; x++) {
		for (int y = x + 2; (tiles = y*y - x*x) <= LIMIT; y++) {
			if ((y - x) % 2 == 0) {
				//printf("Outer Y: %3d, Hole X: %3d, Tiles: %4d\n", y, x, tiles);
				amount++;
			}
		}
	}

	printf("There are %d possibilities.\n", amount);

	return 0;
}