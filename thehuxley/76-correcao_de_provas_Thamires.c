#include <stdio.h>

int comparador(char gabarito[], char prova[], float nota, int i)
{
	if(i > 9)
	{
		return nota;
	}

	if(gabarito[i] == prova[i])
	{
		nota++;
		return comparador(gabarito, prova, nota, i+1);
	}
	else
	{
		return comparador(gabarito, prova, nota, i+1);
	}

}

int comparador2(int resultado)
{

	if(resultado >= 6)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int comparador3(float notas[])
{  



}
void provas(int i, char gabarito[], int cont, int cont2, int notas[], int notas2[])
{
	char prova[12];
	int num;
	int resultado;
	scanf("%d", &num);
	if(num == 9999)
	{
		int alunos = cont2;
		cont = cont*100;
		float pct = cont/(alunos*1.0);
		printf("%.1f%\n", (float) pct);

		return;
	}
	else
	{
		scanf("%s", &prova);
		cont2++;
		resultado = comparador(gabarito, prova, 0, 0);
		notas[i] = resultado;
		notas2[resultado] = notas2[resultado] + 1;

		cont = cont + comparador2(resultado);

		printf("%d %.1f\n", num, (float) resultado);
		provas(i+1, gabarito, cont, cont2, notas, notas2);
	}
}

int maior(int notas[], int i, int maiorFreq, int maiorNota)
{
	if (i == 11) {
		return maiorNota;
	}
	else
	{
		if (notas[i] > maiorFreq)
		{
			maiorFreq = notas[i];
			maiorNota = i;
		}

		return maior(notas, i+1, maiorFreq, maiorNota);
	}
}

int main()
{
	char gabarito[12];
	scanf("%s", &gabarito);
	float notas[100];
	int notas2[11] = {};
	provas(0, gabarito, 0, 0, notas, notas2);
	printf("%.1f", (float) maior(notas2, 0, -1, -1));




	return 0;
}