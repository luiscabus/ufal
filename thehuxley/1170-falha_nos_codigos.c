#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	char pokenome[10];
	scanf("%s", pokenome);

	if (pokenome[6] == 'b')
	{
		printf("Bulbassauro\n");
		return 0;
	}

	if (pokenome[6] == 'c')
	{
		printf("Charmander\n");
		return 0;
	}

	if (pokenome[6] == 's')
	{
		printf("Squirtle\n");
		return 0;
	}

	printf("Codigo Invalido\n");

	return 0;
}