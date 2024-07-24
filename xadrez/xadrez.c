#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>


typedef struct{
	char peao[10];
	char torre[10];
	char cavalo[10];
	char bispo[10];
	char rei;
	char rainha[10];
} pecas;

typedef char criar[9][9];

void clearbuffer (){
	int c;
	while((c = getchar()) != '\n'){}
}

int menu (){
	char saida[10];
	int i = 0;
	while(saida){
//		system("clear");
		printf("BEM VINDO AO JOGO DE XADREZ\n\n");
		printf("Escreva uma da opções abaixo:\n");
		printf("Jogar - para iniciar uma partida\n");
		printf("Sair - para fechar o jogo\n\n");
		fgets(saida,10,stdin);
		for(int i=0; i<strlen(saida); i++){
			saida[i] = tolower(saida[i]);
		}
		//clearbuffer();
		if(strstr(saida, "jogar")){
			return 1;
		}else if(strstr(saida, "sair")){
			return 0;
		}else{
			printf("Escolha não reconhecida, tente novamente\n");
		}
		i+=1;
		if(i == 10){ // em caso de erro de leitura fechar o programa
			printf("ERRO\n");
			return 0; 
		}
	}
	
}
void definir_pecas(pecas  *pb, pecas *pp){

	char pecas_tab[] = {'P','T','H','B','R','Q'};
	enum contagem{
		pawn,rook,knight,bishop,king,queen
	};
	for(int i=0; i<=5;i++){
		for(int j=0;j<10;j++){
			if(i == pawn){
				pb->peao[j] = pecas_tab[i];
				pp->peao[j] = tolower(pecas_tab[i]);
			}else if(i == rook){
				pb->torre[j] = pecas_tab[i];
				pp->torre[j]= tolower(pecas_tab[i]);
			}else if(i == knight){
				pb->cavalo[j] = pecas_tab[i];
				pp->cavalo[j] = tolower(pecas_tab[i]);
			}else if(i == bishop){
				pb->bispo[j] = pecas_tab[i];
				pp->bispo[j] = tolower(pecas_tab[i]);
			}else if(i == king){
				pb->rei = pecas_tab[i];
				pp->rei = tolower(pecas_tab[i]);
			}else if(i == queen){
				pb->rainha[j] = pecas_tab[i];
				pp->rainha[j] = tolower(pecas_tab[i]);
			}
		}
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
				tabuleiro[i][j] = ' ';
			}
		}
	}
}
int coordenadas(){
	
}
void inversor(criar tabuleiro, pecas *pb, pecas *pp){
	criar tabuleiro_temporario;
	for(int i = 9; i > 0;i--){
		for(int j = 9; j>0;j--){
			tabuleiro_temporario[i][j] = tabuleiro[i][j];
		}
	}
	for(int i = 1; i < 9;i--){
		for(int j = 1; j<9;j--){
			tabuleiro[i][j] = tabuleiro_temporario[i][j];
		}
	}
	
}
void partida(criar tabuleiro, pecas *branco, pecas *preto, int saida){
	char coordenada[2];
	char jogada[2];
	enum coordenada_de_letra{
		vazio,a,b,c,d,e,f,g,h
	};
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
/*		do{
			int jogou = 0;
			printf("Insira a coordenada da peça para mover:\n");
			char deu_certo[] = fgets(coordenada,2,stdin);
			if(!deu_certo){
				clearbuffer();
				jogada[2] = "9b";
			}
			jogou +=1;
		}while(jogou <1);*/
	}while(branco->rei != ' '|| preto->rei != ' ');

}

void jogo_xadrez (){	
	int saida = menu();
	if(saida){
	pecas pecasb;
	pecas pecasp;
	definir_pecas(&pecasb, &pecasp);
	criar tabuleiro;
	organizar_tabuleiro(tabuleiro,&pecasb,&pecasp);
	do{
		partida(tabuleiro,&pecasb,&pecasp,saida);
	}while(saida);
	}else{
		printf("Até a proxima!!\n");
	}
}
int main(){
	jogo_xadrez();
	return 0;
}
