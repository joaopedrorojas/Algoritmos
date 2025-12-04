#include <stdio.h>

int main() {

    char entrada[15];
    int arabicos[] = {1000, 500, 100, 50, 10, 5, 1};
    int resul = 0;
    int cont = 0;

        scanf("%s", entrada);

        for(int i = 0; i < 13; i ++){
            
            switch(entrada[0]){

                case 'M':
                    entrada[i] = 1000;
                    break;

                case 'D':
                    entrada[i] = 500;
                    break;

                case 'C':
                    entrada[i] = 100;
                    break;
                    
                case 'L':
                    entrada[i] = 50;
                    break;

                case 'X':
                    entrada[i] = 10;
                    break;

                case 'V':
                    entrada[i] = 5;
                    break;

                case 'I':
                    entrada[i] = 1;
                    break;
            }   
        }

        for(int i = 0; i < 13; i++){

                if(&entrada[i] > &entrada[i + 1]){
                resul+= arabicos[i];
                cont++;
                }

                else{
                    resul += arabicos[i + 1] - arabicos[i];
                    cont++;
                    cont++;
                }
            }
        
        printf("%d\n", resul);

    return 0;
}
    