#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t t, max;
	t = clock();
	max = clock();


	int number,lastprime,i,j,k = 0;
	// printf("Enter the number\n");
	// scanf("%d",&number);
	// number = 2100100200;
	number = 100000000;
	// number = 87654321;

	// int primes[number+1];
	int *primes;
	primes = (int*) malloc(number * sizeof(int));

	// populating array with naturals numbers
	for(i = 2; i<=number; i++)
		primes[i] = i;

	// 
	i = 2;
	while ((i*i) <= number) 
	{
		if (primes[i] != 0)
		{
			for(j = 2; j < number; j++) // to manipulate on each natural number of array.
			{
				if (primes[i]*j > number)
					break;
				else
					// Instead of deleteing , making elemnets 0
					primes[primes[i]*j]=0;
			}
		}
		i++;
	}

	for(i = 2; i<=number; ++i) 
	{
		//If number is not 0 then it is prime
		if (primes[i]!=0) {
			printf("%d ",primes[i]);
			// lastprime = primes[i];
			++k;
		}

		// max = clock() - t;
		// double time_taken = ((double)max)/CLOCKS_PER_SEC; // in seconds
		// if (max >= 3) {
		// 	break;
		// }

	}

	// printf("Last prime: %d\n", lastprime);

	printf("\nPrimos: %d\n", k);


	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\ntook %f seconds to execute \n", time_taken);

	return 0;
}