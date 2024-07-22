/*
objetivo:Receba do usuário via console
as variáveis m, x e n do tipo float e calcule
o valor de y.

• Equação reduzida da reta é y = mx + n.
*/
#include <stdio.h>
#include <stdlib.h>

float valor_de_y (){
    struct{
        float x,m,n,y;
    } elemento;
    printf("Insira o valor do coeficiente angular: \n");
    scanf("%f", &elemento.m);
    printf("Insira o valor de x: \n");
    scanf("%f", &elemento.x);
    printf("Insira o valor do coeficiente linear: \n");
    scanf("%f", &elemento.n);
    elemento.y = elemento.m*elemento.x + elemento.n;
    return elemento.y;
}

int main () {
    printf("O valor de y é %f\n", valor_de_y());
    return 0;
}
