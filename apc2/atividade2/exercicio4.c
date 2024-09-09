//Nome:Davi Roberto Barros Ferreira
//Matrícula: 2412130012
//Exercicio 4
#include<stdio.h>

int main(void){
    int num[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
	};
	int* ptr = &num[0][0];
	int i = 0;
	while((ptr+i) != (ptr+12)){
		if(*(ptr+i) % 2 == 0){
			*(ptr+i) = 0;
		}
		i++;
	}
	for(int i = 0; i < sizeof(num)/sizeof(int); i++){
		printf("%d ", *ptr);
		ptr++;
		if( i % 4 == 3){
			printf("\n");
		}
	}
	for(int i = 0; i < sizeof(num)/sizeof(int); i++){
		printf("&num[%d]: %p\n", i, ptr);
		ptr++;
	}
    return 0;
}

