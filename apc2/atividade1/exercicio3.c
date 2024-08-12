//exercicio 3
//Nome: Davi Roberto Barros Ferreira
//Matrícula: 2412130012
#include<stdio.h>

int main(){
	int n1 = 3, n2 = 5;
	int *ptr1 = &n1, *ptr2 = &n2, temp;
	temp = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = temp;

	printf("n1: %d, n2: %d\n",n1 ,n2);
	return 0;
}

