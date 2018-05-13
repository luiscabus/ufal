#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <math.h>

void build2darray(int linha_max, int coluna_max, int array[][coluna_max], int linha, int coluna)
{
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			return;
		}
		return build2darray(linha_max, coluna_max, array, linha + 1, 0);
	}

	if (coluna == 0) {
		scanf (" %d", &array[linha][coluna] );
	}
	else
	{
		array[linha][coluna] = 0;
	}
	// printf("linha %d coluna %d valor %d\n", linha, coluna, array[linha][coluna]);

	return build2darray(linha_max, coluna_max, array, linha, coluna + 1);
}

void print2darray(int linha_max, int coluna_max, int array[][coluna_max], int linha, int coluna)
{
	// if(coluna == coluna_max || (linha == linha_max))
	// {
		if(linha == linha_max)
		{
			return;
		}
		// printf("Buraco %d destino %d visitado %d\n", linha, array[linha][0], array[linha][1]);
		return print2darray(linha_max, coluna_max, array, linha + 1, 0);
	// }

	
	// printf("%d ", array[linha][coluna]);
	// printf("linha %d coluna %d valor %d\n", linha, coluna, array[linha][coluna]);

	// return print2darray(linha_max, coluna_max, array, linha, coluna + 1);
}

int marcatocas(int linha_max, int coluna_max, int array[][coluna_max], int linha, int coluna, int buraco_inicial, int* maiortoca, int i)
{
	array[linha][1] = 1;

	// printf("Estou no buraco %d destino %d procurando pelo %d\n", linha, array[linha][0], buraco_inicial);

	if (array[linha][0] == buraco_inicial) {
		// printf("Tamanho da toca: %d\n", i);
		if (*maiortoca < i) {
			*maiortoca = i;
		}
		return 1;
	}

	linha = array[linha][0];

	return marcatocas(linha_max, coluna_max, array, linha, coluna, buraco_inicial, maiortoca, i + 1);
}

void gocrazytocas(int linha_max, int coluna_max, int array[][coluna_max], int linha, int coluna, int contatocas, int* maiortoca)
{
	if(linha == linha_max)
	{
		// printf("Chegou ao fim do array com %d tocas\n", contatocas);
		// printf("%d\n", contatocas);
		printf("%d\n", *maiortoca);
		return;
	}

	if (array[linha][1] == 0) {
		int aux;
		aux = marcatocas(linha_max, coluna_max, array, linha, 0, linha, maiortoca, 1);

		if (aux == 1) {
			// printf("Buraco %d destino %d valor %d\n", linha, array[linha][0], array[linha][1]);
			++contatocas;
		}
	}

	// printf("Buraco %d destino %d visitado %d\n", linha, array[linha][0], array[linha][1]);


	return gocrazytocas(linha_max, coluna_max, array, linha + 1, 0, contatocas, maiortoca);
}


int main() {
	int size;
	scanf(" %d", &size);

	int tocarray[size][2];
	build2darray(size, 2, tocarray, 0, 0);

	int maiortoca;
	maiortoca = 0;

	gocrazytocas(size, 2, tocarray, 0, 0, 0, &maiortoca);

	// print2darray(size, 2, tocarray, 0, 0);


	// 15
	// 8 0 13 2 4 12 1 11 6 9 14 5 7 3 10
	// 0 > 8
	// 8 > 6
	// 6 > 1
	// 1 > 0 UMA TOCA
	// 2 > 13
	// 13 > 3
	// 3 > 2 DUAS TOCAS
	// 4 > 

}