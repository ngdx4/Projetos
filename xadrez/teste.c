#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>

int main(){
	char matrix[5][30];
	char string[] = "arroooouuu fufado";
	printf("%ld\n", strlen(string));
	for(int j, i= 0;i<5;i++){
		for(j=0;j<30;j++) matrix[i][j] = '0';
	}
	
	strcpy(matrix[1], string);
//	matrix[1][strlen(string)] = '\0';

	for(int j, i= 0;i<5;i++){
		for(j=0;j<30;j++){
			if(i == 1){
				printf("%c",matrix[i][j]);
			}else{
					printf("[%c]",matrix[i][j]);
			}
		}
		printf("\n");
	}

	printf("%s", string);

	if(matrix[1][sizeof(string)] == '\0'){
		printf("ta zerado");
	}else{
		printf("nao ta zerado");
	}


	return 0;
}
