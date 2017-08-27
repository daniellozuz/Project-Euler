#include <stdio.h>
#include <stdbool.h>

#define LIMIT 100000000
#define SIZE 200

bool isPalindromic(int number);
bool isDistinct(int sum, int sums[]);

int main(void) {
	int amount = 0;
	long long result = 0;
	long long sums[SIZE] = { 0 };

	for (int start = 1; start*start <= LIMIT; start++) {
		int sum = 0;
		int i = start;

		while (sum + i*i <= LIMIT) {
			sum += i*i;
			if (sum - i*i != 0 && isPalindromic(sum) && isDistinct(sum, sums)) {
				printf("%d\n", sum);
				sums[amount] = sum;
				amount++;
				result += sum;
			}
			i++;
		}
	}

	printf("There are %d such numbers below %d.\n", amount, LIMIT);
	printf("They sum up to %lld.\n", result);

	return 0;
}

bool isPalindromic(int number) {
	int n = number;
	int len = 0;
	int digits[8] = { -1 };

	while (n >= 1) {
		digits[len] = n % 10;
		n /= 10;
		len++;
	}

	for (int i = 0; i < len / 2; i++) {
		if (digits[i] != digits[len - i - 1])
			return false;
	}

	return true;
}

bool isDistinct(int sum, int sums[]) {
	for (int i = 0; i < SIZE; i++) {
		if (sum == sums[i])
			return false;
	}

	return true;
}