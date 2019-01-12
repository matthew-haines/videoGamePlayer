#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

/***
    Should be done
    Not tested
***/

typedef struct {
    int mnth;
    int dy;
    int yr;
} dte;

typedef struct {
    char usrnm[10];
    int pswrd;
    double salt;
    dob birth;
    int tpSc;
    int fre; //1 if spot is free, 0 if taken
    int dys_old; //days old for comparison (not accurate)
} user;

void usrnm_qcksort(user *ar, int l, int h){
    if(l<h){
        int pvt = partition(ar, l, h);
        qcksort(ar, l, pvt-1);
        qcksort(ar, pvt+1, h);
    }
}
int usrnm_partition(user *ar, int l, int h){
    int i = l;
    int j;
    char temp[10];
    int n;

    for(j=l; j<h; j++){
        n = strcmp(ar[j].usrnm, ar[h].usrnm);
        if(n < 0){
            strcpy(temp, ar[i].usrnm);
            strcpy(ar[i].usrnm, ar[j].usrnm);
            strcpy(ar[j].usrnm, temp);
            i++;
        }
    }

    strcpy(temp, ar[i].usrnm);
    strcpy(ar[i].usrnm, ar[h].usrnm);
    strcpy(ar[h].usrm, temp);

    return i;
}

int main() {
    int i;
    user fle[101];
    for(i=0; i<101; i++) fle[i].tpSc = 100-i;
    qcksort(fle, 0, 100);
    for(i=0; i<101; i++) printf("%d ", fle[i].tpSc);

    return 0;
}
