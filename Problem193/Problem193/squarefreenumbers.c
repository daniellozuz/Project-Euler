#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Sum up all non-squarefree, remove overlaps of 2, add overlaps of 3? ...?

//1125899906842624
#define LIMIT 1125899906842624
#define C (LIMIT-1)

bool isPrime(long long number);

int main(void) {

	clock_t start = clock();

	int amount = 0;
	long long all = 0;

	for (long long p1 = 2; p1*p1 < LIMIT; p1++) {
		if (isPrime(p1)) {
			all += C / (p1*p1);
			// Ov2
			for (long long p2 = 2; p1*p1*p2*p2 < LIMIT; p2++) {
				if (p2 < p1 && isPrime(p2)) {
					all -= C / (p1*p1*p2*p2);
					// Ov3
					for (long long p3 = 2; p1*p1*p2*p2*p3*p3 < LIMIT; p3++) {
						if (p3 < p2 && isPrime(p3)) {
							all += C / (p1*p1*p2*p2*p3*p3);
							// Ov4
							for (long long p4 = 2; p1*p1*p2*p2*p3*p3*p4*p4 < LIMIT; p4++) {
								if (p4 < p3 && isPrime(p4)) {
									all -= C / (p1*p1*p2*p2*p3*p3*p4*p4);
									// Ov5
									for (long long p5 = 2; p1*p1*p2*p2*p3*p3*p4*p4*p5*p5 < LIMIT; p5++) {
										if (p5 < p4 && isPrime(p5)) {
											all += C / (p1*p1*p2*p2*p3*p3*p4*p4*p5*p5);
											// Ov6
											for (long long p6 = 2; p1*p1*p2*p2*p3*p3*p4*p4*p5*p5*p6*p6 < LIMIT; p6++) {
												if (p6 < p5 && isPrime(p6)) {
													all -= C / (p1*p1*p2*p2*p3*p3*p4*p4*p5*p5*p6*p6);
													// Ov7
													for (long long p7 = 2; p1*p1*p2*p2*p3*p3*p4*p4*p5*p5*p6*p6*p7*p7 < LIMIT; p7++) {
														if (p7 < p6 && isPrime(p7)) {
															all += C / (p1*p1*p2*p2*p3*p3*p4*p4*p5*p5*p6*p6*p7*p7);
															// Ov8
															for (long long p8 = 2; p1*p1*p2*p2*p3*p3*p4*p4*p5*p5*p6*p6*p7*p7*p8*p8 < LIMIT; p8++) {
																if (p8 < p7 && isPrime(p8)) {
																	all -= C / (p1*p1*p2*p2*p3*p3*p4*p4*p5*p5*p6*p6*p7*p7*p8*p8);
																	// No more i guess
																	printf("X");
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	clock_t end = clock();
	
	printf("Elapsed time: %.2fs\n", (float)(end - start) / CLOCKS_PER_SEC);
	printf("There are %d primes.\n", amount);
	printf("All: %lld\n", all);
	printf("Result: %lld\n", LIMIT - all - 1);
	//printf("Ov: %lld\n", ov);

	return 0;
}

bool isPrime(long long number) {
	for (int i = 2; i*i <= number; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}