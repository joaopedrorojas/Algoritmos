#include <stdio.h>

double fat(int n){
    double fatorial = 1;

    while(n > 1){
        fatorial *= n;
        n--;
    }
    return fatorial;
}

double conta(int x){
    double resp = x;

    for(int i = 1; i <= 20; i++){
        resp -= (double) x/fat(i);
        i++;
        if(i== 20)
            break;
        resp += (double) x/fat(i);
    }
    return resp;
}

int main() {
    
    int n;

    while(scanf("%d", &n) != EOF){
        printf("%.5lf\n", conta(n));
    }
    return 0;
}