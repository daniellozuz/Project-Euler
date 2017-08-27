#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 9

struct field {
	int number;
	bool possible[N + 1];
};

void init(struct field grid[][N], int size);
void load(struct field grid[][N], int data[][N], int size);
void read(int data[][N], int size, int number);

void look(struct field grid[][N], int next_state[][N], int size);
bool onlyoption(const struct field * field);
bool equal(int next_state[][N], int prev_state[][N], int size);
void copy(int prev_state[][N], int next_state[][N], int size);
bool complete(const struct field grid[][N], int size);

void show(struct field grid[][N], int size);

int main(void) {
	struct field grid[N][N];
	int accomplished = 0;

	for (int puzzleNo = 2; puzzleNo <= 2; puzzleNo++) {
		int data[N][N] = {
			{ 0, 0, 3, 0, 2, 0, 6, 0, 0 },
			{ 9, 0, 0, 3, 0, 5, 0, 0, 1 },
			{ 0, 0, 1, 8, 0, 6, 4, 0, 0 },
			{ 0, 0, 8, 1, 0, 2, 9, 0, 0 },
			{ 7, 0, 0, 0, 0, 0, 0, 0, 8 },
			{ 0, 0, 6, 7, 0, 8, 2, 0, 0 },
			{ 0, 0, 2, 6, 0, 9, 5, 0, 0 },
			{ 8, 0, 0, 2, 0, 3, 0, 0, 9 },
			{ 0, 0, 5, 0, 1, 0, 3, 0, 0 }
		};
		int prev_state[N][N] = {
			{ 0, 0, 3, 0, 2, 0, 6, 0, 0 },
			{ 9, 0, 0, 3, 0, 5, 0, 0, 1 },
			{ 0, 0, 1, 8, 0, 6, 4, 0, 0 },
			{ 0, 0, 8, 1, 0, 2, 9, 0, 0 },
			{ 7, 0, 0, 0, 0, 0, 0, 0, 8 },
			{ 0, 0, 6, 7, 0, 8, 2, 0, 0 },
			{ 0, 0, 2, 6, 0, 9, 5, 0, 0 },
			{ 8, 0, 0, 2, 0, 3, 0, 0, 9 },
			{ 0, 0, 5, 0, 1, 0, 3, 0, 0 }
		};
		int next_state[N][N] = { { -1 } };

		read(data, N, puzzleNo);

		init(grid, N);
		load(grid, data, N);

		show(grid, N);

		while (!equal(next_state, prev_state, N)) {
			copy(prev_state, next_state, N);
			look(grid, next_state, N);
			show(grid, N);
		}

		if (complete(grid, N)) {
			printf("I solved puzzle number %d\n", puzzleNo);
			accomplished++;
		}

		//show(grid, N);
	}

	printf("I solved %d puzzles in total\n", accomplished);

	return 0;
}

void init(struct field grid[][N], int size) {
	struct field zero = { 0, true, true, true, true, true, true, true, true, true, true };

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < N; j++)
			grid[i][j] = zero;
	}
}

void show(struct field grid[][N], int size) {
	printf("H===+===+===H===+===+===H===+===+===H\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < N; j++) {
			if (j % 3 == 0)
				printf("H %d ", grid[i][j].number);
			else
				printf("| %d ", grid[i][j].number);
		}
		printf("H\n");
		if (i % 3 == 2)
			printf("H===+===+===H===+===+===H===+===+===H\n");
		else
			printf("H---+---+---H---+---+---H---+---+---H\n");
	}
	puts("\n");
}

void load(struct field grid[][N], int data[][N], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < N; j++)
			grid[i][j].number = data[i][j];
	}
}

// i and j are coordinates of a number being checked
// row and col are coordinates of numbers in an area (row, column or square)
void look(struct field grid[][N], int next_state[][N], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j].number == 0) {
				// Check rows - elimination until only 1 option per field
				int row = i;
				for (int col = 0; col < N; col++) {
					if (col != j && grid[row][col].number != 0) {
						grid[i][j].possible[grid[row][col].number] = false;
						//printf("R: At %d %d - %d is not possible\n", i, j, grid[row][col].number);
					}
				}
				// Check columns - elimination until only 1 option per field
				int col = j;
				for (int row = 0; row < N; row++) {
					if (row != i && grid[row][col].number != 0) {
						grid[i][j].possible[grid[row][col].number] = false;
						//printf("C: At %d %d - %d is not possible\n", i, j, grid[row][col].number);
					}
				}
				// Check squares - elimination until only 1 option per field
				for (int row = i - i % 3; row < i + 3 - i % 3; row++) {
					for (int col = j - j % 3; col < j + 3 - j % 3; col++) {
						if (row != i && col != j && grid[row][col].number != 0) {
							grid[i][j].possible[grid[row][col].number] = false;
							//printf("S: At %d %d - %d is not possible\n", i, j, grid[row][col].number);
						}
					}
				}

				if (grid[i][j].number == 0 && onlyoption(&grid[i][j])) {
					for (int p = 1; p <= N; p++) {
						if (grid[i][j].possible[p] == true) {
							grid[i][j].number = p;
							printf("At %d %d I found %d\n", i, j, grid[i][j].number);
						}
					}
				}
			}
			next_state[i][j] = grid[i][j].number;
		}
	}

	// For all rows
	for (int i = 0; i < N; i++) {
		for (int n = 1; n <= N; n++) {
			int hits = 0;
			int coord[2] = { -1, -1 };
			for (int j = 0; j < N; j++) {
				if (grid[i][j].number == 0 && grid[i][j].possible[n] == true) {
					hits++;
					//printf("Hit");
					coord[0] = i;
					coord[1] = j;
				}
			}
			if (hits == 1) {
				grid[coord[0]][coord[1]].number = n;
				printf("At %d %d I selected %d\n", coord[0], coord[1], grid[coord[0]][coord[1]].number);
				next_state[coord[0]][coord[1]] = grid[coord[0]][coord[1]].number;
				break;
			}
		}
	}
	// For all columns
	for (int j = 0; j < N; j++) {
		for (int n = 1; n <= N; n++) {
			int hits = 0;
			int coord[2] = { -1, -1 };
			for (int i = 0; i < N; i++) {
				if (grid[i][j].number == 0 && grid[i][j].possible[n] == true) {
					hits++;
					//printf("Hit");
					coord[0] = i;
					coord[1] = j;
				}
			}
			if (hits == 1) {
				grid[coord[0]][coord[1]].number = n;
				printf("At %d %d I selected %d\n", coord[0], coord[1], grid[coord[0]][coord[1]].number);
				next_state[coord[0]][coord[1]] = grid[coord[0]][coord[1]].number;
				break;
			}
		}
	}
}

bool onlyoption(const struct field * field) {
	int options = 0;

	for (int i = 1; i <= N; i++) {
		if (field->possible[i])
			options++;
	}

	if (options == 1)
		return true;
	else
		return false;
}

bool equal(int next_state[][N], int prev_state[][N], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < N; j++) {
			if (next_state[i][j] != prev_state[i][j])
				return false;
		}
	}

	return true;
}

void copy(int prev_state[][N], int next_state[][N], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < N; j++)
			prev_state[i][j] = next_state[i][j];
	}
}

void read(int data[][N], int size, int number) {
	int counter = 1;
	char ch;
	FILE * fp;

	if ((fp = fopen("sudoku.txt", "r")) == NULL) {
		fprintf(stderr, "I cannot open sudoku.txt\n");
		exit(EXIT_FAILURE);
	}

	while (counter != number) {
		for (int i = 0; i < 10; i++) {
			while ((ch = fgetc(fp)) != '\n')
				continue;
		}
		counter++;
	}

	while ((ch = fgetc(fp)) != '\n')
		continue;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ch = fgetc(fp);
			data[i][j] = ch - 48;
		}
		ch = fgetc(fp);
	}

	if (fclose(fp)) {
		fprintf(stderr, "I cannot close sudoku.txt\n");
		exit(EXIT_FAILURE);
	}
}

bool complete(const struct field grid[][N], int size) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j].number == 0)
				return false;
		}
	}

	return true;
}