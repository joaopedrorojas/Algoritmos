#include <stdio.h>
#include "complexo.h"
 
 
int main() {
    COMPLEXO A, B;
 
    scanComplexo(&A);
    scanComplexo(&B);
    
    printComplexo(A);
    printComplexo(B);
    return 0;
}