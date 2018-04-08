#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int eh_primo(int n, int divisor, int contador){
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

		return eh_primo(n, divisor + 1, contador);
	}
}

int proximo_primo(int y) {
	int primo;
	primo = eh_primo(y, 1, 0);
	
	if (primo == 1) {
		return y;
	} else {
		return proximo_primo(y + 1);
	}
}

int fatorial(int z) {
	if (z == 1 || z == 0)
	{
		return 1;
	}

	return z * fatorial(z - 1);
}


void serie(int limite, int numerador, int denominador, double resultado) {
	if (numerador > limite) {
		printf("\n%.2lf\n", resultado);
		return;
	}

	resultado = resultado + 1.00 * fatorial(numerador) / denominador;

	if (numerador == 1) {
		printf("%d!/%d", numerador, denominador);
	} else {
		printf(" + %d!/%d", numerador, denominador);
	}
	
	// printf(" + %d!/%d", numerador, denominador, resultado);


	denominador = denominador + 1;

	int veriprimo = eh_primo(denominador, 1, 0);

	if (veriprimo != 1) {
		denominador = proximo_primo(denominador);
	}
	
	// printf("%d!/%d resultado %lf ", numerador, denominador, resultado );

	serie(limite, numerador + 1, denominador, resultado);
}





int main() {
	printf("\033c"); //Clear terminal before code output
	
	int numero;
	scanf("%d", &numero);

	serie(numero, 1, 1, 0);


	return 0;
}