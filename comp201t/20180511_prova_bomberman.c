#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <math.h>

void build2darray(int linha_max, int coluna_max, char array_mapa[][coluna_max], int linha, int coluna)
{
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			return;
		}
		return build2darray(linha_max, coluna_max, array_mapa, linha + 1, 0);
	}

	scanf (" %c", &array_mapa[linha][coluna] );

	// printf("linha %d coluna %d valor %d\n", linha, coluna, array_mapa[linha][coluna]);

	return build2darray(linha_max, coluna_max, array_mapa, linha, coluna + 1);
}

void print2array(int linha_max, int coluna_max, char array_mapa[][coluna_max], int linha, int coluna)
{
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			printf("\n");
			return;
		}
		printf("\n");
		return print2array(linha_max, coluna_max, array_mapa, linha + 1, 0);
	}

	printf("%c", array_mapa[linha][coluna]);
	// printf("linha %d coluna %d valor %d\n", linha, coluna, array_mapa[linha][coluna]);

	return print2array(linha_max, coluna_max, array_mapa, linha, coluna + 1);
}

void blow(int linha_max, int coluna_max, char array_mapa[][coluna_max], int linha, int coluna, int cora, int corb)
{
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			// print2array(linha_max, coluna_max, array_mapa, 0, 0);
			return;
		}
		
		return blow(linha_max, coluna_max, array_mapa, linha + 1, 0, cora, corb);
	}

	// Bomb the coordenada
	if (linha == cora && coluna == corb && array_mapa[linha][coluna] == '&') {
		array_mapa[linha][coluna] = '_';
	}

	// Circular
	int newca, newcb;

	// Bomb up
	newca = (( (cora - 1) % linha_max) + linha_max) % linha_max;
	newcb = (( (corb + 0) % coluna_max) + coluna_max) % coluna_max;
	if (linha == newca && coluna == newcb && array_mapa[newca][newcb] == '&') {
		array_mapa[newca][newcb] = '_';
	}

	// Bomb down
	newca = (( (cora + 1) % linha_max) + linha_max) % linha_max;
	newcb = (( (corb + 0) % coluna_max) + coluna_max) % coluna_max;
	if (linha == newca && coluna == newcb && array_mapa[newca][newcb] == '&') {
		array_mapa[newca][newcb] = '_';
	}

	// Bomb left
	newca = (( (cora + 0) % linha_max) + linha_max) % linha_max;
	newcb = (( (corb - 1) % coluna_max) + coluna_max) % coluna_max;
	if (linha == newca && coluna == newcb && array_mapa[newca][newcb] == '&') {
		array_mapa[newca][newcb] = '_';
	}

	// Bomb right
	newca = (( (cora + 0) % linha_max) + linha_max) % linha_max;
	newcb = (( (corb + 1) % coluna_max) + coluna_max) % coluna_max;
	if (linha == newca && coluna == newcb && array_mapa[newca][newcb] == '&') {
		array_mapa[newca][newcb] = '_';
	}

		

	// printf("%c", array_mapa[linha][coluna]);
	// printf("linha %d coluna %d valor %d\n", linha, coluna, array_mapa[linha][coluna]);

	return blow(linha_max, coluna_max, array_mapa, linha, coluna + 1, cora, corb);
}

void scanlines(int size, char mapa[][size], int qty, int i) {
	if (i == qty) {
		// printf("Mapa final: \n");
		print2array(size, size, mapa, 0, 0);
		return;
	}
	int cora, corb;
	scanf(" %d %d", &cora, &corb);

	if (mapa[cora][corb] == '_') {
		// printf("Bombing this bomb no %d em L%dxC%d\n", i, cora, corb);
		blow(size, size, mapa, 0, 0, cora, corb);
	}

	scanlines(size, mapa, qty, i + 1);
}


int main() {
	int size;
	scanf(" %d", &size);

	char mapa[size][size];
	build2darray(size, size, mapa, 0, 0);

	// printf("Mapa inicial:\n");
	// print2array(size, size, mapa, 0, 0);

	int qty;
	scanf(" %d", &qty);
	scanlines(size, mapa, qty, 0);

	// print2array(size, size, mapa, 0, 0);



}