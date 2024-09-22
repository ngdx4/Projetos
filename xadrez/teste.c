#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
typedef char criar[9][9];

int main(){
	criar matriz;
	int tamanho = sizeof(matriz);
	printf("%d\n",tamanho);
	return 0;
}
