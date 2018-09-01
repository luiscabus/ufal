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

int remover_do_inicio(struct_node **head) {
	struct_node *node_auxiliar = NULL;
	node_auxiliar = *head;

	if (*head == NULL) {
		printf("Não posso remover do início, a lista está vazia.\n");
		return 0;
	}

	if ((*head)->next == NULL) {
		printf("Último item removido do início %d\n", (*head)->item);
		*head = NULL;
		return 0;
	}

	if ((*head)->next != NULL) {
		printf("Item removido no início: %d\n", (*head)->item);
		*head = (*head)->next;
	}
	free(node_auxiliar);
	return 1;

}


int inserir_no_final(struct_node **head, int valor_a_adicionar) {

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
	new_node->next = NULL;

	if (*head == NULL) {
		*head = new_node;
	} else {
		// Percorre a lista até encontar o node final e adiciona o novo lá
		struct_node *current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}

	return 0;
}

int remover_do_final(struct_node **head) {

	// Criar um nó
	struct_node *node_penultimo = *head;
	struct_node *node_ultimo = *head;

	if (*head == NULL) {
		printf("Não posso remover do final, a lista está vazia.\n");
		return 0;
	}

	if ((*head)->next == NULL) {
		printf("Último item removido do final %d\n", (*head)->item);
		*head = NULL;
		return 0;
	}

	// Percorre a lista até encontar o node final e adiciona o novo lá
	while (node_ultimo->next != NULL) {
		node_penultimo = node_ultimo;
		node_ultimo = node_penultimo->next;
	}
	node_penultimo->next = NULL;
	printf("Item removido no final %d\n", node_ultimo->item);
	free(node_ultimo);

	return 0;
}


void print_list(struct_node * head) {
	printf("Printando lista de endereço: %p\n", head);
	struct_node * current = head;

	if (head == NULL) {
		printf("Lista vazia.\n");
		return;
	}

	int i = 1;
	while (current != NULL) {
		printf("Nó %d valor: ", i);
		printf("%d\n", current->item);
		current = current->next;
		++i;
	}
}

void print_list_address(struct_node * head) {
	// printf("Printando lista de endereço: %p\n", head);
	struct_node * current = head;

	if (head == NULL) {
		printf("Lista vazia.\n");
		return;
	}

	int i = 1;
	while (current != NULL) {
		// printf("Nó %d valor: ", i);
		printf("%p ", current->next);
		current = current->next;
		++i;
	}
}

int main() {

	system("clear");
	printf("----- início do programa ----- \n\n");


	// Declara ponteiro do tipo nó, chamada head, que aponta para vazio
	// void *head = NULL;
	struct_node *head = NULL;
	printf("Printando head: %p\n", head); // Deve imprimir 0x0, pois o ponteiro está NULL, ou seja, a lista está vazia


	inserir_no_inicio(&head, 3);
	inserir_no_inicio(&head, 2);
	inserir_no_inicio(&head, 1);
	inserir_no_final(&head, 10);
	inserir_no_final(&head, 20);
	inserir_no_final(&head, 30);
	print_list(head);

	remover_do_inicio(&head);
	remover_do_inicio(&head);
	remover_do_inicio(&head);

	print_list(head);

	remover_do_final(&head);
	remover_do_final(&head);
	remover_do_final(&head);


	print_list(head);


	remover_do_inicio(&head);
	remover_do_final(&head);



	printf("\n----- final do programa ----- \n\n\n");
	return 0;
}