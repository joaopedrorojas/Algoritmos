#include <stdio.h>
#include "racional.h"


int main() {
    
    racional a, b, c;

    scanf("%d/%d %d/%d", &a.num, &a.den, &b.num, &b.den);
    c = somarac(a, b);
    printf("A + B = %d/%d\n", c.num, c.den);
    c = subrac(a, b);
    printf("A - B = %d/%d\n", c.num, c.den);
    c = multirac(a, b);
    printf("A * B = %d/%d\n", c.num, c.den);
    c = divrac(a, b);
    printf("A / B = %d/%d\n", c.num, c.den);


    return 0;
}