#include <stdio.h>



void sortNotas(int *n1, int *n2, int *n3, int *n4) {
	if (*n1 >= *n2 && *n2 >=*n3 && *n3 >= *n4) {return;}

	int aux;
	if (*n1 < *n2) {
		aux = *n1;
		*n1 = *n2;
		*n2 = aux;
	}
	if (*n2 < *n3) {
		aux = *n2;
		*n2 = *n3;
		*n3 = aux;
	}
	if (*n3 < *n4) {
		aux = *n3;
		*n3 = *n4;
		*n4 = aux;
	}
	
	sortNotas(n1, n2, n3, n4);
}

void howmanyof(int n1, int T, int count) {
	if (T / n1 < 0) {
		printf("%d of %d\n", count, n1);
		return;
	}

	howmanyof(n1, T / n1, count + 1);
}



void scanline(int nCustomers, int rolling) {
	if (nCustomers == 0) {return;}

	int n1, n2, n3, n4, T;
	scanf(" %d %d %d %d %d", &n1, &n2, &n3, &n4, &T);

	printf("\nCostumer %d:\n", rolling);
	printf("Change: $%d\n", T);

	// printf("Before sort %d %d %d %d\n", n1, n2, n3, n4);

	sortNotas(&n1, &n2, &n3, &n4);

	printf("%d of $%d\n", T / n1, n1);
	printf("%d of $%d\n", (T % n1)/ n2, n2);
	printf("%d of $%d\n", ((T % n1) % n2) / n3, n3);
	printf("%d of $%d\n", (((T % n1) % n2) % n3) / n4, n4);
	printf("Tip: $%d\n", (((T % n1) % n2) % n3) % n4);
	

	// howmanyof(n1, T, 0);
	// howmanyof(n2, T, 0);
	// howmanyof(n3, T, 0);
	// howmanyof(n4, T, 0);


	// printf("After sort %d %d %d %d\n", n1, n2, n3, n4);

	scanline(nCustomers - 1, rolling + 1);
}















int main() {
	int nCustomers;

	scanf("%d", &nCustomers);
	
	scanline(nCustomers, 1);
}