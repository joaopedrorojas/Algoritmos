#include <stdio.h>
#include <string.h>
#include <math.h>
 
long long fatorial(int n){
    if(n==0)
        return 1;
    else
        return n * fatorial(n -1);
}
 
int soma(int n){
    if (n == 0)
        return 0;
    else
        return n + soma(n-1);
}
 
int fibonacci(int n){
 
    if(n == 0 || n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
 
}
 
long conversao(long n){ // decimal para binario
 
    if (n == 0)
        return 0;
    else
        return (n % 2) + 10 * conversao(n /2);
}
 
//conversor de decimais para binarios:
 
char* dec2binRev(int dec, char *s){
    char temp[17];
 
    if (dec < 2)
    {
        sprintf(s, "%hd", dec);
        return s;
    }
    else
    {
        sprintf(s, "%hd", dec % 2);
        strcpy(temp, s);
        strcat(s, dec2binRev(dec / 2, temp));
        return s;
    }
 
}
 
// inversao da cadeia de bits:
 
char* strrev(char *str, int i, int j){
    char aux;
    if(i >= j)
        return str;
    else{
        aux = str[i];
        str[i] = str[j];
        str[j] = aux;
 
        strcpy(str, strrev(str, ++i, --j));
 
        return str;
    }
}
 
//decimal para binario
 
char* dec2bin(int dec, char* s){
    s = dec2binRev(dec, s);
    strcpy(s, strrev(s, 0, strlen(s) - 1));
    return s;
}
 
int bin2dec(char *bits, int n) {
    int bit = bits[0] - 48;
 
    if (n == 1)
        return bit*pow(2, n - 1);
    else
    return bit*pow(2, n - 1) + bin2dec(&bits[1], n - 1);
}
 
/*int main() {
    int x, s, f;
    long c;
    long long z;
 
    scanf("%d", &x);
    z = fatorial(x);
    s = soma(x);
    f = fibonacci(x);
    c = conversao(x);
    printf("\nFatorial: %lld\n", z);
    printf("\nSoma dos numeros anteriores ate o 0: %d\n", s);
    printf("\nN-ésimo elemento de Fibonacci: %d\n", f);
    printf("\nConversão para binário: %ld\n", c);
 
    return 0;
}
*/
 
int main(){
 
    for(int i = 0; i <= 20; i++){
        printf("Fatorial de %d! = %lld", i, fatorial(i));
        printf("\n");
    }
 
printf("\n\n");
 
    for(int i = 0; i <= 40; i++){
        printf("Fibonacci da posicao %d = %d", i, fibonacci(i));
        printf("\n");
    }
 
printf("\n\n");
 
    for(int i = 0; i <= 40; i++){
        printf("Conversão de decimal (%d) para binario = %ld\n", i, conversao(i));
    }
 
    printf("\n\n");
 
    return 0;
}