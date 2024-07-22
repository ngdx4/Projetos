/*
Objetivo: 5. Fazer um programa para calcular os números primos existentes entre os valores de 0 a 50.
*/

#include <stdio.h>
#include <stdlib.h>

int verificador_de_divisivel(int nt){
	
	for(int i = 2; i < nt; i++){
		if( nt % i == 0){
			return 0;
		}else{
			if(nt != 49){
				return printf("%d, ", nt);
			}else{
				return printf("%d.\n",nt);
			}
		}
	}
	if(nt == 2){
		return printf("%d, ", nt);
	}else{
		return 0;
	}
}
void numero_primo (){
	printf("NÚMEROS PRIMOS DE 0 ÁTE 50\n\n");
	for( int nt = 0; nt < 50; nt++){
		verificador_de_divisivel(nt);
	}
}

int main(){
	numero_primo();
	return 0;
}
