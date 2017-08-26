#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 80

bool done(bool M[][N]);
void show(int m[][N]);

int main(void) {
	bool M[N][N];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++)
			M[r][c] = false;
	}
	M[0][0] = true;
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

	while (!done(M)) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				// If needs solving
				if (!M[r][c]) {
					if (c == 0) {
						if (M[r - 1][c]) {
							m[r][c] += m[r - 1][c];
							M[r][c] = true;
						}
					}
					else if (r == 0) {
						if (M[r][c - 1]) {
							m[r][c] += m[r][c - 1];
							M[r][c] = true;
						}
					}
					else {
						if (M[r - 1][c] && M[r][c - 1]) {
							m[r][c] += min(m[r - 1][c], m[r][c - 1]);
							M[r][c] = true;
						}
					}
				}
			}
		}
	}

	//show(m);

	printf("The minimal path sum: %d\n", m[N - 1][N - 1]);

	return 0;
}

bool done(bool M[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!M[i][j])
				return false;
		}
	}

	return true;
}

void show(int m[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%5d ", m[i][j]);

		printf("\n");
	}
}