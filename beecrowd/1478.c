#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n;

    while(scanf("%d", &n) && n != 0){

        int matriz[100][100];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                matriz[i][j] = abs(i - j) + 1;  
            }
        }

        for(int k = 0; k < n; k++){
            for(int l = 0; l < n; l++){
                if(l == 0)
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