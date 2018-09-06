#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criar uma estrutura de nó para árvore
typedef struct binary_tree {
	int item;
	int h;
	struct binary_tree *left;
	struct binary_tree *right;
} binary_tree;



int max(int a, int b) {
	return (a > b) ? a : b;
}

int h(binary_tree *bt) {
	if (bt == NULL) {
		return -1;
	} else {
		return 1 + max( h(bt->left), h(bt->right) );
	}
}

int is_balanced(binary_tree *bt) {
	int bf = h(bt->left) - h(bt->right);
	return ( (-1 <= bf) && (bf <= 1) );
}

int balance_factor(binary_tree *bt) {
	if (bt == NULL) {
		return 0;
	} else if ( (bt->left != NULL) && (bt->right != NULL) ) {
		return (bt->left->h - bt->right->h); 
	} else if ( (bt->left != NULL) && (bt->right == NULL) ) {
		return (1 + bt->left->h);
	} else {
		return (- bt->right->h - 1);
	}
}

binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right) {
	binary_tree *new_leaf = malloc(sizeof(binary_tree));
	new_leaf->item = item;
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	// *raiz = new_leaf;
	return new_leaf;
}

binary_tree* rotate_left(binary_tree *bt) {
	binary_tree *subtree_root = NULL;
	if (bt != NULL && bt->right != NULL) {
		subtree_root = bt->right;
		bt->right = subtree_root->left;
		subtree_root->left = bt;
	}
	subtree_root->h = h(subtree_root);
	bt->h = h(bt);
	return subtree_root;
}

binary_tree* rotate_right(binary_tree *bt) {
	binary_tree *subtree_root = NULL;
	if (bt != NULL && bt->left != NULL) {
		subtree_root = bt->left;
		bt->left = subtree_root->right;
		subtree_root->right = bt;
	}
	subtree_root->h = h(subtree_root);
	bt->h = h(bt);
	return subtree_root;
}

void create_new_tree(binary_tree **raiz, int valor) {
	binary_tree *new_leaf = malloc(sizeof(binary_tree));
	new_leaf->item = valor;
	new_leaf->h = 0;
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	*raiz = new_leaf;
}

void print_tree(binary_tree *raiz, int nivel) {

	if (raiz == NULL) {
		printf(" () ");
		return;
	} else {
		// printf(" ( %d ", raiz->item);
		printf(" ( %d ", raiz->item);
	}

	print_tree(raiz->left, ++nivel);
	print_tree(raiz->right, ++nivel);

	printf(") ");
}


binary_tree* add_to_tree(binary_tree *raiz, int valor) {

	if (raiz == NULL) {
		return create_binary_tree(valor, NULL, NULL);
	} else if (raiz->item > valor) {
		raiz->left = add_to_tree(raiz->left, valor);
	} else {
		raiz->right = add_to_tree(raiz->right, valor);
	}

	raiz->h = h(raiz);
	binary_tree *child;

	if (balance_factor(raiz) == 2 || balance_factor(raiz) == -2) {
		if (balance_factor(raiz) == 2) {
			child = raiz->left;
			if (balance_factor(child) == -1) {
				raiz->left = rotate_left(child);
			}
			raiz = rotate_right(raiz);
		} else if (balance_factor(raiz) == -2) {
			child = raiz->right;
			if (balance_factor(child) == 1) {
				raiz->right = rotate_right(child);
			}
			raiz = rotate_left(raiz);
		}
	}

	// return *raiz;
	return raiz;
	
}



int main() {

	binary_tree *raiz = NULL;


	int item;
	int flag = 0;

	printf("  ");

	while (scanf(" %d", &item) != EOF) {

		if (item == 999) {
			break;
		}

		if (raiz == NULL) {
			create_new_tree(&raiz, item);
			printf("----\n");
			printf("Adicionando %d\n", item);
			printf("Continuou AVL...\n");
			printf("  ");
			print_tree(raiz, 0);
			printf("\n");

		} else {
			printf("----\n");

			printf("Adicionando %d\n", item);

			if (1 == 1) {
				printf("Continuou AVL...\n");
				printf("  ");
				raiz = add_to_tree(raiz, item);
				print_tree(raiz, 0);
				printf("\n");
			} else {
				printf("Antes de ajustar balanceamento...\n");
				printf("  ");
				print_tree(raiz, 0);
				printf("\n");
				raiz = add_to_tree(raiz, item);
				printf("Depois de ajustar balanceamento...\n");
				printf("  ");
				print_tree(raiz, 0);
				printf("\n");
			}
			

		}

	}

	// printf("----\n");

	return 0;
}