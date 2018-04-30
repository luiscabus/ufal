#include <stdio.h>

void mais_frequente(int array_notas[], int i, int lim_sup, int quantidade, int controle) {
	if (i > lim_sup) {
		printf("%d.0\n", controle);
		return;
	}
	if (array_notas[i] > quantidade) {
		quantidade = array_notas[i];
		controle = i;
	}

	return mais_frequente(array_notas, i + 1, lim_sup, quantidade, controle);
}

int compareArray(char answers_array[], char st_answers_array[], int posicao, int contador) {
	if (posicao < 0) {return contador;}
	if (answers_array[posicao] == st_answers_array[posicao]) {contador = contador + 1;}
	return compareArray(answers_array, st_answers_array, posicao - 1, contador);
}

void scanStudents(char answers_array[], float naprovados, int last_std_no, int array_notas[]) {
	int sudentNo;
	scanf(" %d", &sudentNo);

	if (sudentNo == 9999) {
		printf("%.1lf%%\n", (naprovados / last_std_no) * 100);
		mais_frequente(array_notas, 0, 10, 0, 0);
		return;
	}

	char st_answers_array[10+1];
	scanf(" %s", st_answers_array);

	int acertos;
	acertos = compareArray(answers_array, st_answers_array, 10-1, 0);
	printf("%d %d.0\n", sudentNo, acertos);

	array_notas[acertos] = array_notas[acertos] + 1;

	if (acertos >= 6.0) {
		naprovados = naprovados + 1;
	}

	last_std_no = sudentNo;
	scanStudents(answers_array, naprovados, last_std_no, array_notas);
}

int main() {

	char answers_array[10+1];
	scanf (" %s", answers_array);

	int array_notas[11] = {};

	scanStudents(answers_array, 0, 0, array_notas);
}