//MINI POKER
//questao 3
//João Pedro Rojas

#include <stdio.h>

void ordena(int vetor[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        for (int j = i; j < tamanho; j++)
        {
            if (vetor[i] > vetor[j])
            {
                int guia = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = guia;
            }
        }
    }
}


int main()
{
    int teste;
    int mao[6];
    int carta;
    int pontos;
    
    scanf("%d", &teste);
    
    for(int i = 1; i <= teste; i++){
        
        for(int j = 0; j < 5; j++){
            scanf("%d", &carta);
            mao[j] = carta;
        }
        
    ordena(mao, 5);
    
    int c1 = mao[0], c2 = mao[1], c3 = mao[2], c4 = mao[3], c5 = mao[4];
    
    if(c1 == c2 - 1 && c2 == c3 -1 && c3 == c4 - 1 && c4 == c5 - 1)
        pontos = c1 + 200;
        
    else if((c1 == c2 && c2 == c3 && c3 == c4) || (c2 == c3 && c3 == c4 && c4 == c5))
        pontos = c3 + 180;
        
    else if((c1 == c3 && c4 == c5) || (c1 == c2 && c3 == c5))
        pontos = c3 + 160;
        
    else if((c1 == c2 && c2 == c3) || (c2 == c3 && c3 == c4) || (c3 == c4 && c4 == c5))
        pontos = c3 + 140;
        
    else if((c1 == c2 && c3 == c4) || (c1 == c2 && c4 == c5) || (c2 == c3 && c4 == c5))
        pontos = 3 * c4 + 2 * c2 + 20;
        
    else if((c1 == c2) || (c2 == c3))
        pontos = c2;
        
    else if((c3 == c4) || (c4 == c5))
        pontos = c4;
        
        printf("Teste %d\n%d\n\n", i, pontos);
    }
    
    
}