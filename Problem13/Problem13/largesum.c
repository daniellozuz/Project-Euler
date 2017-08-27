#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define LEN 50

void show(int numbers[][LEN]);
void sum(int result[], int numbers[]);

int main(void) {
	int numbers[SIZE][LEN] = { 0 };
	int result[LEN + 2] = { 0 };
	FILE *fp;
	char ch;

	if ((fp = fopen("input.txt", "r")) == NULL) {
		fprintf(stderr, "Cannot open input.txt\n");
		exit(EXIT_FAILURE);
	}

	int i = 0;
	int j = 0;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') {
			i++;
			j = 0;
		}
		else {
			numbers[i][j++] = ch - 48;
		}
	}

	show(numbers);

	for (int i = 0; i < SIZE; i++)
		sum(result, numbers[i]);
		

	printf("Sum of the numbers above:\n");

	for (int i = 0; i < LEN + 2; i++)
		printf("%d", result[i]);

	printf("\n");

	return 0;
}

void show(int numbers[][LEN]) {
	for (int i = 0; i < SIZE; i++) {
		printf("  ");

		for (int j = 0; j < LEN; j++)
			printf("%d", numbers[i][j]);

		printf("\n");
	}
}

void sum(int result[], int numbers[]) {
	int carry = 0;

	for (int i = LEN-1; i >= 0; i--) {
		result[i+2] = (carry = result[i+2] + numbers[i] + carry) % 10;
		carry /= 10;
	}

	if (carry == 1)
		result[1]++;

	if (result[1] == 10) {
		result[1] = 0;
		result[0]++;
	}
}