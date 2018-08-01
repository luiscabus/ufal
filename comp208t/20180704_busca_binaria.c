#include <stdio.h>

int binary_search(int array[], int size, int procurado) {
	int begin = 0;
	int end = size - 1;
	int middle;

	while (begin <= end) {
		middle = (begin + end) / 2;

		printf("Cortei em %d\n", middle);

		if (array[middle] < procurado) {
			begin = middle + 1;
		} else if (array[middle] > procurado) {
			end = middle - 1;
		} else {
			return middle;
		}
	}
	return -1;
}

int main() {

	int arrs = 200;
	int array[arrs];
	int i;
	
	for (i = 0; i < arrs; ++i)
	{
		array[i] = i + 1;
	}

	printf("Array Original:\n");
	for (i = 0; i < arrs; ++i)
	{
		printf("Pos %d Val %d \n", i, array[i]);
	}

	int posicao;
	printf("Que número deseja encontrar? (1-200)\n");
	scanf(" %d", &posicao);
	posicao = binary_search(array, arrs, posicao);
	printf("Posição %d\n", posicao );

	return 0;
}