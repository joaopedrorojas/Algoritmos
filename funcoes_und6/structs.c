
#include <stdio.h>
#include <string.h>

#define tam 50

typedef struct {
        char nome[tam];
        int idade;
        float altura;
        float peso;
        char sexo;
    }pessoa;


int main() {
    
    pessoa lista[5];

    for(int i = 0; i < 5; i++){

    printf("Qual seu nome?\n");
    fgets(lista[i].nome, tam, stdin);
    printf("Qual sua idade?\n");
    scanf("%d", &lista[i].idade);
    printf("Qual sua altura?\n");
    scanf("%f", &lista[i].altura);
    printf("Qual seu peso?\n");
    scanf("%f", &lista[i].peso);
    printf("Qual seu sexo? (M / F)\n");
    scanf(" %c", &lista[i].sexo);
    getchar(); // consume leftover newline
    } 

    printf("\nTodos os convidados:\n");

    for(int j = 0; j < 5; j++){
        printf("%d - %s", j + 1, lista[j].nome);
    }

    return 0;
}