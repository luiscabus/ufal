#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int primom(int numero){ 
	
	if (numero == 1 || numero == 2 || numero == 3) {
		return numero;
	}
	if (numero % 2 == 0 || numero % 3 == 0) {
		return 0;
	}

	int i = 5;
	int w = 2;

	while (i * i <= numero) {
		if (numero % i == 0) {
			return 0;
		}
		// printf("Testando se %d é divisível por %d - com w=%d\n", numero, i, w);

		i += w;
		w = 6 - w;
	}

	return numero;
}

int main() {
	
	clock_t t;
	t = clock();

	int i = 3;


	printf("2 ");
	int nprim = 1;

	while (i < 1000000) {
		// printf("--- Enviando o %d\n", i);

		if (primom(i)) {
			printf("%d ", i);
			++nprim;
		}

		i += 2;

	}

	printf("\nPrimos: %d\n", nprim);
	
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\ntook %f seconds to execute \n", time_taken);
	
	return 0;
}