#include <stdio.h>


//função para contar o número de ciclos
int ciclo(int n){
    int cont = 1;

    while(n != 1){
        if(n % 2 == 1)
            n = n*3 + 1;
        else
            n = n/2;
        cont++;
    }
    return cont;
}


int main() {
    int i, j, aux, cont1, cont2, x = 0;

    //leitura das entradas
    while(scanf("%d %d", &i, &j) != EOF){

    //passar o menor numero para o i e o maior para o j, caso a entrada seja '10 1'
    if(i > j){
        aux = j;
        j = i;
        i = aux;
    }

    //laço de repetição para realizar o ciclo entre o intervalo das entradas
    //e a comparação para ver qual ciclo é maior entre o intervalo
    for(int k = i;k < j; k++){

        cont1 = ciclo(k);
        cont2 = ciclo(k + 1);

        if(x > cont1 && x > cont2)
            continue;

        if(cont1 > cont2)
            x = cont1;
        else
            x = cont2;

    }
    
    printf("%d %d %d\n", i, j, x);
    x = 0;
    }
    return 0;
}
