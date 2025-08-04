#include <stdio.h>

typedef struct {

    int num;
    int den;
}fracao;


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

fracao somaf(fracao a, fracao b){
    fracao k;

    k.num = (a.num * b.den) + (a.den * b.num);
    k.den = a.den * b.den;

    return k;
}

fracao multif(fracao a, fracao b){
    fracao r;

   r.num = a.num * b.num;
   r.den = a.den * b.den;

   return r;
}

fracao divf(fracao a, fracao b){
    fracao s;

    s.num = a.num * b.den;
    s.den = a.den * b.num;

    return s;
}

fracao subf(fracao a, fracao b){
    fracao g;

    g.num = (a.num * b.den) - (a.den * b.num);
    g.den = a.den * b.den;

    return g;
}

int main(){
    int x, y;
    fracao a, b, c;
    int vet[50];

    for(int i = 0; i< 50; i++){
        vet[i] = i + 1;
    }


    printf("Insira dois numeros para serem somados: ");
    scanf("%d %d", &x, &y);
    printf("\nSoma = %d\n", soma(x, y));
    printf("\nInsira um numero para ser calculado o fatorial: ");
    scanf("%d", &x);
    printf("\n%d! = %d\n", x, fatorial(x));
    printf("Insira o numero para ver o N-ésimo elemento em fibonacci: ");
    scanf("%d", &x);
    printf("\nelemento %d de fibonacci = %d\n", x, fibonacci(x));
    printf("\nSoma de todos os espaços do vetor = %d\n", somavetor(vet, 50));
    printf("Média da soma anterior= %d\n", somavetor(vet, 50) / 50);
    printf("\nInsira duas frações para efetuar os calculos: (nesse formato: x/y w/z)\n");
    scanf("%d/%d %d/%d", &a.num,  &a.den, &b.num, &b.den);
    c = somaf(a, b);
    printf("\nSoma de %d/%d + %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num, c.den);
    c = subf(a, b);
    printf("\nSubtração de %d/%d - %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num, c.den);
    c = multif(a, b);
    printf("\nMultiplicação de %d/%d * %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num, c.den);
    c = divf(a, b);
    printf("\nDivisão de %d/%d / %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num, c.den);
    
    return 0;
}