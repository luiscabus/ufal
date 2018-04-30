#include <stdio.h>

void printArray(int my_array[], int i) {
	if (i < 0) {return;}
	printArray(my_array, i - 1);
	printf("Posição %d, valor %d \n", i, my_array[i]);
}

int sumArray(int my_array[], int i, int soma) {
	if (i < 0) {return soma;}
	soma = soma + my_array[i];
	return sumArray(my_array, i - 1, soma);
	// printf("Posição %d, valor %d \n", i, my_array[i]);	
}

int checkReferenceArray(int my_array[], int i, int procurado) {
	if (i < 0) {return 0;}
	// printf("Atual: %d, Procurado: %d\n", my_array[i], procurado);
	if (my_array[i] == procurado) {return 1;}
	return checkReferenceArray(my_array, i - 1, procurado);
}

int sumDistinctiveArray(int my_array[], int i, int soma, int reference_array[], int sizeDistinctive) {
	if (i < 0) {return soma;}
	// printf("Atual: \n"); printArray(reference_array, sizeDistinctive); printf("Procurado %d\n", my_array[i]);
	if (checkReferenceArray(reference_array, sizeDistinctive, my_array[i]) == 0) {
		soma = soma + my_array[i];
		reference_array[i] = my_array[i];
	}
	return sumDistinctiveArray(my_array, i - 1, soma, reference_array, sizeDistinctive);
}

void scan_array(int array[], int i, int lim_superior, int *total_joao, int *total_maria) {
	if (i > lim_superior) {
		// printArray(array, lim_superior);
		return;
	}
	scanf("%d", &array[i]);
	if (array[i] % 2 == 0) {
		// figurinha par é do joão
		*total_joao = *total_joao + 1;
	} else {
		*total_maria = *total_maria + 1;
	}
	return scan_array(array, i + 1, lim_superior, total_joao, total_maria);
}

void distribuite_array(int array[], int i, int lim_superior, int figuras_joao[], int total_joao, int figuras_maria[], int total_maria) {
	if (i > lim_superior) {
		return;
	}
	if (array[i] % 2 == 0) {
		// figurinha par é do joão
		figuras_joao[total_joao] = array[i];
		total_joao = total_joao + 1;
	} else {
		figuras_maria[total_maria] = array[i];
		total_maria = total_maria + 1;
	}
	return distribuite_array(array, i + 1, lim_superior, figuras_joao, total_joao, figuras_maria, total_maria);
}

int main() {
	int total_figurinhas;
	scanf("%d", &total_figurinhas);

	int total_joao, total_maria;
	total_joao = 0;
	total_maria = 0;

	int array_figurinhas[total_figurinhas];
	scan_array(array_figurinhas, 0, total_figurinhas - 1, &total_joao, &total_maria);

	// printf("Joao: %d, Maria: %d\n", total_joao, total_maria);
	printf("%d\n%d\n", total_joao, total_maria);

	int figuras_joao[total_joao];
	int figuras_maria[total_maria];

	int ref_joao[total_joao];
	int ref_maria[total_maria];

	// 
	// O array de ref_ sem inicialização, possui valores malucos, podendo em certos casos dar match em um número sem ele ter sido incluído no array ref
	// 

	distribuite_array(array_figurinhas, 0, total_figurinhas - 1, figuras_joao, 0, figuras_maria, 0);

	// printf("Joao\n");
	// printArray(figuras_joao, total_joao - 1);
	// printf("%d\n", sumArray(figuras_joao, total_joao - 1, 0));

	// printf("Maria\n");
	// printArray(figuras_maria, total_maria - 1);
	// printf("%d\n", sumArray(figuras_maria, total_maria - 1, 0));

	int soma_joao, soma_maria;
	// soma_joao = sumArray(figuras_joao, total_joao - 1, 0);
	// soma_maria = sumArray(figuras_maria, total_maria - 1, 0);
	// soma_joao = sumDistinctiveArray(figuras_joao, total_joao - 1, 0, ref_joao, total_joao - 1);
	soma_maria = sumDistinctiveArray(figuras_maria, total_maria - 1, 0, ref_maria, total_maria - 1);

	if (soma_joao > soma_maria) {
		printf("%d\n", soma_joao);
	} else {
		printf("%d\n", soma_maria);
	}


	return 0;
}