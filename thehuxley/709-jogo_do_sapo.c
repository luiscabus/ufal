#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buildArray(int array[], int i, int lim_superior) {
	if (i == lim_superior) {
		return;
	}
	scanf("%d", &array[i]);
	buildArray(array, i + 1, lim_superior);
}

void printArray(int array[], int i, int lim_superior) {
	if (i == lim_superior) {
		return;
	}
	// printf("Pos %d vale %d\n", i, array[i]);
	printf("%d\n", array[i]);
	printArray(array, i + 1, lim_superior);
}

void jogada(int njogadas, int i, int j, int m, int n, int tabuleiro[], int posicoes[]) {
	if (i == njogadas) {
		printArray(posicoes, 0, m);
		return;
	}

	// printf("Jogada %d\n", i);

	int movimento;
	for (j = 0; j < m; ++j)
	{
		// printf("Movimentando player %d\n", j);
		scanf("%d", &movimento);
		posicoes[j] = (( ( posicoes[j] + movimento ) % n) + n) % n;
		posicoes[j] = (( ( posicoes[j] + tabuleiro[posicoes[j]] ) % n) + n) % n;
	}

	jogada(njogadas, i + 1, j, m, n, tabuleiro, posicoes);
}


int main() {
	int n, m, o; //casas, jogadores, jogadas
	scanf(" %d %d %d", &n, &m, &o);

	int tabuleiro[n];
	buildArray(tabuleiro, 0, n);
	// printArray(tabuleiro, 0, n);

	int posicoes[m];
	memset(posicoes, 0, sizeof(int)*m);
	// memset(array, 0, sizeof(int)*arraysize);


	jogada(o, 0, 0, m, n, tabuleiro, posicoes);

}