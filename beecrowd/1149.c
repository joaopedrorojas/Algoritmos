#include <stdio.h>

int main() {
    
    int x, y, soma = 0;

    scanf("%d", &x);
        while(scanf("%d", &y)){
            if(y <= 0)
                continue;
            for(int i=0; i<y; i++){
                soma += x;
                x++;
            }
            printf("%d\n", soma);
            return 0;
        }
    

    return 0;
}