#include<stdio.h>
#include<stdlib.h>

void inicializar_matrix(int l, int c, float matrix[l][c]){
	for(int j, int i= 0; i<l; i++){
		for( j=0; j<c;j++) matrix[i][j] = 0;
	}
}
void imprimir_matrix(int l, int c, float matrix[l][c]){
	for(int j, int i= 0; i<l; i++){
		for( j=0; j<c;j++){
			if(j == 0){
				printf("[%.2f",matrix[i][j]);
			else if(j == c){
				printf("%.2f\n",matrix[i][j]);
			}
			printf("\n");
	}
}
void codigo(){
	int l,c;
	printf("");
}

int main (){
	codigo();
	return 0;
}
