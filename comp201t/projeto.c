#include <stdio.h>
// #include <stdlib.h>
#define PI 3.1415

int main(void) {

	printf("PI %f\n", PI);

	char letra = 'a';
	int nro = 10;
	float n = 5.25;



	printf("Meu primeiro programa C\n");
	printf("%c\n", letra); //Caractere
	printf("%d\n", letra); //Inteiro, mas caractere permite ser impresso por %d
	printf("%d\n", nro); //Inteiro
	printf("%f\n", n); //Número real 

	printf("Letra %c, inteiro %d, inteiro+10 %d, float %f\n", letra, nro, nro+10, n);


	// printf("Digite uma variável do tipo caractere\n");
	// scanf("%c", &letra);
	// printf("Valor digitado: %c\n", letra);

	printf("Digite dois números\n");
	scanf("%d%f", &nro, &n);
	printf("Valor digitado: %d e float: %f\n", nro, n);





	int x = 5, y = 3;
	printf("Resultado %d\n", x > 4);
	printf("Resultado %d\n", x > y + 4); //falso
	printf("Resultado %d\n", x == 4); //falso
	printf("Resultado %d\n", x - 2 != y); //falso

	printf("Resultado %d\n", x - 2 == y && y + 2 == x); //verdadeiro
	printf("Resultado %d\n", x - 2 == y || y - 2 == x); //verdadeiro
	printf("Resultado %d\n", !(x - 2 == y || y - 2 == x) ); //verdadeiro mas invertido




	int user_input;
	printf("Início do IF\n");
	printf("Digite um valor inteiro\n");
	scanf("%d", &user_input);

	if (user_input > 10)
	{
		printf("O valor é maior que 10\n");
	} else {
		printf("O valor é menor do que 10\n");
	}
	printf("Fim do IF\n");


	int var_terciario;
	var_terciario = 10 > 2 ? 15 : 6 ;
	printf("%d\n", var_terciario);

	(10 > 2) ? printf("Dez é maior que dois\n")
				: printf("Dez não é maior que dois\n");





	char var_caractere;
	printf("Digite um caractere de pontuação\n");
	scanf(" %c", &var_caractere); //Atenção ao espaço antes do %c caractere, para comer os espaços e caracteres especiais (tipo o ENTER do scanf anterior)
	switch( var_caractere ) {
		case '.': printf("Ponto\n"); break;
		case ':': printf("Dois pontos\n"); break;
		case ',': printf("Vírgula\n"); break;
		case ';': printf("Ponto e vírgula\n"); break;
		case '?': printf("Interroção\n"); break;
		default : printf("Não é pontuação\n");
	}



	
	int for_a;
	for( for_a = 1; for_a < 6; for_a = for_a + 1 ){
		printf("%d\n", for_a);
	}
	
	int while_b;
	while (while_b<5) {
		printf("%d\n", while_b);
		while_b++;
	}
	
	


	int var_numeromenorque30;
	printf("Digite um número menor que 30\n");
	scanf("%d", &var_numeromenorque30);
	if (var_numeromenorque30 < 30) {
		while( var_numeromenorque30 < 30 ){
			++var_numeromenorque30;
			printf("%d\n", var_numeromenorque30);
		}
	}





	// system("pause");
	
	return 0;
}

// clang -Wall -o hello hello.c
// ./hello