#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 1000000

bool isPrime(int number);
bool rotationsArePrime(int number);

int main(void) {
	int amount = 0;
	
	for (int i = 2; i < LIMIT; i++) {
		if (isPrime(i) && rotationsArePrime(i))
			amount++;
	}

	printf("There are %d such primes.\n", amount);
	
	return 0;
}

bool isPrime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}

bool rotationsArePrime(int number) {
	int n = number;
	int digits[6] = { -1 };
	int len = 0;

	while (n >= 1) {
		digits[len] = n % 10;
		n /= 10;
		len++;
	}

	for (int i = 0; i < len / 2; i++) {
		int temp = digits[i];
		digits[i] = digits[len - i - 1];
		digits[len - i - 1] = temp;
	}

	for (int i = 1; i < len; i++) {
		int digs[6] = { -1 };
		
		for (int j = 0; j < len; j++)
			digs[j] = digits[(j + i) % len];

		if (digs[0] != 0) {
			int num = 0;

			for (int j = 0; j < len; j++)
				num += digs[j] * (int)pow(10, len - j - 1);

			if (!isPrime(num))
				return false;
		}
		else
			return false;
	}

	return true;
}