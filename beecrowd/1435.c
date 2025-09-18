#include <stdio.h>

int main() {
    
    int n;

    while(scanf("%d", &n) && n != 0){

        int inicio = 0, fim = n -1;
        int matriz[100][100];
        int valor = 1;
        int camadas = (n + 1) / 2;

    for(int j = 0; j < camadas; j++){
        for(int i = inicio; i <= fim; i++){
            matriz[inicio][i] = valor;
            matriz[i][inicio] = valor;
            matriz[fim][i] = valor;
            matriz[i][fim] = valor;
        }
        inicio++;
        fim--;
        valor++;

        }
        
        for(int k = 0; k < n; k++){
            for(int l = 0; l < n; l++){

                if(l ==0)
                    printf("%3d", matriz[k][l]);
                else
                    printf(" %3d", matriz[k][l]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}