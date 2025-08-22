typedef struct {
    double real;
    double imag;
} complexo;
 
int scanComplexo(complexo *c);
 
void printComplexo(complexo c);
 
//operacoes
complexo soma(complexo A, complexo B);
complexo sub(complexo A, complexo B);
complexo multi(complexo A, complexo B);
complexo div(complexo A, complexo B);