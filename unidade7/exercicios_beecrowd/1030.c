#include <stdio.h>
#include <stdlib.h>

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

void deleteList(TipoList *L){
    TipoNode *p = L->first;     
    while(p){   
        L->first = L->first->next;  
        free(p);    
        L->tamanho--;    
        p = L->first;   
    }
    L->last = NULL;     
}

int insertright(int x, TipoList *L){
    TipoNode *aux;
    aux = (TipoNode*)malloc(sizeof(TipoNode));
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

int eliminacao(int ciclo, TipoList *L){
    TipoNode *aux1;
    TipoNode *eliminador;

    eliminador = L->first;
    int contador = 1;

    while(L->tamanho > 1){

        while(contador != ciclo){
            aux1 = eliminador;
            eliminador = eliminador->next;
            contador++;
        }
        aux1->next = eliminador->next;
        free(eliminador);
        L->tamanho--;
        eliminador = aux1;
        contador = 0;
    }
    return aux1->info;
}

int main() {
    
    int NC;

    scanf("%d", &NC);
    for(int i = 1; i <= NC; i++){

        int n, k;
        TipoList L1;

        initList(&L1);

        scanf("%d %d", &n, &k);

        for(int i = 1; i <= n; i++){
            insertright(i, &L1);
        }
        juntaList(&L1);

        int resp;
        resp = eliminacao(k, &L1);

        printf("Case %d: %d\n", i, resp);

        free(&L1);
    }
    
    return 0;
}