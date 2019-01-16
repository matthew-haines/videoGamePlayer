#include <stdlib.h>
#include <math.h>

double normal(double mu, double sigma) {
    // Performs box-muller transform on uniform random variables and returns
    // random variable in normal distribution with mean mu and standard deviation sigma
    srand(time(NULL));
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;

    double rand_norm = sqrt(-2 * ln(u1)) * cos(2 * M_PI * u2);
    return rand_norm * sigma + mu;
}
