#include <stdio.h>
#include <math.h>
#include "poisson.h"

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
