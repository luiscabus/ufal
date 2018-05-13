#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	long double a, b;
	scanf(" %Lf %Lf", &a, &b);

	printf("%.0Lf\n", ((a + b) * ((b - a + 1) / 2)) );
}