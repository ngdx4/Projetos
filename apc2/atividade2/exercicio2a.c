//Nome:Davi Roberto Barros Ferreira
//Matrícula: 2412130012
//exercicio 2, letra a
#include<stdio.h>

int main(void){
	char c,*ptr = NULL, string[] = "Exercicio de APC II";
	int i = 0;
	printf("Insira uma letra: \n");
	c = getchar();
	while(*(string+i)){
		if(*(string+i) == c){
				ptr = (string+i);
		}
		i++;
	}
		if(ptr != NULL){
				printf("&string[%ld]: %p", (ptr - string), ptr);
		}else{
			printf("Caractere não encontrado.\n");
		}
    return 0;
}

