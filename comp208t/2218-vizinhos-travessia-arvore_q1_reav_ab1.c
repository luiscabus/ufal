#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Criar uma estrutura de nó para árvore
typedef struct binary_tree {
	int item;
	int h;
	struct binary_tree *left;
	struct binary_tree *right;
} binary_tree;

void create_new_tree(binary_tree **raiz, int valor) {
	binary_tree *new_leaf = malloc(sizeof(binary_tree));
	new_leaf->item = valor;
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	*raiz = new_leaf;
}

binary_tree *new_leaf(int item, binary_tree *left, binary_tree *right) {
	binary_tree *new_leaf = malloc(sizeof(binary_tree));
	new_leaf->item = item;
	new_leaf->h = 0;
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	return new_leaf;
}




/* Given a binary tree, print its nodes according to the "bottom-up" postorder traversal. */
void make_array_postorder(binary_tree *node, int arrrrrr[], int *i) 
{ 
	if (node == NULL) 
		return; 
	
     // first recur on left subtree 
	make_array_postorder(node->left, arrrrrr, i); 
	
     // then recur on right subtree 
	make_array_postorder(node->right, arrrrrr, i); 
	
     // now deal with the node 
	// printf("%d ", node->item); 
	arrrrrr[*i] = node->item;
	*i += 1;
} 

/* Given a binary tree, print its nodes in inorder*/
void make_array_inorder(binary_tree *node, int arrrrrr[], int *i) 
{ 
	if (node == NULL) 
		return; 
	
     /* first recur on left child */
	make_array_inorder(node->left, arrrrrr, i); 
	
     /* then print the data of node */
	// printf("%d ", node->item);   
	arrrrrr[*i] = node->item;
	*i += 1;
	
     /* now recur on right child */
	make_array_inorder(node->right, arrrrrr, i); 
} 

/* Given a binary tree, print its nodes in preorder*/
void make_array_preorder(binary_tree *node, int arrrrrr[], int *i) 
{ 
	if (node == NULL) 
		return; 
	
     /* first print data of node */
	// printf("%d ", node->item);   
	arrrrrr[*i] = node->item;
	*i += 1;
	
     /* then recur on left sutree */
	make_array_preorder(node->left, arrrrrr, i);   
	
     /* now recur on right subtree */
	make_array_preorder(node->right, arrrrrr, i); 
}   


void print_tree(binary_tree *raiz, int nivel) {

	if (raiz == NULL) {
		printf(" () ");
		return;
	} else {
		// printf(" ( %d ", raiz->item);
		printf(" ( %d ", raiz->item);
	}

	print_tree(raiz->left, ++nivel);
	print_tree(raiz->right, ++nivel);

	printf(") ");
}








void add_to_tree2(binary_tree *raiz, int valor) {

	if (valor < raiz->item) {

		if (raiz->left == NULL) {
			binary_tree *new_leaf = malloc(sizeof(binary_tree));
			new_leaf->item = valor;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			raiz->left = new_leaf;
			return;
		} else {
			add_to_tree2(raiz->left, valor);
		}

	} else {

		if (raiz->right == NULL) {
			binary_tree *new_leaf = malloc(sizeof(binary_tree));
			new_leaf->item = valor;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			raiz->right = new_leaf;
			return;
		} else {
			add_to_tree2(raiz->right, valor);
		}

	}
	
}


void add_to_tree(binary_tree *raiz, int valor) {

	if (valor < raiz->item) {

		if (raiz->left == NULL) {
			binary_tree *new_leaf = malloc(sizeof(binary_tree));
			new_leaf->item = valor;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			raiz->left = new_leaf;
			return;
		} else {
			add_to_tree(raiz->left, valor);
		}

	} else {

		if (raiz->right == NULL) {
			binary_tree *new_leaf = malloc(sizeof(binary_tree));
			new_leaf->item = valor;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			raiz->right = new_leaf;
			return;
		} else {
			add_to_tree(raiz->right, valor);
		}

	}
	
}



// void add_to_tree(binary_tree *raiz, int valor) {

// 	// if (valor < raiz->item) {

		// if (raiz->left == NULL) {
		// 	binary_tree *new_leaf = malloc(sizeof(binary_tree));
		// 	new_leaf->item = valor;
		// 	new_leaf->left = NULL;
		// 	new_leaf->right = NULL;
		// 	raiz->left = new_leaf;
		// 	return;
		// } else if (raiz->right == NULL) {
		// 	binary_tree *new_leaf = malloc(sizeof(binary_tree));
		// 	new_leaf->item = valor;
		// 	new_leaf->left = NULL;
		// 	new_leaf->right = NULL;
		// 	raiz->right = new_leaf;
		// 	return;
		// } else {
		// 	add_to_tree(raiz->left, valor);
		// 	// add_to_tree(raiz->right, valor);
		// }

	// } else {

		// if (raiz->right == NULL) {
		// 	binary_tree *new_leaf = malloc(sizeof(binary_tree));
		// 	new_leaf->item = valor;
		// 	new_leaf->left = NULL;
		// 	new_leaf->right = NULL;
		// 	raiz->right = new_leaf;
		// 	return;
		// } else {
		// 	add_to_tree(raiz->right, valor);
		// }

	// }
	
// }



binary_tree *make_tree (int max_, int array[2][max_], int pos_atual) {

	if (pos_atual == -1) {
		return NULL;
	}

	binary_tree *new_node = malloc(sizeof(binary_tree));
	
	new_node->item = pos_atual;
	new_node->left = make_tree(max_, array, array[0][pos_atual]);
	new_node->right = make_tree(max_, array, array[1][pos_atual]);

	return new_node;

}





int main() {


	// int num_nos;
	// scanf("%d", &num_nos);

	// int tam_array = num_nos * 2 + 1;
	

	// int *array_arvore;
	// array_arvore = malloc(sizeof(int) * tam_array);

	// int no_left, no_right;
	// int i;
	// for (i = 1; i < (tam_array); ++i)
	// {
	// 	scanf("%d %d", &no_left, &no_right);
	// 	array_arvore[i] = no_left;
	// 	++i;
	// 	array_arvore[i] = no_right;
	// }

	// scanf("%d", &array_arvore[0]);

	// for (i = 0; i < (tam_array); ++i)
	// {
	// 	printf("%d \n", array_arvore[i]);
	// }


	int i, num_nos;
	scanf("%d", &num_nos);

	int arvore_willy[2][num_nos];

	for (i = 0; i < num_nos; ++i)
	{
		scanf("%d", &arvore_willy[0][i]);
		// ++i;
		scanf("%d", &arvore_willy[1][i]);
	}

	int raiz;
	scanf("%d", &raiz);

	binary_tree *arvore = NULL;
	arvore = make_tree(num_nos, arvore_willy, raiz);


	// print_tree(arvore, 0);

	int posicao;

	posicao = 0;

	int arr_pre[num_nos];
	make_array_preorder(arvore, arr_pre, &posicao);




	posicao = 0;

	int arr_inn[num_nos];
	make_array_inorder(arvore, arr_inn, &posicao);




	posicao = 0;

	int arr_pos[num_nos];
	make_array_postorder(arvore, arr_pos, &posicao);


	// for (i = 0; i < num_nos; ++i)
	// {
	// 	printf("LEFT %d\n", arvore_willy[0][i]);
	// 	// ++i;
	// 	printf(" RIGHT %d\n", arvore_willy[1][i]);
	// }


	printf("\n");

	int j, previ, nexti;

	printf("Pre Order:\n");
		for (i = 0; i < num_nos; ++i)
		{
			// printf(" %d - ", arr_pre[i]);
		}
		// printf("\n");

		for (i = 0; i < num_nos; ++i)
		{
			// printf(" %d - ", arr_pre[i]);

			for (j = 0; j < num_nos && arr_pre[j] != i; ++j);

				// printf("TO COM I %d e J %d\n", i, j);

			if (j-1 < 0) {
				previ = -1;
				// printf("Agora TO COM I %d e J %d\n", i, j);
			} else {
				previ = arr_pre[j-1];
			}
			if (j+1 > num_nos-1) {
				nexti = -1;
				// printf("iagora TO COM I %d e J %d\n", i, j);
			} else {
				nexti = arr_pre[j+1];
			}
			printf("Node %d: previous = %d next = %d\n", i, previ, nexti);

		}
		// printf("\n");

	printf("In Order\n");
		// for (i = 0; i < num_nos; ++i)
		// {
		// 	printf(" %d - ", arr_inn[i]);
		// }
		// printf("\n");

		for (i = 0; i < num_nos; ++i)
		{
			// printf(" %d - ", arr_inn[i]);

			for (j = 0; j < num_nos && arr_inn[j] != i; ++j);

				// printf("TO COM I %d e J %d\n", i, j);

			if (j-1 < 0) {
				previ = -1;
				// printf("Agora TO COM I %d e J %d\n", i, j);
			} else {
				previ = arr_inn[j-1];
			}
			if (j+1 > num_nos-1) {
				nexti = -1;
				// printf("iagora TO COM I %d e J %d\n", i, j);
			} else {
				nexti = arr_inn[j+1];
			}
			printf("Node %d: previous = %d next = %d\n", i, previ, nexti);

		}

	printf("Post Order\n");
		// for (i = 0; i < num_nos; ++i)
		// {
		// 	printf(" %d - ", arr_pos[i]);
		// }
		// printf("\n");

		for (i = 0; i < num_nos; ++i)
		{
			// printf(" %d - ", arr_pre[i]);

			for (j = 0; j < num_nos && arr_pos[j] != i; ++j);

				// printf("TO COM I %d e J %d\n", i, j);

			if (j-1 < 0) {
				previ = -1;
				// printf("Agora TO COM I %d e J %d\n", i, j);
			} else {
				previ = arr_pos[j-1];
			}
			if (j+1 > num_nos-1) {
				nexti = -1;
				// printf("iagora TO COM I %d e J %d\n", i, j);
			} else {
				nexti = arr_pos[j+1];
			}
			printf("Node %d: previous = %d next = %d\n", i, previ, nexti);

		}




	// binary_tree *raiz = NULL;

	// for (i = 0; i < (tam_array); ++i)
	// {
	// 	if (array_arvore[i] != -1) {
	// 		if (raiz == NULL) {
	// 			create_new_tree(&raiz, array_arvore[i]);
	// 		} else {
	// 			printf("----\n");
	// 			printf("  ");
	// 			printf("Adicionando %d\n", array_arvore[i]);
	// 			add_to_tree(raiz, array_arvore[i]);
	// 			print_tree(raiz, 0);
	// 			printf("\n\n");
	// 		}
	// 	}
		
	// }






	// for (i = 0; i < num_nos; ++i)
	// {
	// 	scanf("%d %d", &no_left, &no_right);
	// 	if (no_left != -1) {
	// 		add_to_tree(main_root, no_left);
	// 	}
	// 	if (no_right != -1) {
	// 		add_to_tree(main_root, no_right);
	// 	}
	// }

	// scanf("%d", &no_raiz);
	// main_root->item = no_raiz;


	// print_tree(main_root, 0);


	return 0;
}