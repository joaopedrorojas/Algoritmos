//somador
#include <stdio.h>

// "int a, int b"  = parametros formais da funcao
            
int somador(int a, int b){  //
    a += b;                 // Soma por valor
    return a;               //
}

int somadorR(int *a, int *b){
    *a += *b;                   // Soma por referencia
    return *a;
}

int main(){
    int x, y, soma;
    scanf("%d %d", &x, &y);
    
    soma = somador(x, y); //x e y sao argumentos para a funcao somador
    printf("%d + %d = %d\n", x, y, soma);
    printf("x = %d, y = %d\n\n", x, y);

    soma = somadorR(&x, &y); 
    printf("%d + %d = %d\n", x, y, soma);
    printf("x = %d, y = %d\n", x, y);
    
    return 0;
}