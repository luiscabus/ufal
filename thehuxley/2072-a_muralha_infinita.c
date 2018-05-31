#include <stdio.h>
#include <stdlib.h>


void viagem(int dias, int px, int py, int reino, int moedas) {
	if (dias < 0) {
		printf("%d\n", moedas);
		return;
	}

	char direcao;
	scanf(" %c", &direcao);

	if (direcao == 'C') {
		++py;
	}
	if (direcao == 'D') {
		++px;
	}

	if (px > py && reino != 1) {
		// printf("foi para o reino de baixo\n");
		reino = 1;
		++moedas;
	}

	if (px < py && reino != 2) {
		// printf("foi para o reino de cima\n");
		reino = 2;
		++moedas;
	}

	if (px == py && reino != 0) {
		// printf("dia %d subiu na muralha\n", dias);
	}

	// printf("Posição atual %d,%d\n", px, py);

	viagem(dias - 1, px, py, reino, moedas);
}


int main() {
	int dias, px, py, reino, moedas;
	px = 0;
	py = 0;
	reino = 0;
	moedas = -1;

	scanf(" %d", &dias);

	// printf("Posição inicial %d,%d\n", px, py);

	viagem(dias, px, py, reino, moedas);

	return 0;
}