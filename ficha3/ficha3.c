#include <stdio.h>

//1

//a
// i = 0: 1 1 4
// i = 1: 2 2 6
// i = 0: 3 3 8
// i = 0: 4 4 10
// i = 0: 5 5 12

//b
// j = 13

void swapM(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

void swap(int v[], int i, int j){
    //swapM(v+i, v+j);
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

int soma(int v[], int N){ // int v[] = int *v
    int soma = 0;
    for(int i = 0; i < N; i++) soma += v[i];
    return soma;
}

void inverteArray (int v[], int N) {

    int i, j;
    for (i=0; i<N/2; i++){
        swap(v, i, N-1-i);
    }
}

int maximum(int v[], int N, int *m){

    *m = v[0];
    for(int i = 1; i < N; i++){
        if(v[i] > *m) *m = v[i];
    }

    return N;
}

void quadrados(int q[], int N){
    q[0] = 0;
    for(int i = 0; i < N; i++) q[i] = q[i-1]+i+i-1;
}

void pascal(int v[], int N){
    int i, linha;
    for(linha = 0; linha <= N; linha++){
        v[linha] = 1;
        for(i = linha-1; i > 0; i--) v[i] = v[i] + v[i-1];
    }
}

void dumpV(int v[], int N){
    for(int i = 0; i < N; i++) printf("%d ", v[i]);
    putchar('\n');
}

// Só é uma pena que não fique mesmo um triângulo :(
void desenhaTrianguloP(int N){
    int v[N+1];
    for(int i = 0; i < N + 1; i++){
        pascal(v, i);
        dumpV(v, i + 1);
    }
}

int main(){

    int a = 3, b = 5, m = -1;
    int v[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("a = %d, &a = %d,\nb = %d, &b = %d\n", a, &a, b, &b);
    swapM(&a, &b);
    printf("a = %d, &a = %d,\nb = %d, &b = %d\n", a, &a, b, &b);

    swap(v, 0, 9);
    printf("v[0] = %d, v[9] = %d,\n", v[0], v[9]);

    printf("Soma: %d\n", soma(v, 10));

    dumpV(v, 10);
    inverteArray(v, 10); // Não dá!?
    dumpV(v, 10);

    printf("Maximum: %d\n", maximum(v, 10, &m));

    quadrados(v, 3);
    dumpV(v, 10);

    printf("\n");
    int pascalN = 10;
    pascal(v, pascalN);
    dumpV(v, pascalN + 1);

    printf("\n");
    desenhaTrianguloP(10);

    return 0;
}

