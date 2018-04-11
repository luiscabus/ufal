#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int scanline(int inteiro) {
	scanf("%d", &inteiro);
	if (inteiro == 0) {
		return 0;
	}
	printf("%d\n", funcao(inteiro, 1));
	scanline(0);
}


int funcao(int parametro1, int contador) {
	if (parametro1 == 0) {
		return 0;
	}
	
	int resto = parametro1 % 2;
	
	if ( resto == 0){
		return (parametro1 % 10) * 2 * contador + funcao(parametro1 / 10, contador + 1);   
	}
	else {
		return (parametro1 % 10) * 3 * contador + funcao(parametro1 / 10, contador + 1);   
	}
}


int main() {
	
	scanline(0);
	
	return 0;
}