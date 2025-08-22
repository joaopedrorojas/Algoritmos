//exercicio 2 da lista 2, unidade 6
#include <stdio.h>

int MDC(int a, int b){

    if(b == 0)
        return a;

    else
        return MDC(b, a%b);
}

int aparece(int a, int b){

    if(a != 0 && b == 0)
        return 0;

    if(a == 0 && b == 0)
        return a;

    if(a == b%10)
        return 1 + aparece(a, b / 10);
    else
        return aparece(a, b / 10);
}

double somavet(double vetor[], int w){

    if(w == 0)
        return 0;

    else
        return vetor[w - 1] + somavet(vetor, w - 1);
}


int main() {
    
    int x, y, w;
    double vet[50];
    double resul;

    /*
    printf("Insira dois numeros naturais para ver o MDC:\n");
    scanf("%d %d", &x, &y);
    printf("O MDC é: %d\n", MDC(x, y));
    */

    /*
    printf("\nInsira dois numeros:\n");
    scanf("%d %d", &x, &y);
    printf("O numero %d aparece %dx no numero %d!\n", x, aparece(x, y), y);
    */

    printf("Insira o tamanho do Vetor:\n");
    scanf("%d", &w);

    for(int i = 0; i < w; i++){
        vet[i] = i + 1;
    }
    resul = somavet(vet, w);
    printf("A soma dos valores do vetor é de: %.2lf\n", resul);

    return 0;
}