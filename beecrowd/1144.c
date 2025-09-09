
#include <stdio.h>

int main() {
    
    int n;
    int num = 1;

    scanf("%d", &n);

    for(int i=0; i <n; i++){
        printf("%d %d %d\n", num, num*num, num*num*num);
        printf("%d %d %d\n", num, num*num + 1, num*num*num + 1);
        num++;
    }

return 0;
}