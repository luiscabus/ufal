#include<stdio.h>
#include<math.h>

void raiz4(){
	printf("A raiz quadrada de %d é %.0f\n", 4, sqrt(4));
}
void raiz9(){
	printf("A raiz quadrada de %d é %.0f\n", 9, sqrt(9));
}
void raiz25(){
	printf("A raiz quadrada de %d é %.0f\n", 25, sqrt(25));
}
void raiz41(){
	printf("A raiz quadrada de %d é %.0f\n", 41, sqrt(41));
	printf("A raiz quadrada de %d é %.4f\n", 41, sqrt(41));
}


void raizquadrada(int numero){
	printf("A raiz quadrada de %d é %.4f\n", numero, sqrt(numero));
}
void raizquadrada2(){
	int numero;
	printf("Digite um número para calcular a raiz quadrada: \n");
	scanf("%d", &numero);
	printf("A raiz quadrada de %d é %.4f\n", numero, sqrt(numero));
}


int main(){
// 	printf("A soma entre %d e %d é: %d\n");
//  	printf("A soma entre %d e %d é: %d\n", 3, 5, 35);
	printf("A soma entre %d e %d é: %d\n", 3, 5, 3+5);
	
// 	printf("A raiz quadrada de %d é %.0f\n", 4, sqrt(4));
// 	printf("A raiz quadrada de %d é %.0f\n", 9, sqrt(9));
// 	printf("A raiz quadrada de %d é %.0f\n", 25, sqrt(25));
	
	raiz4();
	raiz9();
	raiz25();
	raiz41();
	
	raizquadrada(81);
	raizquadrada2();
		
	return 0;
} 
// ## Para compilar com a biblioteca math.h usar -lm ao final da expressão
// gcc 20180206.c -o 20180206 -lm  

// https://www.w3resource.com/c-programming-exercises/basic-declarations-and-expressions/index.php
// http://linguagemc.com.br/a-biblioteca-math-h/