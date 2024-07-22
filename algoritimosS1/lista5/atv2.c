/*
2. Sem usar a função strlen(), faça um programa que leia uma string e imprima quantos caracteres ela possui.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strler (char string[]){
	int i=0;
	while(string[i]){
		i += 1;
	}
	return i-1;
}
void codigo (){
	char string[30];
	printf("Insira uma palavra: \n");
	fgets(string, 30, stdin);
	printf("A palavra tem %d caracteres.\n", strler(string));
}
int main (){
	codigo();
	return 0;
}
