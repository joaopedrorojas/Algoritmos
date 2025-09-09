#include <stdio.h>

int main() {
    int par = 0, impar = 0, num;
    int vetpar[5], vetimpar[5];
    

    for(int i=0; i<15; i++){
        scanf("%d", &num);

        if(num % 2 == 0){
            vetpar[par] = num;
            par++;
        }

        else{
            vetimpar[impar] = num;
            impar++;
        }

        if(par == 5){
            for(int j = 0; j<5; j++){
                printf("par[%d] = %d\n", j, vetpar[j]);
            }
            par = 0;
        }

        if(impar == 5){
            for(int j = 0; j<5; j++){
                printf("impar[%d] = %d\n", j, vetimpar[j]);
            }
            impar = 0;
        }
    }
        for(int k=0; k<impar; k++){
            printf("impar[%d] = %d\n", k, vetimpar[k]);
        }
        for(int l=0; l<par; l++){
            printf("par[%d] = %d\n", l, vetpar[l]);
        }
    return 0;
}