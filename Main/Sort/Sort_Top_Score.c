#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

/***
    Should be done
    Test 1 Passed
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
    dte birth;
    int tpSc;
    int fre; //1 if spot is free, 0 if taken
    int dys_old; //days old for comparison (not accurate)
} user;

void ts_qcksort(user *ar, int l, int h){
    if(l<h){
        int pvt = ts_partition(ar, l, h);
        ts_qcksort(ar, l, pvt-1);
        ts_qcksort(ar, pvt+1, h);
    }
}
int ts_partition(user *ar, int l, int h){
    int i = l;
    int j;
    user temp;

    for(j=l; j<h; j++){
        if(ar[j].tpSc>=ar[h].tpSc){
            temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
            i++;
        }
    }

    temp = ar[i];
    ar[i] = ar[h];
    ar[h] = temp;

    return i;
}

int main(){
    int i;
    user p[10];
    for(i=0; i<10; i++) p[i].fre = i;
    p[0].tpSc = 5;
    p[1].tpSc = 3;
    p[2].tpSc = 8;
    p[3].tpSc = 2;
    p[4].tpSc = 9;
    p[5].tpSc = 6;
    p[6].tpSc = 7;
    p[7].tpSc = 1;
    p[8].tpSc = 10;
    p[9].tpSc = 4;
    ts_qcksort(p, 0, 9);
    for(i=0; i<10; i++) printf("%d %d\n", p[i].tpSc, p[i].fre);
    return 0;
}
