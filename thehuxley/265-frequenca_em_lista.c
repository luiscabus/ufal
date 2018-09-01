#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Criar uma estrutura de nó para lista
typedef struct char_node {
	char item;
	int qtd;
	struct char_node *next;
} char_node;

int remover_do_final(char_node **head) {

	// Criar um nó
	char_node *node_penultimo = *head;
	char_node *node_ultimo = *head;

	if (*head == NULL) {
		// printf("Não posso remover do final, a lista está vazia.\n");
		return 0;
	}

	if ((*head)->next == NULL) {
		// printf("Último item removido do final %d\n", (*head)->item);
		*head = NULL;
		return 0;
	}

	// Percorre a lista até encontar o node final e adiciona o novo lá
	while (node_ultimo->next != NULL) {
		node_penultimo = node_ultimo;
		node_ultimo = node_penultimo->next;
	}
	node_penultimo->next = NULL;
	// printf("Item removido no final %c\n", node_ultimo->item);
	free(node_ultimo);

	return 0;
}

int inserir_no_final(char_node **head, char item, int qtd) {

	// Criar um nó
	char_node *new_node = NULL;

	// Alocar o nó na memória e fazer ele apontar para um endereço
	new_node = (char_node *) malloc(sizeof(char_node));

	// Conferir se houve espaço na memória
	if ( new_node == NULL ) {
		puts("Faltou memória"); //Imprime a string adicionando \n
		return -1;
	}

	// Coloca no valor do nó o valor informado
	new_node->item = item;
	new_node->qtd = qtd;
	new_node->next = NULL;

	if (*head == NULL) {
		*head = new_node;
	} else {
		// Percorre a lista até encontar o node final e adiciona o novo lá
		char_node *current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}

	return 0;
}

void print_list(char_node * head) {
	// printf("Printando lista de endereço: %p\n", head);
	char_node * current = head;

	if (head == NULL) {
		printf("Lista vazia.\n");
		return;
	}

	int i = 1;
	while (current != NULL) {
		printf("%c %d\n", current->item, current->qtd);
		current = current->next;
		++i;
	}

	printf("\n");
}




int main() {

	char_node *head = NULL; // Declara ponteiro do tipo nó, chamada head, que aponta para vazio

	char letras[300] = {};
	char item;
	int i;

	for (i = 0; i < 300; ++i) {
		letras[i] = 0;
	}

	while ((item = getchar()) != EOF) {
		letras[item] = letras[item] + 1;
	}

	// for (i = 0; i < 5; ++i) {
	// 	item = getchar();
	// 	letras[item] = letras[item] + 1;
	// }

	for (i = 299; i > -1; --i) {
		if (letras[i] != 0) {
			// printf("%c %d\n", i, letras[i]);
			inserir_no_final(&head, i, letras[i]);
		}
	}


	print_list(head);


	return 0;
}