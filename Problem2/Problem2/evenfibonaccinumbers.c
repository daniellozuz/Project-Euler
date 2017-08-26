#include <stdio.h>

#define ROZMIAR 40
#define LIMIT 4000000

void show(int *tab, int rozmiar);

int main(void) {
	int tablica[ROZMIAR] = { 1, 2 };

	int i = 1;
	while (tablica[i] + tablica[i - 1] < LIMIT) {
		tablica[i + 1] = tablica[i] + tablica[i - 1];
		i++;
	}

	show(tablica, ROZMIAR);

	int suma = 0;
	for (int i = 0; i < ROZMIAR; i++) {
		if (tablica[i] % 2 == 0)
			suma += tablica[i];
	}

	printf("\nSuma wyrazow parzystych wynosi: %d\n\n", suma);

	return 0;
}

void show(int *tab, int rozmiar) {
	for (int i = 0; i < rozmiar; i++)
		printf("%d\n", tab[i]);
}