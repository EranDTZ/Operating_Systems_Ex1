#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poisson.h"
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    double lambda = atof(argv[1]);
    int k = atoi(argv[2]);

    double pxk = poisson(lambda, k);
    printf("px(%d) = %.4f\n", k, pxk);

    return 0;
}

