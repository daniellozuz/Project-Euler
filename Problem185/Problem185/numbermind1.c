#include <stdio.h>
#include <stdbool.h>

bool checkA(int a);
bool checkB(int a, int b);
bool checkC(int a, int b, int c);
bool checkD(int a, int b, int c, int d);
bool checkE(int a, int b, int c, int d, int e);

int main(void) {
	int amount = 0;

	for (int a = 1; a <= 9; a++) {
		if (!checkA(a))
			continue;
		for (int b = 0; b <= 9; b++) {
			if (!checkB(a, b))
				continue;
			for (int c = 0; c <= 9; c++) {
				if (!checkC(a, b, c))
					continue;
				for (int d = 0; d <= 9; d++) {
					if (!checkD(a, b, c, d))
						continue;
					for (int e = 0; e <= 9; e++) {
						if (!checkE(a, b, c, d, e))
							continue;
						printf("ABCDE = %d%d%d%d%d\n", a, b, c, d, e);
						amount++;
					}
				}
			}
		}
	}
	printf("%d possibilities.\n", amount);

	return 0;
}

bool checkA(int a) {
	return (a != 7);
}

bool checkB(int a, int b) {
	return (b != 0 &&
		10 * a + b != 34 &&
		10 * a + b != 12);
}

bool checkC(int a, int b, int c) {
	return (c != 7 &&
		100 * a + c != 301 &&
		10 * b + c != 41 &&
		100 * a + c != 105 &&
		10 * b + c != 25 &&
		100 * a + 10 * b + c != 903 &&
		100 * a + 10 * b + c != 394 &&
		100 * a + 10 * b + c != 515);
}

bool checkD(int a, int b, int c, int d) {
	return (d != 9 &&
		1000 * a + d != 3000 &&
		100 * b + d != 400 &&
		10 * c + d != 10 &&
		1000 * a + d != 1003 &&
		100 * b + d != 203 &&
		10 * c + d != 53 &&
		1000 * a + 100 * b + d != 9004 &&
		1000 * a + 10 * c + d != 9034 &&
		100 * b + 10 * c + d != 34 &&
		1000 * a + 100 * b + d != 3905 &&
		1000 * a + 10 * c + d != 3045 &&
		100 * +10 * c + d != 945 &&
		1000 * a + 100 * b + d != 5104 &&
		1000 * a + 10 * c + d != 5054 &&
		100 * b + 10 * c + d != 154);
}

bool checkE(int a, int b, int c, int d, int e) {
	return (e != 4 &&
		10000 * a + e != 30009 &&
		1000 * b + e != 4009 &&
		100 * c + e != 109 &&
		10 * d + e != 9 &&
		10000 * a + e != 10001 &&
		1000 * b + e != 2001 &&
		100 * c + e != 501 &&
		10 * d + e != 31 &&
		10000 * a + 1000 * b + e != 90002 &&
		10000 * a + 100 * c + e != 90302 &&
		10000 * a + 10 * d + e != 90042 &&
		1000 * b + 100 * c + e != 302 &&
		1000 * b + 10 * d + e != 42 &&
		100 * c + 10 * d + e != 342&&
		10000 * a + 1000 * b + e != 39008 &&
		10000 * a + 100 * c + e != 30408 &&
		10000 * a + 10 * d + e != 30058 &&
		1000 * b + 100 * c + e != 9408 &&
		1000 * b + 10 * d + e != 9058 &&
		100 * c + 10 * d + e != 458 &&
		10000 * a + 1000 * b + e != 51005 &&
		10000 * a + 100 * c + e != 50505 &&
		10000 * a + 10 * d + e != 50045 &&
		1000 * b + 100 * c + e != 1505 &&
		1000 * b + 10 * d + e != 1045 &&
		100 * c + 10 * d + e != 545);
}