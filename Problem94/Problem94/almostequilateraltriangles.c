#include <stdio.h>
#include <math.h>

#define LIMIT 1000000000

int main(void) {
	long long a, b;
	long long h2, H;
	double h;
	long long sum = 0;

	// a must be odd, h must be natural
	for (a = 3; a < LIMIT / 3 + 1; a+=2) {
		b = a + 1;
		h2 = a*a - (b / 2)*(b / 2);
		h = sqrt(h2);
		H = (long long)h;
		if (h - (double)H < 0.00001) {
			if (H*H == h2) {
				printf("a = %lld, b = %lld, h^2 = %lld, h = %.6f, H = %lld\n", a, b, h2, h, H);
				sum += (a + a + b);
			}
		}
		
		b = a - 1;
		h2 = a*a - (b / 2)*(b / 2);
		h = sqrt(h2);
		H = (long long)h;
		if (h - (double)H < 0.00001) {
			if (H*H == h2) {
				printf("a = %lld, b = %lld, h^2 = %lld, h = %.6f, H = %lld\n", a, b, h2, h, H);
				sum += (a + a + b);
			}
		}
	}

	printf("Sum: %lld\n", sum);

	return 0;
}