#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Criar uma estrutura de nó para lista
typedef struct struct_node {
	int item;
	struct struct_node *next;
} struct_node;

int inserir_no_inicio(struct_node **head, int valor_a_adicionar) {

	// Criar um nó
	struct_node *new_node = NULL;

	// Alocar o nó na memória e fazer ele apontar para um endereço
	new_node = (struct_node *) malloc(sizeof(struct_node));

	// Conferir se houve espaço na memória
	if ( new_node == NULL ) {
		puts("Faltou memória"); //Imprime a string adicionando \n
		return -1;
	}

	// Coloca no valor do nó o valor informado
	new_node->item = valor_a_adicionar;
	// Faz o next do nó apontar para onde apontava o head
	new_node->next = *head;
	// Atualiza o head para que aponte para o novo nó
	*head = new_node;

	return 0;
}

int inserir_ordenado(struct_node **head, int item) {
	struct_node *aux = NULL;
	aux = *head;
	while (aux->next != NULL && aux->next->item < item) {
		aux = aux->next;
	}

	struct_node *new_node = NULL;
	new_node = (struct_node *) malloc(sizeof(struct_node));
	new_node->item = item;
	new_node->next = aux->next;
	aux->next = new_node;

	return 0;
}

int search_list(struct_node *head, int item) {
	struct_node * current = head;

	if (current == NULL) {
		printf("Lista vazia.\n");
		return 0;
	}

	while (current != NULL) {
		if (item == current->item) {
			// current->item = 88;
			return 1;
		}
		current = current->next;
	}

	return 0;
}

void print_list(struct_node * head) {
	// printf("Printando lista de endereço: %p\n", head);
	struct_node * current = head;

	if (head == NULL) {
		printf("Lista vazia.\n");
		return;
	}

	int i = 1;
	while (current != NULL) {
		printf("%d ", current->item);
		current = current->next;
		++i;
	}

	printf("\n");
}


int main() {

	struct_node *head1 = NULL; // Declara ponteiro do tipo nó, chamada head, que aponta para vazio
	struct_node *head2 = NULL; // Declara ponteiro do tipo nó, chamada head, que aponta para vazio

	int i, qtd1, qtd2, item1, item2;

	scanf(" %d", &qtd1);

	for (i = 0; i < qtd1; ++i) {

		scanf("%d", &item1);

		if (head1 == NULL || head1->item >= item1) {
			inserir_no_inicio(&head1, item1);		
		} else {
			inserir_ordenado(&head1, item1);
		}

	}

	scanf(" %d", &qtd2);

	for (i = 0; i < qtd2; ++i) {

		scanf("%d", &item2);

		if (head2 == NULL || head2->item >= item2) {
			inserir_no_inicio(&head2, item2);		
		} else {
			inserir_ordenado(&head2, item2);
		}

	}



	int sublist = 1;
	while (head2 != NULL) {
		if (!search_list(head1, head2->item)) {
			sublist = 0;
		}
		head2 = head2->next;
	}

	if (sublist == 1) {
		printf("1\n");
	} else {
		printf("0\n");
	}


	// print_list(head1);
	// print_list(head2);

	return 0;
}