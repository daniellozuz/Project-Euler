#include <stdio.h>

#define N 15

void show(int triangle[][N], int size);
int max(int triangle[], int size);

int main(void) {
	int triangle[N][N] = { 
		{ 75 },
		{ 95, 64 },
		{ 17, 47, 82 },
		{ 18, 35, 87, 10 },
		{ 20,  4, 82, 47, 65 },
		{ 19,  1, 23, 75,  3, 34 },
		{ 88,  2, 77, 73,  7, 63, 67 },
		{ 99, 65,  4, 28,  6, 16, 70, 92 },
		{ 41, 41, 26, 56, 83, 40, 80, 70, 33 },
		{ 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 },
		{ 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 },
		{ 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 },
		{ 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 },
		{ 63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 },
		{  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23 } 
	};

	show(triangle, N);

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

	show(triangle, N);

	printf("\nMaximum: %d\n", max(triangle[N - 1], N));

	return 0;
}

void show(int triangle[][N], int size) {
	puts("\nTriangle:");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d ", triangle[i][j]);
		}
		printf("\n");
	}
}

int max(int triangle[], int size) {
	int max = -1;
	
	for (int i = 0; i < size; i++) {
		if (triangle[i] > max)
			max = triangle[i];
	}

	return max;
}