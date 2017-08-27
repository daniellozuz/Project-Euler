#include <stdio.h>

#define SIZE 1000
#define MASK 10000000000

long long last10(int number);

int main(void) {
	long long numbers[SIZE] = { 0 };
	long long sum = 0;

	for (int i = 1; i <= SIZE; i++) {
		numbers[i-1] = last10(i);
		sum = (sum + numbers[i-1]) % MASK;
	}

	printf("The last 10 numbers of the sum are: %lld\n", sum);
		
	return 0;
}

long long last10(int number) {
	long long result = 1;

	for (int i = 1; i <= number; i++) {
		result = (result * number) % MASK;
	}

	return result;
}