
#include <stdio.h>


int somador(int n, int m, int matriz[100][100]){

    int somalinha = 0;
    int somacoluna = 0;
    int comparador = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            somalinha += matriz[i][j];
        }
        if(somalinha > comparador)
            comparador = somalinha;
        somalinha = 0;

    }    

    for(int l=0; l<m; l++){
        for(int k=0; k<n; k++){
            somacoluna += matriz[k][l];
        }
        if(somacoluna > comparador)
            comparador = somacoluna;
        somacoluna = 0;
    }

    return comparador;
}

int main() {
    
    int campo[100][100];
    int resultado;
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &campo[i][j]);
        }
    }

    resultado = somador(n, m, campo);
    printf("%d\n", resultado);

    return 0;
}