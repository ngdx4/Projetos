/*
objetivo: 4. Fazer um programa para mostrar os 15 primeiros termos da série de Fibonacci.

Imprima os números encontrados.
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci (int quantidade, int j){
	int long fibonacci[quantidade];
	int nf = 0;
	int nt = 1;
	for( int i= 0; i < quantidade; i++){
		nf += nt;
		nt = nf - nt;
		fibonacci[i] = nf;
	}

	return fibonacci[j];
}

void codigo (){
	int quantidade;
	printf("CALCULADORA DOS NÚMEROS DE FIBONACCI\n\n");
	printf("Insira a quantidade de números fibonacci que você deseja: \n");
	scanf("%d", &quantidade);
		printf("A sequancia de fibonacci é: \n");
	for(int j = 0; j < quantidade; j++){
		if( j < quantidade -1){
			printf("%d, ", fibonacci(quantidade, j));
		}else{
			printf("%d.\n", fibonacci(quantidade, j));
		}
	}
}
int main(){
	codigo();
	return 0;
}
