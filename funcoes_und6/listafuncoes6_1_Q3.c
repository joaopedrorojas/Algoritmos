#include <stdio.h>

double C_area_ret (double larg, double comp){
    double area;

    area = larg * comp;
    return area;
}

double C_perimetro_ret (double larg, double comp){
    double perimetro;

 perimetro = (larg + comp) * 2;
    return perimetro;
}

double C_area_tri (double alt, double base){
    double area;

    area = (alt * base) / 2;
    return area;
}

double C_perimetro_tri (double base){
    double perimetro;

 perimetro = base * 3;
    return perimetro;
}

int main(){
    double larg, comp, base, alt;
    printf("Insira a largura e o comprimento do retangulo desejado: \n");
    scanf("%lf %lf", &larg, &comp);
    printf("Agora a altura e a base do triangulo desejado:\n");
    scanf("%lf %lf", &alt, &base);
    printf("\nArea do retangulo: %.2lf\nPerimetro do retangulo: %.2lf\n\nArea do triangulo: %.2lf\nPerimetro do triangulo: %.2lf\n", C_area_ret(larg, comp), C_perimetro_ret(larg, comp), C_area_tri(alt, base), C_perimetro_tri(base));
}

