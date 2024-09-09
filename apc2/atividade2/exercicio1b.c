//Nome:Davi Roberto Barros Ferreira
//Matrícula: 2412130012
//Exercicio 1, letra b
#include<stdio.h>

int main(void){
    char string[50] = "Avaliação 2";
	int i = 0;
    while(*(string+i)){
        printf("string[%d]: %c\n", i, *(string+i));
		i++;
    }
    return 0;
}

