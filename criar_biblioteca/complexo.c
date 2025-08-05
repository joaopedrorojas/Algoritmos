#include "complexo.h"
#include <stdio.h>
 
void leComplexo(COMPLEXO *C){
    scanf("(%lf %lf'i')", &C->real, &C->imag);
}
 
void escreveComplexo(COMPLEXO C){
    printf("(%lf %+lfi)", C.real, C.imag);
 
}