#include <stdio.h>

//#define max(x,y) 

// Árvores binárias

struct nodo{
    int valor;
    struct nodo *l;
    struct nodo *r;
} typedef *ABin;

int maxBT(int a, int b){
    if(a > b) return a;
    return b;
}

// 1º temos de pensar:
// se temos que percorrer ambos os lados -> função recursiva
// se temos que percorrer só um lado -> função iterativa

int altura(ABin a){
    if (!a) return 0; // caso base
    // função max entre os 2 nodos,
    return maxBT(1 + altura(a->l), 1 + altura(a->r));
}

int nFolhas(ABin a){
    if (!a) return 0;
    if (!a->l && !a->r) return 1;
    return nFolhas(a->l) + nFolhas(a->r);
}

int maisEsquerda(ABin a){
    if (!a) return NULL;
    while(a->l) a = a->l;
    return a;
}

int maisEsquerdaRecursive(ABin a){
    //if (!a) return NULL; // ou return a, que a é NULL
    if (!a->l || !a) return a;
    return maisEsquerda(a->l);
}

void imprimeNivel(ABin a, int l){
    if(a){
        if(!l) printf("%d\n", a->valor); // !l == (l == 0)
        else{
            if(a->l) imprimeNivel(a->l, l-1);
            if(a->r) imprimeNivel(a->r, l-1);
        }
    }
}

int procuraE(ABin a, int x){
    // função linda~
    return (a && ((a->valor == x) || (procuraE(a->l, x)) || (procuraE(a->r, x))));
}

struct nodo *procura(ABin a, int x){
    while(a && x != a->valor){
        if(x > a->valor) a = a->r;
        else a = a->l;
    }
    return a;
}

int nivel(ABin a, int x){
    int n = 0;
    while(a && x != a->valor){
        if(x > a->valor) a = a->r;
        else a = a->l;
        n++;
    }
    // se não encontrar o elemento devolve -1
    if(!a) n = -1;
    return n;
}

// minha versão, está muito provavelmente mal
void imprimeAte2(ABin a, int x){
    if(a){
        if(a->valor != x) printf("%d\n", a->valor);
        else{
            imprimeAte2(a->l, x);
            imprimeAte2(a->l, x);
        }
    }
}

void imprimeAte(ABin a, int x){
    if(a){
        imprimeAte(a->l, x);
        if(x >= a->valor){
            printf("%d\n", a->valor);
            imprimeAte(a->r, x);
        }
    }
}

int main(){

    printf("preciso de net :(\n");

    return 0;
}
