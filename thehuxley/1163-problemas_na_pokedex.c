#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("Bulbasaur\n");
	}
	if (n == 2) {
		printf("Ivysaur\n");
	}
	if (n == 3) {
		printf("Venusaur\n");
	}
	if (n == 4) {
		printf("Charmander\n");
	}
	if (n == 5) {
		printf("Charmeleon\n");
	}
	if (n == 6) {
		printf("Charizard\n");
	}
	if (n == 7) {
		printf("Squirtle\n");
	}
	if (n == 8) {
		printf("Wartortle\n");
	}
	if (n == 9) {
		printf("Blastoise\n");
	}
	if (n == 10) {
		printf("Caterpie\n");
	}
	if (n == 11) {
		printf("Metapod\n");
	}
	if (n == 12) {
		printf("Butterfree\n");
	}

	if (n < 1 || n > 12) {
		printf("Pokémon inválido no momento\n");
	}

	return 0;
}