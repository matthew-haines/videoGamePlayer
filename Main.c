#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef struct {
    int mnth;
    int dy;
    int yr;
} dte;

typedef struct {
    char usrnm[10];
    int pswrd;
    double salt;
    //dob birth;
    struct tm *t;
    int tpSc;
    int fre; //1 if spot is free, 0 if taken
    int dys_old; //days old for comparison (not accurate)
} user;

int main() {
    user fle[101];
    srand(time(NULL));

    return 0;
}
