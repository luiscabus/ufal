#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
		return aux;
	}
}



int main ()
{
	struct_stack * stack = NULL;
	stack = (struct_stack *) malloc(sizeof(struct_stack));

	struct_stack * stack_f = NULL;
	stack_f = (struct_stack *) malloc(sizeof(struct_stack));

	char string[20];

	while ( scanf("%[^\n]s", string) != EOF ) {
		if (strcmp(string, "ENTER")) {
			push(stack, ' ');
			while (stack_f->size > 0) {
				pop(stack_f);
			}
		}
		if (strcmp(string, "BACK")) {
			push(stack_f, ' ');
			pop(stack);
		}
		if (strcmp(string, "FORWARD")) {
			push(stack, ' ');
			pop(stack_f);
		}
	}

	printf("BACK: %d\n", stack->size);
	printf("FORWARD: %d\n", stack_f->size);



	return 0;
}