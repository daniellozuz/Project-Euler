#include <stdio.h>

int main(void) {
	long long number = 600851475143;

	printf("%lld\n", number);

	while (number > 1) {
		for (long long i = 2; i <= number; i++) {
			if (number % i == 0) {
				printf("Liczba %lld dzieli sie przez %lld\n", number, i);
				number /= i;
				break;
			}
		}
	}

	return 0;
}