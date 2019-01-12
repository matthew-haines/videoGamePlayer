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
    dte birth;
    int tpSc;
    int fre; //1 if spot is free, 0 if taken
    int dys_old; //days old for comparison (not accurate)
} user;

int f_age(user p){ //finding age in days; works don't touch
    dte today;
    int age = 0;
    if(age += (today.mnth-1)*31+today.dy-(p.birth.mnth-1)*31-p.birth.dy >= 0) age += (today.mnth-1)*31+today.dy-(p.birth.mnth-1)*31-p.birth.dy;
    else{
        age += -((today.mnth-1)*31+today.dy-(p.birth.mnth-1)*31-p.birth.dy);
        today.yr -= 1;
    }

    age += 365*(today.yr-p.birth.yr);
    printf("%d %d %d: %d %d %d: %d", today.yr, today.mnth, today.dy, p.birth.yr, p.birth.mnth, p.birth.dy, age);
    return age;
}

dte cur(){ //current date
    struct tm *t;
    time_t now;
    time(&now);
    t = localtime(&now);
    return (dte){t->tm_mon+1, t->tm_mday, t->tm_year+1900};
}

void age_user_ar(int *ar, user *fle, int n){ //Calculates age of user
    int i;
    for(i=0; i<n; i++) fle[i].dys_old = f_age(fle[i]);
}

/*void user_ar(int num, int *ar, user *f, int n){ //Creating an extra array for age or top Score for sorting, no point in doing this
    int i;
    if(num==0){
        for(i=0; i<n; i++) ar[i] = f[i].dys_old;
    }else{
        for(i=0; i<n; i++) ar[i] = f[i].tpSc;
    }
}*/

void dob_qcksort(user *ar, int l, int h){
    if(l<h){
        int pvt = dob_partition(ar, l, h);
        dob_qcksort(ar, l, pvt-1);
        dob_qcksort(ar, pvt+1, h);
    }
}
int dob_partition(user *ar, int l, int h){
    int i = l;
    int j;
    user temp;

    for(j=l; j<h; j++){
        if(ar[j].dys_old<=ar[h].dys_old){
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

    return 0;
}
