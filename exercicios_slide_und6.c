#include <stdio.h>

int soma(int a, int b){     //'a' e 'b' são os parametros, soma é o nome da funcao
int s;
s = a + b;

return s;
}

int fatorial(int n){
    long long res = 1;

    for(int i = 1; i <= n; i++){
        res *= i;
    }

    return res;
}

int fibonacci(int n){
    int f0, f1, f2;

    f0 = f1 = f2 = 1;

    if(n == 0 || n == 1)
        return 1;
    else{

    for(int i = 2; i < n; i++){

        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
return f1;
    }
}

int somavetor(int vet[50], int n){
    int soma=0;
    for(int i = 0; i < n;i++){
        soma += vet[i];
    }

    return soma;
}

int main(){
    int x, y;
    int vet[50];

    printf("Insira dois numeros para serem somados: ");
    scanf("%d %d", &x, &y);
    printf("\nSoma = %d\n", soma(x, y));
    printf("\nInsira um numero para ser calculado o fatorial: ");
    scanf("%d", &x);
    printf("\n%d! = %d\n", x, fatorial(x));
    printf("Insira o numero para ver o N-ésimo elemento em fibonacci: ");
    scanf("%d", &x);
    printf("\nelemento %d de fibonacci = %d\n", x, fibonacci(x));
    printf("Insira o nomero de alocações que voce quer no seu vetor: ");
    scanf("%d", &x);
    printf("\nAgora preencha o seu vetor, para no final ver a soma de todos: ");
    for(int i = 0; i < x; i++){
        scanf("%d", &vet[i]);
    }
    printf("\nSoma = %d\n", somavetor(vet, x));
    
    return 0;
}