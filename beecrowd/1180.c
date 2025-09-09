
#include <stdio.h>

int n;

int menor(int vetor[1001]){

    int menor = 1000;

    for(int i=0; i < n; i++){
        if(vetor[i] < menor)
            menor = vetor[i];
    }
    return menor;
}

int posi(int vetor[1001]){

    int menor = 1000;
    int posicao;

    for(int i=0; i < n; i++){
        if(vetor[i] < menor){
            menor = vetor[i];
            posicao = i;
        }
    }
    return posicao;
}

int main() {
    
    int vet[1001];
    int menorv, posicao;

    scanf("%d", &n);

    for(int i=0; i< n; i++){
        scanf("%d", &vet[i]);
    }
        menorv = menor(vet);
        posicao = posi(vet);

        printf("Menor valor: %d\n", menorv);
        printf("Posicao: %d\n", posicao);

    return 0;
}