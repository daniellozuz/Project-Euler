#include <stdio.h>

#define LEN 200

void show(int number[]);
void multiply(int number[], int n);
void add(int number[], int n[]);
int sum(int number[]);

int main(void) {
	int number[LEN] = { 0 };
	number[LEN - 1] = 1;

	for (int i = 1; i <= 100; i++) {
		multiply(number, i);
		show(number);
	}

	printf("Sum of the digits of 100 factorial: %d\n", sum(number));

	return 0;
}

void show(int number[]) {
	int i = 0;

	while (number[i] == 0)
		i++;

	while (i < LEN)
		printf("%d", number[i++]);

	printf("\n");
}

void multiply(int number[], int n) {
	int temp[LEN];

	for (int i = 0; i < LEN; i++)
		temp[i] = number[i];

	for (int i = 1; i < n; i++)
		add(number, temp);
}

void add(int number[], int n[]) {
	int carry = 0;

	for (int i = LEN - 1; i >= 0; i--) {
		number[i] = (carry = number[i] + n[i] + carry) % 10;
		carry /= 10;
	}
}

int sum(int number[]) {
	int result = 0;

	for (int i = 0; i < LEN; i++)
		result += number[i];

	return result;
}