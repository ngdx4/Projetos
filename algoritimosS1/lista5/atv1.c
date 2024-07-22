/*
objetivo: 1. um programa que leia uma string e imprima as quatro primeiras letras dela.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void codigo(){
	char string[30];
	printf("Insira uma palavra:\n");
	fgets(string, 30, stdin);
	printf("As 4 primeiras letras são: ");
	for(int i = 0; i < 4; i++){
		printf("%c", string[i]);
	}
	printf("\n");
}
int main(){
	codigo();
	return 0;
}
