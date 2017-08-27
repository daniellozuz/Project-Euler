#include <stdio.h>
#include <stdbool.h>

bool isTriplet(int a, int b, int c);

int main(void) {


	for (int a = 1; a < 1000; a++) {
		for (int b = 1; b < 1000 - a; b++) {
			int c = 1000 - a - b;
			if (isTriplet(a, b, c))
				printf("%d\n", a*b*c);
		}
	}

	return 0;
}

bool isTriplet(int a, int b, int c) {
	return (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a);
}