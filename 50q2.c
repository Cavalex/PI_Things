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
#define MIN(a,b) (a<b) ? a : b

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

//31
//TODO a estas 3

//inorder -> Esquerda, Nodo, Direita (nodo no meio, in)
//preorder -> Nodo, Esquerda, Direita (nodo à esquerda, pre)
//posorder -> Esquerda, Direita, nodo (nodo à direita, pos)

//A cada chamada da recursiva, é chamada a função para o lado esquerdo
//depois disso, um ciclo while percorre a lista até ao ponto depois de todas
//as inserções à esquerda. É alocada memória para armazenar o valor do nodo atual
//é chamada a função para o lado direito da lista
void inorder(ABin a, LInt *l){
    if (a){
        inorder(a->esq, l);
        while (*l) l = &(*l)->prox;
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        inorder(a->dir,&(*l)->prox);
    }
    else *l = NULL;
}

//32
//aloca memória para guardar o nodo atual na lista ligada, chama a preorder para o ramo esquerdo
//avança o apontador da lista ligada para ajustar depois da execução do lado esquerdo
//executa o lado direito
void preorder(ABin a, LInt *l){
    if(a){
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        preorder(a->esq, &(*l)->prox);
        while(*l) l = &(*l)->prox;
        preorder(a->dir, l);
    }
    else *l = NULL;
}

//33
void posorder(ABin a, LInt *l){
    if(a){
        posorder(a->esq, l);
        while(*l) l = &(*l)->prox;
        posorder(a->dir, l);
        while(*l) l = &(*l)->prox; // Sim, temos de percorrer até ao final da lista 2 vezes
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL; // Necessário
    }
    else *l = NULL;
}

//34
//TODO
int depth(ABin a, int x){
    if(!a) return -1; // nao encontrou

    if(a->valor == x) return 1; // encontrou

    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1 && dir == -1) return -1; // nao encontrou nos dois ramos
    if(esq == -1) return 1 + dir; // encontrou no direito
    if(dir == -1) return 1 + esq; // encontrou no esquerdo
    return esq < dir ? 1 + esq : 1 + dir; //retorna o menor + 1;
}

//35
int freeAB(ABin a){
    if(!a) return 0;
    int nodosLibertados = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return nodosLibertados;
}

//36
//TODO
int pruneAB (ABin *a, int l) {
    if(!(*a)) return 0;
    int nodosLibertados;
    if(l == 0){
        nodosLibertados = 1 + pruneAB(&(*a)->esq, 0) + pruneAB(&(*a)->dir, 0);
        free(*a);
        (*a) = NULL; // POR ALGUMA RAZÃO ISTO É NECESSÁRIO??
        return nodosLibertados;
    }
    return 0 + pruneAB(&(*a)->esq, l-1) + pruneAB(&(*a)->dir, l-1);
}

//37
int iguaisAB(ABin a, ABin b){
    if(!a && !b) return 1;
    if(!a && b || a && !b) return 0;
    return (a->valor == b->valor && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir));
}

//38
//TODO
LInt concat(LInt a, LInt b) {
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox; // vamos até ao final da lista para...
    temp->prox = b; // ... acrescentar o b no final
    return a; // a cabeca da lista
}

LInt nivelL(ABin a, int n){
    if(!a || n < 1) return NULL;
    if(n == 1){
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
} 

//39
//TODO
int nivelV(ABin a, int n, int v[]) {
    if(!a || n < 1) return 0;
    if(n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq,n - 1,v); // 'e' são os elementos à esquerda
        int d = nivelV(a->dir,n - 1,v+e); // 'd' são os elementos à direita
        return e + d;
    }
}

//40
//TODO
int dumpAbin(ABin a, int v[], int N){
    int r = 0;
    if (a && N > 0){
        r = dumpAbin(a->esq, v, N - 1);
        v[r] = a->valor;
        r++;
        r += dumpAbin(a->dir, v + r, N - r);
    }
    return r;
}

//41
//TODO
ABin somasAcA(ABin a){
    if(!a) return NULL;
    // criamos uma nova árvore recursivamente
    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    //o valor da arvore vai ser a soma do valor desta
    //com o valor das folhas, se estas existirem
    new->valor = a->valor + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0);
    return new;
}

//42
//TODO
int contaFolhas(ABin a){
    if(!a) return 0;
    if(a) if(!a->esq && !a->dir) return 1;
    return contaFolhas(a->esq) + contaFolhas(a->dir);
}

//43
ABin cloneMirror(ABin a) {
    if(!a) return NULL;
    ABin temp = a->esq;
    ABin b = malloc(sizeof(struct nodo));
    b->valor = a->valor;
    b->esq = cloneMirror(a->dir);
    b->dir = cloneMirror(temp);
    return (b);
}

//44
//TODO
int addOrd (ABin *a, int x) {
    while(*a) {
        if((*a)->valor == x) return 1;
        if((*a)->valor > x) a = &((*a)->esq); // se x for menor, apontamos para a arvore da esquerda
        else a = &((*a)->dir); // senão apontamos para a da direita
    }
    // quando chegarmos à arvore a colocar o elemento
    // criamos uma nova arvore e colocamos lá o x
    ABin new = malloc(sizeof(struct nodo));
    new->valor = x;
    new->esq = new->dir = NULL;
    (*a) = new; // em vez de apontar para NULL aponta para a nova arvore
    return 0;
}

//45
//não é a melhor maneira de fazer isto, mas funciona...
int lookupAB(ABin a, int x){
    if(!a) return 0;
    if(a->valor == x) return 1;
    else return MAX(lookupAB(a->esq, x), lookupAB(a->dir, x));
}

//46
//TODO
int depthOrd(ABin a, int x){
    if(!a) return -1;
    if(a->valor == x) return 1;
    int d = depthOrd((a->valor < x ? a->dir : a->esq),x);
    // se a procura encontrar alguma coisa retorna 1 + o resultado, 
    // senão retorna -1.
    return d == -1 ? d : 1 + d;
}

//47
int maiorAB(ABin a){
    int maior = a->valor;
    while(a){ // se andarmos sempre para a direita acabamos por encontrar o maior nodo
        maior = a->valor;
        a = a->dir;
    }
    return maior;
}

//48
//TODO
void removeMaiorA(ABin *a){
    // percorrer todos os nodos até ao maior:
    while((*a)->dir) a = &(*a)->dir;
    // temos de passar o apontador para um nodo válido
    // ou ficamos com u "0" no nodo, de acordo com o codeboard...
    // por isso dizemos que o apontador aponta para o da esquerda que nao foi eliminado
    ABin temp = *a;
    free(*a);
    *a = temp->esq;
}

//49
int quantosMaiores(ABin a, int x){
    if(!a) return 0;
    if(a->valor > x) return 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
    return 0 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
}

//50
//TODO
void listToBTree (LInt l, ABin *a) {
    if(!l) return;
    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l) / 2;
    LInt temp = l, prev = NULL;
    int i;
    for(i = 0; i < meio; i++) {
        prev = temp;
        temp = temp->prox;
    }
    new->valor = temp->valor;
    new->esq = new->dir = NULL;
    if(prev) prev->prox = NULL;
    
    if(l != temp) listToBTree(l,&(new->esq));
    if(temp->prox) listToBTree(temp->prox,&(new->dir));
    (*a) = new;
}

//51
//TODO
int deProcuraAux(ABin a, int x, int maior) {
    if(!a) return 1;
    if((maior && a->valor < x) || (!maior && a->valor > x)) return 0;
    return deProcuraAux(a->esq,x,maior) && deProcuraAux(a->dir,x,maior);
}

int deProcura (ABin a) {
    if(!a) return 1;
    int b = deProcuraAux(a->esq,a->valor, 0) && deProcura(a->esq);
    int c = deProcuraAux(a->dir,a->valor, 1) && deProcura(a->dir);
    return b && c;
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
