#define MAX_TPSC 100000
#define MEAN_TPSC 50000
#define STD_DEV_TPSC 10000

double normal(double mu, double sigma, int sd) {
    // Performs box-muller transform on uniform random variables and returns
    // random variable in normal distribution with mean mu and standard deviation sigma
    srand(sd);
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    
    double rand_norm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return rand_norm * sigma + mu;
}
