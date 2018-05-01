#include <stdio.h>
#include <stdlib.h>

int biarray(int linha_max, int coluna_max, double banco_array[][coluna_max], int linha, int coluna)
{
	if(coluna == coluna_max || (linha == linha_max))
	{
		if(linha == linha_max)
		{
			return 0;
		}
		return biarray(linha_max, coluna_max, banco_array, linha + 1, 0);
	}

	double auxe;
	scanf(" %lf", &auxe);

	if (auxe == -1) 
	{
		return linha;
	}
	
	banco_array[linha][coluna] = auxe;

	return biarray(linha_max, coluna_max, banco_array, linha, coluna + 1);
}

void gocomando(double saldos[], int col, double banco[][col], int i, int limite) 
{
	if (i == limite) {return;}

	if (banco[i][0] == 1) {
		// Crédito
		saldos[0] =  saldos[0] + (double)banco[i][1];
		saldos[2] =  saldos[2] + (double)banco[i][1];
	}
	if (banco[i][0] == 0) {
		// Crédito
		saldos[1] =  saldos[1] + (double)banco[i][1];
		saldos[2] =  saldos[2] - (double)banco[i][1];
	}


	gocomando(saldos, col, banco, i + 1, limite);
}

int main() 
{
	int linha, coluna;
	linha = 100;
	coluna = 2;

	int qtdop;
	qtdop = 0;

	double banco[linha][coluna];
	qtdop = biarray(linha, coluna, banco, 0, 0);

	double saldos[3];
	saldos[0] = 0.00;
	saldos[1] = 0.00;
	saldos[2] = 0.00;

	gocomando(saldos, coluna, banco, 0, qtdop);

	printf("Creditos: R$ %.2f\n", saldos[0]);
	printf("Debitos: R$ %.2f\n", saldos[1]);
	printf("Saldo: R$ %.2f\n", saldos[2]);

}