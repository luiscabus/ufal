#include <stdio.h>

void initArray(int array[][2], int i, int linhas) {
	if (i == linhas) {
		return;
	}
	array[i][0] = -1;
	array[i][1] = -1;
	initArray(array, i + 1, linhas);
}

void buildPaisArray(int array[][2], int i, int num_de_pais) {
	if (i == num_de_pais) {
		return;
	}

	int no, filho_esquerda, filho_direita;

	scanf(" %d %d %d", &no, &filho_esquerda, &filho_direita);

	array[no][0] = filho_esquerda;
	array[no][1] = filho_direita;

	buildPaisArray(array, i + 1, num_de_pais);
}

void acharMaiorTamanho(int arvore[][2], int no_atual, int tamanho_atual, int *maiortamanho) {
	if (no_atual == -1) {
		return;
	}

	++tamanho_atual;

	// printf("Estou no nó %d com os filhos %d e %d e meço %d\n", no_atual, arvore[no_atual][0], arvore[no_atual][1], tamanho_atual);

	acharMaiorTamanho(arvore, arvore[no_atual][0], tamanho_atual, maiortamanho);
	acharMaiorTamanho(arvore, arvore[no_atual][1], tamanho_atual, maiortamanho);

	if (tamanho_atual > *maiortamanho) {
		*maiortamanho = tamanho_atual;
	}

}

int main() {
	int num_de_nos, num_de_pais, origem;
	scanf(" %d %d %d", &num_de_nos, &num_de_pais, &origem);

	int arvore[num_de_nos][2];

	initArray(arvore, 0, num_de_nos);

	buildPaisArray(arvore, 0, num_de_pais);

	
	int maiortamanho;
	maiortamanho = 0;

	acharMaiorTamanho(arvore, origem, 0, &maiortamanho);

	// for (int i = 0; i < num_de_nos; ++i)
	// {
	// 	printf("Posição %d filho_e %d filho_d %d\n", i, arvore[i][0], arvore[i][1]);
	// }

	printf("%d\n", maiortamanho);


}


	// n_nós = 7
	// pais = 3 (que tem filhos) [só leio três pares]
	// origem = 0 


	// inicializar o array no[n_nós][2]

	// no[0][0] = 1
	// no[0][1] = 2

	// no[1][0] = 3
	// no[1][1] = 4

	// no[2][0] = 5
	// no[2][1] = 6




	// 								0 - 1 2
	// 				1 - 3 4								2 - 5 6
	// 		3 - -1 -1		4 - -1 -1			5 - -1 -1 		6 - -1 -1




