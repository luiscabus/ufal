#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int primo(int numero, int divisor, int contador){ 
	// printf("Testando se %d é divisível por %d - com contador=%d\n", numero, divisor, contador);
	if(divisor > numero / 2 || contador > 1)
	{
		if (contador == 1){
			return 1;
		}
		else{
			return 0;
		}
	}
	else
	{
		if(numero % divisor == 0)
		{
			++contador;
		}

		return primo(numero, divisor + 1, contador);
	}
}

int main() {

	clock_t t;
	t = clock();

	int nprim = 0;
	int i = 1;

	while (i < 100000) {
		if (primo(i, 1, 0)) {
			printf("%d\n", i);
			++nprim;
		}

		++i;
	}

	printf("\nPrimos: %d\n", nprim);

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\ntook %f seconds to execute \n", time_taken);
	
	return 0;
}