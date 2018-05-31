#include <stdio.h>

void initArray(int array[][3], int i, int linhas) {
	if (i == linhas) {
		return;
	}
	array[i][0] = -1;
	array[i][1] = -1;
	array[i][2] = 0;
	initArray(array, i + 1, linhas);
}

void initNiveis(int array[][2], int i, int linhas) {
	if (i == linhas) {
		return;
	}
	array[i][0] = 100000;
	array[i][1] = 0;
	initNiveis(array, i + 1, linhas);
}

void buildPaisArray(int array[][3], int i, int num_de_nos) {
	if (i == num_de_nos) {
		return;
	}

	int filho_esquerda, filho_direita, valor;

	scanf(" %d %d %d", &valor, &filho_esquerda, &filho_direita);

	array[i][0] = valor;
	array[i][1] = filho_esquerda;
	array[i][2] = filho_direita;

	buildPaisArray(array, i + 1, num_de_nos);
}

void acharMaiorTamanho(int arvore[][3], int no_atual, int tamanho_atual, int *maiortamanho, int niveis[50][2]) {
	if (no_atual == -1) {
		return;
	}

	++tamanho_atual;

	// printf("Estou no nó %d com os filhos %d e %d e meço %d\n", no_atual, arvore[no_atual][0], arvore[no_atual][1], tamanho_atual);
	// printf("Estou no nó %d com os filhos %d e %d e tenho nível %d\n", no_atual, arvore[no_atual][0], arvore[no_atual][1], tamanho_atual);

	acharMaiorTamanho(arvore, arvore[no_atual][1], tamanho_atual, maiortamanho, niveis);
	acharMaiorTamanho(arvore, arvore[no_atual][2], tamanho_atual, maiortamanho, niveis);

	if (tamanho_atual > *maiortamanho) {
		*maiortamanho = tamanho_atual;
	}


	// printf("Estou no nível %d o menor é %d o maior é %d comparar com %d\n", tamanho_atual, niveis[tamanho_atual-1][0], niveis[tamanho_atual-1][1], arvore[no_atual][0]);

	if (niveis[tamanho_atual-1][0] > arvore[no_atual][0]) {
		niveis[tamanho_atual-1][0] = arvore[no_atual][0];
	}
	if (niveis[tamanho_atual-1][1] < arvore[no_atual][0]) {
		niveis[tamanho_atual-1][1] = arvore[no_atual][0];
	}

	// printf("ATLZ Estou no nível %d o menor é %d o maior é %d comparar com %d\n", tamanho_atual, niveis[tamanho_atual-1][0], niveis[tamanho_atual-1][1], arvore[no_atual][0]);

}

void printNiveis(int niveis[][2], int i, int lim) {
	if (i == lim) {
		return;
	}

	printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, niveis[i][1], niveis[i][0]);

	printNiveis(niveis, i + 1, lim);
}

int main() {
	int num_de_nos;
	scanf(" %d", &num_de_nos);

	int arvore[num_de_nos][3];
	initArray(arvore, 0, num_de_nos);
	buildPaisArray(arvore, 0, num_de_nos);

	// for (int i = 0; i < num_de_nos; ++i)
	// {
	// 	printf("Posicao %d valor %d filho_esquerda %d filho_direita %d\n", i, arvore[i][0], arvore[i][1], arvore[i][2]);
	// }

	int niveis[50][2];
	initNiveis(niveis, 0, 50);

	int maiortamanho;
	maiortamanho = 0;
	acharMaiorTamanho(arvore, 0, 0, &maiortamanho, niveis);
	// printf("%d\n", maiortamanho);

	// for (int i = 0; i < maiortamanho; ++i)
	// {
	// 	printf("Posicao %d menor valor %d maior valor %d \n", i, niveis[i][0], niveis[i][1]);
	// }

	printNiveis(niveis, 0, maiortamanho);
	

	return 0;
}