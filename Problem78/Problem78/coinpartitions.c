// To reduce numbers I can take % 1 000 000 for every coefficient in the table. It changes values, but divisibility by 1 000 000 holds.
#include <stdio.h>

#define MAX 20
#define M 1000000

void show(int table[][MAX + 1]);
void show_pn(int table[][MAX + 1]);
int sum(int table[], int start, int end);

int main(void) {
	int table[MAX + 1][MAX + 1] = { 0 };

	for (int i = 1; i <= MAX; i++)
		table[i][1] = 1;

	table[0][0] = 1;
	table[1][0] = 1;

	for (int n = 2; n <= MAX; n++) {
		for (int i = 2; i <= 1 + n / 2; i++) {
			table[n][i] = table[i - 1][0];
		}
		for (int j = n / 2 + 2; j <= n; j++) {
			table[n][j] = sum(table[j - 1], 2 * j - n - 1, j - 1) % M;
		}
		table[n][0] = sum(table[n], 0, MAX) % M;
	}

	show(table);

	show_pn(table);

	return 0;
}

void show(int table[][MAX + 1]) {
	for (int i = 0; i < MAX + 1; i++) {
		for (int j = 0; j < MAX + 1; j++) {
			printf("%4d ", table[i][j]);
		}
		printf("\n");
	}
}

void show_pn(int table[][MAX + 1]) {
	for (int i = 0; i < MAX + 1; i++) {
		printf("%20d \n", table[i][0]);
		if (table[i][0] == 0) {
			break;
		}
	}
}

int sum(int table[], int start, int end) {
	int sum = 0;

	for (int i = start; i <= end; i++)
		sum += table[i];

	return sum;
}