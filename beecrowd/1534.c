#include <stdio.h>

void preencher(int n, int matriz[100][100]){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = 3;
        }
    }
}

void impar(int n, int matriz[100][100]){

    for(int i = 0; i < n; i++){
        
            matriz[i][i] = 1;
    }

    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){

            if(j + k == n - 1){
                matriz[j][k] = 2;
            }
        }
    }
}

void par(int n, int matriz[100][100]){

    for(int i = 0; i < n; i++){
        
            matriz[i][i] = 1;
    }

    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){

            if(j + k == n - 1){
                matriz[j][k] = 2;
            }
        }
    }
}

int main() {
    
    int matriz[100][100];
    int num;

    while(scanf("%d", &num) != EOF){

        preencher(num, matriz);
    
    if(num % 2 == 0){
        par(num, matriz);
    }
    else{
        impar(num, matriz);
    }
    for(int i = 0; i < num; i ++){
        for(int j = 0; j < num; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}
    
    return 0;
}