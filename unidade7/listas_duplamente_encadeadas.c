#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//tipo de dado a ser colocado na lista
typedef short TipoData;

//tipo de dado para lista encadeada
typedef struct TipoNode{
    TipoData info;          //dado armazenado
    struct TipoNode *prev; //no anterior
    struct TipoNode *next; // proximo no
    
}   TipoNode;

typedef struct TipoListDE{
    TipoNode *first;
    TipoNode *last;
    short lenght;
}  TipoListDE;

//inicializacao da lista
void initList(TipoListDE *L){
    L ->first = NULL;
    L ->last = NULL;
    L ->lenght = 0;
}

//apaga a lista
void deletList(TipoListDE *L){
    TipoNode *p = L->first;

    while(p){
        L->first = L->first->next;
        free(p);
        p = L->first;
    }
    L->last = NULL;
    L->lenght = 0;
}

//verificar se a lista esta vazia
bool listaVazia(TipoListDE L){
    return(L.lenght == 0);
}

//escrever a lista
void printList(TipoListDE *L, bool inverso){
    TipoNode *p;

    if(!inverso){
        printf("Primeiro->");
        p = L->first;
        while(p){
            printf("[%hd]->", p->info);
            p = p->next;
        }
        printf("[NULL]");
    }
    else{
        printf("Ultimo->");
        p = L->last;
        while (p){
            printf("[%hd]->", p->info);
            p = p->prev;
        }
        printf("[NULL]");
    }
    return;
}

//insercao a esquerda
short insertleft(TipoData X, TipoListDE *L){
    TipoNode *aux;
    aux = (TipoNode*)malloc(sizeof(TipoNode));

    //verifica se deu erro
    if(aux == NULL){
        return 1;
    } 
    else{
        aux->info = X; //insere x na lista
        aux->next = L->first; //insere o elemento antes do atual primeiro
        aux->prev = NULL; //nao tem anterior

        if(L->first != NULL){
            L->first->prev = aux;
        }
        L->first = aux;

        if(L->last == NULL){
            L->last = aux; // lista vazia
        }
        L->lenght++;
        return 0;
    }
}

//insercao pela direita
short insertRight(TipoData X, TipoListDE *L){
    TipoNode *aux;
    aux = (TipoNode*)malloc(sizeof(TipoNode));

    //verifica se deu erro
    if(aux == NULL){
        return 1;
    } else{
        aux->info = X; //insere x na lista
        aux->next = NULL; //insere o elemento antes do atual primeiro
        aux->prev = L->last; //nao tem anterior

        if(L->last != NULL){
            L->first = L->last = aux;
        } else {
            L->last->next = aux;
            L->last = aux;
    }

        L->lenght ++;
        return 0;
    }
}

//remocao pela esquerda
void removeLeft(TipoListDE *L){
    TipoNode *aux = L->first;
    L->first = L->first->next;
    free(aux);
    if(L->first == NULL){
        L->last == NULL;
    } else {
        L->first->prev = NULL;
    }
    L->lenght--;
}

//remocao pela direita
void removeRight(TipoListDE *L){
    TipoNode *aux = L->last;
    L->last = L->last->prev;
    free(aux);
    
    if(L->last == NULL){
        L->first == NULL;
    } else {
        L->last->next = NULL;
    }

    L->lenght--;
}

//busca elemeto da lista
TipoNode* buscaElemento(TipoData X, TipoListDE *L){
    TipoNode *aux = L->first;

    while(aux && aux->info != X)
        aux = aux->next;
    return aux;
}

int main() {
    
    return 0;
}