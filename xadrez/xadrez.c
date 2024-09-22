#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<locale.h>
#include<wchar.h>


typedef wchar_t criar[9][9];

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
	}else if(strstr(saida,"historico")||strchr(&saida[0],'2')){
//			imprimir_historico(historico);
			printf("Em manutenção\n");
			pausar();
			continue;
		}else if(strstr(saida, "sair")||strchr(&saida[0], '3')){
			break;
		}else{
			printf("Escolha não reconhecida, digite novamente\n");
		}
	}
	return 0;
}

/*void organizar_tabuleiro(criar tabuleiro){
	char pecas_tab[] = {'P','T','H','B','R','Q'};
	char num[9] = {' ','8','7','6','5','4','3','2','1'};
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
}*/
void organizar_tabuleiro(criar tabuleiro){

	wchar_t pecas_tab[12];
	wchar_t c = 0x2654;
	for(int i=0;i<12;i++){
		pecas_tab[i] = c+i;
	}
	char num[9] = {' ','8','7','6','5','4','3','2','1'};
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
				tabuleiro[i][1] = pecas_tab[2];
				tabuleiro[i][8] = pecas_tab[2];
				tabuleiro[i][2] = pecas_tab[4];
				tabuleiro[i][7] = pecas_tab[4];
				tabuleiro[i][3] = pecas_tab[3];
				tabuleiro[i][6] = pecas_tab[3];
				tabuleiro[i][5] = pecas_tab[1];
				tabuleiro[i][4] = pecas_tab[0];
			}else if(i == 2){
				tabuleiro[i][j] = pecas_tab[5];
			}else if(i == 7){
				tabuleiro[i][j] = pecas_tab[11];
			}else if(i == 8){
				tabuleiro[i][1] = pecas_tab[8];
				tabuleiro[i][8] = pecas_tab[8];
				tabuleiro[i][2] = pecas_tab[10];
				tabuleiro[i][7] = pecas_tab[10];
				tabuleiro[i][3] = pecas_tab[9];
				tabuleiro[i][6] = pecas_tab[9];
				tabuleiro[i][5] = pecas_tab[7];
				tabuleiro[i][4] = pecas_tab[6];
			}else{
				tabuleiro[i][j] = ' ';
			}
		}
	}
	
}

int coordenadas(char coordenada[10], int *cont){
	char letras[8] = {'a','b','c','d','e','f','g','h'};
	char num[8] = {'8','7','6','5','4','3','2','1'};
	int x, y,erro=1, i = 0;
	for( i=0;i<8;i++){
		if(coordenada[0] != letras[i] || coordenada[1] != num[i]){
			erro = 0;
		}
		if(coordenada[0] == letras[i] || coordenada[1] == num[i]){
			erro = 1;
			break;
		}
	}
		if(erro == 0) return erro;
	for(i = 0;i<8;i++){
		if(coordenada[0] == letras[i]) y = i+1;
	}
	for( i=0 ;i<8;i++){
		if(coordenada[1] == num[i]) x = i+1;
	}

	*cont += 1;
	if( *cont  % 2 == 1){
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
			if(tabuleiro[i][j] == 0x265A){
				verificadorb = 1;
			}
			if(tabuleiro[i][j] == 0x2654){
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
			if(tabuleiro[1][i] == 0x265F){
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
						tabuleiro[1][i] = 0x265C;
						break;
					case cavalo:
						tabuleiro[1][i] = 0x265E;
						break;
					case bispo:
						tabuleiro[1][i] = 0x265D;
						break;
					case rainha:
						tabuleiro[1][i] = 0x265B;
						break;
					default:
						printf("Escolha não reconhecida, Escreva novamente\n");
						erro = 0;
						break;
				}
			}
			if(tabuleiro[8][i] == 0x2659){
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
						tabuleiro[8][i] = 0x2656;
						break;
					case cavalo:
						tabuleiro[8][i] = 0x2658;
						break;
					case bispo:
						tabuleiro[8][i] = 0x2657;
						break;
					case rainha:
						tabuleiro[8][i] = 0x2655;
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
				wprintf(L"\t %lc  ", tabuleiro[i][j]);
			}else if( i == 0){
				wprintf(L" %lc  ", tabuleiro[i][j]);
			}else if(j == 0){
				wprintf(L" %lc \t", tabuleiro[i][j]);
			}else if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)){
				wprintf(L"{%lc} ", tabuleiro[i][j]);
			}else{
				wprintf(L"[%lc] ", tabuleiro[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}
void undo_jogada(wchar_t *original, wchar_t* copia, int desfazer_jogada, int tamanho){
	int i = 0;
	if(!desfazer_jogada){
		while(i<tamanho){
			*(copia+i) = *(original+i);
			i++;
		}
	}else{
		while(i<tamanho){
				*(original+i) = *(copia+i);
				i++;
		}
	}
}
int verificador_de_movimento(criar tabuleiro,int ix, int iy, int dx, int dy){
	wchar_t peca = tabuleiro[iy][ix];
	int result = 1;
//	printf("peca: %c, iy:%d,dy:%d , iy-1:%d\n",peca, iy, dy, iy+1);

	if(peca == 0x265F){
		if(iy == 7){
			if(tabuleiro[dy][dx] != ' '){
				if(dy == iy-1 || dy == iy-2){
					if(dx == ix){
						result = 1;
					}
				}
			}
		}else if(dy == iy-1){
			if(dx == ix){ 
				result = 1;
			}else{ result = 0;}
			if(tabuleiro[dy][dx] != ' '){
				if(dx == ix-1 || dx == ix + 1){
					result = 1;
				}else{ result = 0;}
			}
		}else{ result = 0;}
	}
	if(peca == 0x2659){
		if(iy == 2){
			if(tabuleiro[dy][dx] != ' '){
				if(dy == iy+1 || dy == iy+2){
					if(dx == ix){
						result = 1;
					}
				}
			}
		}else if(dy == iy+1){
			if(dx == ix){ 
				result = 1;
			}else{ result = 0;}
			if(tabuleiro[dy][dx] != ' '){
				if(dx == ix-1 || dx == ix + 1){
					result = 1;
				}else{ result = 0;}
			}
		}else{ result = 0;}
	}

	return result;
}
int partida(criar tabuleiro){
	criar copia_tabuleiro;
	organizar_tabuleiro(copia_tabuleiro);
	char c;
	char inicio[10], destino[10];
	int ix,iy,dx,dy;
	int  contador = 0, vencedor = 0, tamanho = 81;
	do{
		int jogou = 0, desfazer_jogada = 0, valido = 1;
		system("clear");
		imprimir_tabuleiro(tabuleiro);
//		imprimir_tabuleiro(copia_tabuleiro);
		do{
			if(c == '\n') clearbuffer();
			printf("Insira a coordenada da peça para mover:\n");
			scanf("%s",inicio);
			if(c != '\n') clearbuffer();
			if(!strstr(inicio, "desfazer")){
				printf("Insira a coordenada destino:\n");
				scanf("%s",destino);
				if(c != '\n') clearbuffer();
				iy = coordenadas(inicio, &contador);
				ix = coordenadas(inicio, &contador);
				dy = coordenadas(destino, &contador);
				dx = coordenadas(destino, &contador);
				valido = verificador_de_movimento(tabuleiro,ix,iy,dx,dy);
				undo_jogada(&tabuleiro[0][0],&copia_tabuleiro[0][0],desfazer_jogada, tamanho);
//				pausar();
			}
			if(strstr(inicio, "desfazer") || strstr(destino, "desfazer")){
				desfazer_jogada = 1;
				undo_jogada(&tabuleiro[0][0],&copia_tabuleiro[0][0],desfazer_jogada, tamanho);
				pausar();
				break;
			}else if(ix == 0 || iy == 0 || dx == 0 || dy == 0){
				printf("Insira as coordenadas corretamente, coluna e linha e sem espaços.\n");
			}else if(ix == dx && iy == dy){
				printf("A peça não foi movida.\n");
//				printf("ix:%d\tdx:%d\tiy:%d\tdy:%d\n",ix,dx,iy,dy);
				break;
			}else if(!valido){
				printf("movimento invalido, pressione qualquer tecla para continuar...\n");
				getchar();
				break;
			}else{
				tabuleiro[dy][dx] = tabuleiro[iy][ix];
				tabuleiro[iy][ix] = ' ';
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
		organizar_tabuleiro(tabuleiro);
		do{
			system("clear");
			saida = partida(tabuleiro);
			organizar_tabuleiro(tabuleiro);
		}while(saida);
	printf("Obrigado por jogar!!!\n");
	}else{
		printf("Até a proxima!!\n");
	}
}
int main(){
	setlocale(LC_CTYPE,"");
	jogo_xadrez();
	return 0;
}
