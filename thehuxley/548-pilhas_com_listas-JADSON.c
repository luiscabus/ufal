#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list list;
typedef struct node node;
typedef struct stack stack;

struct list{
  int item;
  list *next;
};
struct node{
  list *li;
  node *prox;
};
struct stack{
  int size;
  node *top;
};
void exibe_list(list *li){
    if(li == NULL){
        printf("EMPTY STACK\n");
        return;
    }
  while(li != NULL){
    printf("%d",li->item);
    if(li->next != NULL){
        printf(" ");
    }
    li = li->next;
  }
  printf("\n");
}

list* insert(list* li, int x){
  list *new_list = (list*) malloc(sizeof(list));
  list *old_head = li;
  new_list->item = x;
  new_list->next = old_head;
  li = new_list;
  return new_list;
}

list* create_list(char string[]){
  int i, x = 0, j = 1, true = 0;
  list *new_list = NULL;
  for(i = strlen(string)-1; i >= 0; i--){
    if((string[i] == 32 || i == 0)){
        if(i == 0){
            x += (string[i]-'0')*j;
        }
      new_list = insert(new_list,x);
      x = 0;
      j = 1;
    }else if (string[i] != 32){
        true = 1;
      x += (string[i]-'0')*j;

      j*=10;
    }
  }
  return new_list;
}

stack* create_stack(){
    stack* new_stack = (stack*) malloc(sizeof(stack));
  new_stack->top = NULL;
  new_stack->size = 0;
  return new_stack;
}
node* create_node(char string[]){
  node* new_node = (node*) malloc(sizeof(node));
  new_node->li = create_list(string);
  new_node->prox = NULL;
  return new_node;
}

void push(stack *st,char string[]){
  st->size ++;
  node *new_node = create_node(string);
  new_node->prox = st->top;
  st->top = new_node;
}

void pop(stack *st){
    if(st->size == 0){
      printf("EMPTY STACK\n");
        return 0;
    }
  exibe_list(st->top->li);
  node *old_node = st->top;
  st->top = st->top->prox;
  st->size--;
  free(old_node);
  old_node = NULL;
}


int main(){
  stack *st = create_stack();
  char string[256], comando[256644];
    while(scanf(" %s ", string) != EOF){
       if(string[1] == 'U'){
            scanf ("%[^\n]", comando);
           push(st,comando);
       }else if(string[1] == 'O'){
           pop(st);
       }
    }
}