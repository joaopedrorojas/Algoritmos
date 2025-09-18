#include <stdio.h>
#include <string.h>

int mdc(int a, int b){

    if(b == 0)
        return a;

    return mdc(b, a%b);

}

int contador (int a, int b){

        if(b == 0 && a == 0)
            return 1;

        else if(b == 0)
            return 0;

        else if(b % 10 == a)
            return 1 + contador(a, b / 10);

        else
            return contador(a, b/10);
}

double somavet (double vet[], int n){

    if(n == -1)
        return 0;

    return vet[n] + somavet(vet, n - 1);
}

void inverte (double vet[], int inic, int fim){

    if(inic >= fim)
        return;

    double guia;

    guia = vet[inic];
    vet[inic] = vet[fim];
    vet[fim] = guia;

    inverte(vet, inic + 1, fim - 1);
}

double menor_valor(double vet[], int n){

    
    
}
int main() {
    
    //int a, b;
    double vet[50];
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &vet[i]);
    }

    //scanf("%d %d", &a, &b);

    //printf("MDC: %d\n", mdc(a, b));
    //printf("O numero %d aparece %dx em %d\n", a, contador(a, b), b);

   // printf("Soma do Vetor: %.2lf\n", somavet(vet, n));

    /*inverte(vet, 0, n - 1);

    printf("Vetor inverso: \n");
    for(int j = 0; j < n; j++){
        if(j == 0)
            printf("%.2lf", vet[j]);
        else
            printf(", %.2lf", vet[j]);
    }
    printf("\n");
    */

    return 0;
}