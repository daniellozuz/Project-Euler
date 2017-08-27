#include <stdio.h>
#include <stdbool.h>

bool rightangle(int a, int b, int c);

int main(void) {
	int c;
	int maxp = 0;;
	int maxsolutions = 0;

	for (int p = 3; p <= 1000; p++) {
		int solutions = 0;
		for (int a = 1; a <= p / 2; a++) {
			for (int b = 1; b <= p / 2; b++) {
				c = p - a - b;
				if (a > b && b > c && c > 0 && rightangle(a, b, c)) {
					//printf("The triangle of lengths a = %d, b = %d, c = %d is right-angled. (perimeter = %d)\n", a, b, c, p);
					solutions++;
				}
			}
		}
		if (solutions > maxsolutions) {
			maxsolutions = solutions;
			maxp = p;
		}
	}

	printf("Maximised number of solutions for p = %d\n", maxp);

	return 0;
}

bool rightangle(int a, int b, int c) {
	if (a*a + b*b == c*c)
		return true;
	if (a*a + c*c == b*b)
		return true;
	if (b*b + c*c == a*a)
		return true;

	return false;
}