#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *next;
}node;

typedef struct stack{
    int size;
    node *top;
}stack;

stack* create_stack(){
   stack *new_stack = (stack*) malloc(sizeof(stack));
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}
void push(stack *st, int item){
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = st->top;
    st->top = new_node;
    st->size++;
}
void pop(stack *st){
     if (st->size > 0) {
        node *tmp = st->top;
        st->top = st->top->next;
        st->size--;
        free(tmp);
    }
}

void r(char string[], stack *st, stack *of){
    if(string[0] == 'E'){
        push(st,1);
        pop(of);
    }else if(string[0] == 'B'){
        pop(st);
        push(of,1);
    }else{
        pop(of);
        push(st,1);
    }
}


int main(){
  stack *st = create_stack();
    stack *of = create_stack();
    char string[20];
    while(scanf(" %s ", string) != EOF){
        r(string,st,of);
    }
   printf("BACK: %d\nFORWARD: %d", st->size-1,of->size);
}