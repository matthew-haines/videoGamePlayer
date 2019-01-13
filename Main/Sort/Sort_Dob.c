#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

/***
    Should be done
    Test 1 Passed.
    Needs more testing.
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

dte cur(){ //current date
    struct tm *t;
    time_t now;
    time(&now);
    t = localtime(&now);
    return (dte){t->tm_mon+1, t->tm_mday, t->tm_year+1900};
}

void f_age(user *p){ //finding age in days; works don't touch
    dte today = cur();
    p->dys_old = 0;
    printf("%d T%d\n", today.yr, p->fre);
    if((today.mnth-1)*31+today.dy >= (p->birth.mnth-1)*31+p->birth.dy) p->dys_old += (today.mnth-1)*31+today.dy-(p->birth.mnth-1)*31-p->birth.dy;
    else{
        printf("%d T%d\n", today.yr, p->fre);
        p->dys_old += 31-p->birth.dy + (12-(p->birth.mnth))*31;
        p->dys_old += (today.mnth-1)*31+today.dy;
        today.yr -= 1;
    }
    printf("%d T%d\n", today.yr, p->fre);

    p->dys_old += 365*(today.yr-p->birth.yr);
    printf("%d %d %d: %d %d %d: %d\n", today.yr, today.mnth, today.dy, p->birth.yr, p->birth.mnth, p->birth.dy, p->dys_old);
}

void age_user_ar(user *fle, int n){ //Calculates age of user
    int i;
    for(i=0; i<n; i++) f_age(&fle[i]);
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
        if(ar[j].dys_old>=ar[h].dys_old){
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
    p[0].birth = (dte){6, 20, 1995};
    p[1].birth = (dte){4, 4, 2002};
    p[2].birth = (dte){1, 1, 1991};
    p[3].birth = (dte){12, 31, 1990};
    p[4].birth = (dte){2, 29, 2000};
    p[5].birth = (dte){11, 4, 2014};
    p[6].birth = (dte){1, 1, 1991};
    p[7].birth = (dte){6, 19, 1995};
    p[8].birth = (dte){5, 10, 1994};
    p[9].birth = (dte){12, 12, 1992};

    age_user_ar(p, 10);
    dob_qcksort(p, 0, 9);
    //for(i=0; i<10; i++) printf("%d\n", p[i].dys_old);
    for(i=0; i<10; i++) printf("%d\\%d\\%d %d\n", p[i].birth.mnth, p[i].birth.dy, p[i].birth.yr, p[i].fre);
    return 0;
}
