// Ponteiro para função 2
#include <stdio.h>

int V[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int somaV(int a, int b) {
    return a + b;
}

int SubV(int a, int b) {
    return a - b;
}

int multV(int a, int b) {
   return a * b;
}

int processa(int V[], int n, int operation()){
    int r = 0;
    
    for (int i = 0; i < n - 1; i++) {
        r += operation(V[i], V[i + 1]);
    }
    return r;
}

int main() {
    int r;
    
   // processa o vetor
   // r = processa(V, 10, somaV);
   // printf("Soma = %d\n", r);


        r = processa(V, 10, SubV);
    printf("Sub = %d\n", r);
    
   //r = processa(V, 10, multV);
   //printf("Produto = %d", r);
    
 //  processa(V, 10, somaV(V[1], V[2]));
}
