#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct queue{
  int priority;
  int pos;
  struct queue *next;
}queue; 

queue* create_queue(){
  queue *p = (queue*) malloc(sizeof(queue));
  p->next = NULL;
  return p;
}
void insert (queue *p,int item, int pos){
    queue *tmp = p;
    queue *new_q = (queue*) malloc(sizeof(queue));
    new_q->pos = pos;
    new_q->priority = item;
    while(tmp ->next != NULL){
        if(item > tmp->next->priority){
        queue *old_next = tmp->next;
        tmp->next = new_q;
        new_q -> next = old_next;
        return;
        }
        tmp = tmp->next;
    }
    tmp->next = new_q;
    new_q->next = NULL;
    return;
}
void print(queue *p){
    queue *solo = p->next;
    while(solo != NULL){
        printf("%d %d\n", solo->priority, solo->pos);
        solo = solo->next;
    }
}
int r(int x, queue *p){
    queue *tmp = p->next;
    int i = 0;
    while(tmp!= NULL){
        if(i != tmp->pos){
            x--;
        }
        tmp= tmp->next;
        i++;
    }
    return x;
}

int main() {
    queue *solo=create_queue();
    int i, j, casos, alunos, aluno;

    scanf(" %d ", &casos);
    for(i = 0; i < casos; i++){
        scanf(" %d ", &alunos);
        for(j = 0; j < alunos; j++){
            scanf("%d", &aluno);
            insert(solo, aluno, j);
        }
        printf("%d\n",r(alunos,solo));
        solo=create_queue();
    }
  return 0;
}