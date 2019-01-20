#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int mth;
    int dy;
    int yr;
} dob;

typedef struct {
    char usrnm[10];
    char pswrd[10];
    double salt;
    dob birth;
    int tpSc;
    int fre;
} user;

typedef struct {
    int x;
    int y;
} dim_t;

// I was bored

void print_polynomial(double * coefficients, int degree, dim_t dim, double scale) {
}

double add(double * arr, int N) {
    double total = 0;
    for (int i = 0; i < N; i++) {
        total += arr[i];
    }
    return total;
}

double average(double * arr, int N) {
    double sum = add(arr, N);
    return sum / (double)N;
}

double standard_deviation(double * x, double mean, int N) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += pow(x[i] - mean, 2);
    }
}

double pearson_correlation(double * x, double * y, int N) {
    double mean_x = average(x, N);
    double mean_y = average(y, N);

    double sigma_x = standard_deviation(x, mean_x, N);
    double sigma_y = standard_deviation(y, mean_y, N);

    double bottom = sqrt(sigma_x) * sqrt(sigma_y);
    double top = 0;
    for (int i = 0; i < N; i++) {
        top += (x[i] - mean_x) * (y[i] - mean_y);
    }
    return top / bottom;
}

