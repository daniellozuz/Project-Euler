#include <stdio.h>
#include <math.h>

#define V 20.0
#define G 9.81
#define H0 100.0
#define HMAX ((V*V)/(2.0*G))
#define PREC 100000000.0
#define DH ((H0+HMAX)/PREC)
#define DD (90.0/PREC)

int main(void) {
	double volume = 0;

	double bestad = 90.0;
	for (double h = H0 + HMAX; h >= 0.0; h -= DH) {
		double r = 0.0;
		double bestr = 0.0;
		for (double ad = bestad; ad >= 0.0; ad -= DD) {
			double ar = ad*0.0174532925;
			if (H0 + (V*V*sin(ar)*sin(ar)) / (2.0*G) >= h) {
				r = (tan(ar) + sqrt(tan(ar)*tan(ar) - (2.0 * (h - H0)*G) / (V*V*cos(ar)*cos(ar)))) / (G / (V*V*cos(ar)*cos(ar)));
				if (r >= bestr) {
					bestr = r;
					bestad = ad;
				}
				else
					break;
			}
			else
				break;
		}
		//printf("For h = %f best r = %f\n", h, bestr);
		volume += r*r*3.1415926535*DH;
	}

	printf("%f\n", volume);

	return 0;
}