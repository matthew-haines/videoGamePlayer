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
    char pswrd[10];
    double salt;
    dte birth;
    int tpSc;
    int fre; //1 if spot is free, 0 if taken
    int dys_old; //days old for comparison (not accurate)
} user;


void output(user *fle, int n){
    int i;
    printf("LoginID.Password.Date of Birth.Top Score:");
    for(i=0; i<n; i++) printf("%s.%s.%d/%d/%d.%d\n", fle[i].usrnm, fle[i].pswrd, fle[i].birth.mnth, fle[i].birth.dy, fle[i].birth.yr, fle[i].tpSc);
}

int main() {
    return 0;
}

