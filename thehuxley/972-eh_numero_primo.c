#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int primo(int n,int divisor, int contador){ 
	if(divisor > n / 2 || contador > 1)
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
		if(n % divisor == 0)
		{
			contador = divisor; 
		}

		return primo(n, divisor + 1, contador);
	}
}

void entradas(int entrada){
	if (entrada == -1){ return; }
	printf("%d\n", primo(entrada, 1, 0) );
	scanf(" %d", &entrada);
	entradas(entrada);
}




int main() {
	int a;
	scanf(" %d", &a);
	entradas(a);

	// printf("Primo? %d\n", primo(5, 1, 0));

	return 0;
}