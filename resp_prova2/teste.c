  #include <stdlib.h>
  #include <stdio.h>

  #define MAX 100

  //Struct árvore
  struct node {
      int conteudo;
      struct node *esquerda, *direita;
  };

  struct node* inserir(struct node *raiz, int valor) {
      if (raiz == NULL) {
          struct node *novo = (struct node*) malloc(sizeof(struct node));
          novo->conteudo = valor;
          novo->esquerda = NULL;
          novo->direita = NULL;
          return novo;
      }
      if (valor < raiz->conteudo) {
          raiz->esquerda = inserir(raiz->esquerda, valor);
      } else if (valor > raiz->conteudo) {
          raiz->direita = inserir(raiz->direita, valor);
      }
      return raiz;
  }

  void imprimirArvore(struct node *raiz) {
      if (raiz != NULL) {
          imprimirArvore(raiz->esquerda);
          printf("%d ", raiz->conteudo);
          imprimirArvore(raiz->direita);
      }
  }

//Struct pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int c) {
    if (estaCheia(p)) {
        printf("Pilha cheia.\n");
        return;
    }
    p->itens[++(p->topo)] = c;
}

int pop(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia.\n");
        return -1;
    }
    return p->itens[(p->topo)--];
}

void imprimir(Pilha *p) {
    printf("Pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

void empilha_Par(Pilha *p, struct node *raiz) {
    if (raiz != NULL) {
        empilha_Par(p, raiz->esquerda);
        if (raiz->conteudo % 2 == 0) {
            push(p, raiz->conteudo);
        }
        empilha_Par(p, raiz->direita);
    }
}

void empilha_Impar(Pilha *p, struct node *raiz) {
    if (raiz != NULL) {
        empilha_Impar(p, raiz->esquerda);
        if (raiz->conteudo % 2 != 0) {
            push(p, raiz->conteudo);  
        }
        empilha_Impar(p, raiz->direita);
    }
}

struct node *arvore = NULL;
int x, valor;
Pilha pilhaPares, pilhaImpares;

int main() {
  iniciarPilha(&pilhaPares);
  iniciarPilha(&pilhaImpares);

  do {
    printf("1- Inserir na arvore\n");
    printf("2- Imprimir arvore\n");
    printf("3- Empilhar pares e impares\n");
    printf("4- Imprimir pilha de pares\n");
    printf("5- Imprimir pilha de impares\n");
    printf("6- Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &x);

      switch (x) {
        case 1:
          printf("Digite um valor: ");
          scanf("%d", &valor);
          arvore = inserir(arvore, valor);
          break;
        case 2:
          printf("Imprimindo arvore:\n");
          imprimirArvore(arvore);
          printf("\n");
          break;
        case 3:
          empilha_Par(&pilhaPares, arvore);
          empilha_Impar(&pilhaImpares, arvore);
          printf ("Empilhados!\n");
          break;
        case 4:
          printf("Imprimindo pilha de pares:\n");
          imprimir(&pilhaPares);
          break;
        case 5:
          printf("Imprimindo pilha de impares:\n");
          imprimir(&pilhaImpares);
          break;
        case 6:
          printf("Saindo...\n");
          break;
        default:
          printf("Opcao invalida.Tente novamente.\n");
          }
      } while (x != 6);

      return 0;
  }