#include <stdio.h>
#include <stdbool.h>

#define DAYS 30

long long prize(char prev, char prevprev, bool includedL, int length);

int main(void) {
	printf("There are %lld prize strings over %d-day period.\n", prize('x', 'x', false, 0), DAYS);
	prize('x', 'x', false, 0);

	return 0;
}

long long prize(char prev, char prevprev, bool includedL, int length) {
	static long long calls = 0;

	switch (length) {
	case 0:
		prize('L', 'x', true, length + 1);
		prize('O', 'x', false, length + 1);
		prize('A', 'x', false, length + 1);
		break;
	case 1:
		switch (prev) {
		case 'L':
			prize('O', 'L', true, length + 1);
			prize('A', 'L', true, length + 1);
			break;
		case 'O':
			prize('A', 'O', false, length + 1);
			prize('O', 'O', false, length + 1);
			prize('L', 'O', true, length + 1);
			break;
		case 'A':
			prize('A', 'A', false, length + 1);
			prize('O', 'A', false, length + 1);
			prize('L', 'A', true, length + 1);
			break;
		default:
			printf("Error\n");
			break;
		}
		break;
	case DAYS:
		calls++;
		break;
	default:
		if (includedL == true) {
			if (prev == 'A' && prevprev == 'A') {
				prize('O', prev, true, length + 1);
			}
			else {
				prize('O', prev, true, length + 1);
				prize('A', prev, true, length + 1);
			}
		}
		else {
			prize('L', prev, true, length + 1);
			if (prev == 'A' && prevprev == 'A') {
				prize('O', prev, false, length + 1);
			}
			else {
				prize('O', prev, false, length + 1);
				prize('A', prev, false, length + 1);
			}
		}

		break;
	}

	return calls;
}