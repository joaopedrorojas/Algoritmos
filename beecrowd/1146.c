#include <stdio.h>

int main() {
    
int n;

while(scanf("%d", &n)){

    if(n == 0)
        return 0;

    for(int i = 1; i<= n;i++){
        printf("%d", i);

        if(i != n)
            printf(" ");
    }
    printf("\n");
}

    return 0;
}