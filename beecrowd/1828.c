#include <stdio.h>
#include <string.h>

int main() {
    
    char sheldon[8], raj[8];
    int n, caso;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){

        scanf("%s %s", sheldon, raj);
    

    if(strcmp(sheldon, "pedra") == 0){
        if(strcmp(raj, "pedra") == 0)
            caso = 3;
        
        else if(strcmp(raj, "papel") == 0)
            caso = 2;

        else if(strcmp(raj, "tesoura") == 0)
            caso = 1;

        else if(strcmp(raj, "lagarto") == 0)
            caso = 1;

        else if(strcmp(raj, "Spock") == 0)
            caso = 2;
    }

    else if(strcmp(sheldon, "papel") == 0){
        if(strcmp(raj, "pedra") == 0)
            caso = 1;
        
        else if(strcmp(raj, "papel") == 0)
            caso = 3;

        else if(strcmp(raj, "tesoura") == 0)
            caso = 2;

        else if(strcmp(raj, "lagarto") == 0)
            caso = 2;

        else if(strcmp(raj, "Spock") == 0)
            caso = 1;
    }

    else if(strcmp(sheldon, "tesoura") == 0){
        if(strcmp(raj, "pedra") == 0)
            caso = 2;
        
        else if(strcmp(raj, "papel") == 0)
            caso = 1;

        else if(strcmp(raj, "tesoura") == 0)
            caso = 3;

        else if(strcmp(raj, "lagarto") == 0)
            caso = 1;

        else if(strcmp(raj, "Spock") == 0)
            caso = 2;
    }

    else if(strcmp(sheldon, "lagarto") == 0){
        if(strcmp(raj, "pedra") == 0)
            caso = 2;
        
        else if(strcmp(raj, "papel") == 0)
            caso = 1;

        else if(strcmp(raj, "tesoura") == 0)
            caso = 2;

        else if(strcmp(raj, "lagarto") == 0)
            caso = 3;

        else if(strcmp(raj, "Spock") == 0)
            caso = 1;
    }

    else if(strcmp(sheldon, "Spock") == 0){
        if(strcmp(raj, "pedra") == 0)
            caso = 1;
        
        else if(strcmp(raj, "papel") == 0)
            caso = 2;

        else if(strcmp(raj, "tesoura") == 0)
            caso = 1;

        else if(strcmp(raj, "lagarto") == 0)
            caso = 2;

        else if(strcmp(raj, "Spock") == 0)
            caso = 3;
    }


    if(caso == 1)
    printf("Caso #%d: Bazinga!\n", i);

    else if(caso == 2)
    printf("Caso #%d: Raj trapaceou!\n", i);

    else
    printf("Caso #%d: De novo!\n", i);
}
    return 0;
}