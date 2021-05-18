#include <stdio.h>

#define MAX(a,b) (a>b) ? a : b

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;


//a)
int altura (ABin a){
    int r = 0;
    if(a){
        r++;
        r += MAX(altura(a->esq), altura(a->dir));
    }
    return r;
}

//b)
int nFolhas (ABin a){
    int r = 0;
    if(a){
        if(!a->esq && !a->dir)
            r++;
        else
            r += nFolhas(a->esq) + nFolhas(a->dir);
    }
    return r;
}

//c)
ABin maisEsquerda (ABin a){
    ABin r = NULL;
    if(a){
        if(a->esq)
            r = maisEsquerda(a->esq);
        else 
            r = a;
    }
    return r;
}

//d)
void imprimeNivel (ABin a, int l){
    if(a){
        if(!l)
            printf("%d ", a->valor);
        else{
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir, l-1);
        }
    }
}

//e)
int procuraE (ABin a, int x){
    int r = 0;
    if(a){
        if(a->valor==x)
            r=1;
        else
            r = MAX(procuraE(a->esq, x), procuraE(a->dir, x));
    }
    return r;
}

//f)
ABin procura (ABin a, int x){
    ABin r = NULL;
    if(a){
        if(x == a->valor)
            r = a;
        else 
	        if (x < a->valor)
	            r = procura (a->esq, x);
	        else
	            r = procura (a->dir, x);
    }
    return r;
}

//g)
int nivel (ABin a, int x){
    int r = -1;
    if(a){
        if(a->valor == x)
            r=0;
        else{
        	if (x < a->valor)
	            r = nivel(a->esq, x);
	        else
	            r = nivel(a->dir, x);

            if(r!=-1)
                r++;
        }
    }
    return r;
}

//h)
void imprimeAte (ABin a, int x){
    
    if(a){
    	if (x > a->valor){
    		imprimeAte(a->esq, x);
    		printf("%d ", a->valor);
    		imprimeAte(a->dir, x);
    	}
    	else 
    		imprimeAte(a->esq, x);
    }
}
