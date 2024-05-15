#include <stdio.h>
#include <math.h>
#include "poisson.h"

double factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double poisson(double lambda, int k) {
    if (k < 0) {
        return 0; // לא ניתן שיהיו מספר אירועים שלילי
    }

    double pxk = pow(lambda, k) * exp(-lambda) / factorial(k);
    return pxk;
}
