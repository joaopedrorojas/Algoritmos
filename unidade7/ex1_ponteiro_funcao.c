// Ex Ponteiros para funções
#include <stdio.h>

typedef int PF(); // declara um tipo para ponteiro para função

int f0 (int a) {
    printf("Executando f0 (%d)\n", a);
}

int f1 (int a) {
    printf("Executando f1 (%d)\n", a);
}

int f2 (int a) {
    printf("Executando f2 (%d)\n", a);
}

int main() {
   PF *funcVet[3];
    funcVet[0] = f0;
    funcVet[1] = f1;
    funcVet[2] = f2;
    int op;
    
    printf("Menu principal\n");
    printf("(0) f(0)\n");
    printf("(1) f(1)\n");
    printf("(2) f(2)\n");
    printf("\n\n");
    scanf("%d", &op);
    if (op >= 0 && op <= 2)
        funcVet[op](10);
    else
        printf("Opção inválida!\n");
    return 0;
}
