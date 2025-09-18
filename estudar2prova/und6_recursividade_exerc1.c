#include <stdio.h>

int soma(int a, int b){

    if(b == 0)
        return a;
    
    return  soma(a + 1, b - 1);
}

int sub(int a, int b){

    if(b == 0)
        return a;

    return sub(a - 1, b - 1);
}

int multi(int a, int b){

    if(b == 0 || a == 0)
        return 0;
    
    else if(a == 1)
        return b;

    else if(b == 1)
        return a;

    return a + multi(a, b - 1);
}

int div(int a, int b){

    if(b == 0)
        return printf("Não existe divisão por 0\n");
    else if(b > a)
        return 0;
    else if(b == 1)
        return a;

    return 1 + div(a - b, b);
}

int expo(int a, int b){

    if(b == 0)
        return 1;
    else if(b == 1)
        return a;

    return a * expo(a, b - 1);
}

int main() {
    
    int a, b;

    while(scanf("%d %d", &a, &b) != EOF){
    printf("Soma: %d\n", soma(a, b));
    printf("Subtração: %d\n", sub(a, b));
    printf("Multiplicação: %d\n", multi(a, b));
    printf("Divisão: %d\n", div(a, b));
    printf("Exponenciação: %d\n", expo(a, b));
    }
    return 0;
}