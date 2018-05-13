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

int repetido(int numero, int digito, int contador) {
	if (numero <= 0) {
		return contador;
	}

	int n_digito = numero % 10;
	if (n_digito == digito)
	{
		++contador;
	}

	return repetido(numero / 10, digito, contador);
}

long int multi_digitos(long int numero) {
	if (numero <= 0) {
		return 1;
	}

	int digito = numero % 10;

	return digito * multi_digitos(numero / 10);
}

void gofind(int numero, long int tentativa) {
	
	long int multip;
	multip = multi_digitos(tentativa);
	if (multip == numero) {
		printf("%li\n", tentativa);
		return;
	}

	gofind(numero, tentativa + 1);
}

int main() {

	int numero;
	scanf("%d", &numero);

	int aux;
	aux = 0;

	// Não pode ser primo
	aux = primo(numero, 1, 0);
	if (aux == 1)
	{
		printf("-1\n");
		return 0;
	}

	// Não pode ser repetido (ex. 2222, 3333, 4444...)
	aux = repetido(numero / 10, numero % 10, 1);
	if (aux > 1)
	{
		printf("-1\n");
		return 0;
	}

	// Não pode ser menor que 10
	if (numero < 10)
	{
		printf("-1\n");
		return 0;
	}


	gofind(numero, 10);


	return 0;
}