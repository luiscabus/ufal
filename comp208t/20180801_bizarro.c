/*
int i;
array a;

a[i] = *(a+i)
i[a] = *(i+a)int i;
array a;

a[i] = *(a+i)
i[a] = *(i+a)

funciona?

funciona?
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int my_array[5] = {};

	my_array[0] = 6;
	my_array[1] = 7;
	my_array[2] = 8;
	my_array[3] = 9;
	my_array[4] = 10;

	printf("%d\n", my_array[2]);
	printf("oiiii\n");
	printf("%d\n", 2[my_array]);
}