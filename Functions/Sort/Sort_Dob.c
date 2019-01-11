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
} user;

int f_age(dte cur, user p){ //finding age in days
    int age = 0;
    if(age += (cur.mnth-1)*31+cur.dy-(p.birth.mnth-1)*31-p.birth.dy >= 0) age += (cur.mnth-1)*31+cur.dy-(p.birth.mnth-1)*31-p.birth.dy;
    else{
        age += -((cur.mnth-1)*31+cur.dy-(p.birth.mnth-1)*31-p.birth.dy);
        cur.yr -= 1;
    }

    age += 365*(cur.yr-p.birth.yr);
    printf("%d %d %d: %d %d %d: %d", cur.yr, cur.mnth, cur.dy, p.birth.yr, p.birth.mnth, p.birth.dy, age);
    return age;
}

dte cur(){ //current date
    struct tm *t;
    time_t now;
    time(&now);
    t = localtime(&now);
    return (dte){t->tm_mon+1, t->tm_mday, t->tm_year+1900};
}

int main() {
     user p;
     p.birth = (dte){10, 2, 2018};
     dte d = cur();

    f_age(d, p);

    return 0;
}
