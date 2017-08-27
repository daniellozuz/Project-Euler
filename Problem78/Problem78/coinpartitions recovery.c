#include <stdio.h>

#define MAX 350

void show(long long table[][MAX + 1]);
void show_pn(long long table[][MAX + 1]);
long long sum(long long table[], int start, int end);

int main(void) {
	long long table[MAX + 1][MAX + 1] = { 0 };

	for (int i = 1; i <= MAX; i++)
		table[i][1] = 1;

	table[0][0] = 1;
	table[1][0] = 1;

	for (int n = 2; n <= MAX; n++) {
		for (int i = 2; i <= 1 + n / 2; i++) {
			table[n][i] = table[i - 1][0];
		}
		for (int j = n / 2 + 2; j <= n; j++) {
			table[n][j] = sum(table[j - 1], 2 * j - n - 1, j - 1);
		}
		table[n][0] = sum(table[n], 0, MAX);
	}

	show(table);

	show_pn(table);

	return 0;
}

void show(long long table[][MAX + 1]) {
	for (int i = 0; i < MAX + 1; i++) {
		for (int j = 0; j < MAX + 1; j++) {
			printf("%4lld ", table[i][j]);
		}
		printf("\n");
	}
}

void show_pn(long long table[][MAX + 1]) {
	for (int i = 0; i < MAX + 1; i++) {
		printf("%20lld \n", table[i][0]);
	}
}

long long sum(long long table[], int start, int end) {
	long long sum = 0;

	for (int i = start; i <= end; i++)
		sum += table[i];

	return sum;
}