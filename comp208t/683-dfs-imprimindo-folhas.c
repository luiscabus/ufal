#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

typedef struct struct_node
{
	char item[20];
	char origem[20];
	char destino[20];
	struct struct_node *prev;
	struct struct_node *next;
} struct_node;


int inserir_inicio_folha(struct_node **head, char valor_a_adicionar[20]) {

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
	// new_node->item = valor_a_adicionar;
	strcpy(new_node->item, valor_a_adicionar);
	// Faz o next do nó apontar para onde apontava o head
	new_node->next = *head;
	new_node->prev = NULL;
	// Atualiza o head para que aponte para o novo nó
	*head = new_node;

	return 0;
}

int inserir_inicio_grafo(struct_node **head, char origem[20], char destino[20]) {

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
	// new_node->item = origem;
	strcpy(new_node->origem, origem);
	strcpy(new_node->destino, destino);
	// Faz o next do nó apontar para onde apontava o head
	new_node->next = *head;
	// Atualiza o head para que aponte para o novo nó
	*head = new_node;

	return 0;
}

int compara_item (char base_comparativa[20], char str_a_comparar[20]) {
	int menor, i;
	menor = strlen(base_comparativa);
	if (strlen(str_a_comparar) < menor) {
		menor = strlen(str_a_comparar);
	}

	if (DEBUG)
		printf("   Comparando %s(%lu) com %s(%lu)\n", str_a_comparar, strlen(str_a_comparar), base_comparativa, strlen(base_comparativa));

	for (i = 0; i < menor; ++i)
	{
		if (DEBUG)
			printf("    Comparando %c com %c\n", base_comparativa[i], str_a_comparar[i]);
		
		if (base_comparativa[i] > str_a_comparar[i]) {
			if (DEBUG)
				printf("    Saiu %s como menor\n", str_a_comparar);

			return 1;
		} else if (base_comparativa[i] < str_a_comparar[i]) {
			if (DEBUG)
				printf("    Saiu %s como maior\n", str_a_comparar);

			return 2;
		}
	}

	if (DEBUG)
		printf("Saiu %s como igual a %s\n", base_comparativa, str_a_comparar);

	return 0;
}

int inserir_ordenado_folha(struct_node **head, char item[20]) {
	struct_node *aux = NULL;
	aux = *head;

	// while (aux->next != NULL && aux->next->item < item) {
	// 	aux = aux->next;
	// }

	while (aux->next != NULL && compara_item(aux->next->item, item) != 1) {
		aux = aux->next;
	}

	struct_node *new_node = NULL;
	new_node = (struct_node *) malloc(sizeof(struct_node));
	// new_node->item = item;
	strcpy(new_node->item, item);

	new_node->next = aux->next;
	aux->next = new_node;

	return 0;
}



int inserir_final_grafo(struct_node **head, char origem[20], char destino[20]) {

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
	// new_node->item = origem;
	strcpy(new_node->origem, origem);
	strcpy(new_node->destino, destino);
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



void delete_from_grafuu(struct_node **head, char adeletar[20]) {
	if (*head == NULL) { return; }

	if ((*head)->next == NULL && strcmp(adeletar, current->destino) == 0) {
		*head = NULL;
		return;
	}

	if ((*head)->next != NULL && strcmp(adeletar, current->destino) == 0) {
		// printf("Item removido no início: %d\n", (*head)->item);
		*head = (*head)->next;
	}

	struct_node * current = *head;

	while (current->next != NULL) {

		// printf("Tô comparando %s com %s -> %s\n", adeletar, current->origem, current->destino);
		if (strcmp(adeletar, current->destino) == 0) {
			// printf("Tô apagando o %s -> %s\n", current->origem, current->destino);

			

			if (current->next != NULL) {
				current->next = current->next->next;
			}

			// if (current->next == NULL) {
			// 	current = NULL;
			// 	return;
			// }
		}

		if (current->next != NULL) {
			if (strcmp(adeletar, current->next->destino) == 0) {
				current->next = current->next->next;

			}
		}

		current = current->next;
	}

	// Aqui, current->next == NULL

}


void delete_from_grafuu2(struct_node **head, char adeletar[20]) {
	struct_node * current = *head;

	if (*head == NULL) { // printf("Lista vazia.\n");
		return;
	}

	while (current != NULL) {

		// printf("Tô comparando %s com %s -> %s\n", adeletar, current->origem, current->destino);
		if (strcmp(adeletar, current->destino) == 0) {
			// printf("Tô apagando o %s -> %s\n", current->origem, current->destino);

			if ((*head)->next == NULL) {
				// printf("Último item removido do início %d\n", (*head)->item);
				*head = NULL;
				return;
			}

			if ((*head)->next != NULL) {
				// printf("Item removido no início: %d\n", (*head)->item);
				*head = (*head)->next;
				// current->next = current->next->next;
			}

			if (current->next != NULL) {
				current->next = current->next->next;
			}

			if (current->next == NULL) {
				current = NULL;
				return;
			}

		}

		current = current->next;
	}

}






void print_list(struct_node *head) {
	// printf("Printando lista de endereço: %p\n", head);
	struct_node * current = head;

	if (head == NULL) {
		// printf("Lista vazia.\n");
		return;
	}

	int i = 1;
	while (current != NULL) {
		printf("%s\n", current->item);
		current = current->next;
		++i;
	}
}



int main(int argc, char const *argv[])
{

	// struct_node grafuu[100];
	struct_node *grafuu = NULL;
	// for (i = 0; i < 100; ++i)
	// {
	// 	grafuu[i].origem = '\0';
	// 	grafuu[i].destino = '\0';
	// }


	int num_de_testes, i, j, k, is_folha;
	char string1[20], string2[20];
	while (scanf("%d", &num_de_testes) != EOF) {
		for (i = 0; i < num_de_testes; ++i)
		{
			// scanf("%s %s", grafuu[i].origem, grafuu[i].destino);
			scanf("%s %s", string1, string2);

			if (grafuu == NULL) {
				inserir_inicio_grafo(&grafuu, string1, string2);		
			} else {
				inserir_final_grafo(&grafuu, string1, string2);
			}
		}


		// printf("Toma grafuuu\n");
		struct_node *cugrafu = grafuu;
		if (DEBUG) {
			printf("\n---- Grafo original ----\n");
			while (cugrafu != NULL) {
				printf("  %s -> %s\n", cugrafu->origem, cugrafu->destino);
				cugrafu = cugrafu->next;
			}
			printf("----\n\n");
		}
			

		// for (i = 0; i < num_de_testes; ++i)
		// {
		// 	printf("%s -> ", grafuu[i].origem);
		// 	printf("%s\n", grafuu[i].destino);
		// }

		while(grafuu != NULL) {

		// 	printf("Primeiro loop no while\n");

			struct_node *lista_folhas = NULL;

			// char array_folhas[100][20];
			// for (j = 0; j < 100; ++j)
			// {
			// 	array_folhas[j][0] = '\0';
			// }

			if (DEBUG)
				printf("---- Verificando FOLHAS\n");
			i = 0;
			struct_node *comp_i_grafu = grafuu;
			while (comp_i_grafu != NULL) {
				is_folha = 1;
				j = 0;

				struct_node *comp_j_grafu = grafuu;

				while (comp_j_grafu != NULL) {
					// compara o da direita com o da esquerda, se nao existir, é folha pq nao aponta pra ninguem
					if (DEBUG)
						printf("   %s (i%d) vs (j%d) %s\n", comp_i_grafu->destino, i, j, comp_j_grafu->origem);
					if (strcmp(comp_i_grafu->destino, comp_j_grafu->origem) == 0) {
						if (DEBUG)
							printf("   o %s é igual a %s, não é folha \n\n", comp_i_grafu->destino, comp_j_grafu->origem);
						is_folha = 0;
						break;
					}

					++j;
					comp_j_grafu = comp_j_grafu->next;
				}

				if (is_folha == 1) {
					// adicionar ao array de folhas
					
					if (DEBUG)
						printf("\n   ---- %s restou como Folha, adicionando ----\n", comp_i_grafu->destino);

					if (lista_folhas == NULL || compara_item(lista_folhas->item, comp_i_grafu->destino) == 1) {
						if (DEBUG)
							printf("   - Inserir na head\n");
						inserir_inicio_folha(&lista_folhas, comp_i_grafu->destino);	
					} else if (compara_item(lista_folhas->item, comp_i_grafu->destino) == 0) {
						if (DEBUG)
							printf("   - Nem vou tentar inserir, a head já é igual\n");
					} else {
						if (DEBUG)
							printf("   - Inserir ordenado\n");
						inserir_ordenado_folha(&lista_folhas, comp_i_grafu->destino);
					}
					if (DEBUG)
						printf("   ----\n\n");

					if (DEBUG) {
						struct_node * current = lista_folhas;
						printf("   ---- Lista de folhas agora ----\n   ");
						while (current != NULL) {
							printf("%s, ", current->item);
							current = current->next;
						}
						printf("\n   ----\n\n");
					}
						
				}

				++i;
				comp_i_grafu = comp_i_grafu->next;
			}

			for (i = 0; (i < num_de_testes && 1 > 2); ++i)
			{

				is_folha = 1;
				

				for (j = 0; j < num_de_testes; ++j)
				{
					// compara o da direita com o da esquerda, se nao existir, é folha pq nao aponta pra ninguem
					if (DEBUG)
						printf("Vendo se %s (i%dj%d) é folha comparando com %s\n", grafuu[i].destino, i, j, grafuu[j].origem);
					if (strcmp(grafuu[i].destino, grafuu[j].origem) == 0) {
						if (DEBUG)
							printf("o %s é igual a %s, não é folha \n", grafuu[i].destino, grafuu[j].origem);
						is_folha = 0;
						break;
					}
				}


				if (is_folha == 1) {
					// adicionar ao array de folhas
					// strcpy(array_folhas[i], grafuu[i].destino);
					// insere_lista_ordenado_unico(grafuu[i].destino);
					if (DEBUG)
						printf("---- Adicionando %s ao array de folhas ----\n", grafuu[i].destino);

					if (lista_folhas == NULL || compara_item(lista_folhas->item, grafuu[i].destino) == 1) {
						if (DEBUG)
							printf("Tentei inserir no inicio\n");
						inserir_inicio_folha(&lista_folhas, grafuu[i].destino);	
					} else if (compara_item(lista_folhas->item, grafuu[i].destino) == 0) {
						if (DEBUG)
							printf("Nem vou tentar inserir, a head já é igual\n");
					} else {
						if (DEBUG)
							printf("Tentei inserir no ordenado\n");
						inserir_ordenado_folha(&lista_folhas, grafuu[i].destino);
					}
					// printf("----\n");

					if (DEBUG) {
						struct_node * current = lista_folhas;
						printf("   ---- Lista de folhas agora ----\n");
						while (current != NULL) {
							printf("   %s\n", current->item);
							current = current->next;
						}
						printf("   ----\n");
					}
						
				}


			}
			if (DEBUG)
				printf("---- \n\n");


			// print_list(lista_folhas);


			struct_node * current = lista_folhas;
			current = lista_folhas;
			if (DEBUG)
				printf("---- Lista final de folhas ----\n");
			while (current != NULL) {
				printf("%s\n", current->item);
				current = current->next;
			}
			if (DEBUG)
				printf("----\n\n");


			// Apagando as linhas que contém folhas no grafo
			current = lista_folhas;
			if (DEBUG)
				printf("---- Deletando ----\n");
			while (current != NULL) {
				// Se está aqui, é porque a linha do grafuu que contém folha tem que ser excluída
				if (DEBUG)
					printf("  Deletando %s\n", current->item);
				delete_from_grafuu(&grafuu, current->item);
				current = current->next;

			}
			if (DEBUG)
				printf("----\n\n");



			if (DEBUG) {
				printf("---- Grafo restante\n");
				cugrafu = grafuu;
				while (cugrafu != NULL) {
					printf("%s -> %s\n", cugrafu->origem, cugrafu->destino);
					cugrafu = cugrafu->next;
				}
				printf("----\n");
				printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n\n\n");
			}
				




			lista_folhas = NULL;
		}




		// printf("Toma grafuuu\n");
		// cugrafu = grafuu;
		// while (cugrafu != NULL) {
		// 	printf("%s -> %s\n", cugrafu->origem, cugrafu->destino);
		// 	cugrafu = cugrafu->next;
		// }
		// printf("\n");


		// for (i = 0; i < 100; ++i)
		// {
		// 	if (strcmp(array_folhas[i], "") != 0) {
		// 		// se printar funcionou
		// 		printf("%s\n", array_folhas[i]);
		// 	}
		// }
	}

	
	





	return 0;
}