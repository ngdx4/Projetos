/* 4.Faça um programa que leia um vetor de oito posições. Em 
seguida, leia também dois valores X e Y quaisquer 
correspondentes a duas posições no vetor. Seu programa deverá 
exibir a soma dos valores encontrados nas
respectivas posições X e Y.
*/

#include <stdio.h>

int main (){
	struct soma {
		int array[8];
		int x,y;
	};
	struct soma num;
	printf("Insira 8 numeros inteiros: \n");
	for(int i = 0; i<8; i++){
		scanf("%d", &num.array[i]);
	}
	printf("Escolha 2 posições do vetor: \n");
	scanf("%d", &num.x);
	scanf("%d", &num.y);
	printf("A soma dos numeros da posição %d e %d  é: %d\n", num.x, num.y, num.array[num.x] + num.array[num.y]);
	return 0;
}


