#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number);

int main(void) {
	int result = 0;
	long long sum = 0;

	for (int n = 1; n <= 100000000; n++) {
		bool ok = true;

		for (int i = 1; i*i <= n; i++) {
			if (n % i == 0) {
				if (!isPrime(i + n / i)) {
					ok = false;
					break;
				}
			}
		}

		if (ok) {
			printf("Number %d satisfies the condition.\n", n);
			result++;
			sum += n;
		}
	}

	printf("There are %d such numbers, which add up to %lld\n", result, sum);

	return 0;
}

bool isPrime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}