#include <stdio.h>
#include <stdlib.h>

void preencher(int n, int **matriz){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = abs(i - j) + 1;
        }
    }
}

int main() {
    
    int n;

    while(scanf("%d", &n) && n != 0){

        int **matriz;

        matriz = (int**)calloc(n, sizeof(int*)); // so é possivel utilizar o calloc, colocando primeiro o numero em seguida
        // uma ',' e depois o tamnho de bytes.

        //vantagem do calloc: nao precisa limpar a memoria no final do codigo

        /*if(matriz == NULL){
            printf("Erro 1: memoria insuficiente\n");
            return 1;
        }*/

        for(int i = 0; i < n; i++){
            matriz[i] = (int*)calloc(n, sizeof(int));

        /*    if(matriz[i] == NULL){
                printf("Erro 2: memoria insuficiente\n");
                return 2;
            }*/
        }

        preencher(n, matriz);

        for(int i = 0; i<n; i++){
            for(int j=0;j<n;j++){
                if(j == 0)
                    printf("%3d", matriz[i][j]);
                else
                    printf(" %3d", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}