#include <stdio.h>

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

void makefibons(int fibons[], int i, int limite) {
	if (i == limite) {
		return;
	}
	fibons[i] = fibonacci(i);
	makefibons(fibons, i + 1, limite);
}

int belongtofibons(int fibons[], int i, int limite, int sujeito) {
	if (i == limite) {
		return 0;
	}

	if (fibons[i] == sujeito) {
		return	1;
	}

	return belongtofibons(fibons, i + 1, limite, sujeito);
}

void makenome(int n, int i, int fibons[]) {
	if (i == n) {
		return;
	}

	if ( belongtofibons(fibons, 0, 20, i+1) == 1 ) {
		printf("O");
	} else {
		printf("o");
	}

	makenome(n, i + 1, fibons);
}

int main() {

	int a;
	scanf("%d", &a);

	int fibons[20];
	makefibons(fibons, 0, 20);

	makenome(a, 0, fibons);

}