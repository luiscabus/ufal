#include <stdio.h>
#include <string.h>

void printarg(int nchars, char **argv) {
	if (nchars < 0) {return;}
	printarg(nchars - 1, argv);
	printf("%s\n", argv[nchars]);
}

int main(int argc, char **argv) {
	printarg(argc -1, argv);
	return 0;
}

// [cabox@box-codeanywhere comp201t]$ gcc 20180410.c -o 20180410
// [cabox@box-codeanywhere comp201t]$ ./20180410 oiee
// >> oiee 