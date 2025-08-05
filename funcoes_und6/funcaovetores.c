#include <stdio.h>

// função calcular a soma dos elemento do Vetor

double somavetor(double V[], int n){
    double soma = 0;
    
    for (int i = 0; i < n; i ++){
        soma += V[i];
    }
    return soma;
}

//função para imprimir o vetor A (procedimento)
void printfvetor(double V[], int n){
    printf("(");
    for(int j = 0; j < n; j++){
        printf("%.2lf", V[j]);
        if(j < n - 1){
            printf(", ");
        }
    }
    printf(")");
}

// arrumar double mediavetor()

int main() {
    int size = 50;
    double A[50];

    for(int i = 0; i < 50; i++){
        A[i] = i + 1;
    }
    printfvetor(A, size);
    printf("\nSoma de A = %.2lf\n\n", somavetor(A, size));
    printf("Média de A = %.2lf\n", somavetor(A, size) / size);

    return 0;
}