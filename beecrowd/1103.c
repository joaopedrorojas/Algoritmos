#include <stdio.h>


int main() {

    int x, y, g;
    scanf("%d %d", &x, &y);

    if(x > y){
        g = x;
        x = y;
        y = g;
    }
    for(x; x < y; x++){
        if(x % 5 == 2 || x % 5 == 3)
            printf("%d\n", x);
    }

    return 0;
}