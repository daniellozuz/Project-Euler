#include <stdio.h>
#include <stdbool.h>

#define START 1000
#define END 9999

bool isprime(int number);
bool same(const int * tab1, const int * tab2);
int included(const int * tab, struct group * groups, int g);
void copyNumber(int number, struct group * groups);
void copyStructure(const struct number *, struct group *);
void showGroups(const struct group *);
void finalCheck(const struct group *);

struct number {
	int number;
	int digits[10];
};

struct group {
	int numbers[24];
	int digits[10];
};

int main(void) {
	int amount = 0;
	struct number * primes;
	struct number temp = { 0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	struct group * groups;
	struct group tempg = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	for (int i = START; i < END; i++) {
		if (isprime(i))
			amount++;
	}

	printf("There are %d primes between %d and %d\n\n", amount, START, END);
	
	primes = (struct number *)malloc(amount * sizeof(struct number));
	amount = 0;
	for (int i = START; i < END; i++) {
		if (isprime(i)) {
			primes[amount] = temp;
			primes[amount].number = i;
			amount++;
		}
	}

	int digit;
	for (int i = 0; i < amount; i++) {
		digit = primes[i].number % 10;
		primes[i].digits[digit] += 1;
		digit = (primes[i].number / 10) % 10;
		primes[i].digits[digit] += 1;
		digit = (primes[i].number / 100) % 10;
		primes[i].digits[digit] += 1;
		digit = (primes[i].number / 1000) % 10;
		primes[i].digits[digit] += 1;
	}

	//printf("Number: 0s: 1s: 2s: 3s: 4s: 5s: 6s: 7s: 8s: 9s:\n");
	//for (int i = 0; i < amount; i++)
		//printf("%6d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d\n", primes[i].number, primes[i].digits[0], primes[i].digits[1], primes[i].digits[2], primes[i].digits[3], primes[i].digits[4], primes[i].digits[5], primes[i].digits[6], primes[i].digits[7], primes[i].digits[8], primes[i].digits[9]);

	groups = (struct group *)malloc(amount * sizeof(struct group));
	for (int i = 0; i < amount; i++)
		groups[i] = tempg;

	int index;
	int g = 0;
	for (int i = 0; i < amount; i++) {
		index = included(primes[i].digits, groups, g);
		if (index != -1) {
			copyNumber(primes[i].number, &groups[index]);
		}
		else {
			copyStructure(&primes[i], &groups[g++]);
		}
	}

	showGroups(groups);

	finalCheck(groups);

	return 0;
}

bool isprime(int number) {
	bool prime = true;

	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0)
			prime = false;
	}

	return prime;
}

bool same(const int * tab1, const int * tab2) {
	for (int i = 0; i < 10; i++) {
		if (tab1[i] != tab2[i])
			return false;
	}

	return true;
}

int included(const int * tab, struct group * groups, int g) {
	for (int i = 0; i < g; i++) {
		if (same(tab, groups[i].digits))
			return i;
	}

	return -1;
}

void copyNumber(int number, struct group * groups) {
	int i = 0;

	while (groups->numbers[i] != 0)
		i++;
	groups->numbers[i] = number;
}

void copyStructure(const struct number * number, struct group * group) {
	for (int i = 0; i < 10; i++) {
		group->digits[i] = number->digits[i];
	}
	copyNumber(number->number, group);
}

void showGroups(const struct group * groups) {
	int i;

	printf("0 1 2 3 4 5 6 7 8 9 Numbers:\n");
	while (groups->numbers[0] != 0) {
		i = 0;
		for (int j = 0; j < 10; j++)
			printf("%d ", groups->digits[j]);
		while (groups->numbers[i] != 0) {
			printf("%d ", groups->numbers[i]);
			i++;
		}
		putchar('\n');
		groups++;
	}
}

void finalCheck(const struct group * groups) {
	int amount;
	while (groups->numbers[0] != 0) {
		amount = 0;
		while (groups->numbers[amount] != 0)
			amount++;
		if (amount >= 3) {
			for (int i = 0; i < amount; i++) {
				for (int j = 0; j < amount; j++) {
					for (int k = 0; k < amount; k++) {
						if (i != j && i != k && j != k && j < k) {
							if (2 * groups->numbers[i] == groups->numbers[j] + groups->numbers[k])
								printf("The three numbers are: %d %d %d\n", groups->numbers[i], groups->numbers[j], groups->numbers[k]);
						}
					}
				}
			}
		}

		groups++;
	}
}