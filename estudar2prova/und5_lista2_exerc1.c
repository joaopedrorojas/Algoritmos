#include <stdio.h>

double conta( int n){
    double resul = 0;
    int g = n;

    for(int i = 1; i <= n; i++){

        resul += (double) i/g;
        g--;

    }
    return resul;
}

int main() {
    
    int n;

    while(scanf("%d", &n) != EOF){

        printf("%.1lf\n", conta(n));
    }

    return 0;
}