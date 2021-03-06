#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int chrtoint(char a){
	int i;
	for (i = 48; i<=57; i++)
		if (toascii(i)==a) return i-48;
	return 0;
}

void main(){
	char n1[80];
	char n2[80];
	int rs[80];
	int c1, c2;

	int i,j,m, cmax, sum;

	printf("Enter First Number:");
	scanf("%s", &n1);
	printf("\nEnter Second Number:");
	scanf("%s", &n2);
	c1 = strlen(n1);
	c2 = strlen(n2);

	strrev(n1);
	strrev(n2);

	cmax = c1;
	if(c1<c2){
		cmax = c2;
	}

	m=0;
	for(i=0; i< cmax; i++){
		if(c1==c2 || (i < c1 && i < c2)){
			sum = m+chrtoint(n1[i])+chrtoint(n2[i]);
		}else if(i >=c1){
			sum = m+chrtoint(n2[i]);
		}else if(i >=c2){
			sum = m+chrtoint(n1[i]);
		}
		rs[i] = sum%10;
		m = sum/10;
	}

	if(m){
		rs[i]=m;
		i++;
	}

	printf("\nResult: ");
	for(j=0; j < i; j++){
		printf("%d", rs[i-j-1]);
	}

}



// #include <stdlib.h>
// #include <string.h>

// static char *bigsum(char *res, const char *arg) {
// 	size_t pos1, pos2, pos3, len3;
// 	unsigned int carry;

// 	pos1 = strlen(res);
// 	pos2 = strlen(arg);
// 	len3 = pos3 = (pos1 < pos2) ? pos2 + 1 : pos1 + 1;
// 	/* reallocate the result array to one more than the larger operand */
// 	res = realloc(res, len3 + 1);
// 	/* set the terminating '\0' at the end of result */
// 	res[pos3] = '\0';
// 	for (carry = 0; pos3 > 0; carry /= 10) {
// 		if (pos1 > 0) carry += res[--pos1] - '0';
// 		if (pos2 > 0) carry += arg[--pos2] - '0';
// 		res[--pos3] = '0' + carry % 10;
// 	}
// 	while (res[0] == '0' && len3 > 1) {
// 		/* normalize the result: remove redundant initial zeroes */
// 		memmove(res, res + 1, len3--);
// 	}
// 	return res;
// }

// int main(int argc, const char **argv) {
// 	/* initialize the result to "0" as an allocated string */
// 	char *result = strcpy(malloc(2), "0");
// 	int i;

// 	for (i = 1; i < argc; i++) {
// 		result = bigsum(result, argv[i]);
// 	}
// 	printf("%s\n", result);
// 	return 0;
// }





#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function for finding sum of larger numbers
char findSum(string str1, string str2)
{
	if (str1.length() > str2.length())
		swap(str1, str2);

	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int carry = 0;
	for (int i=0; i<n1; i++)
	{

		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');

		carry = sum/10;
	}

	for (int i=n1; i<n2; i++)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	if (carry)
		str.push_back(carry+'0');

	reverse(str.begin(), str.end());
	return str;
}

int main() {
	char num1[10000];
	char num2[10000];
	char num3[10000];
	scanf("%s", num1);
	scanf("%s", num2);

	num3 = findSum(num1, num2);

	printf("%s\n", num3);
}