#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long int primo(unsigned long long int n,unsigned long long int divisor, unsigned long long int contador){ 
	if(divisor > n / 2 || contador > 1)
	{
		if (contador == 1){
			return n;
		}
		else{
			return 0;
		}
	}
	else
	{
		if(n % divisor == 0)
		{
			contador = divisor; 
		}

		return primo(n, divisor + 1, contador);
	}
}

int main() {
	// int a;
	// scanf(" %d", &a);

	unsigned long long int oi;
	unsigned long long int aux;
	
	oi = 0;

	while (oi < 99999999999) {
		aux = 0;

		aux = primo(oi, 1, 0);

		if (aux != 0) {
			printf("%llu\n", aux);
		}

		++oi;
	}
	
	

	return 0;
}