#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

//1
void biggest(){
    int n, b;
    scanf("%d", &n);
    b = n;
    while(n != 0){
        scanf("%d", &n);
        if(n > b) b = n;
    }
    printf("biggest: %d", b);
}

//2
void average(){
    int n, i;
    float total = 0; // necessary for the division in the end
    scanf("%d", &n);
    for(i = 0; n != 0; i++){
        total += n;
        scanf("%d", &n);
    }
    printf("average: %f", total/i);
}

//3
void second(){
    int n, b, b2;
    scanf("%d", &n);
    b = n;
    b2 = b;
    while(n != 0){
        scanf("%d", &n);
        if(n > b){
            b = n;
        }
        if(n > b2 && n < b){
            b2 = n;
        }
    }
    printf("biggest: %d\n", b);
    printf("2ndbiggest: %d", b2);
}

//4
int bitsUm(unsigned int n){
    int i = 0;
    while(n){ // enquanto que não estiver tudo a 0
        if(n % 2) i++;
        n >>= 1; // basicamente divide n por 2, dá 1 shift à direita dos bits de n
        //printf("i:%d n:%d\n", i, n);
    }
    return i;
}

//5
int trailingZ(unsigned int n){
    int i = 0;
    while(n){
        if(!(n % 2)) i++;
        n >>= 1;
    }
    return i;
}

//6
int qDig(unsigned int n){
    if(n < 1) return 0;
    return 1 + qDig(n/10);
}

//7
char* mystrcat(char s1[], char s2[]){
    char* s = s1;
    while(*s1) s1++; // chegar ao fim de s1
    while(*s2){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return s;
}

//8
char* mystrcpy(char dest[], char source[]){
    char* s = dest;
    while(*source){
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    return s;
}

//9
int mystrcmp(char s1[], char s2[]){
    while(*s1){
        if(*s1 != *s2) break;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

//TODO
//10
char* mystrstr (char haystack[], char needle[]) {
    int isContained = 1;
    char* ans = haystack;
    char* needleStart = needle;
    while(*needle && *haystack) {
        if(*haystack != *needle) {
            isContained = 0;
            needle = needleStart;
        }
        if(*haystack == *needle) {
            if(!isContained) {
                isContained = 1;
                ans = haystack;
            }
            needle++;
        }
        haystack++;
    }
    if (isContained && !(*needle)) return ans;
    else return NULL;
}

//11
void mystrrev(char s[]){
    int len;
    for(len = 0; s[len]; len++); // queremos o comprimento de s
    char res[len];
    int i;
    for(i = 0; i < len; i++) res[i] = s[len - i - 1]; // criamos o res com o inverso de s
    for(i = 0; i < len; i++) s[i] = res[i]; // copiamos para o s
}

//12
void tail(char* s){
    while(*s){
        *s = *(s+1);
        s++;
    }
}

void strnoV(char s[]){
    while(*s){
        if(*s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U' || *s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u'){
            tail(s);
        }
        else{
            s++;
        }
    }
}

//13
void truncW(char t[], int n){
    int size = -1;
    while(*t){
        if(*t == ' ') size = -1;
        else size++;
        if(size >= n && *t != ' ') tail(t);
        else t++;
    }
}

//14
char charMaisFreq(char s[]){
    int biggest = -1, count = 0;
    char biggestChar, c;
    char* s2;
    while(*s){
        count = 0;
        c = *s;
        s2 = s;
        while(*s2){
            if(*s2 == c) count++;
            s2++;
        }
        if(count > biggest){
            biggest = count;
            biggestChar = c;
        }
        s++;
    }
    return biggestChar;
}

//15
// mesma lógica de cima
int iguaisConsecutivos(char s[]){
    int biggest = 0, count = 0;
    char c;
    char* s2;
    while(*s){
        count = 0;
        c = *s;
        s2 = s;
        while(*s2){
            if(*s2 == c) count++; // são sempre consecutivos no inicio, visto que conta o proprio char no inicio do loop
            else break;
            s2++;
        }
        if(count > biggest){
            biggest = count;
        }
        s++;
    }
    return biggest;
}

//16
//TODO
/* 
int difConsecutivos(char s[]){
    int biggest = 0, count = 1;
    char c;
    char* s2;
    while(*s){
        count = 1;
        c = *s;
        s2 = s;
        while(*s2){
            if(*s2 != *(s2+1)) count++;
            else break;
            s2++;
        }
        if(count > biggest){
            biggest = count;
        }
        s++;
    }
    return biggest;
}
*/


int not_in_prev(char str[], int k, int n) {
    int ans = 1;
    for(int i = k; i < n; i++) {
        if(str[i] == str[n]) {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos(char s[]) {
    int ans = 0;
    for(size_t i = 0; s[i]; i++) {
        int consec = 0;
        for(size_t j = i; s[j]; j++) {
            if(not_in_prev(s,i,j)) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
}

//17
int maiorPrefixo(char s1[], char s2[]){
    int count = 0;
    while(*s1 == *s2){
        count++;
        s1++;
        s2++;
    }
    return count;
}

//18
int maiorSufixo(char s1[], char s2[]){
    int i, j, count = -1; // count begins at -1 because of the '\0'
    for(i = 0; s1[i]; i++); // simply goes to the last element of the array
    for(j = 0; s2[j]; j++);
    while(s1[i] == s2[j]){
        i--;
        j--;
        count++;
    }
    return count;
}

//19
// minha versão
/*
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
*/

//TODO
int sufPref (char s1[], char s2[]) {
    int ans = 0, i, j = 0;
    for(i = 0; s1[i]; i++) {
        if(s1[i] == s2[j++]) ans++;
        else ans = j = 0;
    }
    return ans;
}

//20
int contaPal(char s[]){
    int i, c = 0;
    for(i = 0; s[i]; i++){
        if((s[i] != ' ' && s[i-1] == ' ' && s[i] != '\n') || (s[i] != ' ' && i == 0 && s[i] != '\n')) c++;
    }
    return c;
}

int main(){
    int n = 440;
    char s1[] = "mundo cruel!!!";
    char s2[] = "fgh22ij";

    //average();
    //biggest2();
    //printf("1's -> %d\n", bitsUm(n));
    //printf("0's -> %d\n", trailingZ(n));
    //printf("d's -> %d\n", qDig(n));
    //mystrcpy(s1, s2);
    //printf("string -> %s\n", s1);


    //printf("%c != %c count -> %d\n", *s2, c, count);
    printf("difCon-> %d", difConsecutivos(s1));

    return 0;
}
