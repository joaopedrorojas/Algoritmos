#include <stdio.h>
#include <math.h>

long int cubo (int x){

    return (long int) x * x * x;
}

double raiz3(double x){

    return pow(x, 1.0/3.0);
}

double valorS(int n){
    double S = 1;
    int div = 3;

    for(int i = 1; i < n; i++){
        
        if(i % 2 != 0)
            S -= (double) 1/cubo(div);
        else
            S += (double) 1/cubo(div);
        
        div += 2;
    }

    S *= 32;
    S = raiz3(S);

    return S;
}

int main() {
    
    int n;

    while(scanf("%d", &n) && n != 0){
        printf("%.5lf\n", valorS(n));
    }
    return 0;
}