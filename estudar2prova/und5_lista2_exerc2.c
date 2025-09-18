#include <stdio.h>

int fib(int n){
    int anterior = 0, seguinte, atual = 1;

    for(int i = 0; i < n; i++){
        seguinte = anterior + atual;
        anterior = atual;
        atual = seguinte;
    }

    return atual;
}

int main() {
    
    int n;

    while(scanf("%d", &n) != EOF){

        printf("%d\n", fib(n));
    }
    return 0;
}