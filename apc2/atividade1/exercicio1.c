//exercicio 1
//Nome: Davi Roberto Barros Ferreira
//Matrícula: 2412130012
#include<stdio.h>

int main(void){
	int i = 5;
	int *p;
	p = &i;

	printf("&p: %p\n", &p);
	printf("p (&i - endereço de i): %p\n", p);
	printf("*p ( i - valor de i): %d\n", *p);
	*p = 7;
	printf("*p ( i - valor de i): %d\n", *p);
	printf("Insira um novo valor para i: ");
	scanf("%d", p);
	printf("*p ( i - valor de i): %d\n", *p);
	return 0;
}

