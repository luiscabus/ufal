#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int current,vetor[1000], indice = 0;

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

void find_tree(tree *bt, int busca) {
	if(bt == NULL) {
		return;
	}
	find_tree(bt->left, busca);
	vetor[indice] = bt->value;
	indice++;
	find_tree(bt->right, busca);
}
tree* create_first_tree(){
	return NULL;
}

int main() {
	char string[500];
	int n, i;
	for(i = 0; i < 1000; i++){
	    vetor[i] = -1;
	}
	tree *bt = create_first_tree;
	gets(string);
	current = 0;
	bt = make_tree(string);
	scanf("%d", &n);
	find_tree(bt, n);
	i =0;
	while(1){
	    if(vetor[i] == -1){
	        break;
	    }else{
	        if((vetor[i+1] != -1)  && vetor[i+1] < vetor[i]){
	            printf("FALSO\n");
	            return 0;
	        }
	        i++;
	    }
	}
	printf("VERDADEIRO\n");
	return 0;
}