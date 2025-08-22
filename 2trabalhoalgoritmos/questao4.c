#include <stdio.h>
#include <string.h>

#define max 25

int matriz[max][max]; //matriz que representa as pilhas de blocos
int altura[max];      //vetor que mede a altura de cada pilha
int n;                //número de blocos

//preenche a matriz com suas respectivas pilhas
void preencher(int n){
    for (int i = 0; i < n; i++){
        matriz[i][0] = i; //cada pilha começa com seu respectivo bloco
        altura[i] = 1;    //altura inicial de cada pilha é 1
    }
}

//localiza a posição pi e pj de um bloco na matriz
//pi = a pilha em que o bloco esta
//pj = a posicao em que o bloco esta da pilha
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

//devolve todos os blocos acima do bloco pi e pj para suas posições iniciais
void devolver_acima(int pi, int pj){
    for(int k = altura[pi] - 1; k > pj; k--){
        int bloco = matriz[pi][k];
        matriz[bloco][altura[bloco]++] = bloco; //move o bloco para sua pilha original
        altura[pi]--; //reduz a altura da pilha atual
    }
}

//move um bloco individual de uma pilha para outra
void mover_blocos(int a, int pi_a, int pi_b){
    altura[pi_a]--; //remove o bloco da pilha de origem
    matriz[pi_b][altura[pi_b]++] = a; //adiciona o bloco na pilha de destino
}

//move uma pilha de blocos a partir de pj_a para outra pilha
void mover_pilha(int pi_a, int pj_a, int pi_b){
    for(int k = pj_a; k < altura[pi_a]; k++){
        int bloco = matriz[pi_a][k];
        matriz[pi_b][altura[pi_b]++] = bloco; //move cada bloco para pilha de destino
    }
    altura[pi_a] = pj_a; //atualiza altura da pilha de origem
}

int main() {
    
    scanf("%d", &n); 
    preencher(n);    

    char comando1[5], comando2[5];
    int a, b;

    //le comandos até encontrar 'quit'
    while(scanf("%s", comando1) == 1 && comando1[0] != 'q'){
        scanf("%d %s %d", &a, comando2, &b);
    
        int pi_a, pj_a, pi_b, pj_b;
        localizar(a, &pi_a, &pj_a); 
        localizar(b, &pi_b, &pj_b); 

        //ignora comandos inválidos 
        if(a == b || pi_a == pi_b) continue;

        //executa comando 'move'
        if(strcmp(comando1, "move") == 0){
            if(strcmp(comando2, "onto") == 0){
                //move bloco a sobre bloco b, devolvendo blocos acima de ambos
                devolver_acima(pi_a, pj_a);
                devolver_acima(pi_b, pj_b);
                mover_blocos(a, pi_a, pi_b);
            } else {
                //move bloco a sobre a pilha de b, devolvendo blocos acima de a
                devolver_acima(pi_a, pj_a);
                mover_blocos(a, pi_a, pi_b);
            }
        } else { //comando 'pile'
            if (strcmp(comando2, "onto") == 0) {
                //move pilha a sobre bloco b, devolvendo blocos acima de b
                devolver_acima(pi_b, pj_b);
                mover_pilha(pi_a, pj_a, pi_b);
            } else {
                //move pilha a sobre a pilha de b
                mover_pilha(pi_a, pj_a, pi_b);
            }
        }
    }

    //imprime a posição final das pilhas
    for(int i = 0; i < n; i++){
        printf("%d:", i);
        for(int j = 0; j < altura[i]; j++)
            printf(" %d", matriz[i][j]);
        printf("\n");
    }
    return 0;
}