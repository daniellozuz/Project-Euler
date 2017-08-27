#include <stdio.h>

#define MASK 10000000000

int main(void) {
	long long number = 1L;

	for (int i = 0; i < 7830457; i++)
		number = (number * 2) % MASK;

	number = (number * 28433) % MASK;

	number++;

	printf("The number equals %lld\n", number);

	return 0;
}