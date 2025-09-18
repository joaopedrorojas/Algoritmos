#include <stdio.h>

int soma(int n){
    
    if(n == 0)
    return 0;

    return n + soma(n - 1);
}

long long fat(long long n){

    if(n == 0)
        return 1;

    return n * fat(n - 1);
}

int fib(int n){

    if(n == 0 || n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

long dec2bin(int n){
    if(n == 0)
        return 0;
    
    return (n % 2) + 10 * dec2bin(n / 2);
}

int main() {
    int n;
    long long x;
    long h;
    scanf("%d", &n);
    printf("SOMA: %d\n", soma(n));
    scanf("%lld", &x);
    printf("Fatorial: %lld\n", fat(x));
    scanf("%d", &n);
    printf("Fibonacci: %d\n", fib(n));
    scanf("%ld", &h);
    printf("Binario: %ld\n", dec2bin(h));
    
    return 0;
}