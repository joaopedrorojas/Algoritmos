//beecrowd1183.c

#include <stdio.h>

int main() {
    
   double M[12][12];

    char letra;

    scanf("%c", &letra);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }
        double soma = 0.0, count = 0.0;
        for (int i = 10; i > 0; i--) {
            for (int j = 0; j < i - 1; j++) {
                soma += M[i][j];
                count++;
            }
        }
        if(letra == 'S') {
            printf("%.1lf\n", soma);
        } else if (letra == 'M') {
            printf("%.1lf\n", soma / count);
        }
      
    

    return 0;
    }