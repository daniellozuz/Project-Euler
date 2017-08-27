#include <stdio.h>
#include <stdbool.h>

#define MAX 7654321

bool isprime(int number);
bool ispandigital(int number);

int main(void) {
	for (int i = 2; i < MAX; i++) {
		if (isprime(i) && ispandigital(i))
			printf("%d is a pandigital prime.\n", i);
	}

	return 0;
}

bool isprime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}

bool ispandigital(int number) {
	bool digits[10] = { false, false, false, false, false, false, false, false, false, false };
	int digit;
	int len = 0;

	while (number > 0) {
		digit = number % 10;
		digits[digit] = true;
		number /= 10;
		len++;
	}

	for (int i = 1; i <= len; i++) {
		if (digits[i] == false)
			return false;
	}

	return true;
}