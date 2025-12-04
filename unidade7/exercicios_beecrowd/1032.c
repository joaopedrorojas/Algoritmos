#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int vetorquest[31];

typedef struct TipoNode{
    int info;
    struct TipoNode *next;
}TipoNode;

typedef struct TipoList{
    TipoNode *first;
    TipoNode *last;
    int tamanho;
}TipoList;

void initList(TipoList *L){
    L->first = NULL;
    L->last = NULL;
    L->tamanho = 0;
}
int insertright(int x, TipoList *L){
    TipoNode *aux;
    aux = (TipoNode*)calloc(1, sizeof(TipoNode));
    if(aux == NULL)
        return 1;
    else{
        aux ->info = x;
        aux ->next = NULL;

        if(L->tamanho == 0){
            L->first = aux;
            L->last = aux;
            L->tamanho++;
            return 0;
        }
        else{
            L->last->next = aux;
            L->last = aux;
            L->tamanho++;
            return 0;
        }
    }
}
int juntaList(TipoList *L){
    L->last->next = L->first;

    return 0;
}

void preenchevetor(int vetor[]){

    int im = 3;
    vetor[0] = 2;

    for(int i = 1; i < 30; i++){
        vetor[i] = im;
        im +=2;
    }   
}

int ehprimo(int x, int vetor[]){

    for(int i = 0; i < 30; i ++){
        if(x == vetor[i])
            continue;

        if(x % vetor[i] == 0)
            return 0;
        }
        return 1;
}

int eliminacao(int sca, TipoList *L){
    TipoNode *aux1;
    TipoNode *eliminador;
    int n = 2;
    int final;
    final = (int)sqrt(sca);
    int ciclo;
    int contador = 0;

    eliminador = L->first;

    while(n--){
            aux1 = eliminador;
            eliminador = eliminador->next;
    }
        aux1->next = eliminador->next;
        free(eliminador);
        L->tamanho--;
        eliminador = aux1;

    while(L->tamanho > 1){

        for(int prim = 3; prim <= final; prim += 2){
            if(ehprimo(eliminador->info, vetorquest))
                ciclo = prim;
        }

        while(contador != ciclo){
            aux1 = eliminador;
            eliminador = eliminador->next;
            contador++;
        }

        aux1->next = eliminador->next;
        free(eliminador);
        L->tamanho--;
        eliminador = aux1;
    }
    return aux1->info;
}

int main() {
    
    int sca;
    

    while(scanf("%d", &sca)){
        if(sca == 0)
            return 0;
        
        preenchevetor(vetorquest);
        for(int i = 0; i < 30; i ++){
            printf("%d, ", vetorquest[i]);
        }
        printf("\n");

        TipoList L1;
            initList(&L1);

        for(int i = 1; i <= sca; i++){
            insertright(i, &L1);
        }
        juntaList(&L1);


        int resp;
        resp = eliminacao(sca, &L1);

        printf("%d\n", resp);

        free(&L1);
    }

    
    return 0;
}