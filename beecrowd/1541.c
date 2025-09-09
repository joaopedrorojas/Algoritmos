#include <math.h>
#include <stdio.h>

double conta(double a, double b, double c){

    double area;

    area = (a * b * 100) / c;

    return sqrt(area);
}


int main() {
    
    double a, b, c;

    while(scanf("%lf", &a)){
        if(a == 0)
            return 0;

        scanf("%lf %lf", &b, &c);  

        printf("%d\n", (int)conta(a, b, c));

    }
    return 0;
}