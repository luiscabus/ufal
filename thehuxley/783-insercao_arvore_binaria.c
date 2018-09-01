#include <stdio.h>
#include <stdlib.h>

// Criar uma estrutura de nó para árvore
typedef struct binary_tree {
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
} binary_tree;

void create_new_tree(binary_tree **raiz, int valor) {
	binary_tree *new_leaf = malloc(sizeof(binary_tree));
	new_leaf->item = valor;
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	*raiz = new_leaf;
}

void add_to_tree(binary_tree *raiz, int valor) {

	if (valor < raiz->item) {

		if (raiz->left == NULL) {
			binary_tree *new_leaf = malloc(sizeof(binary_tree));
			new_leaf->item = valor;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			raiz->left = new_leaf;
			return;
		} else {
			add_to_tree(raiz->left, valor);
		}

	} else {
		if (raiz->right == NULL) {
			binary_tree *new_leaf = malloc(sizeof(binary_tree));
			new_leaf->item = valor;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			raiz->right = new_leaf;
			return;
		} else {
			add_to_tree(raiz->right, valor);
		}

	}
	
}

void print_tree(binary_tree *raiz, int nivel) {

	if (raiz == NULL) {
		printf(" () ");
		return;
	} else {
		printf(" ( %d ", raiz->item);
	}

	print_tree(raiz->left, ++nivel);
	print_tree(raiz->right, ++nivel);

	printf(") ");
}


int main() {

	binary_tree *raiz = NULL;


	int item;

	printf("  ");

	while (scanf(" %d", &item) != EOF) {

		if (item == 999) {
			break;
		}

		if (raiz == NULL) {
			create_new_tree(&raiz, item);
		} else {
			printf("----\n");
			add_to_tree(raiz, item);

			printf("Adicionando %d\n", item);
			printf("  ");
			print_tree(raiz, 0);
			printf("\n");
		}

	}

	printf("----\n");

	return 0;
}