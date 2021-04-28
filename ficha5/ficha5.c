#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a) {
    int soma_miniT = 0;
    float final;
    float minis;

    for (int i = 0; i < 6; i++) {
        soma_miniT += a.miniT[i];
    }

    minis = (((float) soma_miniT) / 12) * 20;
    final = round(minis * 0.3 + a.teste*0.7);
    if (a.teste < 8 || minis < 8 || final < 10) final = 0;
    return final;
}

// minha versao, acho que nao funciona
int procuraNum1(int num, Aluno t[], int N){
    while(N >= 0){
        if (t[--N].numero == num) return N;
    }
    return -1;
}

int procuraNum2(int num, Aluno t[], int N){
    int i = 0;
    for(i = 0; i < N && t[i].numero != num; i++) if (i == N) i = -1;
    return i;
}

// pesquisa binária ??
int procuraNum3(int num, Aluno t[], int N){
    int l = 0;
    int r = N-1;
    int meio;
    while(l <= r){
        meio = (l+r) /2;
        if (t[meio].numero == num) return meio;
        if (t[meio].numero < num) l = meio + 1;
        else r = meio - 1;
    }
    return -1;
}
/* 
void imprimeTurmaInd(int ind[], Aluno t[], int N){
    int i;
    for (int i = 0; i < N; i++) imprimeAluno(&t[ind[i]]);
} */

int swapA(Aluno t[], int i, int j){
    Aluno aux;
    aux = t[i];
    t[i] = t[j];
    t[j] = aux;
}

int ordenaPorNum(Aluno t[], int N){
    int i, j;
    for (i = 0; i < N-1; i++)
        // Last i elements are already in place   
        for (j = 0; j < N-i-1; j++) 
            if (t[j].numero > t[j+1].numero)
                swap(t, i, i+1);
}

void swapI(int t[], int i, int j){
    int aux;
    aux = t[i];
    t[i] = t[j];
    t[j] = aux;
}

void criaIndPorNum(Aluno t[], int N, int ind[]){
    int i, flag = 1;
    for (i = 0; i < N; i++) ind[i] = i;
    while(flag){
        flag = 0;
        for (i = 0; i < N-1; i++){
            if (t[ind[i]].numero > t[ind[i+1]].numero) {swapI(ind, i, i+1); flag = 1;}
        }
        N--;
    }
}

void criaIndPorNome(Aluno t[], int N, int ind[]){
    int i, flag = 1;
    for (i = 0; i < N; i++) ind[i] = i;
    while(flag){
        flag = 0;
        for (i = 0; i < N-1; i++){
            if (strcmp(t[ind[i]].nome, t[ind[i+1]].nome) > 0) {swapI(ind, i, i+1); flag = 1;}
        }
        N--;
    }
}

int main(){
    
    Aluno a1;
    Aluno a2;



    return 0;
}





