/*
objetivo: Receba do usuário via console dez
número inteiro e ache qual é o menor e
qual é o maior.
*/
#include <stdio.h>
#include <stdlib.h>

int filtro (int j){
    struct{
    int min, max, temp;
    } num;
    num.temp = 0;
    if(!j){
        printf("Insira 10 números inteiros: \n");
        for(int i=0; i < 10; i++){
            scanf("%d", &num.temp);
            if(i == 0){
                num.min = num.temp;
            }else if(num.min > num.temp){
            num.min = num.temp;
            }else if(num.max < num.temp){
                num.max = num.temp;
            }
        }
    }
    if( j == 0 ){
        return num.min;
    }else{
        return num.max;
    }
}
int main () {
    printf("O valor minimo é %d e o valor máximo é %d.\n", filtro(0), filtro(1));
    return 0;
}
