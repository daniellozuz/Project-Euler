#include <stdio.h>
#include <stdbool.h>

bool samedigits(int number);

int main(void) {

	for (int i = 1; i < 1000000; i++) {
		if (samedigits(i))
			printf("The number you are looking for : %d.\n", i);
	}

	return 0;
}

bool samedigits(int number) {
	int digits[5][10] = { 0 };
	int digit;
	int multiple;

	for (int i = 2; i <= 6; i++) {
		multiple = i*number;
		
		while (multiple >= 1) {
			digit = multiple % 10;
			digits[i-2][digit]++;
			multiple /= 10;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 1; j < 5; j++) {
			if (digits[0][i] != digits[j][i])
				return false;
		}
	}

	return true;
}