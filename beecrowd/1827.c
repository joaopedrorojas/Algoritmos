#include <stdio.h>

void preencher(int n, int matriz[101][101]){

    int maior = n - 1;
    int g = n/3;
    int meio = n/2;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + j == n - 1)
                matriz[i][j] = 3;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                matriz[i][j] = 2;
        }
    }

    for(int i = g; i <= maior - g; i++){
        for(int j = g; j <= maior - g; j++){
            matriz[i][j] = 1;
        }
    }
        matriz[meio][meio] = 4;
}

int main() {
    
    int n;
    int matriz [101][101];

    while(scanf("%d", &n) != EOF){

    preencher(n, matriz);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }printf("\n");

    }
    return 0;
}