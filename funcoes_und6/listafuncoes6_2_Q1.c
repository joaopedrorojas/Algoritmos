
#include <stdio.h>

unsigned soma(unsigned a, unsigned b){

    if(b==0)
        return a;

    else
        return soma(a + 1, b - 1);
}

unsigned subtracao(unsigned a, unsigned b){

    if(b == 0)
        return a;
    else
        return subtracao(a - 1, b - 1);
}

unsigned multi(unsigned a, unsigned b){

    if(b == 0)
        return 0;

    else if(b == 1)
        return a;

    else    
        return a + multi(a, b - 1);
}

unsigned div(unsigned a, unsigned b){

    
    if(b == 1)
        return a;

    else if(b > a)
        return 0;
    
    else
        return 1 + div(a - b, b);
}

unsigned resto(unsigned a, unsigned b){

    if(b == 1)
        return 0;
    
    if(b > a)
        return a;

    else
        return resto(a - b, b);
}

unsigned expo(unsigned a, unsigned b){

    if(b == 0)
        return 1;

    else if(b == 1)
        return a;

    else
        return a * expo(a, b - 1);
}


int main() {
    
    unsigned x, y;

    x = 8;
    y = 3;

    printf("A + B = %u\n", soma(x, y));
    printf("A - B = %u\n", subtracao(x, y));
    printf("A * B = %u\n", multi(x, y));
    printf("A / B = %u\n", div(x, y));
    printf("A %% B = %u\n", resto(x, y));
    printf("A ^ B = %u\n", expo(x, y));

    return 0;
}