
//header file para arvore binaria de busca simples

#include <stdlib.h>
#include <stdbool.h>

//codigo para limpar a tela
#define CLEAR "\033[0;0;0m"
#define RESET "\033[0m"
#define WHITE_RED "\033[97;101m"


//DEFINICAO do TIPO de dado armazenado na arvore
typedef unsigned Tdado;

//DEFINICAO da ESTRUTURA nó de arvore
typedef struct TreeNode
{
    Tdado info;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct TNode{
    TreeNode* info;
    struct TNode *next;
} TNode;

//LISTA SIMPLESMENTE ENCADEADA
typedef struct{
    TNode *first;
    TNode *last;
    int length;
}TListSE;

//insercao pela direita
int InsertRight(TreeNode *x, TListSE *L);

//inicializa a lista
void InitList(TListSE *L);

//verifica se a fila esta vazia
bool isEmpty(TListSE L);

//apaga a lista
void DeleteList(TListSE *L);

//imprime a lista
void PrintList(TListSE L);

//remocao pela esquerda
TreeNode *RemoveLeft(TListSE *L);


//ARVORE

//funcao de inserção
TreeNode* insertBinTree(Tdado x, TreeNode *bt);

//funcao de remocao por merge(promocao de um dos filhos)
TreeNode *deleteByMerge(TreeNode *bt, Tdado x);

//valor minimo de uma arvore
Tdado minTree(TreeNode *bt);

//remocao por copia
TreeNode* deleteByCopy(TreeNode *bt, Tdado x);

//Funcao de impressao
void printBinTree(const TreeNode *bt, int level);

//apaga a arvore inteira
void freeBinTree(TreeNode *bt);

//preOrdem
void preOrdem(TreeNode* bt);

//emOrdem
void emOrdem(TreeNode* bt);

//posOrdem
void posOrdem(TreeNode* bt);

//altura
int altura(TreeNode* bt);

//largura
int largura(TreeNode* bt);

//numero de nós
int numNodes(TreeNode* bt);

//metodo de ordenacao
void percorreLargura(TreeNode *bt);

//busca na arvore
int buscaTree(TreeNode *bt, int x);

//DISTANCIA DA RAIZ ATE O NUMERO
int dist(TreeNode *bt, int x);