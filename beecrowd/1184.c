#include <stdio.h>

int main() {
   
    double M[12][12];
    char letra;
    int i, j;

    scanf("%c", &letra);
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%lf", &M[i][j]);
        }
    }
    
    double soma = 0, count = 0;
    for(i = 0; i < 12; i++){
        for(j = 0 + 1; j < i - 1; j++){
            soma += M[i][j];
            count++;
        }
    }
    if(letra == 'S'){
        printf("%.1lf\n", soma);
    }   else if(letra == 'M'){
        printf("%.1lf\n", soma/count);
    }


    return 0;
}