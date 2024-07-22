/* Objetivo:1.Fazer um programa para receber valores inteiros X, Y e Z
do usuário e determinar se estes valores podem formar os lados
de um triângulo. Em caso afirmativo, informar se o triângulo é
equilátero, isosceles ou escaleno.

Imprima o nome do triângulo formado.
Imprima mensagem de erro caso não seja possivel formar o triângulo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* validador (float x, float y, float z){
	char *nao_triangulo = "Não é possivel formar um triagulo.\n";
	char *triangulo = "É possivel formar um triangulo.\n";
	char *resultado;
	if((x + y > z && y + z > x && x + z > y)){
		resultado = (char*)malloc(strlen(triangulo)+1);
		strcpy (resultado, triangulo);
		
	}else{
		resultado = (char*)malloc(strlen(nao_triangulo)+1);
		strcpy(resultado, nao_triangulo);
		}
	return resultado;
}

char* identificador (float x, float y, float z){
	char *triangulo_equilatero = "É um triângulo equiláteto.\n";
	char *triangulo_isoceles =  "É um triângulo isoceles.\n";
	char *triangulo_escaleno = "É um triângulo escaleno.\n";
	char *resultado;
	char *inexistente = "Não";
	char *validade;
	strcpy(validade, validador(x,y,z));
	if( x == y && y == z){
		resultado = (char*)malloc(strlen(triangulo_equilatero)+ 1);
		strcpy(resultado, triangulo_equilatero);
	}else if((x == y) || (x == z) || (y == z)){
		resultado = (char*)malloc(strlen(triangulo_isoceles)+ 1);
		strcpy (resultado,triangulo_isoceles);
	}else{
		resultado = (char*)malloc(strlen(triangulo_escaleno)+ 1);
		strcpy(resultado,triangulo_escaleno);
	}
	if(strstr(validade, inexistente) != NULL){
		resultado = "";
	}
	return resultado;
}

int main (){

	float x,y,z;
	printf("DETERMINAR SE O TRIÂNGULO EXISTE\n\n");
	printf("Digite o valor de 1 dos lado do triangulo: \n");
	scanf("%f", &x);
	printf("Digite o valor de outro lado do triangulo: \n");
	scanf("%f", &y);
	printf("Digite o valor de outro lado do triangulo: \n");
	scanf("%f", &z);

	printf("%s\n%s", validador(x,y,z), identificador(x,y,z));

	return 0;
}

