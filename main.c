#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/**
 * Calculation from a number to fibonacci
 * @param n
 * @return
 */
int fibonacciCalc(int n) {
    int i, j;
    if (n < 2)
        return n;
    else {
#pragma omp task shared(i)
        i = fibonacciCalc(n - 1);
#pragma omp task shared(j)
        j = fibonacciCalc(n - 2);
#pragma omp taskwait
        return i + j;
    }
}

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
    int n, result;
    char *a = argv[1];
    n = atoi(a);

#pragma omp parallel
    {
#pragma omp single
        result = fibonacciCalc(n);
    }
    printf("Result is %d\n", result);
    return 0;
}
