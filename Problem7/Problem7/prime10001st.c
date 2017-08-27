#include <stdio.h>
#include <stdbool.h>

#define LIMIT 200000

void show(int * numbers, int amount);

int main(void) {
	int numbers[LIMIT] = { 0 };
	int prime;
	int i;

	for (i = 0; i < LIMIT; i++) {
		numbers[i] = i;
	}

	prime = 2;
	i = 2;
	while (prime < LIMIT) {
		while (prime * i < LIMIT) {
			numbers[prime * i] = 0;
			i++;
		}
		i = 2;

		prime++;
		for (int j = prime; j < LIMIT; j++) {
			if (numbers[j] >= prime) {
				prime = numbers[j];
				break;
			}
		}
	}

	//show(numbers, LIMIT);

	int cnt = 0;
	for (int i = 0; i < LIMIT; i++) {
		if (numbers[i] != 0)
			cnt++;

		if (cnt == 10001 + 1) {
			printf("10001st prime: %d\n\n", numbers[i]);
			break;
		}
	}

	return 0;
}

void show(int * numbers, int amount) {
	for (int i = 0; i < amount; i++) {
		printf("%d ", numbers[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
}