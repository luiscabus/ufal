#include <stdio.h>
#include <stdlib.h>

void enquanto()
{
	int n;

	scanf("%d", &n);

	if (n == 999)
	{
		return;
	}
	else
	{
		printf(">>> %d\n", n);
		enquanto();
	}
}

void vai_while(){
	int n;
	scanf("%d", &n);

	while (n != 999)
	{
		printf(">>> %d\n", n);
		scanf("%d", &n);
	}
}

void de_i_a_n(int i, int n, int* array)
{
	if (i == n) {return;}

	printf("Array[%d] = %d\n", i, array[i]);
	de_i_a_n(++i, n, array);

}

void vai_for(int* array)
{
	int i;
	for (int i = 0; i < 3; ++i)
	{
		printf("Array[%d] = %d\n", i, array[i]);
	}
}

void vai_for_matriz()
{
	int n = 2;
	int m = 3;

	int matriz[n][m];

	matriz[0][0] = 1;
	matriz[0][1] = 2;
	matriz[0][2] = 3;

	matriz[1][0] = 4;
	matriz[1][1] = 5;
	matriz[1][2] = 6;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("Matriz[%d][%d] = %d\n", i, j, matriz[i][j]);
		}
	}
}

int main()
{
	// enquanto();

	// vai_while();


	int array[3];
	array[0] = 4;
	array[1] = 12;
	array[2] = 64;

	// de_i_a_n(0, 3, array);

	// vai_for(array);

	vai_for_matriz();
	
	

}