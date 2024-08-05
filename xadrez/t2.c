#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char string[] = "ola";
	int len = strlen(string);
	int size = sizeof(string);

	printf("%d\n%d\n", len, size);

	return 0;
}
