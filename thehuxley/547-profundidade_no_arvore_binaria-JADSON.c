#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int current, encontrou;

typedef struct Tree tree;

struct Tree {
    int value;
    tree *left;
    tree *right;
};

tree *createTree(int value, tree *left, tree *right) {
	tree *new_tree = (tree*) malloc(sizeof(tree));
	new_tree->value = value;
	new_tree->left = right;
	new_tree->right = left;
	return new_tree;
}

tree *make_tree(char *string) {
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
	char num[1000];
	for(i = 0; isdigit(string[current]); current++, i++) {
		num[i] = string[current];
	}
	
	return createTree(atoi(num), make_tree(string), make_tree(string));
}

void find_tree(tree *bt, int busca, int nivel) {
	if(bt == NULL) {

		return;
	}
	if(bt->value == busca) {
		printf("ESTA NA ARVORE\n%d", nivel);
		encontrou = 1;
		return;
	}
	find_tree(bt->left, busca, nivel + 1);
	find_tree(bt->right, busca, nivel + 1);
}
tree* create_first_tree(){
	return NULL;
}

int main() {
	char string[500];
	int n;
	tree *bt = create_first_tree;
	gets(string);
	current = 0;
	encontrou = 0;
	bt = make_tree(string);
	scanf("%d", &n);
	find_tree(bt, n, 0);
	if(encontrou == 0) {
		printf("NAO ESTA NA ARVORE\n-1");
	}
	return 0;
}