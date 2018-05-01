#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArray(int array[], int i, int lim_superior) {
	if (i == lim_superior) {return;}
	printf("Posição %d, valor %d\n", i, array[i]);
	printArray(array, i + 1, lim_superior);
}

void buildArray(int array[], int i, int lim_superior) {
	if (i == lim_superior) {
		array[i] = 0;

		if ( (array[0] == 0 && array[1] == 0 && array[3] == 0 && array[5] == 0 && array[7] == 0 && array[8] == 0 && array[2] == 1 && array[4] == 1 && array[6] == 1) ) {
			array[i] = 1;
			array[i+1] = 1;
		}
		if ( (array[1] == 0 && array[2] == 0 && array[3] == 0 && array[5] == 0 && array[6] == 0 && array[7] == 0 && array[0] == 1 && array[4] == 1 && array[8] == 1)  ) {
			array[i] = 1;
			array[i+1] = 2;
		}
		
		return;
	}
	scanf("%d", &array[i]);
	buildArray(array, i + 1, lim_superior);
}

void hitRound(int luke[], int vader[], int vida_luke, int vida_vader, int rodada) {

	if (vida_luke <=0 && vida_vader <=0) {
		printf("Houve empate.\n");	
		return;
	}
	if (vida_luke <= 0) {
		printf("Darth Vader venceu.\n");
		return;
	}
	if (vida_vader <= 0) {
		printf("Luke Skywalker venceu.\n");
		return;
	}

	if (rodada > 10) {
		// if (vida_luke > vida_vader) {
		// 	printf("Luke Skywalker venceu.\n");
		// } else {
		// 	printf("Darth Vader venceu.\n");
		// }
		// printf("final %d vida luke %d vida vader %d\n", rodada, vida_luke, vida_vader);
		printf("Houve empate.\n");	
		return;
	}

	// printf("rodada %d vida luke %d vida vader %d\n", rodada, vida_luke, vida_vader);
	
	buildArray(luke, 0, 9);
	buildArray(vader, 0, 9);
	
	if (luke[9] == 0 && vader[9] == 0) {
		// printf("Ninguém toma hit\n");
	}
	if (luke[9] == 1 && vader[9] == 0) {
		// printf("Vader toma hit\n");
		vida_vader = vida_vader - 15;
	}	
	if (luke[9] == 0 && vader[9] == 1) {
		// printf("Luke toma hit\n");
		vida_luke = vida_luke - 15;
	}
	if (luke[9] == 1 && vader[9] == 1) {
		if (luke [10] != vader[10]) {
			// printf("Ninguém toma hit\n");
		} else {
			// printf("Todos tomam hit\n");
			vida_luke = vida_luke - 15;
			vida_vader = vida_vader - 15;
		}
	}
	
	return hitRound(luke, vader, vida_luke, vida_vader, rodada + 1);
}

int main() {
   int vida_luke, vida_vader;
	scanf("%d %d", &vida_luke, &vida_vader);
	
	int luke[11];
	int vader[11];
	
	
	
	hitRound(luke, vader, vida_luke, vida_vader, 1);
    
	return 0;
}