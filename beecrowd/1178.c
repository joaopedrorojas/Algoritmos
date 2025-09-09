#include <stdio.h>

int main() {
    
    double n[100];
    double num; 

    scanf("%lf", &num);

    for(int i=0; i<100; i++){

        n[i] = num;
        printf("N[%d] = %.4lf\n", i, n[i]);
        num = num / 2;
    }
    return 0;
}