#include <stdio.h>
#include <stdbool.h>

#define LIMIT 999999999999999
#define TERMS 50

int sumOfDigits(long long number);
bool hasProperty(long long number, int sum);
bool isDistinct(long long pow, long long sequence[]);
void show(long long sequence[]);

int main(void) {
	int sum;
	int amount = 0;
	long long sequence[TERMS] = { 0 };
	
	for (int i = 2; i <= sumOfDigits(LIMIT); i++) {
		long long pow = i;
		while (pow < LIMIT) {
			sum = sumOfDigits(pow);
			if (hasProperty(pow, sum) && isDistinct(pow, sequence)) {
				sequence[amount++] = pow;
				printf("Number: %lld is a term of the sequence.\n", pow, amount);
			}

			pow *= i;
		}
	}

	show(sequence);

	return 0;
}

int sumOfDigits(long long number) {
	int sum = 0;

	while (number >= 1) {
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

bool hasProperty(long long number, int sum) {
	if (sum == 1)
		return false;

	while (number % sum == 0)
		number /= sum;

	if (number == 1)
		return true;

	return false;
}

bool isDistinct(long long pow, long long sequence[]) {
	for (int i = 0; i < TERMS; i++) {
		if (pow == sequence[i])
			return false;
	}

	return true;
}

void show(long long sequence[]) {
	int amount = 0;
	long long temp;

	for (int i = 0; i < TERMS - 1; i++) {
		for (int j = i + 1; j < TERMS; j++) {
			if (sequence[i] > sequence[j]) {
				temp = sequence[i];
				sequence[i] = sequence[j];
				sequence[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < TERMS; i++) {
		if (sequence[i] >= 10)
			printf("%2d: %lld\n", ++amount, sequence[i]);
	}

	printf("There are %d terms in the sequence.\n", amount);
}