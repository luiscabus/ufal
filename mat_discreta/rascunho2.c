#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include <time.h>

void sieve(int n, int primes[])
{
    int i, j;
    for (i=0;i<n;i++) {
        primes[i]=1; // we initialize the sieve list to all 1's (True)
    }

    primes[0]=0,primes[1]=0; // Set the first two numbers (0 and 1) to 0 (False)
    
    // for (i = 2; i < sqrt(n); ++i) { // loop through all the numbers up to the sqrt(n)
    for (i = 2; i * i < n; ++i) { // loop through all the numbers up to the sqrt(n)
    	for (j = i * i; j < n; j += i) { // mark off each factor of i by setting it to 0 (False)
    	    primes[j] = 0;
    	}
    } 
        
}

int main() {
	clock_t t, max;
	t = clock();

    int i, j = 0, n = 87654321; // find the primes up to ...
    // int primes[n*2];
    int *primes;
	primes = (int*) malloc(n * sizeof(int));

    sieve(n, primes);
    
    for (i = 0; i < n; ++i) {
    	if (primes[i] == 1) {
    	    printf("%d ", i); // this just prints out each value if it's Prime
    	    ++j;
    	}
    }

    printf("\nPrimos: %d\n", j);

    t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\ntook %f seconds to execute \n", time_taken);
}

