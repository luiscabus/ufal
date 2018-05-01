#include <stdio.h>

int buildArray(int array[], int i, int lim_superior, float *media, int menorvalor, int *delta, int *somadiagonal, int positivos) {
	if (i > lim_superior) {
		*media = *media / (positivos);
		if (menorvalor % 2 == 0) {
			*delta = 1;
		} else {
			*delta = 0;
		}
		return menorvalor;
	}

	scanf("%d", &array[i]);

	if (array[i] > 0) {
		*media = *media + array[i];
		positivos = positivos + 1;
	}
	
	if (array[i] < menorvalor) {
		menorvalor = array[i];
	}

	if (i != 0 && i != 4 && i!= 8) {
		*somadiagonal = *somadiagonal + array[i];
	}


	return buildArray(array, i + 1, lim_superior, media, menorvalor, delta, somadiagonal, positivos);
}

void printArray(int array[], int i, int lim_superior) {
	if (i > lim_superior) {
		return;
	}
	printf("Posição %d vale %d\n", i, array[i]);
	printArray(array, i + 1, lim_superior);
}

int main() {
	int matriz[9-1];

	float media; 
	int menorvalor, delta, somadiagonal;

	somadiagonal = 0;

	menorvalor = buildArray(matriz, 0, 9-1, &media, 1000000, &delta, &somadiagonal, 0);

	printf("%.2lf %d %d %d\n", media, menorvalor, delta, somadiagonal);

	// printArray(matriz, 0, 9-1);



	return 0;
}