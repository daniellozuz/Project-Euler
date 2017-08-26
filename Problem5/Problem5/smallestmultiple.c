#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int numbers[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	for (int i = 2520; i <= 2000000000; i += 2520) {
		bool ok = true;
		for (int j = 0; j < 10; j++) {
			if (i % numbers[j] != 0)
				ok = false;
		}
		if (ok)
			printf("Number %d is divisible by all the numbers (1-20)\n", i);
	}

	return 0;
}