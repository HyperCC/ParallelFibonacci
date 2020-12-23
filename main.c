#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

/**
 * Factorization of the fibonacci numbers
 * @param fibNum
 */
void factorizar(mpz_t fibNum) {

    // variable declaration and initialization
    mpz_t divisor;
    mpz_init(divisor);
    mpz_set_ui(divisor, 2);

    // if (fibNum <= 5) show the minimum factorial
    if (mpz_cmp_d(fibNum, 5) <= 0) {
        gmp_printf("%Zd ", fibNum);

    } else {
        while (mpz_get_ui(fibNum) != 1) {

            // print te validated value to factorization
            if (mpz_get_ui(fibNum) % mpz_get_ui(divisor) == 0) {
                gmp_printf("%Zd ", divisor);

                mpz_cdiv_q(fibNum, fibNum, divisor);

                if (mpz_get_ui(fibNum) != 1)
                    printf("x ");

            } else {
                // divisor++
                mpz_add_ui(divisor, divisor, 1);
            }
        }
    }

    // clear the memory usage
    mpz_clear(divisor);
}


/**
 * Main class: Calculation from a number to fibonacci
 * @return
 */
int main(int argc, char **argv) {

    printf("---------- Fibonacci code print and factorization ----------\n");

    // fibonacci variables
    mpz_t frstFib;
    mpz_t scndFib;
    mpz_t fibonacci;

    // initialization
    mpz_init_set_str(frstFib, "0", 10);
    mpz_init_set_str(scndFib, "1", 10);
    mpz_init_set_str(fibonacci, "1", 10);

    // catch the data received for command line
    char *a = argv[1];
    int n = atoi(a);

    printf("Fibonacci Code to n=%d \n\n", n);

    int i;
#pragma omp parallel
    for (i = 1; i <= n; ++i) {

        // print all fibonacci series founded
        gmp_printf("%d : %Zd = ", i, fibonacci);

        // print the factorization to fibonacci series
        factorizar(fibonacci);
        printf("\n");

        // calculate the next series
        mpz_add(fibonacci, frstFib, scndFib);
        mpz_set(frstFib, scndFib);
        mpz_set(scndFib, fibonacci);
    }

    // clear variables GMP
    mpz_clear(frstFib);
    mpz_clear(scndFib);
    mpz_clear(fibonacci);

    printf("\nFinalization ..\n");
    return 0;
}