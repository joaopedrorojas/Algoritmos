#include <stdio.h>

int linha;

double soma(double matriz[12][12]){

    double resul = 0;

    for(int i=0; i < 12; i++){
        resul += matriz[linha][i];
    }
    return resul;
}

double media(double matriz[12][12]){

    double resul = 0;

    for(int i=0; i < 12; i++){
        resul += matriz[linha][i];
    }
    return resul/12;
}

int main() {
    
    double matriz[12][12];
    char op;

    scanf("%d %c", &linha, &op);

    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
        switch (op){

        case 'S':
            printf("%.1lf\n", soma(matriz));
            break;

        case 'M':
            printf("%.1lf\n", media(matriz));
            break;


        }
    return 0;
}