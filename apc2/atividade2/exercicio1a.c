//Nome:Davi Roberto Barros Ferreira
//Matrícula: 2412130012
//exercicio 1, letra a
#include<stdio.h>

int main(void){
	int vet[8] = {4, 6, 3, 8, 2, 5, 9, 1};
	for(int i = 0; i<8;i++){
		printf("vet[%d]: %d\n", i, *(vet+i));
	}
	return 0;
}

