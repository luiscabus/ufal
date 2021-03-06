#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int current;
int chars_array[1000];

typedef struct struct_tree {
	int value;
	struct struct_tree *left;
	struct struct_tree *right;
} struct_tree;

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

	int i; // inicializa o chars_array
	for(i = 0; i < 1000; i++){
		chars_array[i] = -1;
	}

	struct_tree *my_tree = NULL;
	gets(chars_array);

	current = 0;
	my_tree = build_tree(chars_array);

	i = 0;
	while(1) {
		printf("string valor %d\n", chars_array[i]);

		if(chars_array[i] == -1){
			break;
		} else {
			if((chars_array[i+1] != -1)  && chars_array[i+1] < chars_array[i]){
				printf("FALSO\n");
				return 0;
			}
			i++;
		}
	}

	printf("VERDADEIRO\n");

	return 0;
}