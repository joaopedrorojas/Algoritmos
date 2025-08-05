//Biblioteca de implementacao de numeros racionais

//tipos de dados disponiveis
    //definicao do tipo racional

typedef struct {
    int num;
    int den;
}racional;

//funcoes disponiveis

int mdc(int a, int b);

racional simplifica(racional r);

racional somarac(racional r1, racional r2);

racional subrac(racional r1, racional r2);

racional multirac(racional r1, racional r2);

racional divrac(racional r1, racional r2);
