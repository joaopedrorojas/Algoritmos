#include <stdio.h>
#include <string.h>
#include "complexo.h"

//definicao do tipo complexo
typedef struct{
    float real; //parte real
    float imag; // parte imaginaria
} complexo;


int scanComplexo(complexo *c){
    scanf("(%f %fi%*c)", &c->real, &c->imag);
}

void printComplexo(complexo c){
    printf("(%.0f %+.0fi)\n", c.real, c.imag);
}


//implementacao das funções do tipo complexo

//soma
complexo soma(complexo a, complexo b){
    complexo res;

    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;

    return res;
}

//subtracao
complexo sub(complexo a, complexo b){
    complexo res;

    res.real = a.real - b.real;
    res.imag = a.imag - b.imag;

    return res;
}

//multiplicacao
complexo multi(complexo a, complexo b){
    complexo res;

    res.real = (a.real * b.real) - (a.imag * b.imag);
    res.imag = (a.real * b.imag) + (a.imag * b.real);

    return res;
}

//divisão
complexo div(complexo a, complexo b){
    complexo res;

    res.real = ((a.real * b.real) + (a.imag * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
    res.imag = ((a.imag * b.real) - (a.real * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));

    return res;
}


    
