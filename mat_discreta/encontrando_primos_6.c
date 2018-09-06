#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Criar uma estrutura de nó para lista
typedef struct struct_node {
	int item;
	struct struct_node *next;
} struct_node;

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
		return 0;
	}

	// Percorre a lista até encontar o node final e adiciona o novo lá
	struct_node *current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;

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
		// printf("Nó %d valor: ", i);
		printf("%d ", current->item);
		current = current->next;
		++i;
	}
}

int primom(int numero){ 
	
	if (numero == 1 || numero == 2 || numero == 3) {
		return numero;
	}
	if (numero % 2 == 0 || numero % 3 == 0) {
		return 0;
	}

	int i = 5;
	int w = 2;

	while (i * i <= numero) {
		if (numero % i == 0) {
			return 0;
		}
		// printf("Testando se %d é divisível por %d - com w=%d\n", numero, i, w);

		i += w;
		w = 6 - w;
	}

	return numero;
}

int main() {

	clock_t t;
	t = clock();

	struct_node *head = NULL;


	int i = 5;
	int w = 2;

	while (i < 9999) {
		// printf("--- Enviando o %d\n", i);
		
		if (primom(i)) {
			printf("%d ", i);
			inserir_no_final(&head, i);
		}

		i += w;
		w = 6 - w;
	}

	// print_list(head);

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\ntook %f seconds to execute \n", time_taken);
	
	return 0;
}