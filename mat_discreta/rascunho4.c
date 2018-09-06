#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// https://codereview.stackexchange.com/questions/112901/eratosthenes-sieve-optimized-in-c

// #define N        1000000000
#define N        100000000

int main(void)
{
    clock_t t, max;
    t = clock();

    int       arraySize = (N/24 + 1);
    uint32_t *primes    = malloc(arraySize);

    // The bits in primes follow this pattern:
    //
    // Bit 0 = 5, bit 1 = 7, bit 2 = 11, bit 3 = 13, bit 4 = 17, etc.
    //
    // For even bits, bit n represents 5 + 6*n
    // For odd  bits, bit n represents 1 + 6*n
    memset(primes , 0xff, arraySize);

    int sqrt_N = sqrt(N);
    for(int i = 5; i <= sqrt_N; i += 4) {
        int iBitNumber = i / 3 - 1;
        int iIndex = iBitNumber >> 5;
        int iBit   = 1 << (iBitNumber & 31);
        if ((primes[iIndex] & iBit) != 0) {
            int increment = i+i;
            for (int j = i * i; j < N; j += increment) {
                int jBitNumber = j / 3 - 1;
                int jIndex = jBitNumber >> 5;
                int jBit   = 1 << (jBitNumber & 31);

                primes[jIndex] &= ~jBit;

                j += increment;
                if (j >= N)
                    break;

                jBitNumber = j / 3 - 1;
                jIndex = jBitNumber >> 5;
                jBit   = 1 << (jBitNumber & 31);

                primes[jIndex] &= ~jBit;

                // Skip multiple of 3.
                j += increment;
            }
        }
        i += 2;
        iBit <<= 1;
        if ((primes[iIndex] & iBit) != 0) {
            int increment = i+i;
            for (int j = i * i; j < N; j += increment) {
                int jBitNumber = j / 3 - 1;
                int jIndex = jBitNumber >> 5;
                int jBit   = 1 << (jBitNumber & 31);

                primes[jIndex] &= ~jBit;

                // Skip multiple of 3.
                j += increment;

                j += increment;
                if (j >= N)
                    break;

                jBitNumber = j / 3 - 1;
                jIndex = jBitNumber >> 5;
                jBit   = 1 << (jBitNumber & 31);

                primes[jIndex] &= ~jBit;
            }
        }
    }

    // Initial count includes 2, 3.
    int count=2;
    for (int i=5; i < N; i += 6) {
        int iBitNumber = i / 3 - 1;
        int iIndex = iBitNumber >> 5;
        int iBit   = 1 << (iBitNumber & 31);
        if (primes[iIndex] & iBit) {
            count++;
            // printf("%d ", i);
        }
        iBit <<= 1;
        if (primes[iIndex] & iBit) {
            count++;
            // printf("%d ", i);
        }
    }



    printf("\nPrimos: %d\n", count);

    free(primes);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\ntook %f seconds to execute \n", time_taken);

    return 0;
}