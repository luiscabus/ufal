#include <stdio.h>

void decrescente(int n)
{
	printf("%d\n", n);
	if (n == 0)
	{
		return;
	}
	return decrescente(n - 1);
}

void crescente(int n)
{
	if (n == -1)
	{
		return;
	}
	crescente(n - 1);
	printf("%d\n", n);
}

int somaaten(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + somaaten(n - 1); //
}

int fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else 
	{
		return fibonacci(n - 1) + fibonacci(n - 2); //
	}
}

void fiban(int n)
{
	if (n == -1)
	{
		return;
	}
	fiban(n - 1);
	printf("Para n=%d, fib=%d\n", n, fibonacci(n) );
}

int piramide(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + piramide(n - 1); //
}

int multiplicar(int n, int m)
{
	if (n == 0)
	{
		return 0;
	}

	return m + multiplicar(n - 1, m);
}

int digitos(int n)
{
	if (n / 10 < 1)
	{
		return 1;
	}

	return 1 + digitos(n / 10);
}













int fat(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}

	return n * fat(n - 1);
}

void echo(int n)
{
	if (n == 999 || n == 9 || n == 5)
	{
		printf("saindoooo...\n");
		return;
	}
	else
	{
		printf("%d\n", n);
	}

	scanf("%d", &n);
	echo(n);
}

int main()
{
	// Clear Screen before code output
	printf("\033c");

	int a, b;
	printf("Digite um número inteiro:\n");
	scanf("%d", &a);

	printf("DECRESCENTE: \n");
	decrescente(a);
	
	printf("CRESCENTE: \n");
	crescente(a);

	printf("SOMAN: \n");
	printf("%d\n", somaaten(a) );

	if (a < 15)
	{
		printf("FIBONACCI: \n");
		printf("%d\n", fibonacci(a) );

		printf("FIBONACCI a N: \n");
		fiban(a);
	}

	printf("PIRÂMIDE: \n");
	printf("%d\n", piramide(a) );

	// scanf("%d", &b);
	b = 4;
	printf("MULTIPLICAR: \n");
	printf("%d\n", multiplicar(a, b) );	

	printf("DIGITOS: \n");
	printf("%d\n", digitos(a) );	





	printf("FAT: \n");
	printf("%d\n", fat(a) );

	printf("ECHO: \n");
	echo(a);
	return 0;
}