#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

node* search(node *head, void *item, int (*equal)(void *item1, void *item2)) {
	
}

void print_linked_list_of_integers() {
	
}

int main() {

	printf("Digite seu telefone (com 4 digitos) e DDD (com 2 digitos)\n");
	int telefone;
	scanf(" %d", &telefone);

	
	int nDigits = floor(log10(abs(telefone))) + 1;

	int i;
	for (i = 0; i < nDigits; ++i)
	{
		/* code */
	}

	struct node
	{
		void * item;
		node * next;
	};






	return 0;
}