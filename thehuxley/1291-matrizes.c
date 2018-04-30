#include <stdio.h>

int buildArray(int array[], int i, int lim_superior, float *media, int maiorvalor, int *delta, int *somadiagonal) {
	if (i > lim_superior) {
		*media = *media / (lim_superior + 1);
		if (maiorvalor > 0) {*delta = 1;}
		if (maiorvalor == 0) {*delta = 0;}
		if (maiorvalor < 0) {*delta = -1;}
		return maiorvalor;
	}
	scanf("%d", &array[i]);
	*media = *media + array[i];
	if (array[i] > maiorvalor) {
		maiorvalor = array[i];
	}
	if (i == 0) {*somadiagonal = *somadiagonal + array[i];}
	if (i == 4) {*somadiagonal = *somadiagonal + array[i];}
	if (i == 8) {*somadiagonal = *somadiagonal + array[i];}
	return buildArray(array, i + 1, lim_superior, media, maiorvalor, delta, somadiagonal);
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
	int maiorvalor, delta, somadiagonal;

	somadiagonal = 0;

	maiorvalor = buildArray(matriz, 0, 9-1, &media, -1, &delta, &somadiagonal);

	printf("%.2lf %d %d %d\n", media, maiorvalor, delta, somadiagonal);

	// printArray(matriz, 0, 9-1);



	return 0;
}