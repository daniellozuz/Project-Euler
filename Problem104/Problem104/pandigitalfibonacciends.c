#include <stdio.h>
#include <stdbool.h>

#define SIZE 75000
#define LIMIT 300000

void add(int sum[], int sth[]);
void swap(int result[], int sth[]);
void show(int num[]);
bool isPandigital(int num[]);

int main(void) {

	int n1[SIZE] = { 0 };
	int n2[SIZE] = { 0 };
	n1[SIZE - 1] = 1;
	n2[SIZE - 1] = 1;

	show(n1);
	show(n2);

	for (int k = 3; k <= LIMIT; k++) {
		int temp[SIZE] = { 0 };
		swap(temp, n2);
		add(n2, n1);
		swap(n1, temp);
		if (k > 100 && isPandigital(n2)) {
			show(n2);
			printf("The %d-th number satisfies the criteria.\n", k);
		}
		if (k % (LIMIT / 10) == 0)
			printf("K: %d\n", k);
	}

	return 0;
}

void add(int sum[], int sth[]) {
	int carry = 0;

	for (int i = SIZE - 1; i >= 0; i--) {
		sum[i] = (carry = sum[i] + sth[i] + carry) % 10;
		carry /= 10;
	}
}

void swap(int result[], int sth[]) {
	for (int i = 0; i < SIZE; i++)
		result[i] = sth[i];
}

void show(int num[]) {
	int i = 0;

	while (num[i] == 0)
		i++;

	while (i < SIZE)
		printf("%d", num[i++]);

	printf("\n");
}

bool isPandigital(int num[]) {
	// last 9
	bool last[10] = { false, false, false, false, false, false, false, false, false, false };

	for (int i = SIZE - 9; i < SIZE; i++) {
		last[num[i]] = true;
	}

	for (int i = 1; i < 10; i++) {
		if (!last[i])
			return false;
	}

	// first 9
	bool first[10] = { false, false, false, false, false, false, false, false, false, false };

	int i = 0;
	while (num[i] == 0)
		i++;

	for (int j = 0; j < 9; j++) {
		first[num[i + j]] = true;
	}

	for (int i = 1; i < 10; i++) {
		if (!first[i])
			return false;
	}

	return true;
}