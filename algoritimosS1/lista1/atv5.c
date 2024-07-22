/*
objetivo:5.Um pequeno produtor rural quer
vender dois bois para abate, pois precisa
fazer receita e pagar suas despesas mensais.
O seu funcionário selecionou 10 animais 
para serem pesados na esperança de que
nesse grupo tenham dois animais ideiais para
serem abatidos.

Caso dois animais em condições ideias sejam
encontrados, calcule a receita que o produtor
irá obter com a sua venda. Caso contrário,
informe ao produtor que um novo grupo de
animais precisa ser selecionado para o
processo de pesagem.


• O valor da arroba do boi está cotado hoje em
R$ 232,60.
• Peso ideal do boi para abate >= 600 quilos.
• Cálculo da receita = Quantidade x Preço.
• Imprima na console o valor da receita.
Imprima na console quantos bois foram pesados.
•Informe ao usuário se o processo teve sucesso
ou não.
*/
// 1 arroba = 15kg
#include <stdio.h>
#include <stdlib.h>

float pesagem (int k){
    const float VALOR_ARROBA = 232.60, ARROBA = 15, BOI_IDEAL=600;
    int i, j, boi_ideal = 0;
    float peso_boi, b1, b2, preço, arroba;
    while(i < 10){
        printf("Insira o peso do boi: \n");
        scanf("%f", &peso_boi);
        if(peso_boi >= BOI_IDEAL){
            boi_ideal += 1;
            if(boi_ideal == 1){
                b1 = peso_boi;
            }
        }
        if( boi_ideal == 2){
            i = 11;
            b2 = peso_boi;
        }
        j += 1;
    }
    peso_boi = b1 + b2;
    arroba = peso_boi / ARROBA;
    preço = VALOR_ARROBA*arroba;
    if ( k == 0){
        return preço;
    }else if(k == 1){
        return j;
    }else if(k == 2){
        if(boi_ideal < 2){
            j = 1;
            return j;
        }else{
            j = 2;
            return j;
        }
    }
}
int main () {
    printf("O valor com a vendo será: %.2f\n",pesagem(0));
    printf("Foram pesados um total de %f bois", pesagem(1));
    if(pesagem(2) == 1){
	printf("Não tem a quantidade necessária de bois ideais no rebanho, solicite uma nova pesagem.");
    }else{
	printf("Tem 2 bois com o peso ideal para a venda.");
    }
    return 0;
}
