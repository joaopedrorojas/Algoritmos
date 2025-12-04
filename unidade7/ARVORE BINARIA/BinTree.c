#include <stdlib.h>
#include <stdio.h>
#include "BinTree.h"
#include <stdbool.h>

//inicializacao da lista
void InitList(TListSE *L){
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

//destruicao da lista = apagar lista
void DeleteList(TListSE *L){
    TNode *p = L->first;     //p = guia auxiliar
    while(p){   //quando p for nulo vai encerrar o laço
        L->first = L->first->next;  //aponta pra next casa
        free(p);    // limpa a casa de p
        L->length--;    //diminui o tamanho do comprimento pq uma casa ja foi limpada
        p = L->first;   // e p = o primeiro que no caso é = ao next que foi apontado para o proximo anteriormente
    }
    L->last = NULL;     // last tem q receber nulo pq ele ainda continua apontando para a ultima casa da lista
}

//verificacao se a lista esta vazia
bool isEmpty(TListSE L){       //bool = funcao booleana

    return (L.length == 0);     // aqui pode conferir tanto o first, o last e o length, se a lista realmente for vazia,
                                //todos elementos serao nulos, opcao usada: length
}

//escrever a lista

void PrintList(TListSE L){
    TNode *p = L.first;  //inicializa p

    printf("[");
    while(p)
    {
        printf("%d", p->info->info);
        if(p-> next)
            printf(", ");
        p = p->next;
    }
    printf("]");
    printf("\n");
    printf("\n");
}

int InsertRight(TreeNode *x, TListSE *L){
    TNode *aux;
    aux = (TNode*)malloc(sizeof(TNode));
    if(aux == NULL)
        return 1;
    else{
        aux ->info = x;
        aux ->next = NULL;

        if(L->length == 0){
            L->first = aux;
            L->last = aux;
            L->length++;
            return 0;
        }
        else{
            L->last->next = aux;
            L->last = aux;
            L->length++;
            return 0;
        }
        
    }
}

TreeNode *RemoveLeft(TListSE *L)
{
    if (L->first == NULL)
        return NULL;
    TNode *aux = L->first;
    TreeNode *ret = aux->info;
    L->first = aux->next;
    if (L->first == NULL)
        L->last = NULL;
    free(aux);
    L->length--;
    return ret;
}

//funcao de insercao
TreeNode* insertBinTree(Tdado x, TreeNode *bt){
    TreeNode *aux;

    //verificar se o ponteiro é nulo
    if(!bt){
        //insere o novo nó
        aux = (TreeNode*)malloc(sizeof(TreeNode));
        if(!aux){
            printf("Erro: Memória insuficiente!\n");
            return bt;
        }
        else{
            aux -> info = x;
            aux -> left = NULL;
            aux -> right = NULL;
            return aux;
        }
    }
    else if(x < bt->info){
        //x é menor que o valor do nó atual, desce pelo ramo esquerdo
        bt->left = insertBinTree(x, bt->left); //insere no ramo esquerdo
        return bt;
    }
    else{
        //x é maior que o valor do nó atual, desce pelo ramo esquerdo
        bt->right = insertBinTree(x, bt->right); //inseree no ramo direito
        return bt;
    }
}

//FUNCAO REMOCAO POR MERGE OU (PROMOCAO DE UM DOS FILHOS)
TreeNode *deleteByMerge(TreeNode *bt, Tdado x){
    TreeNode *p, *p2;

    if(bt == NULL)      //arvore vazia ou chegou no fim da arevore
        return NULL;


    else if(bt->info == x){


        if(bt->left == bt->right){  //é um folha, sem filhos(left == right apenas quando os 2 forem nulos)
            free(bt);               
            return NULL;
        }


    else if(bt->left == NULL){
        p = bt->right;          //caso o 'avo'tem apenas 1 filho e 1 neto, ao apagar o pai vai ser ligado ao filho da direita
        free(bt);               //filho da esquerda nao existe
        return p;
    }
    else if(bt->right == NULL){
        p = bt->left;           //caso o 'avo'tem apenas 1 filho e 1 neto, ao apagar o pai vai ser ligado ao filho da esquerda
        free(bt);               //filho da direita nao existe
        return p;
    }


    else{
        p2 = bt ->left;
        p = p2;
        while(p->right != NULL){    //dois filhos, faz o esquema de promocao como visto na aula
            p = p->right;
        }
        p->right = bt->right;
        free(bt);
        return p2;
    }
    }
    else if(bt->info > x){
        bt->left = deleteByMerge(bt->left, x);      //
    }                                               //Caso o valor do nó nao seja igual ao que foi desejado remover, desce
    else{                                           //de acordo com a ocasiao para algum lado para ver se o proximo nó é o 
        bt->right = deleteByMerge(bt->right, x);    //desejado a remocao
    }
    return bt;
}



//REMOCAO POR COPIA
TreeNode* deleteByCopy(TreeNode *bt, Tdado x){
    TreeNode *t1, *temp;

    if(bt == NULL){ // chegou num nó nulo retorna nulo
        return NULL;
    }

    if(bt->info == x){

        if(bt->right == NULL){
            t1 = bt->left;
            free(bt);
            return t1;
        }

        else if(bt->left == NULL){
            t1 = bt->right;
            free(bt);
            return t1;
        }

        else{
            temp = bt->right;
            while(temp->left !=NULL){
                temp = temp->left;
            }
            bt->info = temp->info;
            bt->right = deleteByCopy(bt->right, temp->info);
        }
    } 

    else if(bt->info > x){
        bt->left = deleteByCopy(bt->left, x);
    }
    else{
        bt->right = deleteByCopy(bt->right, x);
    }
    return bt;
}


//funcao impressao
void printBinTree(const TreeNode *bt, int level){
    int i;

    if(!bt){
        return;
    }
    else{
        printBinTree(bt->right, level + 1);
        for(i = 0; i<level;i++){
            printf("----|");
        }
        printf(WHITE_RED "%u" RESET "\n", bt->info);
        printBinTree(bt->left, level + 1);
    }
}
/*exemplo de impressao
----|8
----|----|6
5
----|3
*/

//FUNCAO APAGAR TODA A ARVORE COM RAIZ EM BT
void freeBinTree(TreeNode* bt){
    if(!bt)
        return;
    freeBinTree(bt->left);
    freeBinTree(bt->right);
    free(bt);
    bt = NULL;
}

//FUNCAO PARA REALIZAR A PRE-ORDEM
void preOrdem(TreeNode* bt){
    if(!bt)
        return;
    
    printf("%u ", bt->info); //equivale a visitar o nó
    preOrdem(bt->left);
    preOrdem(bt->right);
}

//FUNCAO PARA REALIZAR A EM-ORDEM
void emOrdem(TreeNode* bt){
    if(!bt)
        return;
    
    emOrdem(bt->left);
    printf("%u ", bt->info); //equivale a visitar o nó
    emOrdem(bt->right);
}

//FUNCAO PARA REALIZAR A POS-ORDEM
void posOrdem(TreeNode* bt){
    if(!bt)
        return;
    
    posOrdem(bt->left);
    posOrdem(bt->right);
    printf("%u ", bt->info); //equivale a visitar o nó
}

unsigned maior(int x, int y){
    if(x > y)
        return x;
    return y;
}

//FUNCAO PARA DESCOBRIR A ALTURA DA ARVORE
int altura(TreeNode* bt){
    if(!bt)
        return 0;
    return 1 + maior(altura(bt->left), altura(bt -> right));
}

//FUNCAO PARA DESCOBRIR A LARGURA DA ARVORE
int largura(TreeNode* bt){
    
    if(!bt)
        return 0;

    if(bt->left == NULL && bt->right == NULL)
        return 1;
    else
        return largura(bt->left) + largura(bt->right);
}

//NUMERO DE NÓS DA ARVORE
int numNodes(TreeNode* bt){
    if(!bt)
        return 0;

    int soma = 0;
    soma += numNodes(bt->left);
    soma += numNodes(bt->right);
    return soma + 1;
}

//DISTANCIA DA RAIZ ATE O NUMERO
int dist(TreeNode *bt, int x){
    if(!bt)
        return 0;
    if(bt->info == x)
        return 0;
    else if (bt -> info > x)
        return 1 + dist(bt->left, x);
    else
        return 1 + dist(bt->right, x);
}

//PERCURSO EM LARGURA
void percorreLargura(TreeNode *bt)
{
    if (!bt)
    {
        return;
    }
    TListSE fila;
    InitList(&fila);
    InsertRight(bt, &fila);
    while (!isEmpty(fila))
    {
        TreeNode *atual = RemoveLeft(&fila);
        printf("%u ", atual->info);
        if (atual->left)
        {
            InsertRight(atual->left, &fila);
        }
        if (atual->right)
        {
            InsertRight(atual->right, &fila);
        }
    }
    DeleteList(&fila);
}


//BUSCA NA ARVORE
int buscaTree(TreeNode *bt, int x){
    if(!bt)
        return 0;
    if(bt->info == x)
        return bt->info;
    buscaTree(bt->left, x);
    buscaTree(bt->right, x);
}