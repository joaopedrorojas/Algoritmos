#include <stdio.h>

int soma(int x, int y){
     int res;
    res = (x + y) * (x + y);

    return res;
}



int main() {
    
    int a, b, z;

    while(scanf("%d %d", &a, &b) != EOF){
        z = soma(a, b);

        printf("f1(%d, %d) = %d\n", a, b, z);
    }
    
return 0; 
}