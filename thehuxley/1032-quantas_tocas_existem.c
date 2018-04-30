#include <stdio.h>

void buildArray(int array[], int i, int lim_superior) {
	if (i > lim_superior) {
		return;
	}
	scanf("%d", &array[i]);
	buildArray(array, i + 1, lim_superior);
}

void printArray(int array[], int i, int lim_superior) {
	if (i > lim_superior) {
		return;
	}
	printf("Posição %d vale %d\n", i, array[i]);
	printArray(array, i + 1, lim_superior);
}

int isthatinArray(int my_array[], int posicao, int procurado) {
	if (posicao < 0) {return 0;}
	if (my_array[posicao] == procurado) {return 1;}
	return isthatinArray(my_array, posicao - 1, procurado);
}

void gothroughHoles(int array[], int i, int lim_superior, int primburaco, int tocas) {
	if (i > lim_superior - 1) {
		// printf("Tocas: ");
		printf("%d\n", tocas);
		return;
	}
	// printf("Primeiro buraco dessa toca: %d\n", primburaco);
	// printf("Posição %d vale %d\n", i, array[i]);

	if (array[i] == primburaco) {
		tocas++;
		primburaco = array[i+1];
		i++; 
	}

	gothroughHoles(array, i + 1, lim_superior, primburaco, tocas);
}


int main() {

	int buracos;
	scanf("%d", &buracos);

	int array_buracos[buracos];
	buildArray(array_buracos, 0, buracos - 1);
	// printArray(array_buracos, 0, buracos - 1);
	gothroughHoles(array_buracos, 0, buracos - 1, 0, 1);

	return 0;
}