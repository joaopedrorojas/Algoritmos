#include <stdio.h>
#include <math.h>


void preencher1(int n, int matriz[15][15]){

    for(int i = 0; i< n; i++){
        for(int j =0; j < n; j++){
            matriz[i][j] = 1;
        }
    }
}

void preencher(int n, int matriz[15][15]){

    for(int i = 0; i< n; i++){
        for(int j =0; j < n; j++){
            matriz[i][j] = pow(2, i + j);
        }
    }
}

int main() {
    
    int n, tam; 
    int matriz[15][15]; 

    while(scanf("%d", &n) && n != 0){

    preencher(n, matriz);

    int cont = 1;
    tam = n - 1;
    tam = matriz[tam][tam];

        for(int p = 0; p < 9; p++){
            
            if(tam / 10 >= 1){
                tam = tam / 10;
                cont++;
            }
        }

    for(int i = 0; i< n; i++){
        for(int j =0; j < n; j++){
            if(j == 0)
                printf("%*d", cont, matriz[i][j]);
            else
                printf(" %*d", cont, matriz[i][j]);
        }
        printf("\n");
    }   printf("\n");
    }
    return 0;
}