#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Criar uma estrutura de nó para árvore
typedef struct binary_tree {
	char letra;
	int valor;
	struct binary_tree *left;
	struct binary_tree *right;
} binary_tree;

void create_new_tree(binary_tree **raiz, char letra, int valor) {
	binary_tree *new_leaf = malloc(sizeof(binary_tree));
	new_leaf->letra = letra;
	new_leaf->valor = valor;
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	*raiz = new_leaf;
}

void add_to_tree(binary_tree *raiz, char letra, int valor) {

	if (valor < raiz->valor) {

		if (raiz->left == NULL) {
			binary_tree *new_leaf = malloc(sizeof(binary_tree));
			new_leaf->letra = letra;
			new_leaf->valor = valor;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			raiz->left = new_leaf;
			return;
		} else {
			add_to_tree(raiz->left, letra, valor);
		}

	} else {
		if (raiz->right == NULL) {
			binary_tree *new_leaf = malloc(sizeof(binary_tree));
			new_leaf->letra = letra;
			new_leaf->valor = valor;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			raiz->right = new_leaf;
			return;
		} else {
			add_to_tree(raiz->right, letra, valor);
		}

	}

}

char what_char_is_this(char string[200]) {
	char letra;

	return letra;
}

void print_tree(binary_tree *raiz, int nivel) {

	if (raiz == NULL) {
		printf("() ");
		return;
	} else {
		printf("( %c ", raiz->letra);
	}

	print_tree(raiz->left, ++nivel);
	print_tree(raiz->right, ++nivel);

	printf(") ");
}


int main() {

	binary_tree *raiz = NULL;

	char origem_da_arvore[28] = "MGTCKQWAEILORUY BDFHJNPSVXZ";
	char letra;
	int valor, i, j;

	for (i = 0; i < strlen(origem_da_arvore); ++i)
	{
		letra = origem_da_arvore[i];
		valor = (int)origem_da_arvore[i];

		// printf("Letra %c Valor %d\n", letra, valor);

		if (raiz == NULL) {
			create_new_tree(&raiz, letra, valor);
		} else {
			add_to_tree(raiz, letra, valor);
		}
	}

	// print_tree(raiz, 0);
	char caractere;
	binary_tree *tree = NULL;
	tree = raiz;

	while(scanf("%c", &caractere) != EOF) {
		
		if (caractere == '*') {
			printf("%c", tree->letra);
			tree = raiz;
		} else if (caractere == '-') {
			// go left
			tree = tree->left;

		} else if (caractere == '|'){
			// go right
			tree = tree->right;
		}

	}

	printf("\n");





	return 0;
}