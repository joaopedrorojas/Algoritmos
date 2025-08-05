#include <stdio.h>


//Recursividade é utilizar a mesma função para gerar um loop, semelhante a um laço de repetição.

long long fatorial(int n){
    if(n==0)
        return 1;
    else
        return n * fatorial(n -1);
}

int soma(int n){
    if (n == 0)
        return 0;
    else
        return n + soma(n-1);
}

int fibonacci(int n){

    if(n == 0 || n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);

}

long long conversao(int n){ // decimal para binario
    if (n == 0)
        return 0;
    else 
        return (n % 2) + 10 * conversao(n / 2);
}

int conversaobin2dec(long n){ // binario para decimal
    if (n == 0)
        return 0;
    else
        return (n % 10) + 2 * conversaobin2dec(n / 10);
}


int main(){

    for(int i = 0; i <= 20; i++){
        printf("Fatorial de %d! = %lld", i, fatorial(i));
        printf("\n");
    }

printf("\n\n");

    for(int i = 0; i <= 40; i++){
        printf("Fibonacci da posicao %d = %d", i, fibonacci(i));
        printf("\n");
    }

printf("\n\n");

    for(int i = 0; i <= 200; i++){
        printf("Conversão de decimal (%d) para binario = %lld\n", i, conversao(i));
    }

    printf("\n\n");

    for(int i = 0; i <= 200; i++){
        printf("Conversão de binario (%lld) para decimal = %d\n", conversao(i), conversaobin2dec(conversao(i)));
    }

    return 0;
}