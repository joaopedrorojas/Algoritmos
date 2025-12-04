#include <stdio.h>
#include "BinTree.h"

void clear(){
    printf(CLEAR);
}

int main (){
    TreeNode *bt = NULL;
    int op = 0, v = 0;

    do{
        clear();
        printf("Arvore Atual:\n\n");
        printBinTree(bt, 0);
        printf("\nPercurso em pré ordem: ");
        preOrdem(bt);
        printf("\n\n");
        printf("\nPercurso em ordem: ");
        emOrdem(bt);
        printf("\n\n");
        printf("\nPercurso em pós-ordem: ");
        posOrdem(bt);
        printf("\n\n");
        printf("\nPercurso em Largura: ");
        percorreLargura(bt);
        printf("\n\n\n");
        printf("Altura da árvore: %d\n\n", altura(bt));
        printf("Largura da árvore = %d\n\n", largura(bt));
        printf("Número de nós: %d\n\n", numNodes(bt));
        printf("Selecione a opção desejada:\n");
        printf("(0) sair\n");
        printf("(1) inserir\n");
        printf("(2) remocao por merge\n");
        printf("(3) remocao por cópia\n");
        printf("(4) distância de um número 'X' até a raiz\n");
        printf("(5) busca de algum elemento na árvore\n");
        printf("Opção >> ");
        scanf("%d", &op);
        switch(op){
            case 0:
                printf("Programa Encerrado!\n");
                break;

            case 1:
                printf("Qual valor? >> ");
                scanf("%d", &v);
                bt = insertBinTree(v, bt);
                break;

            case 2:
                printf("Qual valor? >> ");
                scanf("%d", &v);
                bt = deleteByMerge(bt, v);
                break;

            case 3:
                printf("Qual valor? >> ");
                scanf("%d", &v);
                bt = deleteByCopy(bt, v);
                break;

            case 4:
                printf("Qual valor? >> ");
                scanf("%d", &v);
                printf("Distância : %d\n\n", dist(bt, v));
                break;

            case 5:
                printf("Qual elemento? >> ");
                scanf("%d", &v);
                printf("\n\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    }while (op != 0);
    freeBinTree(bt);
    return 0;
}
