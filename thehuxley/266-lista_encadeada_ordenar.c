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
}


int main() {

	struct_node *head = NULL; // Declara ponteiro do tipo nó, chamada head, que aponta para vazio

	int item;

	while (scanf(" %d", &item) != EOF && item != 99) {

		// printf("Recebido item %d\n", item);

		if (head == NULL || head->item >= item) {
			// Iniciando a lista ou inserindo na head o menor valor
			inserir_no_inicio(&head, item);		
		} else {
			// O valor do item é maior que a cabeça, insere no meio ou no final
			inserir_ordenado(&head, item);
		}

	}


	print_list(head);

	return 0;
}