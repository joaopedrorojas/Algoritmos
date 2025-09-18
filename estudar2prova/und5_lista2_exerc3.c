#include <stdio.h>

int main() {
    double num = 0;
    double vet[100];
    int i = 0;
    double media;

    while(scanf("%lf", &vet[i]) != -1){
        
        num += vet[i];

        i++;
    }

    media = num / i;

    for(int j = 0; j < i; j++){
        if(vet[j] > media)
            printf("%.2lf maior que a media\n", vet[j]);

            else if(vet[j] < media)
                printf("%.2lf menor que a media\n", vet[j]);

            else
                printf("%.2lf igual a media\n", vet[j]);
    }
    return 0;
}