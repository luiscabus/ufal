#include <stdio.h>
#include <stdlib.h>

void build2darray(int linha_max, int coluna_max, int arr_votos[][coluna_max], int linha, int coluna, int resultado[])
{
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			return;
		}
		return build2darray(linha_max, coluna_max, arr_votos, linha + 1, 0, resultado);
	}

	scanf (" %d", &arr_votos[linha][coluna] );

	// printf("linha %d coluna %d valor %d\n", linha, coluna, arr_votos[linha][coluna]);

	if (linha == 0) {
		resultado[coluna] = 0;
	}

	if (arr_votos[linha][coluna] == 1) {
		resultado[coluna] = (int)resultado[coluna] + 1;
	} else {
		resultado[coluna] = (int)resultado[coluna] + 0;
	}

	// printf("resultado coluna %d é %d\n", coluna, resultado[coluna]);

	return build2darray(linha_max, coluna_max, arr_votos, linha, coluna + 1, resultado);
}

void printResultado(int arr_resultado[], int linha, int limite) {
	if (linha == limite) {return;}

	printf("Princesa %d: %d voto(s)\n", linha + 1, arr_resultado[linha]);

	printResultado(arr_resultado, linha + 1, limite);
}


int main() {

	int princesas, eleitores;

	scanf(" %d %d", &princesas, &eleitores);

	printf("\n");

	int votacao[eleitores][princesas];
	int resultado[princesas];

	build2darray(eleitores, princesas, votacao, 0, 0, resultado);

	printResultado(resultado, 0, princesas);

	return 0;
}