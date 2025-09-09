#include <stdio.h>

int main() {
    
    int x, y, i, soma=0;

    scanf("%d", &x);
        while(scanf("%d", &y)){
            if(y <= x)
                continue;
            for(i=0; soma<y; i++){
                soma += x+i;
            }
            printf("%d\n", i);
            return 0;
        }
    

    return 0;
}