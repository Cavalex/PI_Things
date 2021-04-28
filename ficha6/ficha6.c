#include <stdio.h>

#define Max 10

struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

//exercicio 1

//a
void SinitStack (SStack s){
    s->sp = 0;
}


//b
void SisEmpty (SStack s){
    return (s->sp == 0);
}


//c
int Spush (SStack s, int x){
    int result = 0;
    if (s->sp == Max){
        result = 1;
    }
    else s->values[s->sp++] = x;
    return result;
}

//d

int Spop (SStack s, int *x){
    int result = 0;
    if(SisEmpty(s)){
        r = 1;
    }
    else {
        (*x) = s->values[s->sp--]; //usamos *x e nao "x" porque é "o valor apontado por x"
    }
    return result;
} 


//e
int Stop (SStack s, int *x){
     int result = 0;
    if(SisEmpty(s)){
        r = 1;
    }
    else {
        (*x) = s->values[s->sp]; //neste nao decrementamos o stackpointer
    }
    return result;
}



//EXERCICIO 2

struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

void SinitQueue (SQueue q){
    q->front = 0;
    q->length = 0;
}

void SisEmptyQ (SQueue q){
    return (q->length == 0);
}


int Senqueue (SQueue q, int x){
    int r = 0, pos;
    if(q->length == Max){
        r = 1;
    }
    else {
        pos = (q->front + q->length) % Max;
        q->values [pos] = x;
        q->length++;
    }
    return r;
}

int Sdequeue (SQueue q, int *x){
    int r=0;
    if(SisEmptyQ(q)) r=1;
    else{
        *x = q->values[q->front];
        q->length--;
        q->front = (q->front + 1) % Max;
    }
    return r;
}


int Sfront (SQueue q, int *x){
    int r=0;
    if(SisEmptyQ(q)) r=1;
    else{
        *x = q->values[q->front];
    }
    return r;
}
