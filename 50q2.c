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
int removeDups(LInt *l){
    int rem = 0;
    while(*l){
        LInt aux = (*l), next = (*l)->prox;
        while(next){
            if(next->valor == (*l)->valor){
                aux->prox = next->prox;
                rem++;
                free(next);
            }
            else aux = next;
            next = aux->prox;
        }
        l = &(*l)->prox;
    }
    return rem;
}

//12
int removeMaiorL(LInt* l){
    int maior = (*l)->valor;
    LInt inicio = l;
    // primeiro procuramos pelo maior elemento
    while(*l){
        if((*l)->valor > maior) maior = (*l)->valor;
        l = &(*l)->prox;
    }

    l = inicio;
    while(*l){
        if((*l)->valor == maior){
            printf("valor atual: %d\n", (*l)->valor);
            LInt t = *l;
            (*l) = (*l)->prox;
            free(t);
            break;
        }
        else{
            l = &(*l)->prox;
        }
    }

    return maior;
}

//13
void init(LInt* l){
    while((*l)->prox) l = &(*l)->prox;
    *l = NULL;
}

//14
void appendL(LInt* l, int n){
    while(*l) l = &(*l)->prox;
    (*l) = malloc(sizeof(struct lligada)); // NÃO ESQUECER DO MALLOC
    (*l)->valor = n;
    (*l)->prox = NULL;
}

//15
void concatL(LInt* a, LInt b){
    while(*a) a = &(*a)->prox;
    (*a) = b;
}

//16
// Provavelmente está mal, visto que não
// tenho como testá-la...
LInt cloneL(LInt l){
    LInt new = malloc(sizeof(struct lligada));
    new = l;
    return new;
}

//17

// LInt cloneRev(LInt l){
//     LInt rev = malloc(sizeof(struct lligada));
//     LInt inicio = rev; // É PRECISO ESTA BOSTA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     int i = 0, len = length(l);
//     if(len == 0) return NULL;
//     int valores[len];
//     while(i < len){
//         valores[i] = l->valor;
//         l = l->prox;
//         i++;
//     }
//     i = len - 1;
//     printf("Valor de i no meio: %d\n", i);
//     while(i >= 0){
//         rev->valor = valores[i];
//         printf("rev->valor: %d\n", rev->valor);
//         rev->prox = malloc(sizeof(struct lligada));
//         rev = rev->prox;
//         i--;
//     }
//     for(i = 0; i < len; i++) printf("valores[%d] = %d\n", i, valores[i]);
//     rev = NULL;
//     printf("len inicio:%d\n", length(inicio));
//     return inicio; // ATENÇAO PQ SE PASSARMOS REV ISTO DÁ UM ERRO ESTUPIDO
// }

//TODO
LInt cloneRev2 (LInt l) {
    LInt list = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
}

//18
int maximo(LInt l){
    int max = l->valor;
    while(l){
        if(l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}

//19
int take(int n, LInt* l){
    int i = 0;
    // percorremos todos os nodos até o n
    while((*l) && i < n){
        l = &(*l)->prox;
        i++;
    }
    // retornar quantos valores mudamos
    if(!(*l)) return i;
    // limpar todos os nodos à frente:
    while(*l){
        // tirado do freeL, a ideia é a mesma
        //aux = l->prox;
        //free(l);
        //l = aux;

        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return n;
}

//20
int drop(int n, LInt* l){
    int i = 0;
    while((*l) && i < n){
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
        i++;
    }
    if(!(*l)) return i;
    return n;
}

//21
LInt NForward(LInt l, int N){
    while(N > 0){
        N--;
        l = l->prox;
    }
    return l;
}

//22
int listToArray (LInt l, int v[], int N){
    int i = 0;
    while(l && i < N){
        v[i] = l->valor;
        i++;
        l = l->prox;
    }
    return i;
}

//23
LInt arrayToList (int v[], int N){
    if(N == 0) return NULL;
    LInt l = malloc(sizeof(struct lligada));
    l->valor = *v;
    l->prox = arrayToList(v+1, N-1); // NUNCA PASSAR V++ OU N-- COMO ARGUMENTOS!
    return l;
}

//24
//TODO
LInt somasAcL (LInt l) {
    int sum = 0;
    LInt list = NULL, temp = NULL;
    for(;l; l = l->prox) {
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;
        // na 1ª iteraçao metemos o list como cabeça da lista
        // e inicializamos o 1º temp com o primeiro valor da lista
        if(!list){
            list = new;
            temp = new;
        }
        // depois passamos pelo temp->prox sucessivamente
        // dando-lhe a lista com o valor acumulado em new
        else{
            temp->prox = new;
            temp = temp->prox;
        }
    }
    return list;
}

//25
//TODO
void remreps (LInt l){
    while(l) {
        LInt* c = &(l->prox); // aponta para o proximo nodo

        // percorre todos os nodos seguintes enquanto 
        // eles tiverem o mesmo valor que o nodo original, l
        while (*c && (*c)->valor == l->valor){
            LInt temp = *c;
            *c = (*c)->prox;
            free(temp);
        }
        l = l->prox;
    }
}

//26
//TODO
LInt rotateL (LInt l) {
    if(!l || !(l->prox)) return l;
    LInt temp = l; // só para percorrer a lista mesmo
    LInt list = l->prox; // guardamos a cabeça da lista a retornar
    while(temp->prox) temp = temp->prox; // ir até ao final da lista
    // agora que estamos no ultimo nodo, 
    // dizemos que o proximo valor aponta para o inicio da lista
    temp->prox = l;
    l->prox = NULL; // ou (temp->prox)->prox = NULL;
    return list;
}

//27
//TODO
LInt parte (LInt l){
    LInt cabecaP, *pares = &cabecaP, *impares = &l;
    int i;
    for(i = 1; *impares; i++){
        if(i % 2){ // impar
            // vamos andar com o pointer
            // pq é mais facil eliminar elementos do array assim
            impares = &(*impares)->prox;
        }
        else{ // par
            // copiamos o elemento atual para o "pares"
            // e passamos o pares para o proximo nodo
            *pares = *impares;
            pares = &(*pares)->prox;

            // passamos o elemento atual à frente
            *impares = (*impares)->prox;
        }
    }
    // necessário pq ao copiarmos o *impares para o *pares
    // copiamos tbm o (*pares)->prox, que contem o proximo 
    // elemento do impares, assim terminamos a lista
    // só com elementos pares.
    *pares = NULL;
    return cabecaP;
}

//28
typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} *ABin;

#define MAX(a,b) (a>b) ? a : b

int altura(ABin a){
    if(!a) return 0;
    return MAX(1 + altura(a->esq), 1 + altura(a->dir));
}

//29
ABin cloneAB(ABin a){
    if(!a) return NULL;
    ABin clone = malloc(sizeof(struct nodo));
    clone->valor = a->valor;
    clone->esq = cloneAB(a->esq);
    clone->dir = cloneAB(a->dir);
    return clone;
}

//30
void mirror(ABin *a){
    if(*a){
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
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
