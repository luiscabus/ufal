#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criar uma estrutura de nó para árvore
typedef struct binary_tree {
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
} binary_tree;

// Cria uma pilha para os parêntesis
typedef struct struct_node
{
	char item;
	struct struct_node *next;
} struct_node;
typedef struct struct_stack
{
	int size;
	struct struct_node *top;
} struct_stack;

void push (struct_stack * stack, char c) // Add to stack
{
	struct_node *new_node = (struct_node *) malloc(sizeof(struct_node));
	new_node->item = c;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size = stack->size + 1;
	printf("Pushando %c tamanho %d\n", c, stack->size);
	return;
}

char pop (struct_stack * stack) // Rem from stack
{
	char aux;
	if (stack->size == 0)
	{
		// printf ("Stack is Empty\n");
		return 'X';
	}
	else
	{
		--stack->size;
		struct_node *old_node = stack->top;
		stack->top = stack->top->next;
		aux = old_node->item;
		free(old_node);
		printf("Popando %c tamanho %d\n", aux, stack->size);
		return aux;
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

// 32, 40, 41

	struct_stack * stack = NULL;
	stack = (struct_stack *) malloc(sizeof(struct_stack));

	binary_tree *raiz = NULL;

	char *tree = malloc(sizeof(char) * 200);

	scanf("%[^\n]s", tree);
	int tam = strlen(tree);

	int i;
	for (i = 0; i < tam; ++i) {

		// printf("%c = ", tree[i]);

		if (tree[i] == ' ') { }

		if (tree[i] == '(') {
			// empilha
			// printf("%c\n", tree[i]);
			push(stack, tree[i]);
		}

		if (tree[i] == ')') {
			// desempilha
			// printf("%c\n", tree[i]);
			pop(stack);
		}

		if (tree[i] != '(' && tree[i] != ')' && tree[i] != ' ') {
			// printf("%d\n", tree[i] - '0');
		}

	}


	return 0;
}