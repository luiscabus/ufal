#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void makeArray(int my_array[], int posicao){
	printf("Qual o valor que você quer dar à posição %d?\n", posicao);
	scanf("%d", &my_array[posicao]);
	printf("Ok, alteração realizada.\n");
	// printf("O array na posição [%d] vale %d\n", posicao, my_array[posicao]);
}

void readArray(int my_array[], int posicao){
	if (posicao == 0) {
		return;
	}
	printf("Informe o valor da posição %d\n", posicao);
	scanf("%d", &my_array[posicao]);
	readArray(my_array, posicao - 1);
}

int main(){

	int my_array[10] = {};
	int posicao;
	// scanf("%d", &my_array[0]);
	// printf("O array na posição [0] vale %d\n", my_array[0]);
	printf("Que posição você quer editar do Array?\n");
	scanf("%d", &posicao);
	makeArray(my_array, posicao);
	printf(".. O array na posição [%d] vale %d\n", posicao, my_array[posicao]);
	
	readArray(my_array, 10);
}