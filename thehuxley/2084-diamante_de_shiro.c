#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// 2
// .*.
// *.*
// .*.

// 3
// ..*..
// .*.*.
// *.*.*
// .*.*.
// ..*..

// 4
// 7 // ...*... 4 ; 4 * 2 - 7
// 6 // ..*.*.. 3 5 ; 4 * 2 - 6
// 5 // .*.*.*. 2 4 6 ; 4 * 2 - 5
// 4 // *.*.*.* 1 3 5 7 ; 4
// 3 // .*.*.*. 2 4 6 ; 3
// 2 // ..*.*.. 3 5 ; 2
// 1 // ...*... 4 ; 1

// 5
// linha = raio * 2 - asteriscos
// raio + 4			9// ....*.... 5 ; 5 * 2 - 9 = 1
// raio + 3			8// ...*.*... 4 6 ; 5 * 2 - 8 = 2
// raio + 2			7// ..*.*.*.. 3 5 7 ; 5 * 2 - 7 = 3
// raio + 1			6// .*.*.*.*. 2 4 6 8 ; 5 * 2 - 6 = 4
// raio				5// *.*.*.*.* 1 3 5 7 9 ; 5
// raio - 1			4// .*.*.*.*. 2 4 6 8 ; 4
// raio - 2			3// ..*.*.*.. 3 5 7 ; 3
// raio - 3			2// ...*.*... 4 6 ; 2
// raio - 4			1// ....*.... 5 ; 1
// linha = raio - raio + asteriscos

void printColunas(int linha, int raio, int coluna, int asts) {
	if (coluna == 0) {
		printf("\n");
		return;
	}

	int condicao = 0;

	if (raio % 2 != 0) { // raio ímpar
		if (linha % 2 != 0) { // linha ímpar
			if ((coluna < raio + asts && coluna > raio - asts) && coluna % 2 != 0) { // distância da coluna do meio e posição ímpar
				condicao = 1;
			}
		}

		if (linha % 2 == 0) { // linha par
			if ((coluna < raio + asts && coluna > raio - asts) && coluna % 2 == 0) { // distância da coluna do meio e posição par
				condicao = 1;
			}
		}
	}

	if (raio % 2 == 0) { // raio par
		if (linha % 2 != 0) { // linha ímpar
			if ((coluna < raio + asts && coluna > raio - asts) && coluna % 2 == 0) { // distância da coluna do meio e posição ímpar
				condicao = 1;
			}
		}

		if (linha % 2 == 0) { // linha par
			if ((coluna < raio + asts && coluna > raio - asts) && coluna % 2 != 0) { // distância da coluna do meio e posição par
				condicao = 1;
			}
		}
	}





	// if (linha == raio) { //linha do meio
	// 	if (coluna % 2 != 0) { // coluna ímpar
	// 		condicao = 1;
	// 	}
	// }

	// if (coluna == raio) { // coluna do meio
	// 	if (linha % 2 != 0) {
	// 		condicao = 1;
	// 	}
	// }

	// if (linha % 2 == 0) { //linha par
	// 	if (coluna == raio - asts + 1 || coluna == raio + asts - 1) {
	// 		condicao = 1;
	// 	}
	// }




	// if (linha % 2 != 0) { //linha ímpar
	// 	if (coluna == raio) {
	// 		condicao = 1;
	// 	}
		
	// }

	// if (linha == raio + 1 || linha == raio - 1) {
	// 	if (coluna % 2 == 0) { // coluna par
	// 		condicao = 1;
	// 	}
	// }

	switch( condicao ) {
		case 1: printf("*"); break;
		default : printf(".");
	}




	// int ascos1;
	// if (linha > raio) {
	// 	ascos1 = raio * 2 - linha;
	// } else {
	// 	ascos1 = linha;
	// }

	// int ascos2;
	// if (coluna > raio) {
	// 	ascos2 = raio * 2 - coluna;
	// } else {
	// 	ascos2 = coluna;
	// }

	// if (linha % 2 == 0) { //linhas pares, . no centro
	// 	if (coluna % 2 == 0) {
	// 		printf(" ... ");
	// 	} else {
	// 		printf(" p%d%d ", ascos1, ascos2);
	// 	}
	// } else { //linhas ímpares, * no centro
	// 	if (coluna % 2 != 0) {
	// 		printf(" *** ");
	// 	} else {
	// 		printf(" i%d%d ", ascos1, ascos2);
	// 	}
	// }





	// printf(" L%dC%d ", ascos1, ascos2);

	// printf(" L%d", ascos);
	// printf("C%d ", ascos2);

	// if (ascos == ascos2) {
	// 	printf(" **** ");
	// } else {
	// 	printf(" L%dC%d ", ascos1, ascos2);
	// }
	

	// if ( (linha + 1 / 2 == raio) ) {
	// 	if (coluna % 2 != 0) {
	// 		printf("*");
	// 	} else {
	// 		printf(".");
	// 	}
	// } else {
	// 	printf("%d", coluna);
	// }

	// if (coluna + 1 / 2 == raio) {
	// 	if (linha % 2 != 0) {
	// 		printf("*");
	// 	} else {
	// 		printf(".");
	// 	}
	// } else {
	// 	printf("%d", coluna);
	// }

	// if ( (coluna + 1 / 2 == raio) ) {
		// if (linha % 2 != 0) {
		// 	printf("*");
		// } else {
		// 	printf(".");
		// }
	// } 

	// if ( (linha + 1 / 2 == raio) ) {
	// 	if (coluna % 2 != 0) {
	// 		printf("*");
	// 	} else {
	// 		printf(".");
	// 	}
	// }

	printColunas(linha, raio, coluna - 1, asts);
}

void printLinhas(int raio, int linha) {
	if (linha == 0) {
		return;
	}

	int asteriscos;
	if (linha > raio) {
		asteriscos = raio * 2 - linha;
	} else {
		asteriscos = linha;
	}

//	printf("Linha %d %d*asts: ", linha, asteriscos);
	printColunas(linha, raio, raio * 2 - 1, asteriscos);

	return printLinhas(raio, linha - 1);
}

void diamante(int raio) {
	printLinhas(raio, raio * 2 - 1);
}

int main() {
//	printf("\033c"); //Clear terminal before code output
	
	int raio;

	//Informe o tamanho do diamante
	scanf("%d", &raio);

	diamante(raio);

	return 0;
}