#include <stdio.h>

int main() {
    unsigned trilhas, pontos, atual, anterior;
    unsigned sobe, desce, i, j;
    unsigned minimo = ~0, indice = 0;

    scanf("%u", &trilhas);

    for (i = 1; i <= trilhas; i++) {
        scanf("%u", &pontos);
        sobe = 0;
        desce = 0;

        scanf("%u", &anterior);
        for (j = 1; j < pontos; j++) {
            scanf("%u", &atual);
            if (anterior < atual) {
                sobe += atual - anterior;
            } else {
                desce += anterior - atual;
            }
            anterior = atual; 
        }

        if (minimo > sobe) {
            minimo = sobe;
            indice = i;
        }
        if (minimo > desce) {
            minimo = desce;
            indice = i;
        }
    }

    printf("%u\n", indice);

    return 0;
}