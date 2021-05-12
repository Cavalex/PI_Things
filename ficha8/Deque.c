#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"


void initDeque (Deque *q){
    q->back=q->front=NULL;
}


int DisEmpty (Deque q){
    return (q.back==NULL && q.front==NULL);
}


int pushBack (Deque *q, int x){
    DList nova = malloc(sizeof(struct dlist));
        if (nova==NULL) return 1;
    nova->valor=x;
    nova->ant=NULL;nova->prox=q->back;
        if (q->back!=NULL)
        q->back->ant=nova;
        else q->front=nova;
    q->back=nova;
    
    return 0;
}
int pushFront (Deque *q, int x){
    return -1;
}
int popBack (Deque *q, int *x){
    return -1;
}
int popFront (Deque *q, int *x){
    return -1;
}


int popMax (Deque *q, int *x){
    DList pt, maior;
    if (q->back==NULL) return 1;
    //procurar o maior
    pt = maior = q->back;
    while (pt!=NULL)
    if (pt->valor>maior->valor) {
    maior=pt;
    pt = pt -> prox;
    }
    *x=maior->valor;
    //removê-lo, falra para os casos em que é primeiro e ultimo
    maior->prox->ant=maior->ant;
    maior->ant->prox=maior->prox;
    return 0;
}
int back (Deque q, int *x){
    return (*x);
}
int front (Deque q, int *x){
    return -1;
}
