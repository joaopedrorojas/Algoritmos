#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main() {
    
    int *V = NULL;
    int n;

    printf("Quantos elementos deve ter o vetor? \n");
    scanf("%d", &n);

    //aloca V com tamanho inicial
    printf("Alocando V com tamanho %d...\n", n);
    V = (int*)realloc(NULL, sizeof(int)*n);
    if(!V){
    printf("Erro: nao foi possivel alocar o vetor\n");
    exit(1);
}

//preenchendo o vetor com numeros aleatorios
printf("preenchendo o vetor com numeros aleatorios\n");
srand(time(NULL));
for(int i = 0; i < n; i++){
    V[i] = rand()%(2*n);
}
//imprimindo o vetor
printf("V = [");
for(int j = 0; j < n; j++){
    printf("%d", V[j]);
    if(1 < n - 1)
        printf(", ");
}   
printf("]\n");

//mudando o tamnho do vetor
printf("Dobrando o tamanho do vetor...\n");
n *= 2;
int *new_V = (int*)realloc(V, sizeof(int)*n);
if(!new_V){
    printf("Erro: nao foi possivel realocar o vetor\n");
    exit(2);
}

//imprimindo o vetor
printf("V = [");
for(int j = 0; j < n; j++){
    printf("%d", new_V[j]);
    if(1 < n - 1)
        printf(", ");
}   
printf("]\n");

//diminuindo o tamanho do vetor em 2/3
printf("reduzindo para 2/3 o  tamanho do vetor...\n");
n *= (float)2/3;
new_V = (int*)realloc(new_V, sizeof(int) *n);
if(!new_V){
    printf("Erro: nao foi possivel realocar o vetor\n");
    exit(3);
}
    //imprimindo o vetor
printf("V = [");
for(int j = 0; j < n; j++){
    printf("%d", new_V[j]);
    if(1 < n - 1)
        printf(", ");
}   
printf("]\n");

free(new_V);

    return 0;
}