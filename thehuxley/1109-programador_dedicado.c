#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void produtividade(int programas, int codigos, int *diametasprograma, int *diametascodigo, int *diamaisprodutivo, int *linhasdecodigo, int linhas) {
	int cumpriu = 0;

	if (programas >= 5) {
		// printf("Cumpriu meta de programas hoje \n");
		*diametasprograma = *diametasprograma + 1;
		cumpriu = cumpriu + 1;
	}
	if (codigos >= 100) {
		// printf("Cumpriu meta de linhas hoje \n");
		*diametascodigo = *diametascodigo + 1;
		cumpriu = cumpriu + 1;
	}

	if (*linhasdecodigo <= codigos) {
		*linhasdecodigo = codigos;
		*diamaisprodutivo = linhas;
	}

	if (cumpriu != 2) {
		// printf("Não cumpriu meta hoje\n");
	}

	return;
}

void scanline(int linhas, int *diametasprograma, int *diametascodigo, int *diamaisprodutivo, int *linhasdecodigo){
	if (linhas == 0) { return; }

	int programas, codigos;
	scanf("%d %d", &programas, &codigos);

	// printf("Dia %d\n", linhas);
	
	produtividade(programas, codigos, diametasprograma, diametascodigo, diamaisprodutivo, linhasdecodigo, linhas);

	scanline(linhas - 1, diametasprograma, diametascodigo, diamaisprodutivo, linhasdecodigo);
}

int main()
{
	int diametasprograma;
	diametasprograma = 0;
	int diametascodigo;
	diametascodigo = 0;
	int diamaisprodutivo;
	diamaisprodutivo = 0;
	int linhasdecodigo;
	linhasdecodigo = 0;
	
	scanline(7, &diametasprograma, &diametascodigo, &diamaisprodutivo, &linhasdecodigo);

	printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n", diametasprograma);
	printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n", diametascodigo);
	// printf("DIA QUE MAIS PRODUZIU: %d > %d\n", diamaisprodutivo, linhasdecodigo);

	if (linhasdecodigo == 0) {
		printf("DIA QUE MAIS PRODUZIU: NENHUM\n");
		return 0;
	}

	switch( diamaisprodutivo ) {
		case 7: printf("DIA QUE MAIS PRODUZIU: DOMINGO\n"); break;
		case 6: printf("DIA QUE MAIS PRODUZIU: SEGUNDA\n"); break;
		case 5: printf("DIA QUE MAIS PRODUZIU: TERCA\n"); break;
		case 4: printf("DIA QUE MAIS PRODUZIU: QUARTA\n"); break;
		case 3: printf("DIA QUE MAIS PRODUZIU: QUINTA\n"); break;
		case 2: printf("DIA QUE MAIS PRODUZIU: SEXTA\n"); break;
		case 1: printf("DIA QUE MAIS PRODUZIU: SABADO\n"); break;
		default : printf("DIA QUE MAIS PRODUZIU: SABADO\n");
	}

	return 0;
}