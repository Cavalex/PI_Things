#include <stdio.h>

float multInt1(int n, float m){
    float r = 0;
    while(n > 0){
        r += m;
        n -= 1;
    }
    return r;
}

float multInt1(int n, float m){
    if(n > 0) return multInt1(n-1, m+n);
    else return m;
}

float multInt2(int n, float m){
    float r = 0;
    for(int i = 1; n >= 1; i++){
        printf("\n%d | %d | %f", i, n, m);
        if(n % 2 != 0) r += m;
        n >>= 1; // não usar a divisão ao implementar a multiplicação, usar o right shift
        m += m; // não usar multiplicação ao implementar a multiplicação
    }
    return r;
}

int mdc1(int a, int b){
    int r = a;
    while(r > 0){
        if(a % r == 0 && b % r == 0) return r;
        else r--; 
    }
    return r;
}

int mdc2(int a, int b){
    if(a == b) return a;
    if(a == 0) return b;
    if(b == 0) return a;
    if(a > b) return mdc2(a%b, b);
    if(a < b) return mdc2(a, b%a);
}

int fib1(int n){
    if(n == 0) return 0;
    if(n < 2) return 1;
    else return (fib1(n-1) + fib1(n-2));
}

int fib2(int n){
    int a = 0, b = 1, c;
    if(n <= 1 && n >= 0) return n;
    for(; n > 1; n--){ // os 2 primeiros já são o 0 e o 1;
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int a = 0, b = 20;
    float f = 2.5;

    //printf("\n%f", multInt1(a,f));
    //printf("\n%d x %f = %f", a, f, multInt2(a,f));
    //printf("\nmdc: %d", mdc1(a,b));
    //printf("\nmdc: %d", mdc2(a,b));
    printf("\nfib: %d", fib2(a));

    return 0;
}
