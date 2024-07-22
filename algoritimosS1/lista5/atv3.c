/*
objetivo: 3. Faça um programa que leia uma string e a imprima de trás para a frente.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inversor(char string[], int tamanho){
	int inicio = 0;
	int fim = tamanho - 1;
	char temp;
	while( inicio < fim){
		temp = string[inicio];
		string[inicio] = string[fim];
		string[fim] = temp;
		inicio++;
		fim--;
	}
}

void codigo (){
	char string[30];
	printf("Insira uma palavra:\n");
	fgets( string, 30, stdin);
	int tamanho = strlen(string);
	printf("A ordem normal é: \n%s",string);
	inversor(string, tamanho);
	printf("A ordem inversa é: \n%s",string);
}
int main (){
	codigo();
	return 0;
}
