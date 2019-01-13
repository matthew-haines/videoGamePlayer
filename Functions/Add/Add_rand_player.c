#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#define MAX_N 100

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

int ask_add(){
    int num;
    printf("Enter how many players you wish to add:");
    scanf(" %d", &num);
    return num;
}

int chck_name(user *fle, char nm[]){ //Slow algorithm for checking duplicate user names
    int i, j;
    for(i=0; i<101; i++){
        j = 0;
        while(nm[j] == fle[i].usrnm[j] && nm[j] != 0) j++;
        if(nm[j] == 0 && fle[i].usrnm[j]==0) return 0;
    }
    return 1;
}

void add_rand_name(user *fle, user *p){
    int i, j, lngth, alph, f;
    srand(time(NULL));
    lngth = rand()%3+6;
    f = 0;
    char name[lngth+1];
    do{
        for(j=0; j<lngth; j++){
            alph = rand()%2;
            if(alph==0) name[j] = rand()%10+48;
            else name[j] = rand()%26+97;
        }
        name[j]=0;
        f = chck_name(fle, name);
    }while(f==0);
    strcpy(p->usrnm, name);
}

void add_pswrd(user *p){
    srand(time(NULL));
    int tp; //0 for digit, 1 for lower case, 2 for upper case
    lngth = rand()%6+5;
    char password[lngth];
    for(i=0; i<lngth; i++){
        tp = rand()%3;
        if(tp==0) password[i] = rand()%10+48;
        else if(tp==1) password[i] = rand()%26+65;
        else password[i] = rand()%26+97;
    }
    password[i] = 0;
    strcpy(p->pswrd, password);
}

void add_tpSc(user *p){
    srand(time(NULL));
    p->tpSc = rand()%500001;
}

void add_dob(user *p){
    srand(time(NULL));
    int i;
    int ar[6] = {1, 3, 5, 7, 8, 10, 12};
    p->birth.yr = rand()%21+1990;
    p->birth.mnth = rand()%12+1;
    p->birth.dy = 0;
    for(i=0; i<6; i++){
        if(mp->birth.mnth == ar[i]) p->birth.dy = -1;
    }
    if(p->birth.dy==-1) p->birth.dy = rand()%31+1;
    else if(p->birth.mnth==2 && p->birth.yr%4==0) p->birth.dy = rand()%29+1;
    else p->birth.dy = rand()%30+1;
}

void add(user *fle){
    int i, j;
    int n = ask_add();
    for(i=0; i<n; i++){
        for(j=i; j<MAX_N; j++){
            if(fle[j].fre==0){
                add_rand_name(fle, &fle[j]);
                add_pswrd(&fle[j]);
                add_tpSc(&fle[j]);
                add_dob(&fle[j]);
            }
        }
    }
}

int main() {
    user fle[101];
    FILE * UserData;
    srand(time(NULL));
    printf("Hello World\n");
    return 0;
}
