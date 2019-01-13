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

void usrnm_qcksort(user *ar, int l, int h){
    if(l<h){
        int pvt = usrnm_partition(ar, l, h);
        usrnm_qcksort(ar, l, pvt-1);
        usrnm_qcksort(ar, pvt+1, h);
    }
}
int usrnm_partition(user *ar, int l, int h){
    int i = l;
    int j;
    user temp;
    int n;

    for(j=l; j<h; j++){
        n = strcmp(ar[j].usrnm, ar[h].usrnm);
        if(n < 0){
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

int main() {
    int i;
    user p[10];
    for(i=0; i<10; i++) p[i].fre = i;
    strcpy(p[0].usrnm, "baa");
    strcpy(p[1].usrnm, "abc");
    strcpy(p[2].usrnm, "ab");
    strcpy(p[3].usrnm, "b");
    strcpy(p[4].usrnm, "abd");
    strcpy(p[5].usrnm, "a");
    strcpy(p[6].usrnm, "ca");
    strcpy(p[7].usrnm, "aaa");
    strcpy(p[8].usrnm, "aba");
    strcpy(p[9].usrnm, "ba");

    usrnm_qcksort(p, 0, 9);

    for(i=0; i<10; i++) printf("%s %d\n", p[i].usrnm, p[i].fre);

    return 0;
}
