#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double poisson(double lambda, int k) {
    if (k < 0) {
        return 0;
    }

    double result = pow(lambda, k) * exp(-lambda) / factorial(k);
    return result;
}

//**To compile the program execute the compilation command: gcc main.c -o poisson -lm
//**To run the program Run in Bash: ./poisson <lambda> <k>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    double lambda = atof(argv[1]);
    int k = atoi(argv[2]);

    double result = poisson(lambda, k);
    printf("px(%d) = %.4f\n", k, result);

    return 0;
}

