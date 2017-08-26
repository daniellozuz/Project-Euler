#include <stdio.h>

#define LEN 1000

void twice(int number[]);
void show(int number[]);

int main(void) {
	int number[LEN] = { 0 };
	number[LEN - 1] = 1;

	for (int i = 0; i < 1000; i++)
		twice(number);

	show(number);

	int sum = 0;
	for (int i = 0; i < LEN; i++)
		sum += number[i];

	printf("The sum of the digits of the number above (2 ^ 1000) is %d\n", sum);

	return 0;
}

void twice(int number[]) {
	int carry = 0;
	int new_number[LEN] = { 0 };

	for (int i = LEN - 1; i >= 0; i--) {
		new_number[i] = (2 * number[i] + carry) % 10;
		carry = (2 * number[i] + carry) / 10;
	}

	for (int i = 0; i < LEN; i++)
		number[i] = new_number[i];
}

void show(int number[]) {
	int i = 0;
	while (number[i] == 0)
		i++;

	while (i < LEN) {
		printf("%d", number[i]);
		i++;
	}

	printf("\n");
}