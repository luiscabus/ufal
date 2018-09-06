#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
(5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
(5(4(12(7()())(2()()))()) (8(13()())(4()(1()()))))
*/

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
	// printf("Pushando %c tamanho %d\n", c, stack->size);
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
		// printf("Popando %c tamanho %d\n", aux, stack->size);
		// printf("Popando %c tamanho %d\n", ')', stack->size);
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

struct_node * montar_arvore(struct_node *node, int nivel, int valor) {

	if (node == NULL) {
		return node;
	}



	return node;
}

int get_last_int(char *concatenador, int intervalo) {
	int k, valor = 0;
	for (k = 0; k < intervalo; ++k) {
		// printf("Charrr %c\n", concatenador[k]);
		// printf("inttt %d\n", concatenador[k] - '0');
		valor = valor + ((concatenador[k] - '0') * pow(10,intervalo-k-1));
	}
	return valor;
}


int main() {

// 32, 40, 41

	struct_stack * stack = NULL;
	stack = (struct_stack *) malloc(sizeof(struct_stack));

	binary_tree *raiz = NULL;

	char *tree = malloc(sizeof(char) * 200); // um vetor array tipo tree[200]
	char *concatenador = malloc(sizeof(char) * 10); // um vetor array tipo tree[200]

	scanf("%[^\n]s", tree); // guarda o array lido
	int tam = strlen(tree); // vê o tamanho do array lido e começa a violência



	int valor;
	int last_int;
	int last_stack_size = 0;
	int max_stack_size = 0;

	int i, j, k;
	for (i = 0; i < tam; ++i) {
		last_int = 0;

		if (stack->size > max_stack_size) {
			max_stack_size = stack->size;
		}

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
			
			j = i;
			while(tree[j] != '(' && tree[j] != ')' && tree[j] != ' ') {
				concatenador[j-i] = tree[j];
				++j;
			}
			last_int = get_last_int(concatenador, j-i);
			
			printf("Last Int %d\n", last_int);

			i = j - 1;

		}

		printf("Int %d, nivel %d\n", last_int, stack->size);
		last_stack_size = stack->size;
	}

	printf("Max stack size: %d\n", max_stack_size);

	return 0;
}