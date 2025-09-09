#include <stdio.h>
#include <stdlib.h>

int main(){
    //variaveis
    int *v;//vetor dinamico //declarando uma variavel que é inteiro para um lugar da memoria que cabe inteiros
    int n; // tamanho do vetor v

    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &n);

    // tentar alocar o vetor
    v = (int *)malloc(sizeof(int) * n); // sizeof pois é o tamanho de bytes que cabe em um inteiro
        //^ serve para transformar o malloc em int

        if(v == NULL){
            printf("Erro: memoria insuficiente\n");
            return 1;
        }
        
        
        //manipular o vetor
        for(int i = 0; i < n; i++){
            v[i] = i + 1;
        }

        //escrever o vetor
        for(int j=0; j < n; j++){
            printf("%d", v[j]);
            if(j < n- 1)
                printf(", ");
            else
            printf("\n");
        }

        //desalocar o vetor
        free(v);
        return 0;
}