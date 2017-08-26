// Takes 10 minutes to compute the result, but shows the possibilities in the same form as in the problem page. 

#include <stdio.h>

#define NUM 5

int ways(int number, int min, int seq[], int lvl);

int main(void) {
	int seq[NUM + 1] = { 0 };

	printf("There are %d different ways to write %d as a sum of at least 2 positive integers.\n", ways(NUM, NUM, seq, 0) - 1, NUM);

	return 0;
}

int ways(int number, int max, int seq[], int lvl) {
	static int sol = 0;
	int s[NUM + 1] = { 0 };
	for (int i = 0; i < NUM + 1; i++)
		s[i] = seq[i];

	if (number > 0) {
		for (int i = max; i >= 1; i--) {
			if (number - i == 0)
				sol++;
			s[lvl] = i;
			if (i == number && lvl != 0) {
				int j = 0;
				while (s[j] != 0)
					printf("%d ", s[j++]);
				printf("\n");
			}
			ways(number - i, i, s, lvl + 1);
		}
	}

	return sol;
}