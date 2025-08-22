#include <stdio.h>
#include <string.h>

#define max 25

int matriz[max][max];
int altura[max];
int n;

void preencher(int n){
    for (int i = 0; i < n; i++){
        matriz[i][0] = i;
        altura[i] = 1;
    }
}

void localizar(int bloco, int *pi, int *pj){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < altura[i]; j++) {
            if(matriz[i][j] == bloco){
                *pi = i;
                *pj = j;
                return;
            }
        }
    }
}

void devolver_acima(int pi, int pj){
    for(int k = altura[pi] - 1; k > pj; k--){
        int bloco = matriz[pi][k];
        matriz[bloco][altura[bloco]++] = bloco;
        altura[pi]--;
    }
}

void mover_blocos(int a, int pi_a, int pi_b){
    altura[pi_a]--;
    matriz[pi_b][altura[pi_b]++] = a;
}

void mover_pilha(int pi_a, int pj_a, int pi_b){
    for(int k = pj_a; k < altura[pi_a]; k++){
        int bloco = matriz[pi_a][k];
        matriz[pi_b][altura[pi_b]++] = bloco;
    }
    altura[pi_a] = pj_a;
}

int main() {
    
    scanf("%d", &n);
    preencher(n);

    char comando1[5], comando2[5];
    int a, b;

    while(scanf("%s", comando1) == 1 && comando1[0] != 'q'){
        scanf("%d %s %d", &a, comando2, &b);
    

    int pi_a, pj_a, pi_b, pj_b;
    localizar(a, &pi_a, &pj_a);
    localizar(b, &pi_b, &pj_b);

    if(a == b || pi_a == pi_b) continue;

    if(strcmp(comando1, "move") == 0){
        if(strcmp(comando2, "onto") == 0){
            devolver_acima(pi_a, pj_a);
            devolver_acima(pi_b, pj_b);
            mover_blocos(a, pi_a, pi_b);
            } else {
                devolver_acima(pi_a, pj_a);
                mover_blocos(a, pi_a, pi_b);
            }
        } else {
            if (strcmp(comando2, "onto") == 0) {
                devolver_acima(pi_b, pj_b);
                mover_pilha(pi_a, pj_a, pi_b);
            } else {
                mover_pilha(pi_a, pj_a, pi_b);
            }
        }
    }
        for(int i = 0; i < n; i++){
            printf("%d:", i);
            for(int j = 0; j < altura[i]; j++)
                printf(" %d", matriz[i][j]);
            printf("\n");
        }

    return 0;
}