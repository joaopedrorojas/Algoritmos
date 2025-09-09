#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int **M; // dois asteriscos para declarar matriz

    int i, j; // tamanho da matriz

    printf("Quantas linhas e quantas colunas voce deseja na matriz?\n");
    scanf("%d %d", &i, &j);

    //tentar alocacar o vetor de linhas
    M = (int**)malloc(sizeof(int*) * i); // sizeof pois é o tamanho de bytes que cabe em um inteiro*

        if(M == NULL){
            printf("Erro 1: memoria insuficiente\n");
            return 1;
        }
    
    // tentar alocar os vetores de linhas
    for(int k = 0; k < i; k++){
         M[k] = (int*)malloc(sizeof(int) * j); // nao é mais dois asteriscos no int do malloc // e tambem sem asterisco no sizeof pois agora é um numero nao ponteiro 
        
        if(M[k] == NULL){
            printf("Erro 2: memoria insuficiente\n");
            return 2;
        }
    }
    //manipular a matriz
    for(int k = 0; k < i; k++){
        for(int l = 0; l < j; l++){
            M[k][l] = k + l;
        }
    }

    //escrever a matriz
    for(int k = 0; k < i; k++){
        for(int l = 0; l < j; l++){
            printf("\t%d", M[k][l]);
        }
        printf("\n");
    }

    //desalocacao da matriz
    for(int k = 0; k < i; k++){
        free(M[k]);
    }
    free(M);

    return 0;
}