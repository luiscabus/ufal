#include <stdio.h>

void writeLines(int atual, int coluna, int x, int y, int z, int contador) {
	if (atual > y) {
		return;
	}
	printf("%d", atual);
	if (coluna % x == 0) {
		printf("\n");
	} else {
		printf(" ");
	}

	writeLines(atual + z, coluna + 1, x, y, z, contador);
}

int main() {
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	writeLines(1, 1, x, y, z, 0);



	return 0;
}