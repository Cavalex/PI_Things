#include <stdio.h>
#include <stdlib.h>

/*
Qual é a diferença?
l = &(*l)->prox  // percorre a lista "uma camada acima" sem fazer alterações
*l = (*l)->prox; // o apontado por l é o endereço do proximo usado para avançar mesmo a lista
*/

typedef struct lligada{
    int valor;
    struct lligada *prox;
} *LInt;

//1
int length(LInt l){
    int c = 0;
    while(l){
        c++;
        l = l->prox;
    }
    return c;
}

//2
void freeL(LInt l){
    LInt aux;
    while(l){
        // assim tá correto
        aux = l->prox;
        free(l);
        l = aux;
    }
}

//3
void imprimeL(LInt l){
    while(l){
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

//4
//TODO
LInt reverseL(LInt l){
    LInt frente, tras = NULL;
    while(l){
        frente = l->prox;
        l->prox = tras;
        tras = l;
        l = frente;
    }
}

//5
//TODO
void insertOrd (LInt *l, int x){

    //percorre a lista até encontrar o ponto onde inserir
    //a cada iteração do for, o apontador de l muda para o endereço do proximo valor apontado por l
    while (*l && (*l)->valor < x) l = &(*l)->prox;

    //guarda em temp o apontador para o ponto da lista que vai ficar a seguir À inserção
    LInt temp = *l;

    //o valor apontado por l passa a ser um valor novo cujo proximo vai ser a lista guardada em temp
    *l = malloc (sizeof (struct lligada));
    (*l)->valor = x;
    (*l)->prox = temp;
}

//6
//TODO
int removeOneOrd(LInt* l, int n){
                                  //o apontador de l muda para o endereço do proximo valor apontado por l
    while(*l && ((*l)->valor) != n) l = &(*l)->prox;
    
    if (*l && (*l)->valor == n){
        // tiramos o *l da cadeia e limpamo-lo?
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
        return 0;
    }
    return 1;
}

//7
//TODO
void merge(LInt* r, LInt a, LInt b){
    while(a && b){
        if(a->valor < b->valor){
            (*r) = a;
            a = a->prox;
        }
        else{
            (*r) = b;
            b = b->prox;
        }
        r = &(*r)->prox;
    }
    if(a) *r = a;
    if(b) *r = b;
}

//8
//TODO
void splitQS(LInt l, int x, LInt *mx, LInt *Mx){
    while(l){
        if(l->valor < x){
            *mx = l;
            mx = &(*mx)->prox;
        }
        else{
            *Mx = l;
            Mx = &(*Mx)->prox;
        }
        l = l->prox;
    }
    // terminar as listas, para não ficarem a apontar para o espaço sideral
    *mx = NULL;
    *Mx = NULL;
}

//9
//TODO
LInt parteAmeio (LInt *l){
    int meio = length(*l)/2;
    if(meio == 0) return NULL; // linha necessária ou temos segmentation fault
    
    LInt y = (*l);
    LInt prev = NULL;

    for(int i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }

    prev->prox = NULL;
    return y;
}

//10
//TODO
int removeAll(LInt* l, int n){
    int i = 0;
    while(*l){
        if((*l)->valor == n){
            i++;
            // tecnicamente está correto assim, mas 
            // o ideal é sempre dar free() no final
            // para o coiso não ocupar espaço na mem.
            LInt t = *l; // gravar o *l atual
            (*l) = (*l)->prox;
            free(t); // dar free ao *l gravado antes, visto que ele agora passou apra o proximo
        }
        else{
            l = &(*l)->prox;
        }
    }
    return i;
}

//11
int removeDups(LInt* l){
    int n;
    while(*l){
        n = (*l)->valor;
        if((*l)->valor == l){
            LInt t = *l;
            while()
        }
    }
}


int main(){
    int n = 440;
    char s1[] = "mundo cruel!!!";
    char s2[] = "ababa";

    //average();
    //biggest2();
    //printf("1's -> %d\n", bitsUm(n));
    //printf("0's -> %d\n", trailingZ(n));
    //printf("d's -> %d\n", qDig(n));
    //mystrcpy(s1, s2);
    //printf("string -> %s\n", s1);


    //printf("%c != %c count -> %d\n", *s2, c, count);
    //printf("difCon -> %d", difConsecutivos(s1));
    //printf("pal -> %d", palindrome(s2));

    return 0;
}
