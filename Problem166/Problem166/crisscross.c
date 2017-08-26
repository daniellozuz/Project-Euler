// Remark: The algorithm may be sped up, the core sum turns out to be S as well (1 less for loop)

#include <stdio.h>

void show(int grid[][4], int sum);

int main(void) {
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, S;
	int result = 0;

	for (a = 0; a <= 9; a++) {
		for (c = 0; c <= 9; c++) {
			for (d = 0; d <= 9; d++) {
				for (f = 0; f <= 9; f++) {
					for (g = 0; g <= 9; g++) {
						for (h = 0; h <= 9; h++) {
							for (j = 0; j <= 9; j++) {
								for (k = 0; k <= 9; k++) {
									for (o = 0; o <= 9; o++) {
										S = c + g + k + o;
										b = S - a - c - d;
										e = S - f - g - h;
										p = S - a - f - k;
										l = S - d - h - p;
										i = S - j - k - l;
										m = S - a - e - i;
										n = S - m - o - p;
										if (a + b + c + d == S && e + f + g + h == S && i + j + k + l == S && m + n + o + p == S && a + e + i + m == S &&
											b + f + j + n == S && c + g + k + o == S && d + h + l + p == S && a + f + k + p == S && d + g + j + m == S &&
											b >= 0 && e >= 0 && p >= 0 && l >= 0 && i >= 0 && m >= 0 && n >= 0 &&
											b <= 9 && e <= 9 && p <= 9 && l <= 9 && i <= 9 && m <= 9 && n <= 9) {
											result++;
											
											if (result % 100000 == 8) {
												int grid[4][4];
												grid[0][0] = a; grid[0][1] = b; grid[0][2] = c; grid[0][3] = d;
												grid[1][0] = e; grid[1][1] = f; grid[1][2] = g; grid[1][3] = h;
												grid[2][0] = i; grid[2][1] = j; grid[2][2] = k; grid[2][3] = l;
												grid[3][0] = m; grid[3][1] = n; grid[3][2] = o; grid[3][3] = p;

												show(grid, S);
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

	printf("In %d ways\n", result);

	return 0;
}

void show(int grid[][4], int sum) {
	printf("Grid: (%d)\n", sum);
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++)
			printf("%d ", grid[r][c]);
		printf("\n");
	}
	printf("\n");
}