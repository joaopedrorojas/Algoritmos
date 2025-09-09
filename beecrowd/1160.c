#include <stdio.h>

int main() {
    
    int t;
    int pa, pb;
    double g1, g2;
    
    scanf("%d", &t);

    for(int i = 0; i < t; i++){

        scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);

        for(int j = 1; j <=101; j++){

            pa += pa * (g1/100);
            pb += pb * (g2/100);

            if(j == 101){
                printf("Mais de 1 seculo.\n");
                break;
            }

            if(pa > pb){
                printf("%d anos.\n", j);
                break;
            }

        }

    }
    return 0;
}