#include <stdio.h>

int main() {
    
    int a, certos = 0, p;

    scanf("%d", &a);

    for(int i = 0; i < 5; i++){
        scanf("%d", &p);

        if(p == a)
            certos++;
    }

    printf("%d\n", certos);

    return 0;
}