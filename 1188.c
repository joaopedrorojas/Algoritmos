#include <stdio.h>

int main() {
    double M[12][12];
    char letra;
    int i, j;

    scanf(" %c", &letra);

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf", &M[i][j]);
        }
    }

    double soma = 0;
    int cont = 0, x = 0, y = 11;

    for(int j = 11; j > 6; j--){
        for(int i = x + 1; i < y; i++){
            soma += M[i][j];
            cont++;
        }
        x++;
        y--;
    }
    if(letra == 'S')
        printf("%.1f\n", soma);
    else
        printf("%.1f\n", soma / cont);

    return 0;
}