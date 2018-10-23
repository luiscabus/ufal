#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Criar uma estrutura de nó para árvore
typedef struct binary_tree {
	int item;
	int h;
	struct binary_tree *left;
	struct binary_tree *right;
} binary_tree;

