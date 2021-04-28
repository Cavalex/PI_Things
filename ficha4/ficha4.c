#include <stdio.h>
#include <string.h>

void dumpV(int v[], int N){
    for(int i = 0; i < N; i++) printf("%d ", v[i]);
    putchar('\n');
}

// auxiliary function
int check_vowel(char ch)
{
    /* 
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;

    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return 1;
    */
    char vogais[10] = "aeiouAEIOU"; // tamanho de 11???????
    char *v = vogais;
    while(*v){
        if (*v++ == ch) return 1; // incrementa depois da comparação
    }
    return 0;
}

/* 
int contaVogais(char *s){ // count vowels, return how many vowels are there
    int v = 0;
    for(int i = 0; s[i]; i++){ // s[i] != '\0' , ter só s[i] tbm serve porque o '\0' conta como 0
        if(check_vowel(s[i]))
            v += 1;
    }
    return v;
}
*/

int contaVogais(char *s){
    int v = 0;
    while(*s){ // usar o string como um pointer
        if(check_vowel(*s)) v++;
        s++; // incrementamos o pointer, passamos para o próximo char
    }
    return v;
}

void apaga(char *s, int i){
    while(s[i]){
        s[i] = s[i+1];
        i++;
    }
}

int retiraVogaisRep(char *s){
    int i = 0, c = 0;
    while(s[i]){
        if(s[i] == s[i+1] && check_vowel(s[i])){
            c++;
            apaga(s, i);
        }
        else i++;
    }

    return c;
}

// USAR SEMPRE ESTA ESTRATÉGIA
int retiraVogaisRep2(char *s){
    int i = 0, c = 0, o = 0;
    while(s[i]){
        if(s[i] == s[i+1] && check_vowel(s[i])){
            c++;
        }
        else{
            s[o] = s[i];
            o++;
        }
        i++;
    }
    s[o] = '\0';

    return c;
}

int duplicaVogais(char *s){
    int i = 0, o = 0, c = 0;
    char aux[strlen(s)*2+1];

    while(s[i]){
        if(check_vowel(s[i])){
            aux[o] = s[i];
            o++;
            c++;
        }
        aux[o] = s[i];
        o++;
        i++;
    }
    aux[o] = '\0';

    for(i = 0; aux[i]; i++){
        s[i] = aux[i];
    }
    s[i] = '\0';

    return 0;
}

int duplicaVogais2(char *s){
    int i = strlen(s), c = contaVogais(s);
    int o = i+c;
    char aux[o+1];

    while(i >= 0){
        if(check_vowel(s[i])){
            s[o] = s[i];
            o--;
        }
        s[o] = s[i];
        o--;
        i--;
    }

    return c;
}

int ordenado(int a[], int N){
    int i, flag = 1;
    for(i=0; i<N-1 && a[i] <= a[i+1]; i++);
    return (i == N-1);
}

void merge(int a[], int na, int b[], int nb, int r[]){
    int ia, ib, ir;
    ia = ib = ir = 0;
    
    while(ia < na && ib < nb)
        if(a[ia] < b[ib]) r[ir++] = a[ia++];
        else r[ir++] = b[ib++];
    while(ia < na) r[ir++] = a[ia++];
    while(ib < nb) r[ir++] = b[ib++];
}

int main(){

    int a1[3] = {2,5,6};
    int a2[3] = {1,4,7};
    int a3[6];

    char s0[100] = "aeioubcdfg";
    char s1[100] = "aaaaaaaaaaaaabcerd";
    char s2[100] = "aabceeeerAdgaeagaaaauuzzzevze";

    printf("Vogais de \"%s\": %d\n", s2, contaVogais(s2));
    retiraVogaisRep2(s2);
    printf("vogais: %d; s2: %s\n", contaVogais(s2), s2);
    duplicaVogais2(s2);
    printf("vogais: %d; s2: %s\n\n", contaVogais(s2), s2); // duplicou

    printf("a1 ordenado?: %d\n", ordenado(a1, 5));
    printf("a2 ordenado?: %d\n", ordenado(a2, 5));
    merge(a1, 3, a2, 3, a3);
    dumpV(a3, 6);

    return 0;
}

