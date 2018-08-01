#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void quick_sort(int *v, int size, int side) {
	int aux;

	if (size <= 1) {
		return;
	} else {
		int pivot = v[size / 2];
		int a = 0;
		int b = size - 1;
		
		while (a < b) {
			while (v[a] < pivot) a++;
			while (v[b] > pivot) b--;
			
			if (a < b) {
				// swap(&v[a], &v[b]);
				aux = v[a];
				v[a] = v[b];
				v[b] = aux;
			}

			if (v[a] == v[b]) {
				++a;
			};
		}

		quick_sort(v, b, 0);
		quick_sort(v+a, size - a, 1);

	}
}

int main() {

	int array_size = 10;
	int array[array_size];
	int i;
	
	// for (i = 0; i < array_size; ++i)
	// {
	// 	array[i] = array_size - i;
	// 	// printf("array[%d]\n", i);
	// }

	array[0] = 9;
	array[1] = 1;
	array[2] = 6;
	array[3] = 7;
	array[4] = 9;
	array[5] = 9;
	array[6] = 88;
	array[7] = 9;
	array[8] = 1;
	array[9] = 0;


	printf("Array Original:\n");
	for (i = 0; i < array_size; ++i)
	{
		printf("Pos %d Val %d \n", i, array[i]);
	}

	quick_sort(array, array_size, -1);

	printf("Array após ordenação:\n");
	for (i = 0; i < array_size; ++i)
	{
		printf("Pos %d Val %d \n", i, array[i]);
	}
	


	return 0;
}