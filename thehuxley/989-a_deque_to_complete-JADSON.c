#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _deque deque_t;
typedef struct _node   node_t;

//Guarda um ponteiro pro node anterior, para o proximo node e o valor guardado
struct _node {
	node_t *prev;
  	node_t *next;
  	int    value;
};

//Guarda um ponteiro para o primeiro node, um ponteiro para o ultimo node, e o tamanho do deque
struct _deque {
  	node_t *front;
  	node_t  *rear;
  	int      size;
};

//Cria um node que guarda os valores que s�o enfileirados no deque
node_t*  node_new     (int value);

//Cria um deque dinamicamente e retorna seu endere�o de memoria
deque_t* construct    ();
//Libera a mem�ria do conte�do e do pr�prio deque
void     destruct     (deque_t *deque);

//Retorna o tamanho do deque
int      size         (deque_t *deque);
//Retorna verdadeiro se o deque esta vazio, caso contr�rio, retorna falso
bool     empty        (deque_t *deque);

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int      front        (deque_t *deque);
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int      rear         (deque_t *deque);

//Cria um n� que guarda um valor e o adiciona ao fim do deque
void     enqueue_rear (deque_t *deque, int value);
//Cria um n� que guarda um valor e o adiciona ao inicio do deque
void     enqueue_front(deque_t *deque, int value);
//Retira o valor do final caso n�o esteja vazia
void     dequeue_rear (deque_t *deque);
//Retira o valor da frente caso n�o esteja vazia
void     dequeue_front(deque_t *deque);
//Limpa o conteudo do deque(deixa ele vazio)
void     erase        (deque_t *deque);

//Imprime o deque em uma unica linha, com os elementos separados por um espa�o,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void     print        (deque_t *deque);

int main() {
 	int i, num;
  	scanf("%d", &num);
  
  	deque_t* deque = construct();
  
  	int vector[num];
  	for(i = 0; i < num; ++i)
      	scanf("%d", &vector[i]);
  
  	for(i = 0; i < num; ++i)
      	enqueue_rear(deque, vector[i]);
  
 	printf("%d\n", front(deque));
  	printf("%d\n", rear (deque));
  
  	if(!empty(deque))
  		printf("The size of the deque %d\n", size(deque));
  	else
       	printf("The deque is empty\n");
  	
    scanf("%d", &num);
    for(i = 0; i < num; ++i)
       enqueue_front(deque, i);
  	print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear (deque);
    print(deque);
    
  	erase(deque);
  	for(i = 0; i < 3; ++i)
  		enqueue_rear(deque, i);
  		
  	print(deque);
    destruct(deque);
       
	return 0;
}






node_t *node_new (int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = NULL;
  newNode->prev = NULL;   

  return newNode;
}

deque_t *construct() {
  deque_t *newDeque = (deque_t*) malloc(sizeof(deque_t));
  newDeque->size = 0;
  newDeque->rear = NULL;
  newDeque->front = NULL;

  return newDeque;
}

void destruct(deque_t *deque) {
  erase(deque);
  free(deque);
}

int size(deque_t *deque) {

  return deque->size;
}

bool empty (deque_t *deque) {
  if(!size(deque)) {
    return true;
  } else {
    return false;
  }
}

int front (deque_t *deque) {
  if(!empty(deque)) {
    return deque->front->value;
  } else {
    return INT_MIN;
  }
}

int rear (deque_t *deque) {
  if(!empty(deque)) {
    return deque->rear->value;
  } else {
    return INT_MIN;
  }
}

void enqueue_rear (deque_t *deque, int value) {
  node_t *newNode = node_new(value);
  if(!empty(deque)) {
    deque->rear->next = newNode;
    newNode->prev = deque->rear;
    deque->rear = newNode;
    deque->size++;
  } else {
    deque->rear = deque-> front = newNode;
    deque->rear-> prev = deque-> front;
    deque->rear-> next = NULL;
    deque->front-> next = deque-> rear;
    deque->front-> prev = NULL;
    deque->size++;
  }
}

void enqueue_front(deque_t *deque, int value) {
node_t *newNode = node_new(value);
  if(!empty(deque)) {
    deque->front->prev = newNode;
    newNode->next = deque->front;
    deque->front = newNode;
    deque->size++;
  } else {
    deque->rear = deque-> front = newNode;
    deque->rear-> prev = deque-> front;
    deque->rear-> next = NULL;
    deque->front-> next = deque-> rear;
    deque->front-> prev = NULL;
    deque->size++;
  }
}

void  dequeue_rear (deque_t *deque) {
  node_t *temp;
  if(!empty(deque)) {
    if(size(deque) > 1) {
      temp = deque->rear;
      deque->rear = deque->rear->prev;
      deque->rear->next = NULL;
      free(temp);
      deque->size--;
    } else {
      free(deque->rear);
      deque->rear = NULL;
      deque->front = NULL;
      deque->size--;
    }
  }
}

void dequeue_front(deque_t *deque) {
  node_t *temp;
  if(!empty(deque)) {
    if(size(deque) > 1) {
      temp = deque->front;
      deque->front = deque->front->next;
      deque->front->prev = NULL;
      free(temp);
      deque->size--;
    } else {
      free(deque->rear);
      deque->rear = NULL;
      deque->front = NULL;
      deque->size--;
    }
  }
}

void erase(deque_t *deque) {
  while(!empty(deque)) {
    dequeue_rear(deque);
  }
}

void print(deque_t * deque) {
  deque_t *temp = construct();
  if (!empty(deque)) {
    while(size(deque)) {
      printf("%d", front(deque));
      if(size(deque) > 1) {
        printf(" ");
      } else {
        printf("\n");
      }
      enqueue_rear(temp, front(deque));
      dequeue_front(deque);
    }
  while(size(temp)) {
      enqueue_rear(deque, front(temp));
      dequeue_front(temp);
    }
  }
}