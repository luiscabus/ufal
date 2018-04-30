#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void buildArray(int array[], int i) {
	if (i < 0) {
		return;
	}
	scanf("%d", &array[i]);
	buildArray(array, i - 1);
}

void printArray(int array[], int i) {
	if (i < 0) {
		return;
	}
	printf("Posição %d vale %d\n", i, array[i]);
	printArray(array, i - 1);
}

int biggest(int array[], int i, int controle) {
	if (i < 0) {
		return controle;
	}
	if (array[i] > controle) {
		controle = array[i];
	}
	return biggest(array, i-1, controle);
}

int smallest(int array[], int i, int controle) {
	if (i < 0) {
		return controle;
	}
	if (array[i] < controle) {
		controle = array[i];
	}
	return smallest(array, i-1, controle);
}

int main() {
	int array[6-1];
	buildArray(array, 6-1);

	// printArray(array, 6-1);

	int maior;
	maior = biggest(array, 6-1, 0);

	int menor;
	menor = smallest(array, 6-1, maior);
	printf("%d\n", menor);
	printf("%d\n", maior);

	// printf("%s", string);
	return 0;
}