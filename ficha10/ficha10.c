#include <stdio.h>

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} *ABin;


ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
        m = rand() % N;
        a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;    
}


// Questão 1
ABin removeMenor (ABin *a){
    ABin r;
    if ((*a)->esq==NULL) {
        r=*a; *a=(*a)->dir;
    }
    else r = removeMenor (&((*a)->esq));
    return r;
    
    //ou
    
    /*
    ABin r;
    while (a->esq!=NULL){
    a=&((*a)->esq);
    }
    r=a;*a=(*a)->dir
    return r;
    
    */ 
}

void removeRaiz (ABin *a){
    if ((*a)->esq==NULL) *a=(*a)->dir;
    else if ((*a)->dir==NULL) *a=(*a)->esq;

}

int removeElem (ABin *a, int x){
    int r=0;
    if ((*a)==NULL) r=1;
    else if (x==(*a)->valor) {removeRaiz(a);}
    else if (x<(*a)->valor) {r=removeElem(&((*a)->esq),x);}
    else if (x>(*a)->valor) {r=removeElem(&((*a)->dir),x);}
    return r;
}


// Questão 2
void rodaEsquerda (ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}
void rodaDireita (ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}

void promoveMenor (ABin *a){
    if ((*a)->esq==NULL);
    else 
    {
    promoveMenor(&((*a)->esq));
    rodaDireita(a);
    }
}

void promoveMaior (ABin *a){
    if ((*a)->dir==NULL);
    else 
    {
        promoveMaior(&((*a)->esq));
        rodaEsquerda(a);
    }
}


ABin removeMenorAlt (ABin *a){
    return NULL;
}



// Questão 3
int constroiEspinhaAux (ABin *a, ABin *ult){
    return (-1);
}
int constroiEspinha (ABin *a){
    ABin ult;
    return (constroiEspinhaAux (a,&ult));
}

ABin equilibraEspinha (ABin *a, int n) {
    return NULL;
}

void equilibra (ABin *a) {
}