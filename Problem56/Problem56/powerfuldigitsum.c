#include <stdio.h>

#define SIZE 200

void power(int number[], int base, int exponent);
void show(int number[]);
void multiply(int number[], int base);
void add(int number[], int copy[]);
int sum(int number[]);

int main(void) {
	int number[SIZE] = { 0 };
	int result;
	int best = 0;

	for (int a = 1; a < 100; a++) {
		for (int b = 1; b < 100; b++) {
			power(number, a, b);
			//show(number);
			result = sum(number);
			printf("%d\n", result);
			if (result > best)
				best = result;
		}
	}

	printf("The biggest sum of digits: %d\n", best);

	return 0;
}

void power(int number[], int base, int exp) {
	for (int i = 0; i < SIZE; i++)
		number[i] = 0;

	number[SIZE - 1] = base % 10;
	number[SIZE - 2] = (base / 10) % 10;

	for (int e = 1; e < exp; e++)
		multiply(number, base);
}

void multiply(int number[], int base) {
	int copy[SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++)
		copy[i] = number[i];

	for (int i = 1; i < base; i++)
		add(number, copy);
}

void add(int number[], int copy[]) {
	int carry = 0;

	for (int i = SIZE - 1; i >= 0; i--) {
		number[i] = (carry = number[i] + copy[i] + carry) % 10;
		carry /= 10;
	}
}

int sum(int number[]) {
	int result = 0;

	for (int i = 0; i < SIZE; i++)
		result += number[i];

	return result;
}

void show(int number[]) {
	int i = 0;

	while (number[i] == 0)
		i++;

	while (i < SIZE)
		printf("%d", number[i++]);

	printf("\n");
}