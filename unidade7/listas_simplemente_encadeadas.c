#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//caso nao conseguir entender, desenha para ficar mais simples

//lista simples encadeada
//listas simples encadeadas é basicamente um vetor, porem ao invez de usar uma memoria sequencial ex: casa: 1, 2, 3, 4, 5...
//na lista, o C vai varrendo a memoria achando lugares que caibam a struct, as casas podem ser: 14, 512, 89, 3, nao tem uma sequencia logica
//é criado com structs e defino nela o conteudo com info. e um ponteiro para o elemento seguinte da lista, o ultimo elemento é 'NULL'
//so consegue ir pra frente na memoria


//lista duplamente encadeada
//a diferenca é que possui uma struct com 2 ponteiros  e a informacao
//o ponteiro inicial aponta para a celula anterior
// no meio fica o conteudo com informacao
//o ponteiro final aponta para a celula inteira do proximo
// assim podendo ir e voltar na memoria, ir pra frente e pra tras

//definicao de estrutura de dados
//para se definir os nós de uma lista encadeada utiliza 'structs'
//deve conter os dados e o ponteiro para o proximo elemento

//ex: lista simplesmente encadeada

//dado armazenado = caractere

typedef char dado; //declaracao do tipo de dado armazenado
// declara aqui o tipo da variavel, se quiser trocar para 'int'base substituir aqui o 'char' por 'int'

typedef struct Tipolista{ //declaracao da estrutura de nó de lista
    dado item;      //dado armazenado no nó
    struct Tipolista *next;     //ponteiro para o proximo nó
}Tipolista;

typedef short Tipodata;

typedef struct TipoNode{
    Tipodata info;         // dado armazenado do nó
    struct TipoNode *next; // ponteiro para o proximo nó
}TipoNode;

typedef struct TipoListSE
{
    TipoNode  *first;      //aponta para a primeira celula             //
    TipoNode *last;        //aponta para a ultima celular              // isso tudo ta dentro da estrutura TipoListSE, info. gerais
    short length;       //short que indica o comprimento da lista   //
}TipoListSE;

//inicializacao da lista
void initList(TipoListSE *L){
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

//destruicao da lista = apagar lista
void deleteList(TipoListSE *L){
    TipoNode *p = L->first;     //p = guia auxiliar
    while(p){   //quando p for nulo vai encerrar o laço
        L->first = L->first->next;  //aponta pra next casa
        free(p);    // limpa a casa de p
        L->length--;    //diminui o tamanho do comprimento pq uma casa ja foi limpada
        p = L->first;   // e p = o primeiro que no caso é = ao next que foi apontado para o proximo anteriormente
    }
    L->last = NULL;     // last tem q receber nulo pq ele ainda continua apontando para a ultima casa da lista
}

//verificacao se a lista esta vazia
bool emptyList(TipoListSE L){       //bool = funcao booleana

    return (L.length == 0);     // aqui pode conferir tanto o first, o last e o length, se a lista realmente for vazia,
                                //todos elementos serao nulos, opcao usada: length
}

//escrever a lista

void printList(TipoListSE L){
    TipoNode *p = L.first;  //inicializa p

    printf("[");
    while(p)
    {
        printf("%hd", p->info);
        if(p-> next)
            printf(", ");
        p = p->next;
    }
    printf("]");
    printf("\n");
    printf("\n");
}

//insercao pela esquerda
short insertLeft(Tipodata x, TipoListSE *L)
{
    TipoNode *aux;
    aux = (TipoNode*)malloc(sizeof(TipoNode));
    if(aux == NULL) //falha na alocacao
        return 1;   //sinaliza com erro deixando a lista atual intacta
    else
    {   // insere x na lista
        aux ->info = x;     //atribui x para o campo info
        aux ->next = L->first;      //insere o elemento antes do atual

        L->first = aux;     //faz o ponteiro do primeiro apontar

        if(L->last == NULL) //lista estava vazia
            L->last = aux;  // primeiro elemento é tambem o ultimo

        L->length++;        //incrementa o tamanho da lista

        return 0;
    }

}

short insertright(Tipodata x, TipoListSE *L){
    TipoNode *aux;
    aux = (TipoNode*)malloc(sizeof(TipoNode));
    if(aux == NULL)
        return 1;
    else{
        aux ->info = x;
        aux ->next = NULL;

        if(L->length == 0){
            L->first = aux;
            L->last = aux;
            L->length++;
            return 0;
        }
        else{
            L->last->next = aux;
            L->last = aux;
            L->length++;
            return 0;
        }
        
    }

}
short removeleft(TipoListSE *L){
    TipoNode *aux;
    
        aux = L->first;
        L->first = aux -> next;
        L->length--;
        return 0;
    
}

short removeright(TipoListSE *L){
    TipoNode *aux;

    aux = L->last;
    L->last = L->first;
    while(L->last->next != aux)
        L->last = L->last->next;
    L->last->next = NULL;
    free(aux);
    L->length--;
    return 0;
}

TipoNode* buscaLista(short elemento, TipoListSE *L){
    TipoNode *aux = L->first;

    while(aux && aux->info != elemento)
        aux = aux->next;
    return aux;     //nota: como em cima o aux = aux->next da ultima casa que é igual a NULL, se o elemento nao estiver na
                    //      lista ele ja vai retornar NULL automaticamente.
}

int somalist(TipoListSE *L){
    int soma = 0;
    TipoNode *aux = L->first;

    while(aux){
        soma += aux->info;
        aux = aux->next;
    }
    
    return soma;
}

short substituilist(short valor, TipoListSE *L, int posicao){

    TipoNode *aux = L->first;

    for(int i = 1; i < posicao; i++){
        aux = aux->next;

        if(aux == NULL)
        return 1;
    }

    aux->info = valor;

    return 0;
}

short acharlist(TipoListSE *L, int posicao, int *valor){

    TipoNode *aux = L->first;

    if(posicao > L->length || posicao < 1)
        return 1;

    for(int i = 1; i < posicao; i++){
            aux = aux->next;
    }
    *valor = aux->info;

    return 0;
}

float medialist(TipoListSE *L, float *resp){
    float media = 0;
    TipoNode *aux = L->first;


    if(L->length == 0){
        return 1;
    }

    for(int i = 1; i <= L->length; i++){
            media += aux->info;
            aux = aux->next;
    }
    *resp = media / L->length;

    return 0;
}

int main(){

    TipoListSE L1;
    short a;
    printf(" Inicializando a lista.\n");
    initList(&L1);
    printf("Lista inicializada.\n");
    if(emptyList(L1)){
        printf("Lista vazia.\n");
    }
    printList(L1);
    printf("\n");

    //inserindo a lista
    
    printf("1 = preencher em direcao a esquerda\n2 = preencher em direcao a direita\n");
    int lado, entradas;
    scanf("%d", &lado);

    if(lado == 1){
        printf("Quantas entradas:");
        scanf("%d", &entradas);
        printf("Pode preencher com as entradas:\n");
        while(entradas--){
            scanf("%hd", &a);
            insertLeft(a, &L1);
        }
    }
    else{
        printf("Quantas entradas:\n");
        scanf("%d", &entradas);
        printf("Pode preencher com as entradas:\n");
        while(entradas--){
            scanf("%hd", &a);
            insertright(a, &L1);
        }
    }
    printList(L1);
    printf("Soma da lista: [%d]\n", somalist(&L1));
    printf("\n");

    int substituicao;
    printf("Deseja alterar algo dentro da lista? 1-sim 2-nao\n");
    scanf("%d", &substituicao);
    if(substituicao == 1){
        short valor;
        int posicao;

        printf("Insira o valor que voce deseja incluir e em seguida a posicao\n");
        scanf("%hd %d", &valor, &posicao);
        substituilist(valor, &L1, posicao);

        printList(L1);
    }

    int posicao;
    printf("Insira a posicao que voce deseja descobrir o elemento\n");
    scanf("%d", &posicao);
    int valor;
    if(!acharlist(&L1, posicao, &valor))
        printf("Valor encontrado: [ %d ]\n", valor);
    else
        printf("Posição nao existe\n");
    printf("\n");

    float media;

    if(!medialist(&L1, &media))
        printf("Media: [ %.2f ]\n", media);
    else
        printf("Lista vazia, portanto nao existe media\n");
    printf("\n");

    int remove;
    printf("Deseja apagar algum elemento da lista? Nao = 0, Pela esquerda = 1 ou Pela direita = 2\n");
    scanf("%d", &remove);

    if(remove == 1){
        int quantia;
        printf("Quantas casas voce deseja remover?\n");
        scanf("%d", &quantia);
        while(quantia--)
            removeleft(&L1);
        printf("Nova lista apos a remocao:\n");
        printList(L1);
    }
    else if(remove == 2){
        int quantia;
        printf("Quantas casas voce deseja remover?\n");
        scanf("%d", &quantia);
        while(quantia--)
            removeright(&L1);
        printf("Nova lista apos a remocao:\n");
        printList(L1);
    }

    int busca;
    printf("Voce deseja fazer alguma busca? 1- Sim, 0- Nao\n");
    scanf("%d", &busca);
    if(busca == 1){
        short elemento;
        printf("Qual elemento voce deseja buscar?\n");
        scanf("%hd", &elemento);

        TipoNode *existe;
        existe = buscaLista(elemento, &L1);

        if(existe){ //caso for != de NULL
            printf("Elemento encontrado no endereco %p.\n", existe);
            printf("Valor: %hd\n", existe->info);
        }
        else
            printf("Elemento nao encontrado\n");
    }

    deleteList(&L1);
    
    return 0;
}