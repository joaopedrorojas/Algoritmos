#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int **M; //dois asteriscos p/ ponteiro em matriz
    int n; // escala da matriz quadrada

    while(scanf("%d", &n) && n != 0){ // while != de 0

    //como é uma matriz quadrada i = j

    M = (int**)malloc(sizeof(int*) * n); // esse malloc, esta apenas indicando o inicio das linhas, pensa num vetor

    if(M == NULL){                                  //
        printf("Erro 1: Memoria insuficiente\n");   // caso falte memoria na hora de procurar espaço
        return 1;                                   //
    }

    for(int j= 0; j< n; j++){

        M[j] = (int*)malloc(sizeof(int) * n); // ja esse malloc, faz parte de um vetor dentro de um vetor e esta procurando espaco
        //pense num cinema e vc esta procurando 4 fileiras com 3 espacos vazios grudados.
        //no caso esse malloc esta dentro do outro malloc anterior
        
        if(M[j] == NULL){                               //
            printf("Erro 2: Memoria insuficiente\n");   // caso nao exista memória suficiente nesse novo malloc
            return 2;                                   //
        }
    }

    // a partir daqui é o preenchimento da matriz, como no exer. 1435 do beecrowd
    int inicio = 0, fim = n -1;
        int matriz[100][100];
        int valor = 1;
        int camadas = (n + 1) / 2;

    for(int j = 0; j < camadas; j++){
        for(int i = inicio; i <= fim; i++){
            matriz[inicio][i] = valor;
            matriz[i][inicio] = valor;
            matriz[fim][i] = valor;
            matriz[i][fim] = valor;
        }
        inicio++;
        fim--;
        valor++;

        }
        
        for(int k = 0; k < n; k++){
            for(int l = 0; l < n; l++){

                if(l ==0)
                    printf("%3d", matriz[k][l]);
                else
                    printf(" %3d", matriz[k][l]);
            }
            printf("\n");
        }
        printf("\n");

}

    // parte para limpar a area da memoria ocupada pela matriz
    // nota-se que tem q fazer o trabalho contrario ao de criar regiao com o malloc,
    // primeiro limpa os vetores dentro do vetor principal.
    for(int k = 0; k < n; k++){
        free(M[k]);
    }
    // e aquui limpa o vetor principal
    free(M);

    return 0;
}