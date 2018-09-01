#include <stdio.h>
#include <stdlib.h>

int hash(char c, int j, int k) {
	return (c - 65 + j + k);
}
int main() {

	int casos_de_teste = 0;
	int linhas_a_seguir = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	char caractere;
	int soma_total = 0;

	scanf(" %d", &casos_de_teste);

	for (i = 0; i < casos_de_teste; ++i) {
		// printf("Loop dos casos de teste %d\n", i);
		scanf(" %d\n", &linhas_a_seguir);
		
		for (j = 0; j < linhas_a_seguir; ++j) {
			// printf("Loop da linha %d do caso de teste %d\n", j, i);
			for (k = 0; k < 50; ++k) {
				// printf("Loop do caractere %d da linha %d caso de teste %d\n", k, j, i);
				scanf("%c", &caractere);
				if (caractere == '\n') {
					break;
				}
				soma_total = soma_total + hash(caractere, j, k);
				// soma_total = soma_total + (caractere - 65 + j + k);
				// printf("Tenho caractere %c %d, linha %d, coluna %d\n", caractere, caractere, j, k);
			}
		}

		printf("%d\n", soma_total);
		soma_total = 0;
	}

	return 0;
}