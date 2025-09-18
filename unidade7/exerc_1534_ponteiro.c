#include <stdio.h>
#include <stdlib.h>

void preencher(int n, int **matriz){

    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            matriz[i][j] = 3;
        }
    }
}

void diagonais(int n, int **matriz){

    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                matriz[i][j] = 1;
        }
    }

    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            if(i + j == n - 1)
                matriz[i][j] = 2;
        }
    }
}

int main() {
    
    int **matriz;
    int n;

    while(scanf("%d", &n) != EOF){

    matriz = (int**)malloc(sizeof(int*) * n);

    for(int i = 0; i < n; i++){
        matriz[i] = (int*)malloc(sizeof(int) * n);
    }

    preencher(n, matriz);
    diagonais(n, matriz);

    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    }
    return 0;
}