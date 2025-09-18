#include <stdio.h>

int conta(int dia, int mes, int ano){
    int ds;
    int k, j;

    if(mes == 1){
        mes = 13;
        ano--;
    }

    else if(mes == 2){
        mes = 14;
        ano--;
    }

    k = ano % 100;
    j = ano / 100;


    ds = (dia + (int)((13 * (mes + 1))/5) + k + (int)(k/4) + (int)(j / 4) - (2*j) ) % 7;

    return ds;
}

int main() {
    
    int dia, mes, ano;
    int ds;

    while(scanf("%d/%d/%d", &dia, &mes, &ano) != EOF){

        ds = conta(dia, mes, ano);
        
        switch (ds){

            case 0:{
                printf("Sabado\n");
                break;
            }

            case 1:{
                printf("Domingo\n");
                break;
            }

            case 2:{
                printf("Segunda-feira\n");
                break;
            }

            case 3:{
                printf("Terca-feira\n");
                break;
            }

            case 4:{
                printf("Quarta-feira\n");
                break;
            }

            case 5:{
                printf("Quinta-feira\n");
                break;
            }

            case 6:{
                printf("Sexta-feira\n");
                break;
            }
        }
    }

    return 0;
}