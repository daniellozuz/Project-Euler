#include <stdio.h>
#include <stdbool.h>

#define START	1000
#define END		9999

void Tri(int start, int end, int tri[]);
void Sq(int start, int end, int sq[]);
void Pent(int start, int end, int pent[]);
void Hex(int start, int end, int hex[]);
void Hept(int start, int end, int hept[]);
void Oct(int start, int end, int oct[]);

void check(int first2, int groups[], int figurate[][100], int stop);

int main(void) {
	int tri[100] = { 0 };
	int sq[100] = { 0 };
	int pent[100] = { 0 };
	int hex[100] = { 0 };
	int hept[100] = { 0 };
	int oct[100] = { 0 };

	int figurate[6][100] = { 0 };

	Tri(START, END, figurate[0]);
	Sq(START, END, figurate[1]);
	Pent(START, END, figurate[2]);
	Hex(START, END, figurate[3]);
	Hept(START, END, figurate[4]);
	Oct(START, END, figurate[5]);

	for (int i = 0; i < 30; i++) {
		int l2 = figurate[5][i] % 100;
		int groups[6] = { true, true, true, true, true, false };
		//printf("Starting from: %d", figurate[5][i]);
		check(l2, groups, figurate, figurate[5][i]);
	}

	return 0;
}

void Tri(int start, int end, int tri[]) {
	int amount = 0;

	printf("Triangular:\n");

	for (int i = 1; i <= end; i++) {
		int num = (i*(i + 1)) / 2;
		if ( num > end)
			break;

		if (num >= start && num % 100 >= 10) {
			tri[amount++] = num;
			printf("%4d  ", num);
			if (amount % 10 == 0)
				printf("\n");
		}
	}

	printf("\nThere are %d valid triangular numbers.\n", amount);
}

void Sq(int start, int end, int sq[]) {
	int amount = 0;

	printf("Square:\n");

	for (int i = 1; i <= end; i++) {
		int num = i*i;
		if (num > end)
			break;

		if (num >= start && num % 100 >= 10) {
			sq[amount++] = num;
			printf("%4d  ", num);
			if (amount % 10 == 0)
				printf("\n");
		}
	}

	printf("\nThere are %d valid square numbers.\n", amount);
}

void Pent(int start, int end, int pent[]) {
	int amount = 0;

	printf("Pentagonal:\n");

	for (int i = 1; i <= end; i++) {
		int num = (i*(3 * i - 1)) / 2;
		if (num > end)
			break;

		if (num >= start && num % 100 >= 10) {
			pent[amount++] = num;
			printf("%4d  ", num);
			if (amount % 10 == 0)
				printf("\n");
		}
	}

	printf("\nThere are %d valid pentagonal numbers.\n", amount);
}

void Hex(int start, int end, int hex[]) {
	int amount = 0;

	printf("Hexagonal:\n");

	for (int i = 1; i <= end; i++) {
		int num = i*(2 * i - 1);
		if (num > end)
			break;

		if (num >= start && num % 100 >= 10) {
			hex[amount++] = num;
			printf("%4d  ", num);
			if (amount % 10 == 0)
				printf("\n");
		}
	}

	printf("\nThere are %d valid hexagonal numbers.\n", amount);
}

void Hept(int start, int end, int hept[]) {
	int amount = 0;

	printf("Heptagonal:\n");

	for (int i = 1; i <= end; i++) {
		int num = (i*(5 * i - 3)) / 2;
		if (num > end)
			break;

		if (num >= start && num % 100 >= 10) {
			hept[amount++] = num;
			printf("%4d  ", num);
			if (amount % 10 == 0)
				printf("\n");
		}
	}

	printf("\nThere are %d valid heptagonal numbers.\n", amount);
}

void Oct(int start, int end, int oct[]) {
	int amount = 0;

	printf("Octagonal:\n");

	for (int i = 1; i <= end; i++) {
		int num = i*(3 * i - 2);
		if (num > end)
			break;

		if (num >= start && num % 100 >= 10) {
			oct[amount++] = num;
			printf("%4d  ", num);
			if (amount % 10 == 0)
				printf("\n");
		}
	}

	printf("\nThere are %d valid octagonal numbers.\n", amount);
}

void check(int first2, int groups[], int figurate[][100], int stop) {
	static bool found = false;


	if (!groups[0] && !groups[1] && !groups[2] && !groups[3] && !groups[4] && !groups[5] && stop/100 == first2) {
		printf("\n\nSolution: %d\n\n\n", stop);
		found = true;
	}
	if (!found) {
		for (int g = 0; g < 6; g++) {
			if (groups[g]) {
				for (int i = 0; i < 100; i++) {
					if (figurate[g][i] / 100 == first2) {
						int gr[6];
						for (int i = 0; i < 6; i++)
							gr[i] = groups[i];
						gr[g] = false;
						check(figurate[g][i] % 100, gr, figurate, stop);
						if (found)
							printf("Found.%d\n", figurate[g][i]);
					}
				}
			}
		}
	}
}