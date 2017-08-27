#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 80

void show(int m[][N]);
bool theSame(const int mins[], const int prevmins[]);

int main(void) {
	int m[N][N];

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

	for (int c = 1; c < N; c++) {
		int mins[N];
		int prevmins[N];
		for (int i = 0; i < N; i++) {
			mins[i] = 999999999;
			prevmins[i] = 999999998;
		}

		while (!theSame(mins, prevmins)) {
			for (int i = 0; i < N; i++)
				prevmins[i] = mins[i];

			for (int r = 0; r < N; r++) {
				if (r == 0)
					mins[r] = min(m[r][c - 1], m[r + 1][c] + mins[r + 1]);
				else if (r == N - 1)
					mins[r] = min(m[r][c - 1], m[r - 1][c] + mins[r - 1]);
				else
					mins[r] = min(m[r][c - 1], m[r - 1][c] + mins[r - 1], m[r + 1][c] + mins[r + 1]);
			}
		}

		for (int r = 0; r < N; r++)
			m[r][c] += mins[r];
	}

	show(m);

	int best = 999999999;
	for (int r = 0; r < N; r++) {
		if (m[r][N - 1] < best)
			best = m[r][N - 1];
	}

	printf("Minimal path sum: %d\n", best);

	return 0;
}

void show(int m[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%5d ", m[i][j]);

		printf("\n");
	}
}

bool theSame(const int mins[], const int prevmins[]) {
	for (int i = 0; i < N; i++) {
		if (mins[i] != prevmins[i])
			return false;
	}

	return true;
}