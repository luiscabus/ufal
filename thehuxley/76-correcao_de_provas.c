#include <stdio.h>

void printArray(char my_array[], int posicao) {
	if (posicao < 0) {return;}
	printArray(my_array, posicao - 1);
	printf("Posição %d, valor %c \n", posicao, my_array[posicao]);
}

int compareArray(char answers_array[], char st_answers_array[], int posicao, int contador) {
	if (posicao < 0) {return contador;}
	if (answers_array[posicao] == st_answers_array[posicao]) {contador = contador + 1;}
	return compareArray(answers_array, st_answers_array, posicao - 1, contador);
}

void scanStudents(char answers_array[]) {
	int sudentNo;
	scanf(" %d", &sudentNo);
	if (sudentNo == 9999) {return;}

	char st_answers_array[10] = {};
	scanf(" %s", &st_answers_array);
	// printArray(st_answers_array, 10-1);

	float acertos;
	acertos = compareArray(answers_array, st_answers_array, 10-1, 0);
	printf("%d %.1lf\n", sudentNo, acertos);

	scanStudents(answers_array);
}

int main() {
	// char string[200];
	// char character;
	// printf ("write something: ");
	// scanf (" %s", string);
	// printf ("%s\n\n", string);
	// printf ("\nwrite a character: ");
	// scanf (" %c", &character);
	// printf ("\nCharacter %c  Correspondent number: %d\n", character, character);


	char answers_array[10] = {};
	scanf (" %s", answers_array);
	// printArray(answers_array, 10-1);

	scanStudents(answers_array, 0);
}