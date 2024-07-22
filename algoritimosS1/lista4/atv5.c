/*
5.Faça um programa que possua um array de nome vetor_a que armazene seis números inteiros. O programa deve executar os seguintes passos:

a) Atribua os seguintes valores a esse array: 1, 0, 5, -2, -5, 7.

b) Armazene em uma variável auxiliar a soma dos valores das posições

vetor_a[0], vetor_a[1] e vetor_a[5] do array e mostre na tela essa

soma.

C) Modifique o array na posição 4, atribuindo a essa posição o valor 100.

d) Mostre na tela cada valor do array vetor_a, um em cada linha, ao final do processamento.
*/

#include<stdio.h>

void codigo(){
	int vetor_a[] = {1,0,5,-2,-5,7};
	int coconut = vetor_a[0] + vetor_a[1] + vetor_a[5];
	printf("%d\n", coconut);
	vetor_a[3] = 100;
	for(int i = 0; i < 8; i++){
		printf("%d ", vetor_a[i]);
	}
}
int main (){
	codigo();
	return 0;
}
