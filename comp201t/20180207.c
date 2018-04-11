#include <stdio.h>

void multiplicar(int *param){
	*param = *param * 2;
}

int primeiro_grau(int x){
	return ((2 * x) + 7);
}

void primeiro_grau2(int x, int *rdef, int *rdeg){
	*rdef = 2 * x + 7;
	*rdeg = 9 * x + 13;
}

int main(void) {
	int x = 2;
	printf("%d\n", x);
	multiplicar(&x);
	printf("%d\n", x);

	printf("%d\n", primeiro_grau(0) );
	printf("%d\n", primeiro_grau(5) );

	int rdef, rdeg;
	x = 0;
	primeiro_grau2(x, &rdef, &rdeg);
	printf("A função calculou f(%d) = %d e g(%d) = %d \n", x, rdef, x, rdeg);

	x = 5;
	primeiro_grau2(x, &rdef, &rdeg);
	printf("A função calculou f(%d) = %d e g(%d) = %d \n", x, rdef, x, rdeg);


	return 0;
}