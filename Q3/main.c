#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poisson.h"

int main() {
    long double lambda1 = 2;
    int k1 = 1;
    long double result = poisson(lambda1, k1);
    printf("px(%d) = %.4Lf\n", k1, result);

    long double lambda2 = 2;
    int k2 = 10;
    result = poisson(lambda2, k2);
    printf("px(%d) = %.4Lf\n", k2, result);

    long double lambda3 = 2;
    int k3 = 2;
    result = poisson(lambda3, k3);
    printf("px(%d) = %.4Lf\n", k3, result);

    long double lambda4 = 3;
    int k4 = 3;
    result = poisson(lambda4, k4);
    printf("px(%d) = %.4Lf\n", k4, result);

    long double lambda5 = 100;
    int k5 = 3;
    result = poisson(lambda5, k5);
    printf("px(%d) = %.4Lf\n", k5, result);

    return 0;
}

