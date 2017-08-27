// Current state of the programme solves all puzzles. The trial and error approach does not work in compliance with all the sudokus possible. There needs to be recurence involved.
// Also the code needs a lot of cleaning.

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
	int result = 0;

	for (int puzzleNo = 1; puzzleNo <= 50; puzzleNo++) {
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
			result += 100 * grid[0][0].number + 10 * grid[0][1].number + grid[0][2].number;
		}
		else {
			// Guessing part
			int guess[3] = { -1, -1, -1 };
			int bad_guesses[10][3] = { -1 };
			struct field previous_grid[N][N];
			// Guess one
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (grid[i][j].number == 0) {
						for (int n = 1; n <= N; n++) {
							if (grid[i][j].possible[n] == true && n != 4) {
								grid[i][j].number = n;
								guess[0] = i;
								guess[1] = j;
								guess[2] = n;
								// Break 3 loops
								goto end_guess;
							}
						}
					}
				}
			}
			end_guess:
			// Try solving
			next_state[0][0] = -1;
			while (!equal(next_state, prev_state, N)) {
				copy(prev_state, next_state, N);
				look(grid, next_state, N);
				show(grid, N);
			}
			// Check if valid (break, continue)
			bool error = false;
			int present[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			// Check rows
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (grid[i][j].number != 0) {
						present[j] = grid[i][j].number;
					}
				}
				// Check for multiple presences
				for (int j1 = 0; j1 < N - 1; j1++) {
					for (int j2 = j1 + 1; j2 < N; j2++) {
						if (present[j1] != 0 && present[j2] != 0 && present[j1] == present[j2]) {
							// Error
							error = true;
						}
					}
				}
				// Reset present to 0's
				for (int j = 0; j < N; j++) {
					present[j] = 0;
				}
			}
			// Check columns
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < N; i++) {
					if (grid[i][j].number != 0) {
						present[i] = grid[i][j].number;
					}
				}
				// Check for multiple presences
				for (int i1 = 0; i1 < N - 1; i1++) {
					for (int i2 = i1 + 1; i2 < N; i2++) {
						if (present[i1] != 0 && present[i2] != 0 && present[i1] == present[i2]) {
							// Error
							error = true;
						}
					}
				}
				// Reset present to 0's
				for (int i = 0; i < N; i++) {
					present[i] = 0;
				}
			}
			// Check squares ?????????????
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					for (int r = i * 3; r < i * 3 + 3; r++) {
						for (int c = j * 3; c < j * 3 + 3; c++) {
							if (grid[r][c].number != 0) {
								present[(r%3) * 3 + c%3] = grid[r][c].number;
							}
						}
					}
					// Check for multiple presences
					for (int i1 = 0; i1 < N - 1; i1++) {
						for (int i2 = i1 + 1; i2 < N; i2++) {
							if (present[i1] != 0 && present[i2] != 0 && present[i1] == present[i2]) {
								// Error
								error = true;
							}
						}
					}
					// Reset present to 0's
					for (int k = 0; k < N; k++) {
						present[k] = 0;
					}
				}
			}
			if (error) {
				printf("I guessed incorrectly.\n");
				printf("Number %d may not be in (%d, %d)\n", guess[2], guess[0], guess[1]);
			}

			// Check if complete
			if (complete(grid, N)) {
				printf("I solved puzzle number %d after trial and error method\n", puzzleNo);
				accomplished++;
				result += 100 * grid[0][0].number + 10 * grid[0][1].number + grid[0][2].number;
			}
		}

		//show(grid, N);
	}

	printf("I solved %d puzzles in total\n", accomplished);
	printf("The result is: %d\n", result);

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
			}
		}

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
		for (int i = 0; i < N; i++) {
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
			}
		}

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
	// For all squares ????????????????????????????????????????
	for (int i = 0; i < N; i++) {
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
			}
		}
	}
	// Every square
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Every number
			for (int n = 1; n <= N; n++) {
				int hits = 0;
				int coord[2] = { -1, -1 };
				// Every cell in a square
				for (int col = 3 * i; col < 3 * i + 3; col++) {
					for (int row = 3 * j; row < 3 * j + 3; row++) {
						if (grid[row][col].number == 0 && grid[row][col].possible[n] == true) {
							hits++;
							//printf("Hit");
							coord[0] = row;
							coord[1] = col;
						}
					}
				}
				if (hits == 1) {
					grid[coord[0]][coord[1]].number = n;
					printf("Square: At %d %d I selected %d\n", coord[0], coord[1], grid[coord[0]][coord[1]].number);
					next_state[coord[0]][coord[1]] = grid[coord[0]][coord[1]].number;
					break;
				}
			}
		}
	}

	// Complex part
	// Elimination
	for (int i = 0; i < N; i++) {
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
			}
		}
	}
	// Groups
	// For all rows
	for (int i = 0; i < N; i++) {
		for (int n = 1; n <= N; n++) {
			bool sectors[3] = { false, false, false };
			for (int j = 0; j < N; j++) {
				if (grid[i][j].number == 0 && grid[i][j].possible[n] == true) {
					sectors[j / 3] = true;
					printf("Groups: Row - %d, Number %d may be in sector %d\n", j, n, j/3);
				}
			}
			if (sectors[0] && !sectors[1] && !sectors[2]) {
				// empty square (i/3, 0) but for the row (i)
				for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++) {
					for (int col = 0; col < 3; col++) {
						if (row != i && grid[row][col].number == 0) {
							grid[row][col].possible[n] = false;
							printf("Groups: At %d %d - %d is not possible\n", row, col, n);
						}
					}
				}
			}
			if (!sectors[0] && sectors[1] && !sectors[2]) {
				// empty square (i/3, 0) but for the row (i)
				for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++) {
					for (int col = 3; col < 6; col++) {
						if (row != i && grid[row][col].number == 0) {
							grid[row][col].possible[n] = false;
							printf("Groups: At %d %d - %d is not possible\n", row, col, n);
						}
					}
				}
			}
			if (!sectors[0] && !sectors[1] && sectors[2]) {
				// empty square (i/3, 0) but for the row (i)
				for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++) {
					for (int col = 6; col < 9; col++) {
						if (row != i && grid[row][col].number == 0) {
							grid[row][col].possible[n] = false;
							printf("Groups: At %d %d - %d is not possible\n", row, col, n);
						}
					}
				}
			}
		}
	}
	// Elimination
	for (int i = 0; i < N; i++) {
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
			}
		}
	}
	// Groups
	// For all columns
	for (int j = 0; j < N; j++) {
		for (int n = 1; n <= N; n++) {
			bool sectors[3] = { false, false, false };
			for (int i = 0; i < N; i++) {
				if (grid[i][j].number == 0 && grid[i][j].possible[n] == true) {
					sectors[i / 3] = true;
					printf("Groups: Row - %d, Number %d may be in sector %d\n", i, n, i / 3);
				}
			}
			if (sectors[0] && !sectors[1] && !sectors[2]) {
				// empty square (i/3, 0) but for the row (i)
				for (int row = 0; row < 3; row++) {
					for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++) {
						if (col != j && grid[row][col].number == 0) {
							grid[row][col].possible[n] = false;
							printf("Groups: At %d %d - %d is not possible\n", row, col, n);
						}
					}
				}
			}
			if (!sectors[0] && sectors[1] && !sectors[2]) {
				// empty square (i/3, 0) but for the row (i)
				for (int row = 3; row < 6; row++) {
					for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++) {
						if (col != j && grid[row][col].number == 0) {
							grid[row][col].possible[n] = false;
							printf("Groups: At %d %d - %d is not possible\n", row, col, n);
						}
					}
				}
			}
			if (!sectors[0] && !sectors[1] && sectors[2]) {
				// empty square (i/3, 0) but for the row (i)
				for (int row = 6; row < 9; row++) {
					for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++) {
						if (col != j && grid[row][col].number == 0) {
							grid[row][col].possible[n] = false;
							printf("Groups: At %d %d - %d is not possible\n", row, col, n);
						}
					}
				}
			}
		}
	}

	// The hardest part (squares considered)
	// Elimination
	for (int i = 0; i < N; i++) {
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
			}
		}
	}
	show(grid, N);
	// Groups
	// For all squares
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int n = 1; n <= N; n++) {
				bool rows[3] = { false, false, false };
				bool cols[3] = { false, false, false };
				// For every cell in a square
				for (int ii = i * 3; ii < i * 3 + 3; ii++) {
					for (int jj = j * 3; jj < j * 3 + 3; jj++) {
						if (grid[ii][jj].number == 0 && grid[ii][jj].possible[n] == true) {
							rows[ii - i * 3] = true;
							cols[jj - j * 3] = true;
							printf("Groups hard square(%d,%d): Number %d may be in position Row - %d, Column - %d\n", i,j,n, ii, jj);
						}
					}
				}
				if (rows[0] && !rows[1] && !rows[2]) {
					// empty the row (3*i + 0) but for the square in which you are (i, j)
					for (int col = 0; col < 9; col++) {
						if (col / 3 != j && grid[3*i][col].number == 0) {
							grid[3 * i][col].possible[n] = false;
							printf("Groups hard square(%d,%d): At %d %d - %d is not possible\n", i,j,3 * i, col, n);
						}
					}
				}
				if (!rows[0] && rows[1] && !rows[2]) {
					// empty the row (3*i + 1) but for the square in which you are (i, j)
					for (int col = 0; col < 9; col++) {
						if (col / 3 != j && grid[3 * i + 1][col].number == 0) {
							grid[3 * i + 1][col].possible[n] = false;
							printf("Groups hard square(%d,%d): At %d %d - %d is not possible\n", i, j, 3 * i + 1, col, n);
						}
					}
				}
				if (!rows[0] && !rows[1] && rows[2]) {
					// empty the row (3*i + 2) but for the square in which you are (i, j)
					for (int col = 0; col < 9; col++) {
						if (col / 3 != j && grid[3 * i + 2][col].number == 0) {
							grid[3 * i + 2][col].possible[n] = false;
							printf("Groups hard square(%d,%d): At %d %d - %d is not possible\n", i, j, 3 * i + 2, col, n);
						}
					}
				}
				if (cols[0] && !cols[1] && !cols[2]) {
					// empty the col (3*j + 0) but for the square in which you are (i, j)
					for (int row = 0; row < 9; row++) {
						if (row / 3 != i && grid[row][3 * j].number == 0) {
							grid[row][3*j].possible[n] = false;
							printf("NNNGroups hard square(%d,%d): At %d %d - %d is not possible\n", i, j, row, 3*j, n);
						}
					}
				}
				if (!cols[0] && cols[1] && !cols[2]) {
					// empty the col (3*j + 1) but for the square in which you are (i, j)
					for (int row = 0; row < 9; row++) {
						if (row / 3 != i && grid[row][3 * j + 1].number == 0) {
							grid[row][3 * j+1].possible[n] = false;
							printf("NNNGroups hard square(%d,%d): At %d %d - %d is not possible\n", i, j, row, 3 * j+1, n);
						}
					}
				}
				if (!cols[0] && !cols[1] && cols[2]) {
					// empty the col (3*j + 2) but for the square in which you are (i, j)
					for (int row = 0; row < 9; row++) {
						if (row / 3 != i && grid[row][3 * j+2].number == 0) {
							grid[row][3 * j+2].possible[n] = false;
							printf("NNNGroups hard square(%d,%d): At %d %d - %d is not possible\n", i, j, row, 3 * j+2, n);
						}
					}
				}
			}
		}
	}

	// Connecting groups of 2
	// For every row
	for (int r = 0; r < N; r++) {
		for (int c1 = 0; c1 < N - 1; c1++) {
			if (grid[r][c1].number == 0) {
				int amount1 = 0;
				int possib1[N + 1] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				for (int n = 1; n <= N; n++) {
					if (grid[r][c1].possible[n] == true) {
						possib1[amount1] = n;
						amount1++;
					}
				}
				if (amount1 == 2) {
					for (int c2 = c1 + 1; c2 < N; c2++) {
						if (grid[r][c2].number == 0) {
							int amount2 = 0;
							int possib2[N + 1] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
							for (int n = 1; n <= N; n++) {
								if (grid[r][c2].possible[n] == true) {
									possib2[amount2] = n;
									amount2++;
								}
							}
							if (amount2 == 2) {
								if (possib1[0] == possib2[0] && possib1[1] == possib2[1]) {
									for (int i = 0; i < N; i++) {
										if (grid[r][i].number == 0 && i != c1 && i != c2) {
											grid[r][i].possible[possib1[0]] = false;
											grid[r][i].possible[possib1[1]] = false;
											printf("Tadadarows: At %d %d - %d and %d is not possible\n", r, i, possib1[0], possib1[1]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	// For every column
	for (int c = 0; c < N; c++) {
		for (int r1 = 0; r1 < N - 1; r1++) {
			if (grid[r1][c].number == 0) {
				int amount1 = 0;
				int possib1[N + 1] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				for (int n = 1; n <= N; n++) {
					if (grid[r1][c].possible[n] == true) {
						possib1[amount1] = n;
						amount1++;
					}
				}
				if (amount1 == 2) {
					for (int r2 = r1 + 1; r2 < N; r2++) {
						if (grid[r2][c].number == 0) {
							int amount2 = 0;
							int possib2[N + 1] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
							for (int n = 1; n <= N; n++) {
								if (grid[r2][c].possible[n] == true) {
									possib2[amount2] = n;
									amount2++;
								}
							}
							if (amount2 == 2) {
								if (possib1[0] == possib2[0] && possib1[1] == possib2[1]) {
									for (int i = 0; i < N; i++) {
										if (grid[i][c].number == 0 && i != r1 && i != r2) {
											grid[i][c].possible[possib1[0]] = false;
											grid[i][c].possible[possib1[1]] = false;
											printf("Tadadacolumns: At %d %d - %d and %d is not possible\n", i, c, possib1[0], possib1[1]);
										}
									}
								}
							}
						}
					}
				}
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