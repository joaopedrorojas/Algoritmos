#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int **M = NULL;
    int linhas, colunas;

    printf("Quantas linhas e colunas voce deseja?\n");
    scanf("%d %d", &linhas, &colunas);

    printf("Alocando a matriz...\n");
    M = (int**)calloc(linhas, sizeof(int*));
    if(!M){
        printf("Erro 1: Nao é possivel alocar a matriz\n");
        exit(1);
    }

    for(int i = 0; i < linhas; i++){
        M[i] = (int*)calloc(colunas, sizeof(int));
        if(!M[i]){
        printf("Erro 2: Nao é possivel alocar a matriz\n");
        exit(2);
        }
    }
    printf("Preenchendo a matriz com valores aleatorios\n");
    srand(time(NULL));  //gerando semente para criacao de numeros aleatorios
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j ++){
            M[i][j] = rand() % (linhas * colunas);
            printf("M[%d][%d] = %d\n", i, j, M[i][j]);
        }
    }

    printf("Imprimindo a matriz:\n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j ++){
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }

    //realocando a matriz para dobrar o numero de linhas e colunas
    printf("Ampliando a matriz com o realloc()\n");

    //dobrando o numero de linhas
    M = (int**)realloc(M, sizeof(int*) * 2 * linhas);
    if(!M){
        printf("Erro 3: Nao é possivel realocar as linhas da matriz\n");
        exit(3);
    }

    //dobrando o numero de colunas para cada linhas recem-adicionada
    for(int i = 0; i < 2 * linhas; i++){
        M[i] = (int*)realloc(M[i], sizeof(int) * 2 * colunas);
        if(!M[i]){
        printf("Erro 4: Nao é possivel realocar as linhas da matriz\n");
        exit(4);
        }
    }
    //preencher as novas colunas das linhas pre existentes
    printf("preenchendo as novas posicoes com '1'\n");
    for(int i = 0; i < linhas; i++){
        for(int j = colunas; j < 2 * colunas; j++){
            M[i][j] = 1;
            printf("M[%d][%d] = %d\n", i, j, M[i][j]);
        }
    }

    //preenchendo as novas linhas
    printf("preenchendo as novas linhas com '1'\n");
    for(int i = linhas; i < linhas * 2; i++){
        for(int j = 0; j < 2 * colunas; j++){
            M[i][j] = 1;
            printf("M[%d][%d] = %d\n", i, j, M[i][j]);
            }
    }

    printf("Imprimindo a matriz expandida:\n");
    for(int i = 0; i < 2 * linhas; i++){
        for(int j = 0; j < 2 * colunas; j ++){
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }

    printf("Reduzindo a matriz para 2/3...\n");
    linhas *=(float)4/3;    // '4/3' por que é 2/3 * 2 que foi o tamanho dobrado anteriormente
    colunas *=(float)4/3;

    //reduzindo linhas/vetores para 2/3
    M = (int**)realloc(M, sizeof(int*) * linhas);
    if(!M){
        printf("Erro 5: Nao é possivel realocar as linhas da matriz\n");
        exit(5);
    }

    //reduzindo as colunas em 2/3
    for(int i = 0; i < linhas; i++){
        M[i] = (int*)realloc(M[i], sizeof(int) * colunas);
        if(!M[i]){
            printf("Erro 6: Nao é possivel realocar as linhas da matriz\n");
            exit(6);
        }
    }

    printf("Imprimindo a matriz reduzida:\n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j ++){
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }

    //desalocar a matriz
    for(int i = 0; i < linhas; i++){
        free(M[i]);
    }
    free(M);

    return 0;
}