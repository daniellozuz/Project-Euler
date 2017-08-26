#include <stdio.h>

#define SIZE 100

void factor(int * product, int size);
void show(int * product, int size);
void reduce(int * product1, int * product2, int size);
long long multiply(int * product, int size);

int main(void) {
	// Combinations 20 out of 40  40!/((40-20)!*20!)
	int product1[SIZE] = { 0 }; // 40 * 39 * ... * 22 * 21
	int product2[SIZE] = { 0 }; // 20!
	long long answer;

	for (int i = 2; i <= 20; i++) {
		product2[i - 2] = i;
	}
	
	for (int i = 21; i <= 40; i++) {
		product1[i - 21] = i;
	}
	show(product1, SIZE);
	factor(product1, SIZE);
	show(product1, SIZE);
	factor(product2, SIZE);
	show(product2, SIZE);
	reduce(product1, product2, SIZE);
	show(product1, SIZE);

	answer = multiply(product1, SIZE);

	printf("\nAnswer: %lld\n\n", answer);
	
	return 0;
}

void factor(int * product, int size) {
	int temp[SIZE] = { 0 };
	int n = 0;
	int j;
	for (int i = 0; i < size; i++) {
		j = 2;
		while (product[i] > 1) {
			if (product[i] % j == 0) {
				temp[n++] = j;
				product[i] /= j;
			}
			else
				j++;
		}
	}

	for (int i = 0; i < SIZE; i++)
		product[i] = temp[i];
}

void show(int * product, int size) {
	for (int i = 0; i < size; i++) {
		if (product[i] > 1)
			printf("%d ", product[i]);
	}
	putchar('\n');
}

void reduce(int * product1, int * product2, int size) {
	for (int i = 0; i < SIZE; i++) {
		int j = 0;
		while (product2[i] > 1) {
			if (product2[i] == product1[j]) {
				product2[i] = 0;
				product1[j] = 0;
				break;
			}
			j++;
		}
	}
}

long long multiply(int * product, int size) {
	long long result = 1LL;
	
	for (int i = 0; i < size; i++) {
		if (product[i] > 1)
			result *= product[i];
	}

	return result;
}