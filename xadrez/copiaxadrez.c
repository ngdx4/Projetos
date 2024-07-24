#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>

void clearbuffer (){
	int c;
	while((c = getchar()) != '\n'){}
}

typedef struct{
	char peao[8];
	char torre[10];
	char cavalo[10];
	char bispo[10];
	char rei;
	char rainha[9];
} pecas;

typedef char criar[9][9];

void definir_pecas(pecas  *pb, pecas *pp){

	char pecas_tab[] = {'P','T','H','B','R','Q'};
	enum contagem{
		p,t,c,b,k,r
	};
	for(int i=0; i<=5;i++){
		for(int j=0;j<=10;j++){
			if(i == 0 && j<=8){
				pb->peao[j] = pecas_tab[i];
				pp->peao[j] = tolower(pecas_tab[i]);
				for(int i=0;i<=10;i++){
					printf("\n(%c)(  1  )%d)\n", pb->peao[j],i);
				}
			}else if(i == 1){
				pb->torre[j] = pecas_tab[i];
				pp->torre[j]= tolower(pecas_tab[i]);
				for(int i=0;i<=10;i++){
					printf("\n(%c)(  2  )%d\n", pb->peao[j],i);
				}
			}else if(i == 2){
				pb->cavalo[j] = pecas_tab[i];
				pp->cavalo[j] = tolower(pecas_tab[i]);
				for(int i=0;i<=10;i++){
					printf("\n(%c)(  3  )%d\n", pb->peao[j],i);
				}
			}else if(i == 3){
				pb->bispo[j] = pecas_tab[i];
				pp->bispo[j] = tolower(pecas_tab[i]);
				for(int i=0;i<=10;i++){
					printf("\n(%c)(  4  )%d\n", pb->peao[j],i);
				}
			}else if(i == 4){
				pb->rei = pecas_tab[i];
				pp->rei = tolower(pecas_tab[i]);
				for(int i=0;i<=10;i++){
					printf("\n(%c)(  5  )%d\n", pb->peao[j],i);
				}
			}else if(i == 5 && j<=9){
				pb->rainha[j] = pecas_tab[i];
				pp->rainha[j] = tolower(pecas_tab[i]);
				for(int i=0;i<=10;i++){
					printf("\n(%c)(  6  )%d\n", pb->peao[j],i);
				}
				for(int i=0;i<=10;i++){
					printf("\n(%c)(  7  )%d\n", pb->peao[j],i);
				}
			}
		}
	}
	for(int i=0;i<=10;i++){
		printf("\n(%c)(%d)\n", pb->peao[i],i);
	}
}
void organizar_tabuleiro(criar tabuleiro,pecas *pb, pecas *pp){
	char num[9] = {' ','1','2','3','4','5','6','7','8'};
	char letras[8] = {'a','b','c','d','e','f','g','h'};
	for(int i=0; i<9;i++){
		for(int j=0; j<9;j++){
			if(i == 0){
				tabuleiro[i][j] = letras[j];
			}else if(j == 0){
				tabuleiro[i][j] = num[i];
			}else if(i == 0 && j == 8){
				tabuleiro[i][j]	= '\n';
			}else if(i == 1){
				tabuleiro[i][1] = pp->torre[0];
				tabuleiro[i][8] = pp->torre[1];
				tabuleiro[i][2] = pp->cavalo[0];
				tabuleiro[i][7] = pp->cavalo[1];
				tabuleiro[i][3] = pp->bispo[0];
				tabuleiro[i][6] = pp->bispo[1];
				tabuleiro[i][4] = pp->rainha[0];
				tabuleiro[i][5] = pp->rei;
			}else if(i == 2){
				tabuleiro[i][j] = pp->peao[j-1];
			}else if(i == 7){
				tabuleiro[i][j] = pb->peao[j-1];
			}else if(i == 8){
				tabuleiro[i][1] = pb->torre[0];
				tabuleiro[i][8] = pb->torre[1];
				tabuleiro[i][2] = pb->cavalo[0];
				tabuleiro[i][7] = pb->cavalo[1];
				tabuleiro[i][3] = pb->bispo[0];
				tabuleiro[i][6] = pb->bispo[1];
				tabuleiro[i][4] = pb->rainha[0];
				tabuleiro[i][5] = pb->rei;
			}else{
				tabuleiro[i][j] = '0';
			}
		}
	}
}

int menu (){
//	system("clear");
	printf("BEM VINDO AO JOGO DE XADREZ\n");
	return 0;
}

void jogo_xadrez (){	
	int saida = menu();
	pecas pecab;
	pecas pecap;
	definir_pecas(&pecab, &pecap);
	criar tabuleiro;
	organizar_tabuleiro(tabuleiro,&pecab,&pecap);
	do{
		for(int i=0; i<9;i++){
			for(int j=0; j<9;j++){
				if(i == 0 && j == 0){
					printf("\t %c  ", tabuleiro[i][j]);
				}else if( i == 0){
					printf(" %c  ", tabuleiro[i][j]);
				}else if(j == 0){
					printf(" %c \t", tabuleiro[i][j]);
				}else{
					printf("[%c] ", tabuleiro[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");


		saida = 0;
	}while(saida != 0);
}

int main(){
	jogo_xadrez();
	return 0;
}
