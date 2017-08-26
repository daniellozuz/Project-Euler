#include <stdio.h>
#include <limits.h>

long long power(int base, int exponent);

int main(void) {
	printf("Max value of long long is : %lld\n", LLONG_MAX);
	
	for (long long i = 1000000000; i * i <= 1929394959697989990; i += 10) {
		if ((i * i % 1000) / 100 == 9 &&
			(i * i % 100000) / 10000 == 8 &&
			(i * i % 10000000) / 1000000 == 7 &&
			(i * i % 1000000000) / 100000000 == 6 &&
			(i * i % 100000000000) / 10000000000 == 5 &&
			(i * i % 10000000000000) / 1000000000000 == 4 &&
			(i * i % 1000000000000000) / 100000000000000 == 3 &&
			(i * i % 100000000000000000) / 10000000000000000 == 2)
			printf("The number you are looking for: %lld\n", i);
	}

	return 0;
}