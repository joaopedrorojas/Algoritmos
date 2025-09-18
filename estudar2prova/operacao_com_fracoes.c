#include <stdio.h>

typedef struct{
	int cima;
	int baixo;
}fracao;

int mdc(int a, int b){

	int resp = 1;

	while(resp){
		resp = a % b;
		a = b;
		b = resp;
	}
	return a;
}

fracao simplifica(fracao x){
	int mdcdiv;
	fracao resp;

	mdcdiv = mdc(x.cima, x.baixo);

	resp.cima = x.cima / mdcdiv;
	resp.baixo = x.baixo / mdcdiv;

	if(resp.baixo < 0){
		resp.cima = -resp.cima;
		resp.baixo = -resp.baixo;
	}

	return resp;

}

fracao soma(fracao x, fracao y){
	fracao resul;

	resul.cima = (x.cima * y.baixo) + (y.cima * x.baixo);
	resul.baixo = x.baixo * y.baixo;

	return simplifica(resul);
}

fracao sub(fracao x, fracao y){
	fracao resul;

	resul.cima = (x.cima * y.baixo) - (y.cima * x.baixo);
	resul.baixo = x.baixo * y.baixo;

	return simplifica(resul);
}

fracao multi(fracao x, fracao y){
	fracao resul;

	resul.cima = x.cima * y.cima;
	resul.baixo = x.baixo * y.baixo;

	return simplifica(resul);
}

fracao div(fracao x, fracao y){
	fracao resul;

	resul.cima = x.cima * y.baixo;
	resul.baixo = x.baixo * y.cima;

	return simplifica(resul);
}

int main() {
	
	fracao x, y, resp;

	printf("Insira as duas frações a serem operadas: ex: (x/y w/z)\n");

	scanf("%d/%d %d/%d", &x.cima, &x.baixo, &y.cima, &y.baixo);

	resp = soma(x, y);
	printf("%d/%d + %d/%d = %d/%d\n", x.cima, x.baixo, y.cima, y.baixo, resp.cima, resp.baixo);

	resp = sub(x, y);
	printf("%d/%d - %d/%d = %d/%d\n", x.cima, x.baixo, y.cima, y.baixo, resp.cima, resp.baixo);

	resp = multi(x, y);
	printf("%d/%d * %d/%d = %d/%d\n", x.cima, x.baixo, y.cima, y.baixo, resp.cima, resp.baixo);

	resp = div(x, y);
	printf("%d/%d / %d/%d = %d/%d\n", x.cima, x.baixo, y.cima, y.baixo, resp.cima, resp.baixo);

	return 0;
}