#include <stdio.h>

int main() {
    
    int num;
    int arabicos[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    while(scanf("%d", &num) && num != 0){

        for(int i = 0; i < 13; i++){

            while(num >= arabicos[i]){
            
                printf("%s", romanos[i]);
                num -= arabicos[i];
            }
        }
        printf("\n");
    }

    return 0;
}