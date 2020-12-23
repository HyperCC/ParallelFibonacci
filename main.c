#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>
#include <math.h>

/**
 * Calculation from a number to fibonacci
 * @param n
 * @return
 */


/**
 * Factorization of the fibonacci numbers
 * @param fibNum
 */
void factorization(int fibNum) {
    int divisor = 2;

    if (fibNum <= 5) {
        printf("%d", fibNum);

    } else {
        while (fibNum != 1) {

            if (fibNum % divisor == 0) {
                printf("%d ", divisor);
                fibNum = fibNum / divisor;

                if (fibNum != 1)
                    printf("x ");

            } else {
                divisor++;
            }
        }
    }
}

/**
 * Main class
 * @return
 */
int main(int argc, char **argv) {

    printf("---------- Fibonacci code print and factorization ----------\n");

    mpz_t frstFib;
    mpz_t scndFib;
    mpz_t sumFib;

    mpz_init_set_str(frstFib, "0", 10);
    mpz_init_set_str(scndFib, "1", 10);
    mpz_init_set_str(sumFib, "0", 10);

    char *a = argv[1];
    int n = atoi(a);

    printf("Fibonacci Code to n=%d \n\n", n);

    for (int i = 1; i <= n; ++i) {

        mpz_add(sumFib, frstFib, scndFib);
        //sumFib = frstFib + scndFib;

        mpz_set(frstFib, scndFib);
        mpz_set(scndFib, sumFib);
        //frstFib = scndFib;
        //scndFib = sumFib;

        gmp_printf("%d -> %Zd \n", i, sumFib);
        //printf("%i -> %d \n", i, frstFib);
    }

    mpz_clear(frstFib);
    mpz_clear(scndFib);
    mpz_clear(sumFib);

    return 0;
}