#include <stdio.h>

void buildPaisArray(int array[][2], int i, int num_de_nos) {
	if (i == num_de_nos) {
		return;
	}

	int filho_esquerda, filho_direita;

	scanf(" %d %d", &filho_esquerda, &filho_direita);

	array[i][0] = filho_esquerda;
	array[i][1] = filho_direita;

	buildPaisArray(array, i + 1, num_de_nos);
}


void acharNosQueTemFolhas(int arvore[][2], int no_atual, int pai_do_atual, int paiscomfolhas[]) {
	if (no_atual == -1) {
		return;
	}

	// printf("Estou no nó %d com os filhos %d e %d \n", no_atual, arvore[no_atual][0], arvore[no_atual][1]);

	acharNosQueTemFolhas(arvore, arvore[no_atual][0], no_atual, paiscomfolhas);
	acharNosQueTemFolhas(arvore, arvore[no_atual][1], no_atual, paiscomfolhas);

	if (arvore[no_atual][0] == -1 && arvore[no_atual][1] == -1) {
		// printf("Atual: %d é folha\n", pai_do_atual);
		paiscomfolhas[pai_do_atual] = 1;
	}

}

// void registrar_pais(int paiscomfolhas[], int posicao) {
// 	paiscomfolhas[posicao] = 1;
// }

void limpar_paiscomfolhas(int paiscomfolhas[], int i, int limite) {
	if (i == limite) {
		return;
	}
	paiscomfolhas[i] = 0;
	limpar_paiscomfolhas(paiscomfolhas, i + 1, limite);
}

void printar_paiscomfolhas(int paiscomfolhas[], int i, int limite) {
	if (i == limite) {
		return;
	}
	if (paiscomfolhas[i] != 0) {
		// printf("Pai com folha %d\n", i);			
		printf("%d\n", i);			
	}
	printar_paiscomfolhas(paiscomfolhas, i + 1, limite);
}


int main() {
	int num_de_nos;
	scanf("%d", &num_de_nos);

	int arvore[num_de_nos][2];
	buildPaisArray(arvore, 0, num_de_nos);


	int paiscomfolhas[num_de_nos];
	limpar_paiscomfolhas(paiscomfolhas, 0, num_de_nos);


	acharNosQueTemFolhas(arvore, 0, 0, paiscomfolhas);

	printar_paiscomfolhas(paiscomfolhas, 0, num_de_nos);

}