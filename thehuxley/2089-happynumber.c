#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// #define NELEMS(x)  (sizeof(x) / sizeof((x)[0])) // NELEMS não está funcionando

void addToArray(int item, int colecao[], int i) {
	colecao[i] = item;
	// printf("Posição %d tem valor %d\n", i, colecao[i]);
}

void printallarray(int colecao[], int i) {
	if (i == -1) {
		return;
	}

	printf("Coleção %d valor %d\n", i, colecao[i]);
	printallarray(colecao, i - 1);
}

int findinarray(int colecao[], int i, int sujeito) {
	// printf("find: posicao %d valor %d sujeito procurado %d\n", i, colecao[i], sujeito);

	if (i == -1) {
		return 0;
	}

	if (colecao[i] == sujeito) {
		return 1;
	}

	return findinarray(colecao, i - 1, sujeito);
}

int quadradodosdigitos(int numero, int resultado) {
	if (numero == 0) {
		return 0;
	}

	int digito = numero % 10;

	return (digito * digito) + quadradodosdigitos(numero / 10, resultado);
}

void happynumber(int numero, int colecao[], int posarray) {

	if (posarray == 20) {
		printf("array enorme\n");
		return;
	}

	addToArray(numero, colecao, posarray);

	if (numero == 1) {
		printf("S\n");
		// printallarray(colecao, posarray - 1);
		// printallarray(colecao, NELEMS(colecao)); //NELEMS está dando warning
		return;
	}

	// printf("Numero: %d, quadrado: %d\n", numero, quadradodosdigitos(numero, 0));

	numero = quadradodosdigitos(numero, 0);

	int existe = findinarray(colecao, posarray, numero);
	// printf("resultado existe %d\n\n", existe);
	if (existe == 1) {
		printf("N\n");
		return;
	}

	happynumber(numero, colecao, posarray + 1);
}

void umadez(int numero, int colecao[], int posarray, int limite) {
	if (posarray == limite) {
		return;
	}

	addToArray(quadradodosdigitos(numero, 0), colecao, posarray );
	umadez(numero, colecao, posarray + 1, limite);
}


int main() {
	// printf("\033c"); //Clear terminal before code output
	
	int numero;
	// int colecao[] = {}; // Segmentation fault: 11
	int colecao[1000] = {};

	// printf("Digite o número para verificar se é um HappyNumber\n");
	scanf("%d", &numero);

	// printf("umadezz \n");
	// umadez(numero, colecao, 0, 10);

	// printf("happynumber \n");
	happynumber(numero, colecao, 0);


	return 0;
}