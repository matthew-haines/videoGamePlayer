#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "structure.h"
#include "header.h" //placement name for function header

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

int chck_name(user *fle, char nm[]){ //Slow algorithm for checking duplicate user names
    int i, j;
    for(i=0; i<101; i++){
        j = 0;
        while(nm[j] == fle[i].usrnm[j] && nm[j] != 0) j++;
        if(nm[j] == 0 && fle[i].usrnm[j]==0) return 0;
    }
    return 1;
}

void add_user_player(user *fle){
    char usrnm[10];
    char pswrd[10];
    char pswrd2[10];
    int tpSc;
    dte dob;
    int chk = 0;

    do{
        printf("Enter username:");
        scanf(" %s", usrnm);
        chk = chck_name(fle, usrnm);
    }while(chk==1);


    do{
        printf("Enter password:");
        scanf(" %s", pswrd);
        printf("Enter password again:");
        scanf(" %s", pswrd2);
        chk = strcmp(pswrd, pswrd2);
    }while(chk==0);

    printf("Enter Top Score:");
    scanf(" %d", &tpSc);

    printf("Enter Date of Birth\nMonth:%d\nDay:%d\nYear:%d.", dob.mnth, dob.dy, dob.yr);

    /***
        STILL NEED TO ADD TO DATABASE. WHERE??
    ***/
}


int main() {
    return 0;
}

