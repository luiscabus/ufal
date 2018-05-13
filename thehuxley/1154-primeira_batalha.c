#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>




int main() {
	int a1, a2, a3;
	scanf("%d %d %d", &a1, &a2, &a3);

	int vitoria;
	vitoria == 0;

	if (a1 > 10 || a2 > 10 || a3 > 10)
	{
		++vitoria;
	}

	if (a1 % 2 == 0 || a2 % 2 == 0 || a3 % 2 == 0)
	{
		++vitoria;
	}

	if (a1 == 0 || a2 == 0 || a3 == 0)
	{
		printf("Não\n");
		return 0;
	}

	if (vitoria == 2) {
		printf("Sim\n");
		return 0;
	} else {
		printf("Não\n");
	}


	return 0;
}