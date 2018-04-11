#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// 3
// 100 500 20 50 bezaliel
// 1000 1000 20 30 Clodes 
// 10000 10500 10 50 Clodes 


// 100 500 20 50 bezaliel

// v1c
// clodes 100 20+50
// bezaliel 500 50

// v2b
// clodes 100-50 70
// bezaliel 500 50

// v3c
// clodes 50 70+50
// bezaliel 500 50

// v4b
// clodes 50-50 120
// bezaliel 500 50


// 1000 1000 20 30 Clodes 

// fClo = bela(1000)/cloF(20) = 50
// fBel = clod(1000)/belF(30) = 33,33

// >>> identificar que fBel > fClo, buff energia... 

// v1c
// clodes 1000 20+50
// bezaliel 1000 30

// v2b
// clodes 1000-30 70
// bezaliel 1000 30

// --- fim 1 rodada

// fClo = bela(1000)/cloF(70) = 14,28
// fBel = clod(970)/belF(30) = 32,33

// >>> identificar que fClo < fBel, passar a atacar... 

// v3c
// clodes 970 70+50
// bezaliel 1000 30

// v4b
// clodes 970-30 120
// bezaliel 1000 30

// --- fim 2 rodada

// fClo = bela(1000)/cloF(120) = 8,33
// fBel = clod(950)/belF(30) = 31,33

void quemvence(int vida_clodes, int vida_bezaliel, int forca_clodes, int forca_bezaliel){
	float hitsClo = ceil(1.00 * vida_bezaliel / forca_clodes);
	float hitsBel = ceil(1.00 * vida_clodes / forca_bezaliel);

	// printf("vclo %d vbel %d fclo %d fbel %d\n", vida_clodes, vida_bezaliel, forca_clodes, forca_bezaliel);
	// printf("hitsClo %f hitsBel %f\n", hitsClo, hitsBel);

	if (vida_clodes <= 0) {
		printf("Bezaliel\n");
		return;
	}

	if (hitsClo > hitsBel) {
	// if (1.0 * vida_bezaliel / forca_clodes > hitsBel > 1.0 * vida_clodes / forca_bezaliel) {
		quemvence(vida_clodes - forca_bezaliel, vida_bezaliel, forca_clodes + 50, forca_bezaliel);
	} else {
		printf("Clodes\n");
		return;
	}

}

void scanline(int linhas){
	if (linhas == 0) {
		return;
	}

	int vida_clodes, vida_bezaliel, forca_clodes, forca_bezaliel;
	scanf("%d %d %d %d", &vida_clodes, &vida_bezaliel, &forca_clodes, &forca_bezaliel);
	
	quemvence(vida_clodes, vida_bezaliel, forca_clodes, forca_bezaliel);

	scanline(linhas - 1);
}


int main() {
	int batalhas;
	scanf("%d", &batalhas);

	scanline(batalhas);

	return 0;
}