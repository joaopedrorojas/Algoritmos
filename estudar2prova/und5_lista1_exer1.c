#include <stdio.h>

double conta(int n){
    double h = 0;

    for(int i = 1; i <= n; i++){

        h += (double) 1/i;
    }
    return h;
}

int main() {
    
    int n;

    while(scanf("%d", &n) && n != 0){

        printf("%.5lf\n", conta(n));
    }
    return 0;
}