#include <stdlib.h>
#include <math.h>
#include "../box-muller.h"
// GNU Scientific Librarys
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

const int input_size = 8;
const int l1_size = 16;
const int l2_size = 32;
const int out_size = 1;

const int batch_size = 1;
const int epochs = 100;
const double learning_rate = 0.0001;

typedef struct {
    double (*forward)(double x);
    double (*backward)(double x);
} activation_t;

typedef struct {
    double (*forward)(double y_hat, double y);
    double (*backward)(double y_hat, double y);
} loss_t;

typedef struct {
    gsl_matrix * w;
    gsl_matrix * dw;
    gsl_matrix * b;
    gsl_matrix * x_cache;
    // gsl_matrix * db; not needed because dz = db 
    activation_t * activation;
} layer_t;

double sigmoid_func(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative_func(double x) {
    return sigmoid_func(x) * (1.0 - sigmoid_func(x));
}

double RELU_func(double x) {
    if (x > 0.0) return x;
    return 0.0;
}

double RELU_derivative_func(double x) {
    if (x > 0.0) return 1.0;
    return 0.0;
}

double MSE_func(double y_hat, double y) {
    return pow(y - y_hat, 2.0); 
}

double MSE_derivative_func(double y_hat, double y) {
    return 2.0 * (y - y_hat);
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
    layer->b = gsl_matrix_alloc(batch_size, out_size);
    
    guassianInit(layer->w);
    guassianInit(layer->b);
    return * layer;
}

void clear_grad(gsl_matrix * param) {
    gsl_matrix_set_all(param, 0.0);
}

void update_param(gsl_matrix * param, gsl_matrix * grad, double alpha) {
    gsl_matrix_scale(grad, alpha);
    gsl_matrix_add(param, grad);
    clear_grad(grad);
}

void forward_pass(layer_t layer, gsl_matrix * input, gsl_matrix * out) {
    // For Dense Layers
    gsl_matrix z;
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, input, layer.w, 0.0, &z);
    gsl_matrix_add(&z, layer.b);
    gsl_matrix a;
    element_wise(&z, layer.activation->forward, &a);
    *layer.x_cache = *input;
    *out = a;
}

void backward_pass(layer_t layer, gsl_matrix * input, gsl_matrix * out) {
    // For Dense Layers
    // Input is activated value of layer
    gsl_matrix dz;
    element_wise(input, layer.activation->backward, &dz);
    // db = dz
    update_param(layer.b, &dz, learning_rate);
    *out = *layer.w;
    // dw = x_cache
    update_param(layer.w, layer.x_cache, learning_rate);
}

void write_sample_matrix(gsl_matrix * sample, gsl_matrix * data, int index) {
    for (int i = 0; i < data->size2; i++) {
        gsl_matrix_set(sample, 1, i, gsl_matrix_get(data, index, i));
    }
}

int main() {
    activation_t sigmoid;
    sigmoid.forward = sigmoid_func;
    sigmoid.backward = sigmoid_derivative_func;

    activation_t RELU;
    RELU.forward = RELU_func;
    RELU.backward = RELU_derivative_func;

    loss_t MSE;
    MSE.forward = MSE_func;
    MSE.backward = MSE_derivative_func;

    layer_t l1 = createLayer(input_size, l1_size);
    layer_t l2 = createLayer(l1_size, l2_size);
    layer_t l3 = createLayer(l2_size, out_size);

    // Training
    gsl_matrix * X = gsl_matrix_alloc(10000, 8); // 10000 samples of size 8
    gsl_matrix * y = gsl_matrix_alloc(10000, 1);
    gsl_matrix * sample = gsl_matrix_alloc(1, 8);
    gsl_matrix * a1 = gsl_matrix_alloc(1, l1_size);
    gsl_matrix * da1 = gsl_matrix_alloc(1, l1_size);
    gsl_matrix * a2 = gsl_matrix_alloc(l1_size, l2_size);
    gsl_matrix * da2 = gsl_matrix_alloc(l1_size, l2_size);
    gsl_matrix * a3 = gsl_matrix_alloc(l2_size, out_size);
    gsl_matrix * da3 = gsl_matrix_alloc(l2_size, out_size);
    gsl_matrix * cost = gsl_matrix_alloc(10000, 1); // We can average this for metrics
    gsl_matrix * dcost = gsl_matrix_alloc(10000, 1); 

    for (int yes = 0; yes < epochs; yes++) {
        for (int i = 0; i < X->size1; i++) {
            write_sample_matrix(sample, X, i);

            // Forward
            forward_pass(l1, sample, a1);
            forward_pass(l2, a1, a2);
            forward_pass(l3, a2, a3);

            // element_wise(a3, MSE.forward, cost);
            // element_wise() whatever im bored
            backward_pass(l3, dcost, da2);
            backward_pass(l2, da2, da1);
            backward_pass(l1, da1, NULL);
        }
        printf("Epoch %d/%d", yes, epochs);
    }
}
