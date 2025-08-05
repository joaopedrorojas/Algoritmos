#include "racional.h"
#include <stdlib.h>

int mdc(int a, int b){
    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;   
    }



racional simplifica(racional r){
    racional simples = r;
    int divisor = mdc(abs(simples.num), abs(simples.den));
    simples.num /= divisor;
    simples.den /= divisor;

    if(simples.den < 0) {
        simples.num = -simples.num;
        simples.den = -simples.den;
    }
    return simples;
}


racional somarac(racional r1, racional r2){
    racional soma;
    
    soma.den = r1.den* r2.den;
    soma.num = (r1.num* r2.den) + (r2.num* r1.den);
    return simplifica(soma);
}

racional subrac(racional r1, racional r2){
    racional sub;
    
    sub.den = r1.den* r2.den;
    sub.num = (r1.num* r2.den) - (r2.num* r1.den);
    return simplifica(sub);
}

racional multirac(racional r1, racional r2){
    racional m;
    
    m.num = r1.num * r2.num;
    m.den = r1.den * r2.den;
    return simplifica(m);
}


racional divrac(racional r1, racional r2){
    racional d;
    
    d.num = r1.num * r2.den;
    d.den = r1.den * r2.num;
    return simplifica(d);
}