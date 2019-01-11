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
    dte birth;
    int tpSc;
    int fre;
    int dys_old; //in days (not accurate but used for comparison)
} user;

int f_age(user p){ //finding age in days; works don't touch
    dte today = cur();
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

void srt_dob(int *srted_dob, user *fle, int n){ //TO DO: Merge with quick sort, figure out data structure for storage
    int i;
    for(i=0; i<n; i++) srted_dob[i] = f_age();
}

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
        if(ar[j].tpSc<=ar[h].tpSc){ //enumerate the elements for more versatility
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
     user p;
     p.birth = (dte){10, 2, 2018};
     dte d = cur();

    f_age(d, p);

    return 0;
}
