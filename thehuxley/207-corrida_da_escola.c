#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int scan_voltas(int m_voltas) {
	if (m_voltas == 0) { return 0; }

	int tempo;
	scanf("%d", &tempo);

	// printf("na volta %d o tempo foi %d\n", m_voltas, tempo);

	return tempo + scan_voltas(m_voltas - 1);
}


void scan_competidores(int n_competidores, int competidor, int m_voltas, int melhortempo, int compmaisrapido) {
	if (competidor > n_competidores) { 
		printf("%d\n", compmaisrapido);
		return; 
	}

	// printf("Competidor %d\n", competidor);
	int tempototal = 0;
	tempototal = scan_voltas(m_voltas);
	// printf("Tempo total %d\n", tempototal);

	if (tempototal < melhortempo || melhortempo == 0) {
		melhortempo = tempototal;
		compmaisrapido = competidor;
	}

	scan_competidores(n_competidores, competidor + 1, m_voltas, melhortempo, compmaisrapido);
}


int main()
{
	int n_competidores, m_voltas;

	scanf("%d %d", &n_competidores, &m_voltas);

	scan_competidores(n_competidores, 1, m_voltas, 0, 0);

	return 0;
}