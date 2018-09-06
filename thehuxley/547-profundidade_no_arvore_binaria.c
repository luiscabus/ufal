#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int current, gotyou;

typedef struct Stree struct_tree;

struct Stree {
	int value;
	struct_tree *left;
	struct_tree *right;
};


struct_tree *createTree(int value, struct_tree *left, struct_tree *right) {
	struct_tree *new_tree = (struct_tree*) malloc(sizeof(struct_tree));
	new_tree->value = value;
	new_tree->left = right;
	new_tree->right = left;
	return new_tree;
}

struct_tree *build_tree(char *string) {
	if(current == strlen(string)) {
		return NULL;
	}

	while((string[current] == '(') || (string[current] == ' ')) {
		current++;
	}
	
	if (string[current] == ')') {
		while(string[current] == ')') {
			current++;
		}
		return NULL;
	}

	int i;
	char numeros[1000];
	for(i = 0; isdigit(string[current]); current++, i++) {
		numeros[i] = string[current];
	}
	
	return createTree(atoi(numeros), build_tree(string), build_tree(string));
}

void search_in_tree(struct_tree *binary_tree, int busca, int nivel) {
	if(binary_tree == NULL) {
		return;
	}

	if(binary_tree->value == busca) {
		printf("ESTA NA ARVORE\n%d", nivel);
		gotyou = 1;
		return;
	}

	search_in_tree(binary_tree->left, busca, nivel + 1);
	search_in_tree(binary_tree->right, busca, nivel + 1);
}


int main() {
	char string[1000];

	int numero;

	struct_tree *binary_tree = NULL;

	gets(string);
	current = 0;
	gotyou = 0;

	binary_tree = build_tree(string);

	scanf("%d", &numero);
	
	search_in_tree(binary_tree, numero, 0);
	
	if(gotyou == 0) {
		printf("NAO ESTA NA ARVORE\n");
		printf("-1");
	}
	
	return 0;
}