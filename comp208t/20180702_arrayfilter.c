#include <stdio.h>

void filter(int (*f)(int), int array[], int limite, int i) {
	if (i == limite) {
		return;
	}

	if ( (*f)(array[i]) != 1 ) {
		array[i] = -1;
	}

	filter((*f), array, limite, ++i);
}

int par(int x) {
	if (x % 2 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int maiorque8(int x) {
	if (x > 8) {
		return 0;
	} else {
		return 1;
	}
}


int main() {

	int array[14];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	array[5] = 6;
	array[6] = 7;
	array[7] = 8;
	array[8] = 9;
	array[9] = 10;
	array[10] = 11;
	array[11] = 12;
	array[12] = 13;
	array[13] = 14;

	int i;
	printf("Array Original: \n");

	for (i = 0; i < 14; ++i)
	{
		printf("Pos %d Val %d\n", i, array[i]);
	}

	filter(par, array, 14, 0);
	printf("Array filtrado par: \n");

	for (i = 0; i < 14; ++i)
	{
		printf("Pos %d Val %d\n", i, array[i]);
	}
	
	filter(maiorque8, array, 14, 0);
	printf("Array filtrado maiorque8: \n");
	
	for (i = 0; i < 14; ++i)
	{
		printf("Pos %d Val %d\n", i, array[i]);
	}
	

	return 0;
}