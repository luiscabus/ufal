#include <stdlib.h>

void read(int linha_max, int coluna_max, int mapa_array[][coluna_max], int linha, int coluna)
{
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			return;
		}
		return read(linha_max, coluna_max, mapa_array, linha + 1, 0);
	}

	// printf("Capturando o valor da linha %d coluna %d\n", linha, coluna);
	scanf ( "%d", &mapa_array[linha][coluna] );
	// printf("Valor %d\n", mapa_array[linha][coluna]);

	return read(linha_max, coluna_max, mapa_array, linha, coluna + 1);
}

void getcomandos(char comandos[], int qtd, int i) 
{
	if (i == qtd) {return;}
	scanf(" %c", &comandos[i]);
	return getcomandos(comandos, qtd, i + 1);
}

void gocomando(char comandos[], int posicao_atual[], int col, int mapa[][col], int i, int limite) 
{
	if (i == limite) {return;}

	if (comandos[i] == 'D') {
		if (mapa[posicao_atual[0]][posicao_atual[1] + 1] == 1) {
			posicao_atual[1] = posicao_atual[1] + 1;
		}
	}
	if (comandos[i] == 'E') {
		if (mapa[posicao_atual[0]][posicao_atual[1] - 1] == 1) {
			posicao_atual[1] = posicao_atual[1] - 1;
		}
	}

	if (comandos[i] == 'C') {
		if (mapa[posicao_atual[0] - 1][posicao_atual[1]] == 1) {
			posicao_atual[0] = posicao_atual[0] - 1;
		}
	}
	if (comandos[i] == 'B') {
		if (mapa[posicao_atual[0] + 1][posicao_atual[1]] == 1) {
			posicao_atual[0] = posicao_atual[0] + 1;
		}
	}


	gocomando(comandos, posicao_atual, col, mapa, i + 1, limite);
}


int main()
{
	int linha, coluna;
	scanf ( "%d %d", &linha, &coluna );

	int mapa[linha][coluna];
	read(linha, coluna, mapa, 0, 0);

	int qtd;
	scanf(" %d", &qtd);

	char comandos[qtd + 1];
	getcomandos(comandos, qtd, 0);

	int posicao_atual[2];
	scanf(" %d %d", &posicao_atual[0], &posicao_atual[1]);

	// printf("linha %d coluna %d\n", posicao_atual[0], posicao_atual[1]);

	gocomando(comandos, posicao_atual, coluna, mapa, 0, qtd);

	// printf("linha %d coluna %d\n", posicao_atual[0], posicao_atual[1]);
	printf("(%d,%d)\n", posicao_atual[0], posicao_atual[1]);

	return 0;
}