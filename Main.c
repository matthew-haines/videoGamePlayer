#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    int mth;
    int dy;
    int yr;
} dob;

typedef struct {
    char usrnm[10];
    int pswrd;
    double salt;
    dob birth;
    int tpSc;
} user;

int main() {
    return 0;
}
