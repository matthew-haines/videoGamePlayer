#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

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
    int fre;
} user;

void sort_ts(){

}

int main() {
    user fle[101];
    srand(time(NULL));

    return 0;
}
