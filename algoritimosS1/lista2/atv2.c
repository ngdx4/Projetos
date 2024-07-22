/*
objetivo:2. Fazer um programa que recebe um símbolo de operação do usuário (+, -, / ou *) e dois números reais (float). O programa deve retornar o resultado da operação recebida sobre estes dois números.

Imprima a operação selecionada pelo usuário. Imprima o número calculado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculadora (char operacao, float n1, float n2){
	switch(operacao){
		case '+':
			printf("O resultado é: %f\n", n1 + n2);
			break;
		case '-':
			printf("O resultado é: %f\n", n1 - n2);
			break;
		case '*':
			printf("O resultado é: %f\n", n1 * n2);
			break;
		case '/':
			printf("O resultado é: %f\n", n1 / n2);
			break;
	}
}

int main (){
	char operacao;
	float n1, n2;
	printf("\n CALCULADORA SIMPLES \n");
	printf("Operações:\n soma: +\n subtração: -\n multiplicação: *\n divisão: /\n");
	printf("Digite o simbolo da operação desejada: \n");
	scanf(" %c", &operacao);
	printf("Insira o primeiro número: \n");
	scanf("%f", &n1);
	printf("Insira o segundo número: \n");
	scanf("%f", &n2);

	calculadora(operacao, n1, n2);

	return 0;
}
