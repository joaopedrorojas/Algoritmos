#include <stdio.h>

int main() {
    
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i ++){

        if(i == 0)
            printf("Ho");
        else
            printf(" Ho");
    }printf("!\n");
    return 0;
}