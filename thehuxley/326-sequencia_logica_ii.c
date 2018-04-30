#include <stdio.h>

void writeLines(int x, int y, int atual, int contador) {
	if (atual > y) {
		return;
	}
	printf("%d", atual);
	if (atual % x == 0) {
		printf("\n");
	} else {
		printf(" ");
	}

	writeLines(x, y, atual + 1, contador);
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	writeLines(x, y, 1, 0);



	return 0;
}