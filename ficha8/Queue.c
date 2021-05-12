#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue (Queue *q){
    q->inicio = q->fim = NULL;
}


int QisEmpty (Queue q){
    return (q.inicio==NULL);
}


int enqueue (Queue *q, int x){
    LInt nova = malloc(sizeof (struct slist));
    if (nova==NULL) return 1;
    nova->valor=x;nova->prox=NULL;
    if (q->fim != NULL)
    q->fim->prox=nova;
    else q->inicio=nova;
    q->fim=nova;
    return 0;
}


int dequeue (Queue *q, int *x){
    LInt aux = q->inicio;
    if (q->inicio==NULL) return 1;
    *x=q->inicio->valor;
    if (q->inicio==q->fim) q->inicio=q->fim=NULL;
    else q->inicio=q->inicio->prox;
    free(aux);
    return 0;
}


int frontQ (Queue q, int *x){
    return -1;
}

typedef LInt QueueC;

void initQueueC (QueueC *q);
int QisEmptyC (QueueC q){
    return -1;
}
int enqueueC (QueueC *q, int x){
    return -1;
}
int dequeueC (QueueC *q, int *x){
    return -1;
}
int frontC (QueueC q, int *x){
    return -1;
}
