#include <stdio.h>

#define ROZMIAR 1000

int main(void) {
	int tablica[ROZMIAR] = { 0 };

	for (int i = 0; i < ROZMIAR; i += 5)
		tablica[i] = i;

	for (int i = 0; i < ROZMIAR; i += 3)
		tablica[i] = i;

	int suma = 0;
	for (int i = 0; i < ROZMIAR; i++)
		suma += tablica[i];

	printf("Suma wynosi: %d", suma);

	return 0;
}