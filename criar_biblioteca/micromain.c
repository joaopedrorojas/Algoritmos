#include <stdio.h>
#include "complexo.h"
 
 
int main() {
    COMPLEXO A, B;
 
    leComplexo(&A);
    leComplexo(&B);
    
    escreveComplexo(A);
    escreveComplexo(B);
    return 0;
}