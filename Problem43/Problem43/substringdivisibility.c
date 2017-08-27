#include <stdio.h>
#include <stdbool.h>

bool palindromic(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

int main(void) {

	long long sum = 0;

	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				for (int d = 0; d <= 9; d++) {
					if (d % 2 != 0)
						continue;

					for (int e = 0; e <= 9; e++) {
						if ((100 * c + 10 * d + e) % 3 != 0)
							continue;

						for (int f = 0; f <= 9; f++) {
							if (f % 5 != 0)
								continue;

							for (int g = 0; g <= 9; g++) {
								if ((100 * e + 10 * f + g) % 7 != 0)
									continue;

								for (int h = 0; h <= 9; h++) {
									if ((100 * f + 10 * g + h) % 11 != 0)
										continue;

									for (int i = 0; i <= 9; i++) {
										if ((100 * g + 10 * h + i) % 13 != 0)
											continue;

										for (int j = 0; j <= 9; j++) {
											if ((100 * h + 10 * i + j) % 17 != 0)
												continue;

											if (!palindromic(a, b, c, d, e, f, g, h, i, j))
												continue;

											printf("Number %d%d%d%d%d%d%d%d%d%d satisfies all criteria.\n", a, b, c, d, e, f, g, h, i, j);
											sum += (1000000000LL * a + 100000000LL * b + 10000000LL * c + 1000000LL * d + 100000LL * e + 10000LL * f + 1000LL * g + 100LL * h + 10LL * i + j);
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

	printf("Sum of the numbers: %lld\n", sum);

	return 0;
}

bool palindromic(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
	int n[10];
	n[0] = a; n[1] = b; n[2] = c; n[3] = d; n[4] = e; n[5] = f; n[6] = g; n[7] = h; n[8] = i; n[9] = j;

	for (int i = 0; i <= 8; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if (n[i] == n[j])
				return false;
		}
	}

	return true;
}