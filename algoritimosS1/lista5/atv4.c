/*
objetivo: 4. Construa um programa que leia duas strings do teclado. Imprima uma mensagem informando se a segunda string lida está contida dentro da primeira.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void codigo(){
	char frase[30];
	char palavra[30];
	printf("Insira uma frase: \n");
	fgets(frase, 50, stdin);
	printf("Insira uma palavra: \n");
	fgets(palavra, 30, stdin);
	if(strstr(frase,palavra)){
		printf("A palavra está contida na frase.\n");
	}else{
		printf("A palavra não está contida na frase.\n");
	}	
}
int main (){
	codigo();
	return 0;
}
