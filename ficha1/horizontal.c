#include <stdio.h>

void triangulo(int n){
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
