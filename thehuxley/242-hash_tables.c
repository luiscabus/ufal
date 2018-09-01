#include <stdio.h>
#include <stdlib.h>

// Criar uma estrutura de nó para lista
typedef struct struct_node {
	int item;
	struct struct_node *next;
} struct_node;

int inserir_no_final(struct_node **head, int valor_a_adicionar) {

	// printf("%p\n", *head);

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

void print_list(struct_node * head) {
	// printf("Printando lista de endereço: %p\n", head);
	struct_node * current = head;

	if (head == NULL) {
		printf("\\\n");
		return;
	}

	int i = 1;
	while (current != NULL) {
		// printf("Nó %d valor: ", i);
		printf("%d -> ", current->item);
		current = current->next;
		++i;
	}
	printf("\\\n");
}

int hash(int chave, int tamanho_do_array) {
	return chave % tamanho_do_array;
}

int main() {

	int casos_de_teste = 0;
	int tamanho_do_array = 0;
	int qtd_de_chaves = 0;
	int chave = 0;

	int i, j, k;

	scanf(" %d", &casos_de_teste);

	for (i = 0; i < casos_de_teste; ++i) {
		// printf("To no caso de teste %d\n", i);

		scanf("%d %d\n", &tamanho_do_array, &qtd_de_chaves);

		struct_node **array_chaves = malloc(sizeof(struct_node*) * tamanho_do_array);

		// struct_node *array_chaves[tamanho_do_array];

		// for (j = 0; j < tamanho_do_array; ++j) {
		// 	array_chaves[j] = NULL;
		// }
		
		for (j = 0; j < qtd_de_chaves; ++j) {
			scanf("%d", &chave);

			inserir_no_final( &array_chaves[hash(chave, tamanho_do_array)], chave);

		}

		for (j = 0; j < tamanho_do_array; ++j) {
			printf("%d -> ", j);
			print_list(array_chaves[j]);
		}
		printf("\n");

	}

	return 0;
}