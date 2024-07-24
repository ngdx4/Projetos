/*
objetivo: 5. Leia uma string do teclado e conte quantas vogais (a, e, i, o, u) ela possui. Entre com um caractere (vogal ou consoante) e substitua todas as vogais da palavra dada por esse caractere. Ao final, imprima a nova string e o número de vogais que ela possui.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void trocador(char string[],char vogais[], char caracter, int tamanho, int* contador){
	int cont = 0;
	for(int i = 0; i < tamanho-1;i++){
		for(int j=0; j<5;j++){
			if(string[i] == vogais[j]){
				string[i] = caracter;
				cont += 1;
			}
		}
	}
	*contador = cont;
}
void codigo (){
	char string[100];
	char caracter;
	char vogais[5] = {'a','e','i','o','u'};
	int contador;
	printf("Insira uma palavra: \n");
	fgets(string, 100, stdin);
	printf("Insira uma caractere: \n");
	scanf(" %c", &caracter);
	int tamanho = strlen(string);
	trocador(string,vogais,caracter, tamanho,&contador);
	printf("a palavra tem %d vogais.\n", contador);
	printf("A palavra com as vogais trocada é:\n%s\n", string);
	
}
int main (){
	codigo();
	return 0;
}
