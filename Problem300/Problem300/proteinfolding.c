#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define L 15
#define M ((L+1)/2+3+(L+1)/2)
#define C ((L+1)/2+1)

void show(int grid[][M]);
void showProtein(int g[][M]);
int genNext(int grid[][M], int sequence[], int b, int first, int nheadx, int nheady, int nhead);

int main(void) {
	clock_t start = clock();

	int grid[M][M] = { 0 };
	//grid[C][C] = 1;

	int sum = 0;
	// For every protein 2^L poss. Generate all shapes, pick the optimal.
	for (int s = 0; s < (int)pow(2, L); s++) {
		// H binary 0
		// P binary 1
		int sequence[L] = { (s / 16384) % 2, (s / 8192) % 2, (s / 4096) % 2, (s / 2048) % 2, (s / 1024) % 2, (s / 512) % 2, (s / 256) % 2, (s / 128) % 2, (s / 64) % 2, (s / 32) % 2, (s / 16) % 2, (s / 8) % 2, (s / 4) % 2, (s / 2) % 2, s % 2 };

		int connections = genNext(grid, sequence, 0, true, C, C, 1);
		printf("Best solution for sequence: %d%d%d%d%d%d%d%d%d%d%d%d (%d/%d): There are %d H-H connections.\n", sequence[0], sequence[1], sequence[2], sequence[3], sequence[4], sequence[5], sequence[6], sequence[7], sequence[8], sequence[9], sequence[10], sequence[11], s + 1, (int)pow(2, L), connections / 2);
		sum += connections;
	}

	printf("%d / %d = %.10lf\n", sum / 2, (int)pow(2, L), (double)sum / (2*pow(2, L)));

	clock_t end = clock();
	printf("Time: %.2fs\n", (float)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

void show(int grid[][M]) {
	static int calls = 1;
	
	printf("Grid (%d):\n", calls);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", grid[i][j]);

		printf("\n");
	}
	
	calls++;
}

void showProtein(int g[][M]) {
	printf("Protein:\n");
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (g[i][j] == 0)
				printf("  ");
			else if (g[i][j] == 1)
				printf("P ");
			else
				printf("H ");
		}

		printf("\n");
	}
}

int genNext(int grid[][M], int sequence[], int b, int first, int nheadx, int nheady, int nhead) {
	int head = nhead;
	int headx = nheadx;
	int heady = nheady;
	grid[headx][heady] = head;

	if (head == L) {
		int amount = 0;
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < M; y++) {
				// Check from grid, do not create g
				if (grid[x][y] != 0 && sequence[grid[x][y] - 1] == 0) {
					if (grid[x + 1][y] != 0 && sequence[grid[x + 1][y] - 1] == 0)
						amount++;
					if (grid[x][y + 1] != 0 && sequence[grid[x][y + 1] - 1] == 0)
						amount++;
					if (grid[x - 1][y] != 0 && sequence[grid[x - 1][y] - 1] == 0)
						amount++;
					if (grid[x][y - 1] != 0 && sequence[grid[x][y - 1] - 1] == 0)
						amount++;
				}
			}
		}

		//showProtein(g);
		//show(grid);

		if (amount > b) {
			//show(grid);
			b = amount;
			//printf("Best solution so far: There are %d H-H connections.\n", amount / 2);
		}
	}
	else {
		if (first) {
			if ((abs(headx + 1 - C) + abs(heady - C) <= (L + 1) / 2) && grid[headx + 1][heady] == 0) {
				if (head < L) {
					b = genNext(grid, sequence, b, false, headx + 1, heady, head + 1);
					grid[headx + 1][heady] = 0;
				}
			}
		}
		else {
			if ((abs(headx + 1 - C) + abs(heady - C) <= (L + 1) / 2) && grid[headx + 1][heady] == 0) {
				if (head < L) {
					b = genNext(grid, sequence, b, false, headx + 1, heady, head + 1);
					grid[headx + 1][heady] = 0;
				}
			}
			if ((abs(headx - C) + abs(heady + 1 - C) <= (L + 1) / 2) && grid[headx][heady + 1] == 0) {
				if (head < L) {
					b = genNext(grid, sequence, b, false, headx, heady + 1, head + 1);
					grid[headx][heady + 1] = 0;
				}
			}
			if ((abs(headx - 1 - C) + abs(heady - C) <= (L + 1) / 2) && grid[headx - 1][heady] == 0) {
				if (head < L) {
					b = genNext(grid, sequence, b, false, headx - 1, heady, head + 1);
					grid[headx - 1][heady] = 0;
				}
			}
			if ((abs(headx - C) + abs(heady - 1 - C) <= (L + 1) / 2) && grid[headx][heady - 1] == 0) {
				if (head < L) {
					b = genNext(grid, sequence, b, false, headx, heady - 1, head + 1);
					grid[headx][heady - 1] = 0;
				}
			}
		}
	}

	return b;
}