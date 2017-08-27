#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define N 100

void show(int triangle[][N], int size);
int maximum(int triangle[], int size);

int main(void) {
	int triangle[N][N] = { 0 };
	FILE * fp;

	if ((fp = fopen("p067_triangle.txt", "r")) == NULL) {
		fprintf(stderr, "Cannot open p067_triangle.txt");
		exit(EXIT_FAILURE);
	}

	char ch;
	int i = 0;
	int j = 0;
	bool first = true;
	int dig1;
	int dig2;
	int number;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') {
			i++;
			j = 0;
		}
		else if (isdigit(ch)) {
			if (first) {
				dig1 = ch - 48;
				first = false;
			}
			else {
				dig2 = ch - 48;
				number = dig1 * 10 + dig2;
				triangle[i][j] = number;
				j++;
				first = true;
			}
		}
	}

	//show(triangle, N);

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == i) {
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else {
				if (triangle[i - 1][j - 1] > triangle[i - 1][j])
					triangle[i][j] += triangle[i - 1][j - 1];
				else
					triangle[i][j] += triangle[i - 1][j];
			}
		}
	}

	//show(triangle, N);

	printf("\nMaximum: %d\n", maximum(triangle[N - 1], N));

	return 0;
}

void show(int triangle[][N], int size) {
	puts("\nTriangle:");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%2d ", triangle[i][j]);
		}
		printf("\n");
	}
}

int maximum(int triangle[], int size) {
	int max = -1;

	for (int i = 0; i < size; i++) {
		if (triangle[i] > max)
			max = triangle[i];
	}

	return max;
}