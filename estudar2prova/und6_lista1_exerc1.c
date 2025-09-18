#include <stdio.h>

int conta(int x, int y){

    return (x + y) * (x + y);
}

int main() {
    
    int x;
    while(scanf("%d", &x) != EOF){
        int y;
        scanf("%d", &y);

        printf("f1(%d, %d) = %d\n", x, y, conta(x, y));
    }
    return 0;
}