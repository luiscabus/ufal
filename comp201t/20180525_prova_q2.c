#include <stdio.h>

int ambrosionumber(int number, int ambro) {
	if (number == 0) {
		return ambro;
	}

	// printf("Número %d, Resto %d\n", number, number % 10);

	if (ambro == 0)
	{
		if (number % 10 == 0 || number % 10 == 1 || number % 10 == 2 || number % 10 == 3 || number % 10 == 4 || number % 10 == 5) {
			ambro = 0;
		} else {
			ambro = 1;
		}
	}

	return ambrosionumber(number / 10, ambro);
}

void getnextAmbrosio(int number, int i, int procurado) {
	if (ambrosionumber(number, 0) == 0) {
		++i;
		if (i == procurado) {
			printf("%d\n", number);
			return;
		}
	} else {
		// printf("O número %d não é ambro\n", number);
	}

	getnextAmbrosio(number + 1, i, procurado);
}

void readlines(int t, int i) {
	if (i == t) {
		return;
	}

	int aux;
	scanf(" %d", &aux);
	getnextAmbrosio(0, 0, aux);

	readlines(t, i+1);
}

int main() {

	int t;
	scanf(" %d", &t);
	readlines(t, 0);

}