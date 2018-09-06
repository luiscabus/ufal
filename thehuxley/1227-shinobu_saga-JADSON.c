#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
STACK* Create_stack(){
    STACK* new_stack = (STACK*) malloc(sizeof(STACK));
    new_stack->head = NULL;
    return new_stack;
}

NODE* create_node(int element){
    NODE *new_node = (NODE*) malloc(sizeof(NODE));
    new_node->element = element;
   return new_node;
}
int IS_EMPTY(STACK* stack){
    if(stack == NULL){
        return -1;
    }else{
        return 0;
    }
}

int POP(STACK* stack){
  NODE *old_top = stack->head;
  stack->head = stack->head->next;
  return old_top->element;
}

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element){
    NODE* new_node = create_node(element);
    NODE* old_head = stack->head;
    new_node->next = old_head;
    stack->head = new_node;
}

void result(STACK* stack, char operation){
    int num1 = POP(stack);
    int num2 = POP(stack);
    if(operation == 42){
        PUSH(stack,num1*num2);
    }if(operation == 43){
        PUSH(stack,num1+num2);
    }if(operation == 45){
        PUSH(stack,num2-num1);
    }if(operation == 47){
        PUSH(stack,num2/num1);
    }
}

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size){
    int i, x = 0, j, t;
    char op[256];
    for(i = 0; i < size; i++){
        scanf(" %s ", &op);
        if(op[0]>=42 && op[0] <= 47){
            result(calculadora,op[0]);
            //printf("%d*****\n", calculadora->head->element);
        }else{
            x = 0;
            t = 1;
            for(j = strlen(op)-1; j >= 0; j--){
                x+= (op[j] - '0')*t;
                t*=10;
            }
            PUSH(calculadora,x);
             // printf("%d\n", calculadora->head->element);
            
        }
    }
}