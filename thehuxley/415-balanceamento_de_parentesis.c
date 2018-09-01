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

int is_empty(struct_stack * stack) {
	if(stack->size == 0) {
		return 1;
	} else {
		return 0;
	}
}

// ([)] CASO TESTE
int main ()
{
	struct_stack * stack = NULL;
	stack = (struct_stack *) malloc(sizeof(struct_stack));

	int i, j, casos;
	scanf(" %d\n", &casos);
	// getchar();

	char c, aux, enne;
	char string[256];
	int flag;

	for (i = 0; i < casos; ++i)
	{	
		

		flag = 1;
		// printf("\n\nCaso %d forrrrroi com C = %c\n", i + 1, c);

		// scanf("%s", string);
		// strcpy(' \0', string);

		// string[0] = ' ';
		scanf("%[^\n]s", string);
		enne = getchar();

		// printf("Peguei: %s em %d\n", string, i + 1);

		for (j = 0; j < strlen(string); ++j) {

			if (string[0] == 'x') {
				break;
			}

			// if (strlen(string) <= 0) {
			// 	break;
			// }

			if (string[j] != ' ') {

				if (string[j] == '[' || string[j] == '(') {
					push(stack, string[j]);
				}
				
				if (string[j] == ']')
				{
					if (pop(stack) != '[') {
						flag = 0;
						break;
					}
				}

				if (string[j] == ')')
				{
					if (pop(stack) != '(') {
						flag = 0;
						break;
					}
				}
				
			}
			// printf("fLAG no while %d stack size %d\n", flag, stack->size);


		}

		for (j = 0; j < 256; ++j) {
			string[j] = 'x';
		}

		if (flag == 1 && stack->size == 0) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}

		// printf("\n\n");
		
		c = 'X';
		while (stack->size > 0) {
			// printf("Limpando stack\n");
			pop(stack);
		}
		stack->top = NULL;
	}


	return 0;
}