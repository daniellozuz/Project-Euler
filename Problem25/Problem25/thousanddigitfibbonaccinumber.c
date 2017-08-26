#include <stdio.h>

#define SIZE 1000
#define LIMIT 10000

void copy(int copy[], int number[]);
void add(int sum[], int added[]);
void show(int number[]);
int digits(int number[]);

int main(void) {
	int temp[SIZE] = { 0 };
	int number1[SIZE] = { 0 };
	int number2[SIZE] = { 0 };
	number1[SIZE - 1] = 1;
	number2[SIZE - 1] = 1;

	//show(number1);
	//show(number2);

	for (int i = 3; i <= LIMIT; i++) {
		copy(temp, number2);
		add(number2, number1);
		copy(number1, temp);
		//show(number2);
		if (digits(number2) == SIZE) {
			printf("The first Fibonacci number to have %d digits is the %d term of the Fibonacci sequence.\n", SIZE, i);
			break;
		}
	}

	return 0;
}

void copy(int copy[], int number[]) {
	for (int i = 0; i < SIZE; i++)
		copy[i] = number[i];
}

void add(int sum[], int added[]) {
	int carry = 0;

	for (int i = SIZE - 1; i >= 0; i--) {
		sum[i] = (carry = sum[i] + added[i] + carry) % 10;
		carry /= 10;
	}
}

void show(int number[]) {
	int i = 0;

	while (number[i] == 0)
		i++;

	while (i < SIZE)
		printf("%d", number[i++]);

	printf("\n");
}

int digits(int number[]) {
	int i = 0;

	while (number[i] == 0)
		i++;

	return SIZE - i;
}