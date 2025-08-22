#include <stdio.h>
#include <string.h>
#include "complexo.h"

int main() {
    
    complexo n1, n2, c;
    char op;

    while(scanComplexo(&n1) != EOF){

    scanf(" %c ", &op);

    scanComplexo(&n2);

    switch (op){

        case'+':
            c = soma(n1, n2);
        break;

        case'-':
            c = sub(n1, n2);
        break;

        case'*':
            c = multi(n1, n2);
        break;

        case'/':
            c = div(n1, n2);
        break;

        default:

    }

     printComplexo(c);

}
    return 0;
}