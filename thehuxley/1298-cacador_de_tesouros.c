/*
Entrada: 
5 6 .#oo#o.o#...#......o#.#.o#oo..
*/

#include <stdio.h>

void buildMatrix(int n_linhas, int n_colunas, char matriz[][n_colunas], int linha, int coluna) {

	if(linha == n_linhas || (coluna == n_colunas))
	{
		if(linha == n_linhas)
		{
			return;
		}
		return buildMatrix(n_linhas, n_colunas, matriz, linha + 1, 0);
	}

	scanf(" %c", &matriz[linha][coluna]);

	// printf("linha %d coluna %d valor %c\n", linha, coluna, matriz[linha][coluna]);

	buildMatrix(n_linhas, n_colunas, matriz, linha, coluna + 1);
}

void movimentar_labirinto(int n_linhas, int n_colunas, char matriz[][n_colunas], int linha, int coluna, int soma_atual, int *somador) {
	
	if (matriz[linha][coluna] == '#' || linha == n_linhas || coluna == n_colunas || linha < 0 || coluna < 0)
	{
		// printf("Parei aqui (%d, %d) \n", linha, coluna);
		return;
	}

	// printf("Estou aqui (%d, %d) \n", linha, coluna);

	char aux;
	aux = matriz[linha][coluna];
	matriz[linha][coluna] = '#';

	if (aux == 'b') { soma_atual = soma_atual + 1; }
	if (aux == 'p') { soma_atual = soma_atual + 5; }
	if (aux == 'o') { soma_atual = soma_atual + 10; }
	if (aux == 'd') { soma_atual = soma_atual + 50; }

	movimentar_labirinto(n_linhas, n_colunas, matriz, linha, coluna + 1, soma_atual, somador);
	movimentar_labirinto(n_linhas, n_colunas, matriz, linha + 1, coluna, soma_atual, somador);

	movimentar_labirinto(n_linhas, n_colunas, matriz, linha - 1, coluna, soma_atual, somador);
	movimentar_labirinto(n_linhas, n_colunas, matriz, linha, coluna - 1, soma_atual, somador);

	matriz[linha][coluna] = aux;

	if (soma_atual > *somador)
	{
		*somador = soma_atual;
	}


}


int main() {
	int n_linhas, n_colunas;
	scanf(" %d %d", &n_linhas, &n_colunas);

	char matriz[n_linhas][n_colunas];
	buildMatrix(n_linhas, n_colunas, matriz, 0, 0);

	int somador;
	movimentar_labirinto(n_linhas, n_colunas, matriz, 0, 0, 0, &somador);

	printf("%d\n", somador);


}