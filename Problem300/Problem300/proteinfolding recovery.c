#include <stdio.h>

#define L 9
#define M (2*L-1)

void show(int grid[][M]);
void showProtein(int g[][M]);
void genNext(int grid[][M]);

int main(void) {

	int grid[M][M] = { 0 };
	grid[L - 1][L - 1] = 1;

	genNext(grid);

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
				printf("H ");
			else if (g[i][j] == 1)
				printf("P ");
			else
				printf("  ");
		}

		printf("\n");
	}
}

void genNext(int grid[][M]) {
	int head = 0;
	int headx = 0;
	int heady = 0;

	for (int x = 0; x < M; x++) {
		for (int y = 0; y < M; y++) {
			if (grid[x][y] > head) {
				head = grid[x][y];
				headx = x;
				heady = y;
			}
		}
	}

	if (head == L - 1) {
		show(grid);

		// Test the protein (Calculate amount of H-H contacts for every P-H sequence)
		for (int s = 0; s <= 255; s++) {
			// H binary 0
			// P binary 1
			int sequence[L - 1] = { (s / 128) % 2, (s / 64) % 2, (s / 32) % 2, (s / 16) % 2, (s / 8) % 2, (s / 4) % 2, (s / 2) % 2, s % 2 };

			int g[M][M] = { 0 };
			for (int x = 0; x < M; x++) {
				for (int y = 0; y < M; y++) {
					if (grid[x][y] != 0)
						g[x][y] = sequence[grid[x][y] - 1];
					else
						g[x][y] = 9;
				}
			}

			showProtein(g);

			int amount = 0;
			for (int x = 0; x < M; x++) {
				for (int y = 0; y < M; y++) {
					if (g[x][y] == 0 && g[x + 1][y] == 0)
						amount++;
					if (g[x][y] == 0 && g[x][y + 1] == 0)
						amount++;
					if (g[x][y] == 0 && g[x - 1][y] == 0)
						amount++;
					if (g[x][y] == 0 && g[x][y - 1] == 0)
						amount++;
				}
			}

			printf("There are %d H-H connections.\n", amount / 2);
		}
	}

	if (grid[headx + 1][heady] == 0) {
		int g[M][M];
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < M; y++) {
				g[x][y] = grid[x][y];
			}
		}

		g[headx + 1][heady] = head + 1;
		if (head + 1 < L)
			genNext(g);
	}
	if (grid[headx][heady + 1] == 0) {
		int g[M][M];
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < M; y++) {
				g[x][y] = grid[x][y];
			}
		}

		g[headx][heady + 1] = head + 1;
		if (head + 1 < L)
			genNext(g);
	}
	if (grid[headx - 1][heady] == 0) {
		int g[M][M];
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < M; y++) {
				g[x][y] = grid[x][y];
			}
		}

		g[headx - 1][heady] = head + 1;
		if (head + 1 < L)
			genNext(g);
	}
	if (grid[headx][heady - 1] == 0) {
		int g[M][M];
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < M; y++) {
				g[x][y] = grid[x][y];
			}
		}

		g[headx][heady - 1] = head + 1;
		if (head + 1 < L)
			genNext(g);
	}
}