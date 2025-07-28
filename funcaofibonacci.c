#include <stdio.h>

long long fatorial(int n){
    long long resul = 1; // variavel de retorno
    for(int j = 2; n >= j; n--){
        resul *= n;
    }
    return resul;
}

long fibonacci(int n){
    long f0, f1, f2; // primeiro, segundo e valor atual do fibonacci

f0 = f1 = f2 = 1; // inicializa todos em 1

for(int i = 2; i <= n; i++){
    f2 = f1 + f0;
    f0 = f1;
    f1 = f2;
}
    return f2;
}


int main() {

    for(int i = 0; i < 10; i++){
    printf("fibonacci(%d) = %ld\n", i, fibonacci(i));
    }

    long long resp = fatorial(11) + fibonacci(11);
    printf("resp = %ld\n", resp);
    printf("\n");
    return 0;
}