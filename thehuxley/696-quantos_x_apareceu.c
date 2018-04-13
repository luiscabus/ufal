#include <stdio.h>

void readArray(int my_array[], int posicao) {
	if (posicao < 0) {return;}
	readArray(my_array, posicao - 1);
	// printf("Informe o valor da posição %d\n", posicao);
	scanf("%d", &my_array[posicao]);
}

void printArray(int my_array[], int posicao) {
	if (posicao < 0) {return;}
	printArray(my_array, posicao - 1);
	printf("Posição %d, valor %d \n", posicao, my_array[posicao]);
}

int countArray(int my_array[], int posicao, int procurado, int contador) {
	if (posicao < 0) {return contador;}
	if (my_array[posicao] == procurado) {contador = contador + 1;}
	// printf("Procurado %d, Atual %d, Contador %d\n", procurado, my_array[posicao], contador);
	return countArray(my_array, posicao - 1, procurado, contador);
}

int main() {
	int my_array[10] = {};
	readArray(my_array, 10-1);

	int procurado;
	scanf("%d", &procurado);

	int contador;
	contador = countArray(my_array, 10-1, procurado, 0);

	// printArray(my_array, 10-1);

	printf("%d\n", contador);

	return 0;
}