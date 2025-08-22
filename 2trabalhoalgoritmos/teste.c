#include <stdio.h>
#include <string.h>
void mover_acima(short mesa[26][26], short locais[26][2], short fileira, short bloco){
	short row, alvo, i, j;
	row = locais[bloco][0];
	j = 0;
	while (mesa[fileira][j] != -1){
		j++;
	}
	for (i = locais[bloco][1]; mesa[row][i] != -1; i++){
		alvo = mesa[row][i];
		mesa[row][i] = -1;
		mesa[fileira][j] = alvo;
		locais[alvo][0] = fileira;
		locais[alvo][1] = j;
		j++;
	}
}
void remover_acima(short mesa[26][26], short locais[26][2], short bloco){
	short tmp, alvo, j, i;
	tmp = locais[bloco][0];
	for (i = locais[bloco][1]+1; mesa[tmp][i] != -1; i++){
		alvo = mesa[tmp][i];
		mesa[tmp][i] = -1;
		j = 0;
		while (mesa[alvo][j] != -1){
			j++;
		}
		while (j){
			mesa[alvo][j] = mesa[alvo][j-1];
			// simula o colocar-se embaixo
			locais[mesa[alvo][j-1]][1]++;
			j--;
		}
		mesa[alvo][0] = alvo;
		locais[alvo][0] = alvo;
		locais[alvo][1] = 0;
	}
}
int main(){
	/* mesa armazena pilhas
	 * locais[i] é o endereço do bloco de numero i*/
	short quan, bloco_a, bloco_b, mesa[26][26], locais[26][2];
	short i, j, alvo;
	char com1[16], com2[16];
	scanf("%hd", &quan);
	memset(mesa, -1, sizeof(short) * 26 * 26);
	for (i = 0; i < quan; i++) {
		mesa[i][0] = i;
		locais[i][0] = i;
		locais[i][1] = 0;
	}
	// para depuração
	/*for (i = 0; i < quan; i++) {
		for(j = 0; j < quan; j++) {printf("%2hd ", mesa[i][j]);}
		printf("\n");
	}*/
	while(1) {
		scanf("%s", com1);
		if (strcmp(com1, "quit") == 0){ break; }
		scanf("%hd %s %hd", &bloco_a, com2, &bloco_b);
		/* para depuração
		printf("inst: %s %hd %s %hd\n", com1, bloco_a, com2, bloco_b);
		*/
		if (locais[bloco_a][0] != locais[bloco_b][0]){
			/* para depuração
			printf("BA:[%hd][%hd], BB:[%hd][%hd]\n", locais[bloco_a][0], locais[bloco_a][1], locais[bloco_b][0], locais[bloco_a][1]);
			*/
			if (strcmp(com1, "move") == 0){

				if (strcmp(com2, "over") == 0){
					/* REMOVE SOBRE A */
					remover_acima(mesa, locais, bloco_a);
					mesa[locais[bloco_a][0]][locais[bloco_a][1]] = -1;
					j = 0;
					alvo = locais[bloco_b][0];
					while (mesa[alvo][j] != -1){
						j++;
					}
					mesa[alvo][j] = bloco_a;
					locais[bloco_a][0] = alvo;
					locais[bloco_a][1] = j;
				} else {
					/* REMOVE SOBRE B */
					remover_acima(mesa, locais, bloco_b);
					/* REMOVE SOBRE A */
					remover_acima(mesa, locais, bloco_a);
					/*Coloca o bloco a sobre o bloco b, devolvendo quaisquer blocos sobre a e b às suas posições originais.*/
					mesa[locais[bloco_b][0]][locais[bloco_b][1]+1] = bloco_a;
					mesa[locais[bloco_a][0]][locais[bloco_a][1]] = -1;
					locais[bloco_a][0] = locais[bloco_b][0];
					locais[bloco_a][1] = locais[bloco_b][1]+1;
				}

			} else {
				if (strcmp(com2, "over") == 0){
					/*Coloca o bloco a sobre o bloco b, devolvendo quaisquer blocos sobre a e b às suas posições originais.*/
					mover_acima(mesa, locais, locais[bloco_b][0], bloco_a);
				} else {
					/* REMOVE SOBRE B*/
					remover_acima(mesa, locais, bloco_b);
					mover_acima(mesa, locais, locais[bloco_b][0], bloco_a);
					/*Move a pilha que começa com a (incluindo blocos acima) sobre b, devolvendo quaisquer blocos sobre b às posições originais, mantendo a ordem dos blocos movidos.*/
				}
			}
		} /*else {
			para depuração
			printf("IGNORADA\n");
		}
		for (i = 0; i < quan; i++) {
			for(j = 0; j < quan; j++) {printf("%2hd ", mesa[i][j]);}
			printf("\n");
		}*/
	}
	for (i = 0; i < quan; i++) {
		printf("%hd:", i);
		for(j = 0; mesa[i][j] != -1; j++) {printf(" %hd", mesa[i][j]);}
		printf("\n");
	}
	return 0;
}