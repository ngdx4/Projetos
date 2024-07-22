/*
objetivo: Receba do usuario via console uma sequência de números
inteiros até que 3 números pares sejam lidos.
• Imprima quantas vezes o laço precisou ser repetido
*/
#include <stdio.h>
#include <stdlib.h>

int main (){
	int n,i,j = 0;
	while(i < 3){
		printf("Insira um número inteiro: \n");
		scanf("%d",&n);
		if(n%2 ==1){
			i += 1;
		}
		j += 1;
	}
	printf("O laço se repetiu %d vezes\n",j);
	return 0;
}
