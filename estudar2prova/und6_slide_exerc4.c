#include <stdio.h>

double soma(double vetor[], int n){
double resp = 0;

for(int i = 0; i < n; i ++){
    resp += vetor[i];
}
return resp;
}

double media(double vetor[], int n){
    double resp = 0;

    for(int i = 0; i < n; i++){
        resp += vetor[i];
    }
    return resp/n;
}

int main() {
    
    double vetor[50];
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        vetor[i] = i + 1;
    }

    for(int j = 0; j < n; j++){
        if(j == 0)
        printf("%.2lf", vetor[j]);
        else
        printf(",\t%.2lf", vetor[j]);
    }
    printf("\n\nSoma: %.2lf\n", soma(vetor, n));
    printf("Media: %.2lf\n", media(vetor, n));
    
    return 0;
}