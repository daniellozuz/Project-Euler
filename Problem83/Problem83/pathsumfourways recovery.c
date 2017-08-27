#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 5

void show(const int m[][N]);
bool done(const int M[][N]);
bool adjacent(const int r, const int c, const int M[][N]);

int main(void) {
	/*
	FILE *fp;

	if ((fp = fopen("matrix.txt", "r")) == NULL) {
		fprintf(stderr, "Could not open matrix.txt\n");
		exit(EXIT_FAILURE);
	}
	char ch;

	int r = 0;
	int c = 0;
	int number = 0;
	while (ch = fgetc(fp)) {
		if (ch == EOF) {
			m[r][c] = number;
			break;
		}
		if (ch == '\n') {
			m[r][c] = number;
			r++;
			c = 0;
			number = 0;
		}
		else if (ch == ',') {
			m[r][c] = number;
			c++;
			number = 0;
		}
		else {
			number *= 10;
			number += (ch - 48);
		}
	}
	*/
	int m[N][N] = { { 131, 673, 234, 103, 18 },
	{ 201, 96, 342, 965, 150 },
	{ 630, 803, 746, 422, 111 },
	{ 537, 699, 497, 121, 956 },
	{ 805, 732, 524, 37, 331 } };
	int M[N][N];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++)
			M[r][c] = false;
	}
	M[0][0] = true;

	while (!done(M)) {
		int values[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				values[i][j] = 999999999;
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (!M[r][c] && adjacent(r, c, M)) {
					if (r == 0 && c != 0 && c != N - 1) {
						int best = 999999999;
						if (M[r][c - 1]) {
							if (best > m[r][c - 1])
								best = m[r][c - 1];
						}
						if (M[r + 1][c]) {
							if (best > m[r + 1][c])
								best = m[r + 1][c];
						}
						if (M[r][c + 1]) {
							if (best > m[r][c + 1])
								best = m[r][c + 1];
						}

						values[r][c] = best;
					}
					else if (c == 0 && r != 0 && r != N - 1) {
						int best = 999999999;
						if (M[r - 1][c]) {
							if (best > m[r - 1][c])
								best = m[r - 1][c];
						}
						if (M[r][c + 1]) {
							if (best > m[r][c + 1])
								best = m[r][c + 1];
						}
						if (M[r + 1][c]) {
							if (best > m[r + 1][c])
								best = m[r + 1][c];
						}

						values[r][c] = best;
					}
					else if (r == N - 1 && c != 0 && c != N - 1) {
						int best = 999999999;
						if (M[r][c - 1]) {
							if (best > m[r][c - 1])
								best = m[r][c - 1];
						}
						if (M[r - 1][c]) {
							if (best > m[r - 1][c])
								best = m[r - 1][c];
						}
						if (M[r][c + 1]) {
							if (best > m[r][c + 1])
								best = m[r][c + 1];
						}

						values[r][c] = best;
					}
					else if (c == N - 1 && r != 0 && r != N - 1) {
						int best = 999999999;
						if (M[r - 1][c]) {
							if (best > m[r - 1][c])
								best = m[r - 1][c];
						}
						if (M[r][c - 1]) {
							if (best > m[r][c - 1]) {
								best = m[r][c - 1];
							}
						}
						if (M[r + 1][c]) {
							if (best > m[r + 1][c])
								best = m[r + 1][c];
						}

						values[r][c] = best;
					}
					else if (r == 0 && c == N - 1) {
						int best = 999999999;
						if (M[r][c - 1]) {
							if (best > m[r][c - 1])
								best = m[r][c - 1];
						}
						if (M[r + 1][c]) {
							if (best > m[r + 1][c])
								best = m[r + 1][c];
						}

						values[r][c] = best;
					}
					else if (c == 0 && r == N - 1) {
						int best = 999999999;
						if (M[r - 1][c]) {
							if (best > m[r - 1][c])
								best = m[r - 1][c];
						}
						if (M[r][c + 1]) {
							if (best > m[r][c + 1])
								best = m[r][c + 1];
						}

						values[r][c] = best;
					}
					else if (c == N - 1 && r == N - 1) {
						int best = 999999999;
						if (M[r][c - 1]) {
							if (best > m[r][c - 1])
								best = m[r][c - 1];
						}
						if (M[r - 1][c]) {
							if (best > m[r - 1][c]) {
								best = m[r - 1][c];
							}
						}

						values[r][c] = best;
					}
					else {
						int best = 999999999;
						if (M[r - 1][c]) {
							if (best > m[r - 1][c])
								best = m[r - 1][c];
						}
						if (M[r][c - 1]) {
							if (best > m[r][c - 1])
								best = m[r][c - 1];
						}
						if (M[r + 1][c]) {
							if (best > m[r + 1][c])
								best = m[r + 1][c];
						}
						if (M[r][c + 1]) {
							if (best > m[r][c + 1])
								best = m[r][c + 1];
						}

						values[r][c] = best;
					}
				}
			}
		}

		int best = 999999999;
		int besti = -1;
		int bestj = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (values[i][j] + m[i][j] < best) {
					best = values[i][j];
					besti = i;
					bestj = j;
				}
			}
		}

		m[besti][bestj] += best;
		M[besti][bestj] = true;
	}

	show(m);

	printf("The minimal path sum: %d\n", m[N - 1][N - 1]);

	return 0;
}

void show(const int m[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%5d ", m[i][j]);

		printf("\n");
	}
}

bool done(const int M[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!M[i][j])
				return false;
		}
	}

	return true;
}

bool adjacent(const int r, const int c, const int M[][N]) {
	if (r == 0 && c == 0) {
		if (M[r + 1][c] || M[r][c + 1])
			return true;
	}
	else if (r == 0 && c == N - 1) {
		if (M[r][c - 1] || M[r + 1][c])
			return true;
	}
	else if (r == N - 1 && c == 0) {
		if (M[r - 1][c] || M[r][c + 1])
			return true;
	}
	else if (r == N - 1 && c == N - 1) {
		if (M[r - 1][c] || M[r][c - 1])
			return true;
	}
	else if (r == 0) {
		if (M[r][c - 1] || M[r + 1][c] || M[r][c + 1])
			return true;
	}
	else if (c == 0) {
		if (M[r - 1][c] || M[r][c + 1] || M[r + 1][c])
			return true;
	}
	else if (r == N - 1) {
		if (M[r][c - 1] || M[r - 1][c] || M[r][c + 1])
			return true;
	}
	else if (c == N - 1) {
		if (M[r - 1][c] || M[r][c - 1] || M[r + 1][c])
			return true;
	}
	else {
		if (M[r - 1][c] || M[r + 1][c] || M[r][c - 1] || M[r][c + 1])
			return true;
	}
}