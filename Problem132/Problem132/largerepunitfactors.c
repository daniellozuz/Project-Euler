#include <stdio.h>
#include <stdbool.h>

#define SIZE 100000
#define MAXFACTOR 5000
#define REPMAX 100000
#define LIMIT 40

#define PRIME_LIMIT 1200000

void factorize(int number);
void factorize2(int number[], int factors[]);

bool isprime(int number);
bool divisible(int number[], int n);
bool divisible2(long zeros, int n);
bool divisible3(long zeros, int n);
void divide(int number[], int n);
void show(int number[]);
int showfactors(int factors[]);

int main(void) {
	int amount = 0;
	int primes[100000] = { 0 };
	
	for (int i = 2; i <= PRIME_LIMIT+1000; i++) {
		if (isprime(i))
			primes[amount++] = i;
	}

	printf("%d primes found.\n", amount);

	amount = 0;
	int sum = 0;
	for (int i = 3; primes[i] < PRIME_LIMIT; i++) {
		//printf("Checking %d\n", primes[i]);
		if (divisible3(1000000000, primes[i])) {
			amount++;
			sum += primes[i];
			printf("%d works. Primes found so far: %d. Sum: %d\n", primes[i], amount, sum);
			if (amount == 40)
				break;
		}
	}
	/*
	int factors2[MAXFACTOR + 1] = { 0 };
	int reps2[8] = { 31250, 64000, 65536, 78125, 80000, 81920, 100000, 102400 };

	for (int n = 0; reps2[n] <= REPMAX; n++) {
		int num[SIZE] = { 0 };
		for (int i = SIZE - 1; i >= SIZE - reps2[n]; i--)
			num[i] = 1;

		for (int i = 2; i < MAXFACTOR; i++) {
			if (divisible(num, i))
				factors2[i] = i;
		}
		showfactors(factors2);
	}
	*/

	/*
	// Deduction part
	int factors[MAXFACTOR + 1] = { 0 };
	int reps[48] = { 2, 4, 5, 8, 10, 16, 20, 25, 32, 40, 50, 64, 80, 100, 125, 128, 160, 200, 250, 256, 320, 400, 500, 512, 625, 640, 800, 1000, 1024, 1250, 1280, 1600, 2000, 2048, 2500, 2560, 3125, 3200, 4000, 4096, 5000, 5120, 6250, 6400, 8000, 8192, 10000, 10240 };

	for (int n = 0; reps[n] <= REPMAX; n++) {
		int number[SIZE] = { 0 };
		// R(REP)
		for (int i = SIZE - 1; i >= SIZE - reps[n]; i--)
			number[i] = 1;

		printf("Starting number:");
		show(number);
		factorize2(number, factors);
		showfactors(factors);
	}
	*/
	return 0;
}

void factorize(int number) {
	for (int i = 2; i <= MAXFACTOR; i++) {
		if (number % i == 0) {
			number /= i;
			printf("Divisible by %d\n", i);
			factorize(number);
			break;
		}
	}
}

void factorize2(int number[], int factors[]) {
	for (int i = 2; i <= MAXFACTOR; i++) {
		if (divisible(number, i)) {
			divide(number, i);
			//show(number);
			//printf("Divisible by %d\n", i);
			factors[i] = i;
			factorize2(number, factors);
			break;
		}
	}
}

bool divisible(int number[], int n) {
	int i = 0;
	int temp = 0;
	int r;
	
	while (number[i] == 0)
		i++;

	while (i < SIZE) {
		temp += number[i];
		if (temp >= n) {
			r = temp / n;
			temp = temp - r * n;
			temp = temp * 10;
		}
		else {
			r = 0;
			temp = temp * 10;
		}
		i++;
	}

	if (temp == 0)
		return true;

	return false;
}

bool divisible2(long zeros, int n) {
	long i = 0;
	int temp = 0;
	int r;

	while (i < zeros) {
		temp += 1;
		if (temp >= n) {
			r = temp / n;
			temp = temp - r * n;
			temp = temp * 10;
		}
		else {
			r = 0;
			temp = temp * 10;
		}
		printf("Temp: %d\n", temp);
		i++;
	}

	if (temp == 0)
		return true;

	return false;
}

bool divisible3(long zeros, int n) {
	long i = 0;
	int temp = 0;
	int r;
	int prev = -1;
	int recurence = -1;

	while (i < zeros) {
		temp += 1;
		if (temp >= n) {
			r = temp / n;
			temp = temp - r * n;
			temp = temp * 10;
		}
		else {
			r = 0;
			temp = temp * 10;
		}
		//printf("Temp: %4d ", temp);
		i++;

		if (temp == 0) {
			if (prev == -1)
				prev = i;
			else
				recurence = i - prev;
		}

		if (recurence != -1) {
			if ((1000000000 + i) % recurence == 0)
				return true;
			else
				return false;
		}

		//printf("Recurence: %d at index: %d\n", recurence, i);
	}

	if (temp == 0)
		return true;

	return false;
}

void divide(int number[], int n) {
	int i = 0;
	int temp = 0;
	int r;
	int result[SIZE] = { 0 };

	while (number[i] == 0)
		i++;

	while (i < SIZE) {
		temp += number[i];
		if (temp >= n) {
			r = temp / n;
			temp = temp - r * n;
			temp = temp * 10;
		}
		else {
			r = 0;
			temp = temp * 10;
		}
		result[i] = r;
		i++;
	}

	i = 0;
	while (i < SIZE)
		number[i] = result[i++];
}

void show(int number[]) {
	int i = 0;

	while (number[i] == 0)
		i++;

	while (i < SIZE)
		printf("%d", number[i++]);

	printf("\n");
}

int showfactors(int factors[]) {
	int sum = 0;
	int amount = 0;

	printf("Factors:\n");
	for (int i = 0; i <= MAXFACTOR && amount < LIMIT; i++) {
		if (factors[i] != 0) {
			printf("%d\n", factors[i]);
			sum += factors[i];
			amount++;
		}
	}
	printf("The sum of the first forty prime factors is: %d\n", sum);

	return sum;
}

bool isprime(int number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}