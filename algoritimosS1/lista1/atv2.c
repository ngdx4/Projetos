/*
objetivo:Receba do usuário via console uma
sequência de números inteiros até que
5 números impares sejam lidos.

•Imprima o primeiro número impar lido.
•Imprima o último número impar lido.
•Imprima quantas vezes o laço precisou ser repetido.
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    struct {
        int num, primeiro, i, j;
    } variaveis;

    variaveis.j = 0;

    while(variaveis.i < 5){
        printf("Insira um numero inteiro: \n");
        scanf("%d", &variaveis.num);
        if(variaveis.num % 2 == 1){
            variaveis.i += 1;
            if(variaveis.i == 1){
                variaveis.primeiro = variaveis.num;
            }
        }
        variaveis.j += 1;
    }
    printf("O primeiro número ímpar lido é %d.\n", variaveis.primeiro);
    printf("O ultimo número impar lido é %d.\n",variaveis.num);
    printf("O laço de repetição rodou %d vezes.\n", variaveis.j);
    return 0;
}
