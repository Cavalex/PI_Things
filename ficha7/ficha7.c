#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

//1
void libertaLista(Palavras l){
    Palavras aux;
    while(l){
        // está mal
        // free(l);
        // l = l->prox;
        
        // assim tá correto
        aux = l->prox;
        free(l);
        l = aux;
    }
}

//2.1
int existeP(Palavras l, char *p){
    // while(l != NULL){
    //     if(strcmp(l->palavra, p) == 0) return 1;
    //     l = l->prox;
    // }
    // return 0;

    // wow
    while(l && strcmp(l->palavra, p)) l = l->prox;
    return (l != NULL);
}

//2.2
int ocorreP(Palavras l, char *p){
    int count = 0;
    while(l != NULL){
        if(strcmp(l->palavra, p) == 0) count++;
        l = l->prox;
    }
    return count;
}

//2
int quantasP(Palavras l){
    int count = 0;
    // deve haver uma maneira diferente de fazer isto
    // tecnicamente é isto...
    // while(temp != NULL){
    //     if(temp->ocorr == 1) count++;
    //     temp = temp->prox;
    // }

    // while(l){ // (l) == (l != NULL)
    //     if(ocorreP(l, l->palavra) == 1) count++;
    //     l = l->prox;
    // }

    while(l){
        if(!existeP(l->prox, l->palavra)) count++;
        l = l->prox;
    }

    return count;
}

//3
void listaPal(Palavras l){
    // o temp é desnecessário, 
    // podemos usar o l visto que é um pointer
    Palavras temp = l;
    while(temp != NULL){
        printf("palavra -> %s, ocorrencias -> %d ", temp->palavra, temp->ocorr);
        temp = temp->prox;
        putchar('\n');
    }
}

//4
char *ultima(Palavras l){
    // while(l){
    //     if(l->prox == NULL) return l->palavra;
    //     else l = l->prox;
    // }

    // char *r = NULL;
    // while(l){
    //     r = l->palavra;
    //     l = l->prox;
    // }
    // return r;

    // pode crashar caso a lista esteja vazia
    while(l->prox){ l = l->prox; }
    return l->palavra;
}

//5
Palavras acrescentaInicio(Palavras l, char *p){
    Palavras temp = malloc(sizeof(struct celula));
    // meter sempre este teste
    if (temp == NULL) return NULL; // caso teste ao malloc
    temp->palavra = p;
    temp->ocorr = 1;
    temp->prox = l;
    return temp;
}

//6
Palavras acrescentaFim(Palavras l, char *p){
    Palavras aux = l;
    if (l == NULL){
        return acrescentaInicio(l, p);
    }
    while(aux->prox) aux = aux->prox;
    aux->prox = acrescentaInicio(NULL, p);
    return l;

    // nao funciona :(
    // Palavras r = l;
    // Palavras nova = malloc(sizeof(struct celula));
    // if (nova == NULL) return NULL;
    // nova->palavra = p;
    // nova->ocorr = 1;
    // nova->prox = NULL;

    // while(l){
    //     if(!(l->prox)){
    //         l->prox = nova;
    //         break;
    //     }
    //     l = l->prox;
    // }
    // return r;
}

//7
// mais facil de forma recursiva
Palavras acrescenta (Palavras l, char *p){
    //o l é nulo entao so queremos acrescentar a celula nova
    //testamos se a primeira é menor que a segunda
    if(!l || (strcmp(p,l->palavra) < 0)){
        return acrescentaInicio(l,p);
    }
    else if ((strcmp(p,l->palavra) == 0)){
        l->ocorr++;
        return l;
    }
    else{
        l->prox = acrescenta(l->prox,p);
        return l;
    }

}

//8
Palavras maisFreq (Palavras l){
    Palavras res;
    int max = 0; //automaticamente menor que todas as freqs (que começam a 1);
    
    while (l){
        if(l->ocorr > max){
            res = l;
            max = l->ocorr;
        }
        l = l->prox;
    }
    return res;
}

int main(){

    char *conta1[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "k"};
    Palavras dic = NULL;

    for (int i = 0; i < 10; i++){
        dic = acrescentaInicio(dic, conta1[i]);
        //printf("palavra indice %d -> %s ", i, dic->palavra); // yey
        //putchar('\n');
    }
    listaPal(dic);
    printf("ultima: %s\n", ultima(dic));
    printf("quantas: %d\n", quantasP(dic));
    libertaLista(dic);
    listaPal(dic);
    acrescentaFim(dic, conta1[9]);
    listaPal(dic);

    return 0;
}

