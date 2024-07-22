/*
objetivo: 1.Crie um programa que leia do teclado seis valores inteiros e os armazene em um vetor (array) em C. Em seguida mostra na tela os valores na ordem em que foram lidos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array(){
	struct array{
		int array;
	};
	struct array num[6];

	printf("Insira 6 valores inteiros: \n");
	for(int i=0;i< 6;i++){
		scanf("%d", &num[i].array);
	}
	printf("Os valores digitados são: \n");
	for(int i = 0; i<6 ;i++){
		printf("%d", num[i].array);
	}
	printf("\n");
}
int main(){
	array();
	return 0;
}

