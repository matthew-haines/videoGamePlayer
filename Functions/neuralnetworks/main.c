#include <stdlib.h>
#include <math.h>
#include "../box-muller.h"
// GNU Scientific Librarys
#include <gsl/gsl_matrix.h>

const int input_size = 8;
const int l1_size = 16;
const int l2_size = 32;
const int out_size = 2;

typedef struct {
    void (*forward)(gsl_matrix x);
    void (*backward)(gsl_matrix x);
} activation_t;

typedef struct {
    gsl_matrix * w;
    gsl_matrix * dw;
    gsl_matrix * b;
    gsl_matrix * bw;
    activation_t * activation;
} layer_t;

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double sigmoid_derivative(double x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

double RELU(double x) {
    if (x > 0) return x;
    return 0;
}

double RELU_derivative(double x) {
    if (x > 0) return 1;
    return 0;
}

void element_wise(gsl_matrix * in, double (*function)(double x), gsl_matrix * out) {
    for (int i = 0; i < out->size1; i++) {
        for (int j = 0; j < out->size2; j++) {
            gsl_matrix_set(out, i, j, function(gsl_matrix_get(in, i, j)));
        }
    }
    return;
}

void guassianInit(gsl_matrix * matrix) {
    for (int i = 0; i < matrix->size1; i++) {
        for (int j = 0; j < matrix->size2; j++) {
            gsl_matrix_set(matrix, i, j, normal(0.0, 0.001));
        }
    }
    return;
}

layer_t createLayer(int in_size, int out_size) {
    layer_t * layer = (layer_t *)malloc(sizeof(layer_t));
    layer->w = gsl_matrix_alloc(in_size, out_size);
    layer->dw = gsl_matrix_alloc(in_size, out_size);
    layer->b = gsl_matrix_alloc(1, out_size);
    layer->bw = gsl_matrix_alloc(1, out_size);
    
    guassianInit(layer->w);
    guassianInit(layer->b);
    return * layer;
}

int main() {
    layer_t l1 = createLayer(input_size, l1_size);
    layer_t l2 = createLayer(l1_size, l2_size);
    layer_t l3 = createLayer(l2_size, out_size);


}
