#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long double factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

long double poisson(long double lambda, int k) {
    if (k < 0) {
        return 0;
    }

    long double result = pow(lambda, k) * exp(-lambda) / factorial(k);
    return result;
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    long double lambda = atof(argv[1]);
    int k = atoi(argv[2]);

    long double result = poisson(lambda, k);
    printf("px(%d) = %.4Lf\n", k, result);

    return 0;
}

