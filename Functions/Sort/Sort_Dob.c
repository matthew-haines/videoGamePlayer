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
    if(cur.mnth*30+cur.dy-p.birth.mnth*30-p.birth.dy >= 0) age += cur.mnth*30+cur.dy-p.birth.mnth*30-p.birth.dy;
    else{
        age += -cur.mnth*30-cur.dy+p.birth.mnth*30+p.birth.dy;
        cur.yr -= 1;
    }

    age += 365*(cur.yr-p.birth.yr);
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
     p.birth = (dte){1, 1, 2019};
     dte d = cur();

    printf("%d", f_age(d, p));

    return 0;
}
