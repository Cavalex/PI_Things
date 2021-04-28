#include <stdio.h>

void quadrado(int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("#");
        }
        printf("\n");
    }
}

void xadrez(int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if ((i+j) % 2 == 0) printf("#");
            else printf("_");
        }
        printf("\n");
    }
}

void trianguloV (int n){
    //cima
    for(int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            printf("#");
        }
        printf("\n");
    }

    //baixo
    for(int i = n; i > 0; i--){
        for (int j = i; j > 0; j--){
            printf("#");
        }
        printf("\n");
    }
}

void trianguloH (int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j >= n-i) printf("#");
            else printf(" ");
        }
        printf("#");
        for(int j = 0; j < i; j++){
            printf("#");
        }
        printf("\n");
    }
}

int main(){
    //quadrado(5);
    //xadrez(5);
    trianguloV(15);
    //trianguloH(10);
    if(1==1==1) printf("aaaah");

    return 0;
}
