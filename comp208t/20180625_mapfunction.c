#include <stdio.h>

void map(int (*f)(int), int array[], int limite, int i) {
	if (i == limite) {
		return;
	}

	array[i] = (*f)(array[i]);

	map((*f), array, limite, ++i);
}

int square(int x) {
	return x * x;
}

int cube(int x) {
	return x * x * x;
}

int main() {

	int array[4];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;

	map(square, array, 4, 0);

	int i;

	for (i = 0; i < 4; ++i)
	{
		printf("Pos %d Val %d\n", i, array[i]);
	}
	
	map(cube, array, 4, 0);
	
	for (i = 0; i < 4; ++i)
	{
		printf("Pos %d Val %d\n", i, array[i]);
	}
	

	return 0;
}