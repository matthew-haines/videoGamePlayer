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

int get_yr(){
    int num;
    printf("Please enter the year:\n");
    do{
        scanf(" %d", &num);
        if(num < 1990 || num > 2010) printf("Year is invalid. Please try again.\n");
    }while(num < 1990 || num > 2010);
    return num;
}

int get_mnth(){
    int num;
    printf("Please enter the month:\n");
    do{
        scanf(" %d", &num);
        if(num < 1 && num > 12) printf("Year is invalid. Please try again.\n");
    }while(num < 1 && num > 12);
    return num;
}

int get_day(int yr, int mnth){
    int lng[6] = {1, 3, 5, 7, 8, 10, 12};
    int i;
    int dy;
    int chk = 30;
    for(i=0; i<6; i++){
        if(mnth == lng[i]) chk = 31;
    }
    if(mnth == 2){
        if(yr % 4 == 0) chk = 29;
        else chk = 28;
    }

    printf("Please enter the day:\n");

    do{
        scanf(" %d", &dy);
        if(dy < 1 || dy > chk) printf("Date is invalid. Please try again.\n");
    }while(dy < 1 || dy > chk);
    return dy;
}

void add_user_player(user *fle, user *p){
    char name[10];
    char pswrd[10];
    char pswrd2[10];
    int topSc;
    dte dob;
    int chk = 0;

    do{
        chk = 1;
        printf("Enter username:");
        scanf(" %s", name);
        if(chck_name(fle, name)==0){
            chk = 0;
            printf("Username taken. Please try again.\n");
        }else if(strlen(name)<6){
            chk = 0;
            printf("Username too short. Please try again.\n");
        }else if(strlen(name > 10)){
            chk = 0;
            printf("Username too long. Please try again.\n");
        }
    }while(chk==0);
    strcmp(p->usrnm, name);

    do{
        printf("Enter password:");
        scanf(" %s", pswrd);
        printf("Enter password again:");
        scanf(" %s", pswrd2);

        if(strlen(pswrd) < 5){
            chk = 1;
            printf("Password is too short. Please try again.\n");
        }else if(strlen(pswrd) > 10){
            chk = 1;
            printf("Password is too long. Please try again.\n");
        }else if(strcmp(pswrd, pswrd2) != 0){
            chk = 1;
            printf("Password do not match. Please try again.\n");
        }
    }while(chk!=0);
    strcmp(p->pswrd, psrwd);

    do{
        printf("Enter Top Score:");
        scanf(" %d", &topSc);
        if(topSc < 0) printf("Score is negative. Please try again.\n");
        else if(topSc > 500000) printf("Score is too high. Please try again.\n");
    }while(topSc < 0 || topSc > 500000);
    p->tpSc = topSc;

    p->birth.yr = get_yr();
    p->birth.mnth = get_mnth();
    p->birth.dy = get_day(p->birth.yr, p->birth.mnth);

    /***
        STILL NEED TO ADD TO DATABASE. WHERE??
    ***/
}


int main() {
    return 0;
}

