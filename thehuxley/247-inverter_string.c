#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void buildArray(char string[], int i) {
	// char aux; // Compoprtamento estranho
	// aux = scanf("%c", &string[i]); // Comportamento estranho
	if (scanf("%c", &string[i]) == EOF) {
		printArray(string, i);
		return;
	}
	// scanf("%c", &string[i]);
	buildArray(string, i + 1);
}

void printArray(char string[], int i) {
	if (i < 0) {
		return;
	}
	printf("%c", string[i]);
	printArray(string, i - 1);
}

int main() {
	char string[256];
	// scanf("%s", string);

	buildArray(string, 0);

	// printf("%s", string);
	return 0;
}