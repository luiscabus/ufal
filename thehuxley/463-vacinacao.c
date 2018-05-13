#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void vacina(int sarampo, int hepatite, int criancas, int idade) {
	scanf("%d", &idade);
	if (idade == 100)
	{
		printf("%d\n", sarampo);
		printf("%d\n", hepatite);
		printf("%d\n", criancas);
		return;
	}

	if (idade >= 3 && idade <= 6)
	{
		++sarampo;
	}

	if (idade >=5 && idade <= 8)
	{
		++hepatite;
	}

	if (idade == 5 || idade == 6)
	{
		++criancas;
	}

	return vacina(sarampo, hepatite, criancas, idade);
}

int main() {
	vacina(0, 0, 0, 0);
	return 0;
}