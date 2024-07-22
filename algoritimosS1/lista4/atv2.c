/*
objetivo: 2. Crie um programa que leia do teclado seis valores inteiros e em seguida, dë ao usuário a opção de exibir na tela os valores lidos na ordem de leitura ou na ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inversor(int num[], int tamanho){
	int fim = tamanho - 1;
	int i = 0;
        while( i < fim){
                int temp = num[i];
                num[i] = num[fim];
                num[fim] = temp;
		i++;
		fim--;
        }
}

void codigo (){
        enum escolha{
                normal,
                invertida
        };
        int num[6];
        char escolha[10];
        int opcao;
        int tamanho;

        printf("Insira 6 números inteiros: \n");
        for(int i = 0;i<6;i++){
                scanf("%d", &num[i]);
        }
        tamanho = (sizeof(num)/ sizeof(num[0]));
        printf("Escolha se quer imprimir na ordem normal ou invertida?\n");
      scanf("%s", escolha);

        if( strstr(escolha,"normal")){
                opcao = 0;
        }else if(! strcmp(escolha,"invertida")){
                opcao = 1;
        }
        switch (opcao){
                case normal:
                        for(int i = 0; i<6;i++){
                                printf("%d\n", num[i]);
                        }
                        break;
                case invertida:
			inversor(num, tamanho);
                        for(int i=0; i<tamanho ;i++){
                                printf("%d\n", num[i]);

                        }
                        break;
        }
}
int main (){
        codigo();
        return 0;
}
