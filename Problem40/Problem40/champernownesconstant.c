#include <stdio.h>

void show(int digits, int digit);

int main(void) {
	int digits = 0;
	int digit;

	for (int i = 1; i < 1000000; i++) {
		if (i < 10) {
			digits++;
			digit = i;
			show(digits, digit);
		}
		else if (i < 100) {
			digits++;
			digit = i / 10;
			show(digits, digit);
			digits++;
			digit = i % 10;
			show(digits, digit);
		}
		else if (i < 1000) {
			digits++;
			digit = i / 100;
			show(digits, digit);
			digits++;
			digit = (i / 10) % 10;
			show(digits, digit);
			digits++;
			digit = i % 10;
			show(digits, digit);
		}
		else if (i < 10000) {
			digits++;
			digit = i / 1000;
			show(digits, digit);
			digits++;
			digit = (i / 100) % 10;
			show(digits, digit);
			digits++;
			digit = (i / 10) % 10;
			show(digits, digit);
			digits++;
			digit = i % 10;
			show(digits, digit);
		}
		else if (i < 100000) {
			digits++;
			digit = i / 10000;
			show(digits, digit);
			digits++;
			digit = (i / 1000) % 10;
			show(digits, digit);
			digits++;
			digit = (i / 100) % 10;
			show(digits, digit);
			digits++;
			digit = (i / 10) % 10;
			show(digits, digit);
			digits++;
			digit = i % 10;
			show(digits, digit);
		}
		else if (i < 1000000) {
			digits++;
			digit = i / 100000;
			show(digits, digit);
			digits++;
			digit = (i / 10000) % 10;
			show(digits, digit);
			digits++;
			digit = (i / 1000) % 10;
			show(digits, digit);
			digits++;
			digit = (i / 100) % 10;
			show(digits, digit);
			digits++;
			digit = (i / 10) % 10;
			show(digits, digit);
			digits++;
			digit = i % 10;
			show(digits, digit);
		}
	}

	return 0;
}

void show(int digits, int digit) {
	static int result = 1;

	switch (digits) {
	case 1:
		printf("        1st digit: %d\n", digit);
		result *= digit;
		break;
	case 10:
		printf("       10th digit: %d\n", digit);
		result *= digit;
		break;
	case 100:
		printf("      100th digit: %d\n", digit);
		result *= digit; 
		break;
	case 1000:
		printf("    1 000th digit: %d\n", digit);
		result *= digit; 
		break;
	case 10000:
		printf("   10 000th digit: %d\n", digit);
		result *= digit; 
		break;
	case 100000:
		printf("  100 000th digit: %d\n", digit);
		result *= digit; 
		break;
	case 1000000:
		printf("1 000 000th digit: %d\n", digit);
		result *= digit; 
		printf("The result is : %d\n", result);
		break;
	}
}