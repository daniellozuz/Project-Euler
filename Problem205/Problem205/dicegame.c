#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int roll(int dice, int faces);
int increment(int v[], int size, int max);
int sum(int v[], int size);

int main(void) {
	// Visualization of a problem
	int peter = 0;
	int all = 0;

	srand((unsigned int)time(0));
	
	for (int i = 0; i < 100000; i++) {
		if (roll(9, 4) > roll(6, 6))
			peter++;
		all++;
	}

	printf("Peter won in %d out of %d rolls.\n", peter, all);
	puts("Unfortunatelly this method is not precise enough.");

	// Proper solution //
	
	// Peter
	int vP[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int sumsP[37] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	int sumP;

	while ((vP[0] != 4) || (vP[1] != 4) || (vP[2] != 4) || (vP[3] != 4) || (vP[4] != 4) || (vP[5] != 4) || (vP[6] != 4) || (vP[7] != 4) || (vP[8] != 4)) {
		sumP = increment(vP, 9, 4);
		sumsP[sumP] += 1;
	}

	printf("Possibilities Peter (%d):\n", sum(sumsP, 36));
	for (int i = 1; i <= 36; i++) {
		if (sumsP[i] > 0)
			printf("%d - %d\n", i, sumsP[i]);
	}

	// Colin
	int vC[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int sumsC[37] = { 0, 0, 0, 0, 0, 0, 1 };
	int sumC;

	while ((vC[0] != 6) || (vC[1] != 6) || (vC[2] != 6) || (vC[3] != 6) || (vC[4] != 6) || (vC[5] != 6)) {
		sumC = increment(vC, 6, 6);
		sumsC[sumC] += 1;
	}

	printf("Possibilities Colin (%d):\n", sum(sumsC, 36));
	for (int i = 1; i <= 36; i++) {
		if (sumsC[i] > 0)
			printf("%d - %d\n", i, sumsC[i]);
	}

	long long numerator = 0;
	// Multiply out appropriate terms
	for (int i = 9; i <= 36; i++) {
		for (int j = 6; j < i; j++) {
			numerator += sumsP[i] * sumsC[j];
		}
	}
	printf("Peter wins in %lld out of %lld rolls\n", numerator, 12230590464);
	printf("That means probability of: %.7f\n", numerator / 12230590464.0);

	return 0;
}

int roll(int dice, int faces) {
	int result = 0;
	int number;

	for (int i = 1; i <= dice; i++) {
		number = rand() % faces + 1;
		result += number;
	}

	return result;
}

int increment(int v[], int size, int max) {
	int sum = 0;
	
	v[size - 1] += 1;
	for (int i = size-1; i > 0; i--) {
		if (v[i] == max + 1) {
			v[i] = 1;
			v[i - 1] += 1;
		}
	}

	for (int i = 0; i < size; i++)
		sum += v[i];

	return sum;
}

int sum(int v[], int size) {
	int result = 0;

	for (int i = 1; i <= size; i++)
		result += v[i];

	return result;
}