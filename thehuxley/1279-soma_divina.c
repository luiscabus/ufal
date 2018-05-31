#include <stdio.h>
#include <stdlib.h>

int biarray(int linha_max, int coluna_max, int bi_array[][coluna_max], int linha, int coluna)
{
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			return 0;
		}
		return biarray(linha_max, coluna_max, bi_array, linha + 1, 0);
	}

	int auxe;
	scanf(" %d", &auxe);

	// if (auxe == -1) 
	// {
	// 	return linha;
	// }
	
	bi_array[linha][coluna] = auxe;

	return biarray(linha_max, coluna_max, bi_array, linha, coluna + 1);
}

void sombiarray(int linha_max, int coluna_max, int bi_array_UM[][coluna_max], int bi_array_DOIS[][coluna_max], int linha, int coluna) {
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			return;
		}
		return sombiarray(linha_max, coluna_max, bi_array_UM, bi_array_DOIS, linha + 1, 0);
	}

	printf("%d\n", bi_array_UM[linha][coluna] + bi_array_DOIS[linha][coluna]);

	return sombiarray(linha_max, coluna_max, bi_array_UM, bi_array_DOIS, linha, coluna + 1);
}

int main() {
	int matriz_de_ordem;
	scanf(" %d", &matriz_de_ordem);

	if (matriz_de_ordem == 0) {
		printf("Vazia\n");
		return 0;
	}

	int matriz_UM[matriz_de_ordem][matriz_de_ordem];
	biarray(matriz_de_ordem, matriz_de_ordem, matriz_UM, 0, 0);

	int matriz_DOIS[matriz_de_ordem][matriz_de_ordem];
	biarray(matriz_de_ordem, matriz_de_ordem, matriz_DOIS, 0, 0);

	sombiarray(matriz_de_ordem, matriz_de_ordem, matriz_UM, matriz_DOIS, 0, 0);

	return 0;
}