/*
3.Faça um programa que leia cinco valores e os armazene em um vetor. Em seguida, mostre todos os valores lidos juntamente com a média dos valores lidos ao final.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
		float num[5];
		int i;
	} numeros;
	numeros cont;

float media(){
	float media = 0;
	for(int i = 0; i < 5; i++){
		media += cont.num[i];
	}
	media /= 5;
	return media;
}

void armazenamento_vetor(){
	printf("Insira 5 valores abaixo: \n");
	for(cont.i = 0; cont.i<5;cont.i++){
		scanf("%f", &cont.num[cont.i]);
	}
	printf("Os valores inseridos foram: \n");
	for(cont.i = 0; cont.i<5;cont.i++){
		printf("%.2f\n", cont.num[cont.i]);
	}
	printf("\nA media é %.2f\n", media());
}
int main (){
	armazenamento_vetor();
	return 0;
}
