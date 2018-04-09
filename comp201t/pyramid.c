#include <stdio.h>

int halfpyramid()
{
	 int i, j, rows;

	 printf("Enter number of rows: "); scanf(" %d",&rows);

	 for(i=1; i<=rows; ++i)
	 {
		  for(j=1; j<=i; ++j)
		  {
				printf("%d ",j);
		  }
		  printf("\n");
	 }
	 return 0;
}

int fullpyramid()
{
    int i, space, rows, k=0, count = 0, count1 = 0;

    printf("Enter number of rows: ");
    scanf("%d",&rows);

    for(i=1; i<=rows; ++i)
    {
        for(space=1; space <= rows-i; ++space)
        {
            printf("  ");
            ++count;
        }

        while(k != 2*i-1)
        {
            if (count <= rows-1)
            {
                printf("%d ", i+k);
                ++count;
            }
            else
            {
                ++count1;
                printf("%d ", (i+k-2*count1));
            }
            ++k;
        }
        count1 = count = k = 0;

        printf("\n");
    }
    return 0;
}

int floydtriangle()
{
    int rows, i, j, number= 1;

    printf("Enter number of rows: ");
    scanf("%d",&rows);

    for(i=1; i <= rows; i++)
    {
        for(j=1; j <= i; ++j)
        {
            printf("%d ", number);
            ++number;
        }

        printf("\n");
    }

    return 0;
}

int main()
{
	halfpyramid();
	
	printf("\n\n");
	
	fullpyramid();
	
	printf("\n\n");
	
	floydtriangle();
	
	return 0;
}