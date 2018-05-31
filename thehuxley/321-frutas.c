#include <stdio.h>
#include <stdlib.h>

int countfrutas(char frus[], int i, int count) {
	if (frus[i] == '\0') {
		return count;
	}

	if (frus[i] == ' ') {
		++count;
	}

	return countfrutas(frus, i + 1, count);
}

void readfrutas(int dias, int todias, float totalkg, float totaldin) {
	if (dias == 0) {
		printf("%.2f kg por dia\n", totalkg/todias);
		printf("R$ %.2f por dia\n", totaldin/todias);
		return;
	}

	float din;
	scanf("%f", &din);
	totaldin = totaldin + din;

	char frus[200];
	// scanf(" %s", frus);
	scanf(" %[^\n]", frus);
	// scanf(" %[\^n]s", frus);
	// scanf ("%[^\n]%*c", frus);

	int cfrus;
	cfrus = countfrutas(frus, 0, 1);
	printf("dia %d: %d kg\n", todias - dias + 1, cfrus);

	totalkg = totalkg + cfrus;

	readfrutas(dias - 1, todias, totalkg, totaldin);
}

int main() {
	int dias;

	scanf("%d", &dias);

	readfrutas(dias, dias, 0, 0);

	return 0;
}