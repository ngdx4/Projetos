#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>

typedef char criar[9][9];

void pausar(){//não existe o comando "system("pause");" no termux.
	printf("Pressione qualquer tecla para continuar...\n");
	getchar();
}

void clearbuffer (){
	int c;
	while((c = getchar()) != '\n'){}
}
/*void historico(char peca_escolida[3], char peca_movida[3]){
	char *historico[500];
	strcpy();
}*/
/*void imprimir_historico(char historico[500]){
	int tamanho = strlen(historico);	
	printf("t7");
	for(int i = 0; i<tamanho;i++){
		if(i % 2 == 1){
			printf("jogada %d - %c moveu para", i, historico[i]);
		}else{
			printf("%c\n", historico[i]);
		}
	}
}*/
int menu (){
	char saida[10];
	while(!strstr(saida, "sair")){
		printf("Escreva uma da opções abaixo:\n");
		printf("Jogar - para iniciar uma nova partida\n");
		printf("historico - para abrir o historico da ultima partida\n");
		printf("Sair - para fechar o jogo\n\n");
		if(fgets(saida, sizeof(saida), stdin) == NULL){
			printf("ERRO DE LEITURA\n");
			clearbuffer();
			continue;
		}
		for(int i = 0; i<strlen(saida);i++) saida[i] = tolower(saida[i]);
		if(strstr(saida, "jogar")|| strchr(&saida[0], '1')){
			return 1;
/*	}else if(strstr(saida,"historico")||strchr(&saida[0],'2')){
			imprimir_historico(historico);
			system("pause");
			continue;*/
		}else if(strstr(saida, "sair")||strchr(&saida[0], '3')){
			break;
		}else{
			printf("Escolha não reconhecida, digite novamente\n");
		}
	}
	return 0;
}

void organizar_tabuleiro(char *original){
	criar tabuleiro;
	char pecas_tab[] = {'P','T','H','B','R','Q'};
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
				tabuleiro[i][1] = tolower(pecas_tab[1]);
				tabuleiro[i][8] = tolower(pecas_tab[1]);
				tabuleiro[i][2] = tolower(pecas_tab[2]);
				tabuleiro[i][7] = tolower(pecas_tab[2]);
				tabuleiro[i][3] = tolower(pecas_tab[3]);
				tabuleiro[i][6] = tolower(pecas_tab[3]);
				tabuleiro[i][5] = tolower(pecas_tab[4]);
				tabuleiro[i][4] = tolower(pecas_tab[5]);
			}else if(i == 2){
				tabuleiro[i][j] = tolower(pecas_tab[0]);
			}else if(i == 7){
				tabuleiro[i][j] = pecas_tab[0];
			}else if(i == 8){
				tabuleiro[i][1] = pecas_tab[1];
				tabuleiro[i][8] = pecas_tab[1];
				tabuleiro[i][2] = pecas_tab[2];
				tabuleiro[i][7] = pecas_tab[2];
				tabuleiro[i][3] = pecas_tab[3];
				tabuleiro[i][6] = pecas_tab[3];
				tabuleiro[i][5] = pecas_tab[4];
				tabuleiro[i][4] = pecas_tab[5];
			}else{
				tabuleiro[i][j] = ' ';
			}
		}
	}
	for(int i=0;i<sizeof(tabuleiro);i++) *(
}

int coordenadas(char coordenada[2], int *cont){
	char letras[8] = {'a','b','c','d','e','f','g','h'};
	int x, y;
	for(int i = 0;i<8;i++){
		if(coordenada[0] == letras[i]){
			x = i+1;
		}
	}
	y = atoi(&coordenada[1]);
	*cont += 1;
	if( *cont  % 2 == 0){
		return x;
	}else{
		return y;
	}
	
}
int verificador_ganhador(criar tabuleiro){
	int verificadorb = 0;
	int verificadorp = 0;
	for(int i = 0; i<9;i++){
		for(int j = 0; j<9; j++){
			if(tabuleiro[i][j] == 'R'){
				verificadorb = 1;
			}
			if(tabuleiro[i][j] == 'r'){
				verificadorp = 1;
			}
		}
	}
	if(verificadorb == 1 && verificadorp == 0){
		return 1;
	}
	if(verificadorb == 0 && verificadorp == 1){
		return 2;
	}else{
		return 0;
	}
}

void upgrade_peao(criar tabuleiro){
	int erro = 0;
	int peao;
	char c;
	char escolha[7];
	enum pecas_de_troca{
		torre,
		cavalo,
		bispo,
		rainha
	};
	while(!erro){
		erro = 1;
		for(int i=0; i<9;i++){
			if(tabuleiro[1][i] == 'P'){
				printf("Escreva qual peça ira trocar pelo peao:\n");
				printf("Torre - Cavalo - Bispo - Rainha\n");
				fgets(escolha, sizeof(escolha),stdin);
				for(int i=0;i<7;i++){
					escolha[i] = tolower(escolha[i]);
				}
				if(strstr(escolha, "torre")){
					peao = torre;
				}else if(strstr(escolha,"cavalo")){
					peao = cavalo;
				}else if(strstr(escolha, "bispo")){
					peao = bispo;
				}else if(strstr(escolha, "rainha")){
					peao = rainha;
				}
				switch(peao){
					case torre:
						tabuleiro[1][i] = 'T';
						break;
					case cavalo:
						tabuleiro[1][i] = 'H';
						break;
					case bispo:
						tabuleiro[1][i] = 'B';
						break;
					case rainha:
						tabuleiro[1][i] = 'Q';
						break;
					default:
						printf("Escolha não reconhecida, Escreva novamente\n");
						erro = 0;
						break;
				}
			}
			if(tabuleiro[8][i] == 'p'){
				printf("Escreva qual peça ira trocar pelo peao\n");
				printf("Torre - Cavalo - Bispo - Rainha\n");
				fgets(escolha, sizeof(escolha),stdin);
				for(int i=0;i<7;i++){
					escolha[i] = tolower(escolha[i]);
				}
				if(strstr(escolha, "torre")){
					peao = torre;
				}else if(strstr(escolha,"cavalo")){
					peao = cavalo;
				}else if(strstr(escolha, "bispo")){
					peao = bispo;
				}else if(strstr(escolha, "rainha")){
					peao = rainha;
				}
				switch(peao){
					case torre:
						tabuleiro[8][i] = 't';
						break;
					case cavalo:
						tabuleiro[8][i] = 'h';
						break;
					case bispo:
						tabuleiro[8][i] = 'b';
						break;
					case rainha:
						tabuleiro[8][i] = 'q';
						break;
					default:
						printf("Escolha não reconhecida, Escreva novamente\n");
						erro = 0;
						break;
				}
			}
		}
	}
	if(c == '\n'){
		clearbuffer();
	}
}
void imprimir_tabuleiro(criar tabuleiro){
	for(int i=0; i<9;i++){
		for(int j=0; j<9;j++){
			if(i == 0 && j == 0){
				printf("\t %c  ", tabuleiro[i][j]);
			}else if( i == 0){
				printf(" %c  ", tabuleiro[i][j]);
			}else if(j == 0){
				printf(" %c \t", tabuleiro[i][j]);
			}else if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)){
				printf("{%c} ", tabuleiro[i][j]);
			}else{
				printf("[%c] ", tabuleiro[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}
void undo_jogada(char *raiz, char* nutella, int desfazer_jogada, int tamanho){
	int i = 0;
	if(!desfazer_jogada){
		while(i<tamanho){
			*(nutella+i) = *(raiz+i);
			i++;
		}
	}else{
		while(i<tamanho){
				*(raiz+i) = *(nutella+i);
				i++;
		}
	}
	printf("%d   %d\n",desfazer_jogada, i);
}
int partida(criar tabuleiro){
	criar copia_tabuleiro;
	organizar_tabuleiro(copia_tabuleiro);
	char c;
	char inicio[10], destino[10];
	int ix,iy,dx,dy;
	int contador = 0, vencedor = 0, tamanho = sizeof(tabuleiro);
	do{
		int jogou = 0, desfazer_jogada = 0;
		system("clear");
		imprimir_tabuleiro(tabuleiro);
		imprimir_tabuleiro(copia_tabuleiro);
		do{
			printf("Insira a coordenada da peça para mover:\n");
			fgets(inicio, sizeof(inicio), stdin);
			if(c == '\n') clearbuffer();
			if(!strstr(inicio, "desfazer")){
				printf("Insira a coordenada destino:\n");
				fgets(destino, sizeof(destino), stdin);
				if(c == '\n') clearbuffer();
				ix = coordenadas(inicio, &contador);
				iy = coordenadas(inicio, &contador);
				dx = coordenadas(destino, &contador);
				dy = coordenadas(destino, &contador);
				undo_jogada(&tabuleiro[0][0],&copia_tabuleiro[0][0],desfazer_jogada, tamanho);
//				pausar();
			}
			if(strstr(inicio, "desfazer") || strstr(destino, "desfazer")){
				desfazer_jogada = 1;
				undo_jogada(&tabuleiro[0][0],&copia_tabuleiro[0][0],desfazer_jogada, tamanho);
				pausar();
				continue;
			}else if(ix == dx && iy == dy){
				printf("A peça não foi movida.\n");
				continue;
			}else{
				tabuleiro[dx][dy] = tabuleiro[ix][iy];
				tabuleiro[ix][iy] = ' ';
				break;
			}
		}while(!jogou);
		vencedor = verificador_ganhador(tabuleiro);
		if(vencedor == 0){
			upgrade_peao(tabuleiro);
		}
		if(c == '\n'){
			clearbuffer();
		}
	}while(vencedor == 0);
	system("clear");
	imprimir_tabuleiro(tabuleiro);
	if(vencedor == 1){
		printf("Parabens o jogador das peças brancas ganhou!!!\n");
		sleep(5);
	}else if(vencedor == 2){
		printf("Parabens o jogador das peças pretas ganhou!!!\n");
		sleep(5);
	}
	if(c != '\n'){clearbuffer();}
	system("clear");
	return menu();
}

void jogo_xadrez (){
	system("clear");
	printf("\nBEM VINDO AO JOGO DE XADREZ\n\n");
	char *historico_temp[] = {NULL};
	int saida = menu();
	if(saida){
		criar tabuleiro;
		organizar_tabuleiro(&tabuleiro[0][0]);
		do{
			system("clear");
			saida = partida(tabuleiro);
			organizar_tabuleiro(&tabuleiro[0][0]);
		}while(saida);
	printf("Obrigado por jogar!!!\n");
	}else{
		printf("Até a proxima!!\n");
	}
}
int main(){
	jogo_xadrez();
	return 0;
}
