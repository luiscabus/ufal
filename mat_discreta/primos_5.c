#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int primom(int numero, int * primes, int n_primes){ 
	
	if (numero == 1 || numero == 2 || numero == 3) {
		return numero;
	}
	if (numero % 2 == 0 || numero % 3 == 0) {
		return 0;
	}

	int i = 0;

	while (i < n_primes && primes[i] * primes[i] <= numero) {
		if (numero % primes[i] == 0) {
			return 0;
		}
		// printf("Testando se %d é divisível por %d\n", numero, primes[i]);
		
		++i;
	}

	return numero;
}

int main() {

	clock_t t;
	t = clock();

	int n, v;
	n = 87654321;
	v = n / 10;

	int * primes = malloc(v * sizeof(int));
	if (primes == NULL) {
	  fprintf(stderr, "malloc failed\n");
	  return(-1);
	}

	printf("2 3 ");
	int n_primes = 0;
	int tentativas = 0;

	int i = 5;
	int w = 2;

	// while (i < 200100200) {
	while (i < n) {
		// printf("--- Enviando o %d\n", i);
		
		if (primom(i, primes, n_primes)) {
			printf("%d ", i);
			primes[n_primes] = i;
			++n_primes;
		} else {
			// printf("try %d \n", i);
		}

		++tentativas;

		i += w;
		w = 6 - w;
	}

	printf("\nPrimos: %d, Tentativas: %d\n", n_primes + 2, tentativas) ;

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\ntook %f seconds to execute \n", time_taken);
	
	return 0;
}