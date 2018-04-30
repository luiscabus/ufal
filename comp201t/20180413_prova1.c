#include <stdio.h>
#include <math.h>

int compare_double(double f1, double f2)
{
	double precision = 0.000000001;
	if (((f1 - precision) < f2) && 
		((f1 + precision) > f2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


double whatdelta(int a, int b, int c) { // b2 - 4 a c
	return (1.00 * (b * b) - (4 * a * c));
}

double raizes(int a, int b, int c, double raizdedelta, int nraiz) { // -b +- rDelta // 2a
	double numerador, denominador, resultado;
	numerador = 1.00 * (-b + raizdedelta);
	denominador = 1.00 * (2 * a);
	resultado = 1.00 * numerador / (double)denominador;

	// printf("numerador %lf denominador %lf\n", numerador, denominador);
	printf("X");
	if (nraiz == 1){
		printf("1");
	}
	if (nraiz == 2){
		printf("2");
	}

	if (numerador /(double)denominador == 0) {
		printf(" = 0.00\n");
	} else {
		printf(" = %.2lf\n", numerador /(double)denominador);
	}

	// printf(" = %.2lf\n", round( numerador/(double)denominador * 100 ) / 100 );

	return 0;
}



void scanline(int equacoes, int rolling) {
	if (equacoes == 0) {return;}

	printf("\nTest %d: ", rolling);

	int a, b, c;
	char sinb, sinc;
	scanf("%dx^2 %c %dx %c %d", &a, &sinb, &b, &sinc, &c);
	// printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("%dx^2 %c %dx %c %d\n", a, sinb, b, sinc, c);

	if (a == 0) {
		if (b == 0) {
			printf("SEM RESPOSTA\n");
			scanline(equacoes - 1, rolling + 1);
			return;
		} else {
			printf("X = ");
			printf("%.2lf\n", (-c/(double)b) );
			scanline(equacoes - 1, rolling + 1);
			return;
		}
	}

	double delta;
	delta = whatdelta(a, b, c);
	// printf("Delta %lf\n", delta);
	
	double raizdedelta;
	raizdedelta = sqrt(delta);
	// printf("Raiz de Delta %lf\n", raizdedelta);

	if (isnan(raizdedelta)) {
		printf("SEM RESPOSTA\n");
	} else {

		if (compare_double(raizdedelta, 0.000000)) {
			raizdedelta = 0;
		}
		

		if (raizdedelta == 0) {
			raizes(a, b, c, raizdedelta, 0);
		}

		if (raizdedelta != 0) {
			raizes(a, b, c, raizdedelta, 1);
			raizes(a, b, c, -raizdedelta, 2);
		}
	}

	

	scanline(equacoes - 1, rolling + 1);
}



int main()
{
	int nequacoes;
	scanf("%d", &nequacoes);
	
	scanline(nequacoes, 1);

	return 0;
}