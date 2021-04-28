#include <stdio.h>

void triangulo(int n){
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
