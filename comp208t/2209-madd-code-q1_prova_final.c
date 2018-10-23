#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char what_char_is_this(char string[200]) {
	char letra;

	if ( strcmp(string, "@") == 0) {letra = 'M';}
	else if ( strcmp(string, "-") == 0) {letra = 'G';}
	else if ( strcmp(string, "|") == 0) {letra = 'T';}
	else if ( strcmp(string, "--") == 0) {letra = 'C';}
	else if ( strcmp(string, "-|") == 0) {letra = 'K';}
	else if ( strcmp(string, "|-") == 0) {letra = 'Q';}
	else if ( strcmp(string, "||") == 0) {letra = 'W';}
	else if ( strcmp(string, "---") == 0) {letra = 'A';}
	else if ( strcmp(string, "--|") == 0) {letra = 'E';}
	else if ( strcmp(string, "-|-") == 0) {letra = 'I';}
	else if ( strcmp(string, "-||") == 0) {letra = 'L';}
	else if ( strcmp(string, "|--") == 0) {letra = 'O';}
	else if ( strcmp(string, "|-|") == 0) {letra = 'R';}
	else if ( strcmp(string, "||-") == 0) {letra = 'U';}
	else if ( strcmp(string, "|||") == 0) {letra = 'Y';}
	else if ( strcmp(string, "----") == 0) {letra = ' ';}
	else if ( strcmp(string, "---|") == 0) {letra = 'B';}
	else if ( strcmp(string, "--|-") == 0) {letra = 'D';}
	else if ( strcmp(string, "--||") == 0) {letra = 'F';}
	else if ( strcmp(string, "-|--") == 0) {letra = 'H';}
	else if ( strcmp(string, "-|-|") == 0) {letra = 'J';}
	else if ( strcmp(string, "|---") == 0) {letra = 'N';}
	else if ( strcmp(string, "|--|") == 0) {letra = 'P';}
	else if ( strcmp(string, "|-||") == 0) {letra = 'S';}
	else if ( strcmp(string, "||-|") == 0) {letra = 'V';}
	else if ( strcmp(string, "|||-") == 0) {letra = 'X';}
	else if ( strcmp(string, "||||") == 0) {letra = 'Z';}

	return letra;
}


int main() {

	int i;
	char string[100];
	for (i = 0; i < 100; ++i)
	{
		string[i] = '\0';
	}

	char caractere;



	int k;
	k = 0;
	while(scanf("%c", &caractere) != EOF) {
		
		if (caractere == '*') {
			// printf("string lida %s vale %c\n", string, what_char_is_this(string));
			printf("%c", what_char_is_this(string));
			k = 0;
			for (i = 0; i < 100; ++i)
			{
				string[i] = '\0';
			}
		} else {
			string[k] = caractere;
			++k;
		}
	}

	printf("\n");

	return 0;
}