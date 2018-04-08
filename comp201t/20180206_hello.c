#include <stdio.h>
// #include <stdlib.h>
#define PI 3.1415

int main(void) {

	printf("\n");
	printf("Meu primeiro programa C - PI é %.4f\n", PI);

	char letra = 'a';
	int nro = 10;
	float n = 5.25;

	//%d é para Inteiro, mas permite imprimir caractere
	printf("Caractere %c, Inteiro %d, Inteiro+10 %d, Número Real Float %.3f\n\n", letra, nro, nro+10, n);


	printf("Digite dois números \n");
	scanf(" %d%f", &nro, &n);
	printf("Valor digitado: inteiro %d e float: %f\n\n", nro, n);



	// int x = 5, y = 3;
	// printf("Resultado %d\n", x > 4);
	// printf("Resultado %d\n", x > y + 4); //falso
	// printf("Resultado %d\n", x == 4); //falso
	// printf("Resultado %d\n", x - 2 != y); //falso

	// printf("Resultado %d\n", x - 2 == y && y + 2 == x); //verdadeiro
	// printf("Resultado %d\n", x - 2 == y || y - 2 == x); //verdadeiro
	// printf("Resultado %d\n", !(x - 2 == y || y - 2 == x) ); //verdadeiro mas invertido



	int user_input = nro, par_ou_impar;
	// printf("Digite um valor inteiro\n");
	// scanf(" %d", &user_input);

	par_ou_impar = user_input % 2;
	if (par_ou_impar == 0) {
		printf("O número %d é Par ", user_input);
	} else {
		printf("O número %d é Ímpar ", user_input);
	}

	if (user_input > 10)
	{
		printf("e é maior que 10");
	} else {
		printf("e é menor do que 10");
	}
	printf("\n\n");


	int var_terciario;
	var_terciario = 10 > 2 ? 15 : 6 ;
	printf("%d\n", var_terciario);

	(10 > 2) ? printf("Dez é maior que dois\n")
				: printf("Dez não é maior que dois\n");
	printf("\n");



	char var_caractere;
	printf("Digite um caractere de pontuação\n");
	scanf(" %c", &var_caractere); //Atenção ao espaço antes do %c caractere, para comer os espaços e caracteres especiais (tipo o ENTER do scanf anterior)
	switch( var_caractere ) {
		case '.': printf("Ponto\n"); break;
		case ':': printf("Dois pontos\n"); break;
		case ',': printf("Vírgula\n"); break;
		case ';': printf("Ponto e vírgula\n"); break;
		default : printf("Não é pontuação\n");
	}
	printf("\n");





	int var_numeromenorque10 = user_input;
	// printf("Digite um número menor que 10\n");
	// scanf("%d", &var_numeromenorque10);
	if (var_numeromenorque10 < 10) {
		while( var_numeromenorque10 < 10 ){
			++var_numeromenorque10;
			printf("%d\n", var_numeromenorque10);
		}
	}





	// system("pause");
	
	return 0;
}

// clang -Wall -o hello hello.c
// ./hello