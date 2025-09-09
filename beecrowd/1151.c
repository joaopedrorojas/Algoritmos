#include <stdio.h>

int main() {
    
    int n, anterior = 0, atual = 1, soma = 0;

    scanf("%d", &n);

    if(n >= 1)
    printf("%d ", anterior);

    if(n >= 2)
    printf("%d", atual);
    for(int i = 3; i <= n; i++){
        soma = anterior + atual;
        anterior = atual;
        atual = soma;
        printf(" %d", soma);
    }
    printf("\n");

    return 0;
}