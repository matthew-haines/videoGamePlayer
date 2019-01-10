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

void qcksort(user *ar, int l, int h){
    if(l<h){
        int pvt = partition(ar, l, h);
        qcksort(ar, l, pvt-1);
        qcksort(ar, pvt+1, h);
    }
}
int partition(user *ar, int l, int h){
    int i = l;
    int j;
    int temp;

    for(j=l; j<h; j++){
        if(ar[j].tpSc<=ar[h].tpSc){
            temp = ar[i].tpSc;
            ar[i].tpSc = ar[j].tpSc;
            ar[j].tpSc = temp;
            i++;
        }
    }

    temp = ar[i].tpSc;
    ar[i].tpSc = ar[h].tpSc;
    ar[h].tpSc = temp;

    return i;
}

int main() {
    user fle[101];


    return 0;
}
