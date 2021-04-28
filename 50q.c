#include <stdio.h>

//1
void biggest(){
    int n;
    scanf("%d", &n);
    int b = n;
    while(n != 0){
        scanf("%d", &n);
        if(n > b) b = n;
    }
    printf("biggest: %d",b);
}

//2
void average(){
    int n, i = 0;
    float ac = 0;
    scanf("%d", &n);
    //ac += n;
    while(n != 0){
        ac += n;
        i++;
        scanf("%d", &n);
    }
    printf("average: %f", ac/i);
} 

//3
void biggest2(){
    int n;
    scanf("%d", &n);
    int b = n, b2 = n;
    while(n != 0){
        scanf("%d", &n);
        if(n > b){
            b2 = b;
            b = n;
        }
    }
    printf("2nd biggest: %d", b2);
}

//4
int bitsUm(unsigned int n){
    int i = 0;
    while(n){ // enquanto que não estiver tudo a 0
        if(n % 2) i++;
        n >>= 1; // basicamente divide n por 2, dá shift à direita dos bits de n
    }
    return i;
}

//5
//original
int trailingZ(unsigned int n){
    int i = 0;
    if(n == 0) return 32; // ??????? necessay for a problem
    while(n){
        if(n % 2 == 0) i++;
        n /= 2; 
    }
    return i;
}

int trailingZ2(unsigned int n){
    int i = 0;
    while(n){
        if (!(n % 2)) i++;
        n >>= 1;
    }
    return i;
}

//6
int qDig(unsigned int n){
    if(n < 1) return 0;
    return 1 + qDig(n / 10);
}

//19
int sufPref(char s1[], char s2[]){
    int c = 0;
    int j, i;
    int last = 0;
    for(i = 0; s1[i] != '\0'; i++){
        if(s1[i] == s2[0]){
            for(j = i; s1[j] != '\0'; j++){
                last++;
                if(s1[j] == s2[(j-i)]) c++;
            }
            if(s1[j] == '\0' && last == c) return c;
            c = 0;
            last = 0;
        }
    }
    return c;
}

//20
int contaPal(char s[]){
    int i, c = 0;
    for(i = 0; s[i] != '\0'; i++){
        if((s[i] != ' ' && s[i-1] == ' ' && s[i] != '\n') || (s[i] != ' ' && i == 0 && s[i] != '\n'))c++;
    }
    return c;
}

int main(){
    int n = 440;

    //biggest2();
    printf("1's -> %d\n", bitsUm(n));
    printf("0's -> %d\n", trailingZ(n));
    printf("d's -> %d", qDig(n));

    return 0;
}
