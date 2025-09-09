#include <stdio.h>

unsigned long long fib(unsigned long long num){

    unsigned long long a = 0, b = 1, c;

    if(num == 0)
        return 0;

    if(num == 1)
        return 1;

    while(--num){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    
    int n;
    unsigned long long elem;
    

    scanf("%d", &n);

    for(int i =0; i<n; i++){

        scanf("%llu", &elem);
        printf("Fib(%llu) = %llu\n", elem, fib(elem));
    }
    return 0;
}