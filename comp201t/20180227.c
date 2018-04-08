#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
   double litros;
   char combustivel;
   double valor_total;

	scanf("%lf %c", &litros, &combustivel); 

	if (combustivel == 'A'){
		valor_total = 1.90 * litros;
		if (litros <= 20){
		    valor_total = valor_total * 0.97;
		} else {
		    valor_total = valor_total * 0.95;
		}
		printf("R$ %.2lf\n", valor_total);
	}

	if (combustivel == 'G'){
		valor_total = 2.50 * litros;
	   if (litros <= 20){
		    valor_total = valor_total * 0.96;
		} else {
		    valor_total = valor_total * 0.94;
		}
		printf("R$ %.2lf\n", valor_total);
	}

	if (combustivel == 'D'){
		valor_total = 1.66 * litros;
		if (litros > 25){
		    valor_total = valor_total * 0.96;
		} 
		printf("R$ %.2lf\n", valor_total);
	}

	
return 0;
}