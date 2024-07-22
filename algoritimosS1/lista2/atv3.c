/*
objetivo: 3. Escreva um programa que receba a velocidade com que um motorista estava dirigindo em uma avenida. Calcule a multa que o motorista vai receber, considerando que são pagos R$ 5,00 por cada km/h que estiver acima da velocidade permitida.

Se a velocidade do motorista estiver dentro do limite, o programa deve informar que não há multa. A velocidade máxima permitida é de 60 km/h.

Imprima a velocidade do motorista.

Imprima a informação se haverá multa.

Imprima o valor da multa.
*/

#include <stdio.h>
#include <stdlib.h>

float valor_multa (float velocidade){
	const float LIMITE_VELOCIDADE = 60.0;
	const float MULTA = 5.0;
	if(velocidade <= LIMITE_VELOCIDADE){
		return 0;
	}else{
		return (velocidade - LIMITE_VELOCIDADE) * MULTA;
	}
}

void multa (){
	float velocidade;

	printf("CALCULO DE MUKTA\n");
	printf("Insira a sua velocidade na via durante o trajeto: \n");
	scanf("%f", &velocidade);
	printf("A sua velocidade era de %.2fKm/h\n", velocidade);
	if(valor_multa(velocidade)){
		printf("há multa e o valor é de %.2f Reais\n", valor_multa(velocidade));
	}else{
		printf("Não há multa\n");
	}
}
int main(){
	multa();
	return 0;
}
