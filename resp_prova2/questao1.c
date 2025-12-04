//album de figurinhas
//questao 1
// João Pedro Rojas

#include <stdio.h>

int main()
{
    int r;
    int a, b;
    int teste = 1;
    
    while(scanf("%d", &r) && r != 0){
        
        int ca = 0, cb = 0;
        
        for(int i = 0; i < r; i++){
            
             scanf("%d %d", &a, &b);
             
             ca += a;
             cb += b;
        }
        if(ca > cb){
            printf("Teste %d\nAldo\n\n", teste);
        }
        
        else{
            printf("Teste %d\nBeto\n\n", teste);
        }
        teste++;
    }

    return 0;
}