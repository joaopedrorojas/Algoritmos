#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nome[200];
    int tamanho_do_nome, ultimo_nome, fim_do_primeiro_nome;

    fgets(nome, 200, stdin);

        tamanho_do_nome = strlen(nome);
        nome[tamanho_do_nome - 1] = '\0';

        //printar o ultimo sobrenome
        for(int i = tamanho_do_nome - 1; i >= 0; i--){

            if(nome[i] == ' '){  //descobrir a posicao do ultimo nome
                ultimo_nome = i + 1;

                //printar o ultimo nome e a ','
                while(ultimo_nome < tamanho_do_nome){
                    printf("%c", nome[ultimo_nome]);
                    ultimo_nome++;
                    if(ultimo_nome == tamanho_do_nome)
                        printf(",");
                }
                ultimo_nome = i;
                break;
            }
        }

        //printar o primeiro nome
        for(int j = 0; j < tamanho_do_nome; j++){

            if(nome[j] == ' '){
                fim_do_primeiro_nome = j;

                for(int k = 0; k < fim_do_primeiro_nome; k++){
                    printf("%c", nome[k]);
                }
                break;
            }
        }
        
        for(int l = fim_do_primeiro_nome; l < ultimo_nome - 1; l++){

            if(isupper(nome[l])){
                printf(" %c.", nome[l]);
            }
        }

        printf("\n");
    return 0;
}