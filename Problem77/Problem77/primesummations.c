#include <stdio.h>
#include <stdbool.h>

#define NUMBER 71
#define MAXVECTOR (NUMBER/2)
#define PRIMES 20
#define MAXSTORAGE 6000

int recursion(int number, int primes[], int vector[], int index, int storage[][MAXVECTOR], int start);
void sort(int storage[][MAXVECTOR]);
void showall(int storage[][MAXVECTOR]);
void showsolution(int storage[][MAXVECTOR]);
void remove_duplicates(int storage[][MAXVECTOR]);
void sortvector(int sortedvector[], int vector[], int index);
bool distinct(int sortedvector[], int storage[][MAXVECTOR]);

int main(void) {
	int number = NUMBER;
	int primes[PRIMES] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
	int vector[MAXVECTOR] = { 0 };
	int storage[MAXSTORAGE][MAXVECTOR] = { 0 };
	int solutions;

	solutions = recursion(number, primes, vector, 0, storage, 0);
	printf("%d solutions.\n", solutions);

	sort(storage);
	remove_duplicates(storage);
	//showall(storage);
	showsolution(storage);

	return 0;
}

int recursion(int number, int primes[], int vector[], int index, int storage[][MAXVECTOR], int start) {
	static int solutions = 0;
	if (number > 1) {
		for (int i = start; i < PRIMES && primes[i] <= number; i++) {
			vector[index] = primes[i];
			//printf("Calling recursion: number - %d, index - %d\n", number, index);
			recursion(number - primes[i], primes, vector, index + 1, storage, i);
		}
	}
	else if (number == 0) {
		// Sort vector, if it is distinct, insert it
		int sortedvector[MAXVECTOR];
		for (int i = 0; i < MAXVECTOR; i++)
			sortedvector[i] = 0;
		sortvector(sortedvector, vector, index);
		if (distinct(sortedvector, storage)) {
			for (int i = 0; i < index; i++) {
				//printf("%d ", vector[i]);
				storage[solutions][i] = sortedvector[i];
			}
			//printf("\n");
			solutions++;
		}
	}

	return solutions;
}

void sort(int storage[][MAXVECTOR]) {
	for (int i = 0; i < MAXSTORAGE; i++) {
		for (int j1 = 0; j1 < MAXVECTOR - 1; j1++) {
			for (int j2 = j1 + 1; j2 < MAXVECTOR; j2++) {
				if (storage[i][j1] < storage[i][j2]) {
					int temp = storage[i][j1];
					storage[i][j1] = storage[i][j2];
					storage[i][j2] = temp;
				}
			}
		}
	}
}

void showall(int storage[][MAXVECTOR]) {
	for (int i = 0; i < MAXSTORAGE; i++) {
		for (int j = 0; j < MAXVECTOR; j++) {
			printf("%d ", storage[i][j]);
		}
		printf("\n");
	}
}

void remove_duplicates(int storage[][MAXVECTOR]) {
	for (int i1 = 0; i1 < MAXSTORAGE - 1; i1++) {
		if (storage[i1][0] != 0) {
			for (int i2 = i1 + 1; i2 < MAXSTORAGE; i2++) {
				if (storage[i2][0] != 0) {
					bool thesame = true;
					for (int j = 0; j < MAXVECTOR; j++) {
						if (storage[i1][j] != storage[i2][j])
							thesame = false;
					}
					if (thesame) {
						for (int j = 0; j < MAXVECTOR; j++) {
							storage[i2][j] = 0;
						}
					}
				}
			}
		}
	}
}

void showsolution(int storage[][MAXVECTOR]) {
	int solutions = 0;

	for (int i = 0; i < MAXSTORAGE; i++) {
		if (storage[i][0] != 0) {
			for (int j = 0; j < MAXVECTOR; j++) {
				if (storage[i][j] != 0)
					printf("%d ", storage[i][j]);
			}
			printf("\n");
			solutions++;
		}
	}

	printf("There are %d solutions.\n", solutions);
}

void sortvector(int sortedvector[], int vector[], int index) {
	for (int i = 0; i < index; i++)
		sortedvector[i] = vector[i];

	for (int i1 = 0; i1 < index - 1; i1++) {
		for (int i2 = i1 + 1; i2 < index; i2++) {
			if (sortedvector[i1] < sortedvector[i2]) {
				int temp = sortedvector[i1];
				sortedvector[i1] = sortedvector[i2];
				sortedvector[i2] = temp;
			}
		}
	}
}

bool distinct(int sortedvector[], int storage[][MAXVECTOR]) {
	for (int i = 0; i < MAXSTORAGE; i++) {
		if (storage[i][0] != 0) {
			bool thesame = true;
			for (int j = 0; j < MAXVECTOR; j++) {
				if (sortedvector[j] != storage[i][j])
					thesame = false;
			}
			if (thesame)
				return false;
		}
	}

	return true;
}