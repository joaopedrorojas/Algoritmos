//monopolio
//questao 4 
//João Pedro Rojas

#include <stdio.h>
int main() {
    
   int dinheiro, operacoes;
   
   scanf("%d %d", &dinheiro, &operacoes);
  
   int Dalia = dinheiro, Eloi = dinheiro, Felix = dinheiro;
    
   for (int i = 0; i < operacoes; i++){
       
       char oper, jog1, jog2;
       int gasto;
       
       scanf(" %c", &oper);
       if (oper == 'C') {
           
           scanf(" %c %d", &jog1, &gasto);
           
            if (jog1 == 'D')
                Dalia -= gasto;
                
            else if (jog1 == 'E')
                Eloi -= gasto;
                
            else if (jog1 == 'F')
                Felix -= gasto;
       }
       
       else if (oper == 'V') {
           
           scanf(" %c %d", &jog1, &gasto);
           
            if (jog1 == 'D') 
                Dalia += gasto;
                
            else if (jog1 == 'E') 
                Eloi += gasto;
                
            else if (jog1 == 'F') 
                Felix += gasto;
       }
       else if (oper == 'A') {
           
           scanf(" %c %c %d", &jog1, &jog2, &gasto);
           
           if (jog1 == 'D') 
           Dalia += gasto;
           
           else if (jog1 == 'E') 
           Eloi += gasto;
           
           else if (jog1 == 'F') 
           Felix += gasto;
           
           if (jog2 == 'D') 
           Dalia -= gasto;
           
           else if (jog2 == 'E') 
           Eloi -= gasto;
           
           else if (jog2 == 'F') 
           Felix -= gasto;
       }
   }
   printf("%d %d %d\n", Dalia, Eloi, Felix);
   
   return 0;
}
