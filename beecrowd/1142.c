
#include <stdio.h>

int main() {
    
    int n;
    int num = -1;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        num += 2;
        printf("%d ", num);
        num++;
        printf("%d ", num);
        num++;
        printf("%d ", num);
        printf("PUM\n");
    }

    return 0;
}