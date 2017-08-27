#include <stdio.h>
#include <stdbool.h>

#define SIZE 750000
#define MAXP (SIZE*2)

bool coprime(long long m, long long n);
bool bothOdd(long long m, long long n);
long long gcd(long long m, long long n);

int main(void) {
	// Perimeters are always even numbers (index = perimeter/2 - 1)
	char perims[SIZE] = { 0 };
	int amount = 0;

	for (long long k = 1; k <= MAXP; k++) {
		for (long long n = 1; (k * 2 * n) <= MAXP && (k*n*n) <= MAXP; n++) {
			for (long long m = n + 1; (k*m*m) <= MAXP && (2 * k*m*n) <= MAXP; m++) {
				long long a = k*(m*m - n*n);
				long long b = k * 2 * m*n;
				long long c = k*(m*m + n*n);

				long long p = a + b + c;
				if (p <= MAXP && coprime(m, n) && !bothOdd(n, m)) {
					if (perims[p / 2 - 1] < 2)
						perims[p / 2 - 1]++;
				}				
			}
		}
	}

	for (int i = 0; i < SIZE; i++) {
		if (perims[i] == 1)
			amount++;
	}

	printf("There are %d such triangles below %d.\n", amount, MAXP);

	return 0;
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