#include <stdio.h>
 
int main() {
    int pessoas;
    int rodadas;
    int teste = 1;
    int fila[100];
    int num_por_rodadas;
    int acao_indv;
    
    while(scanf("%d %d", &pessoas, &rodadas)){
        if(pessoas == 0 && rodadas == 0)
            return 0;
        
        for(int i = 0; i < pessoas; i++){
            scanf("%d", &fila[i]);
        }
        
        int participantes, ordem;
        
        for (int j = 0; j < rodadas; j++){
            
            scanf("%d %d", &participantes, &ordem);
            
            int nova_fileira[100], contador = 0;
            
            for (int k = 0; k < participantes; k++){
                
                scanf("%d", &acao_indv);
                if (ordem == acao_indv) {
                    nova_fileira[contador++] = fila[k];
                }
            }
            for (int p = 0; p < contador; p++){
                fila[p] = nova_fileira[p];
            }
            participantes = contador;
        }
        
        printf("Teste %d\n%d\n\n", teste++, fila[0]);
    }
    return 0;
}