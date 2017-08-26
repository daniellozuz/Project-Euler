#include <stdio.h>
#include <stdbool.h>

#define MAXP 100000000

bool isPyth(long long a, long long b, long long c);
bool goodTiling(long long a, long long b, long long c);
bool coprime(long long m, long long n);
bool bothOdd(long long m, long long n);
long long gcd(long long m, long long n);

int main(void) {
	/*
	int amount = 0;

	for (int a = 1; a <= MAXPER / 2; a++) {
		for (int b = a + 1; b <= MAXPER / 2; b++) {
			for (int c = b + 1; c <= MAXPER / 2 && c <= MAXPER - a - b; c++) {
				if (isPyth(a, b, c)) {
					if (goodTiling(a, b, c)) {
						printf("Triangle %d %d %d. It could be used for tiling. :)\n", a, b, c);
						amount++;
					}
				}
			}
		}
	}

	printf("There are %d triangles with perimeter below %d that could be used for tiling.\n", amount, MAXPER);
	*/

	// Pythagorean triangles (triples) can be generated using the following formulae:
	// a = k(m^2-n^2)
	// b = k(2mn)
	// c = k(m^2+n^2)
	// m,n,k are positive integers
	// m > n
	// m,n are coprimes
	// m,n are not both odd

	long long amount = 0;

	for (long long k = 1; k < MAXP; k++) {
		for (long long n = 1; (k * 2 * n) < MAXP && (k*n*n) < MAXP; n++) {
			for (long long m = n + 1; (k*m*m) < MAXP && (2 * k*m*n) < MAXP; m++) {
				long long a = k*(m*m - n*n);
				long long b = k * 2 * m*n;
				long long c = k*(m*m + n*n);
				if (a + b + c < MAXP) {
					// It always is Pythagorean
					if (goodTiling((a < b) ? a : b, (a > b) ? a : b, c) && coprime(m, n) && !bothOdd(n, m)) {
						amount++;
						//printf("Triangle %lld %lld %lld. ", a, b, c);
						//printf("n = %lld, m = %lld ", n, m);
						//printf("Good for tiling. :)\n");
					}
				}
			}
		}
		//printf("%d\n", k);
	}

	printf("There are %lld triangles with perimeter below %d that could be used for tiling.\n", amount, MAXP);

	return 0;
}

bool isPyth(long long a, long long b, long long c) {
	return (a*a + b*b == c*c);
}

bool goodTiling(long long a, long long b, long long c) {
	//printf("%lld %% (%lld - %lld) == 0\n", c, b, a);
	return (c % (b - a) == 0);
}

bool coprime(long long m, long long n) {
	return (gcd(m, n) == 1);
}

long long gcd(long long a, long long b) {
	if (a == b)
		return a;

	if (a > b)
		return gcd(a - b, b);

	if (b > a)
		return gcd(a, b - a);
}

bool bothOdd(long long m, long long n) {
	return (m % 2 == 1 && n % 2 == 1);
}