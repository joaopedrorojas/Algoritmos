#include <stdio.h>

//funcao fatorial(int n)
long long fatorial(int n){
    long long resul = 1; // variavel de retorno
    for(int j = 2; n >= j; n--){
        resul *= n;
    }
    return resul;
}

int main() {
    for (int i = 0; i < 10; i ++){
        printf("%d! = %ld\n", i, fatorial(i));
    }
    printf("\n");
    return 0;
}