//Nome:Davi Roberto Barros Ferreira
//Matrícula: 2412130012
//exercicio 2, letra b
#include<stdio.h>

int main(void){
    char string[] = "Exercicio de APC II";
	char *ptr = string;
	int num;
	while(*ptr){
		ptr++;
	}
	ptr--;
	num = ptr - string;
	printf("A string tem %d caracteres\n", num);
    return 0;
}

