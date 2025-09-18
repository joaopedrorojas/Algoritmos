#include <stdio.h>

int main() {
    
    int l, g;

    while(scanf("%d", &l) != EOF){

    int n1 = 0, n2 = 0, n3 = 0;
    
        for(int i = 0; i < l; i++){
            
            scanf("%d", &g);
            if(g < 10)
                n1++;
                else if(g >= 20)
                    n3++;
                    else
                        n2++;
        }
        if(n3 > 0)
            printf("3\n");
        else if(n2 > 0)
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}