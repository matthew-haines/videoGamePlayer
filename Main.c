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
    //dob birth;
    struct tm *t;
    int tpSc;
    int fre;
} user;

int ask_add(){
    int num;
    printf("Enter how many players you wish to add:");
    scanf(" %d", &num);
    return num;
}

int chck(user *fle, char nm[]){ //Slow algorithm for checking duplicate user names
    int i, j;
    for(i=0; i<101; i++){
        j = 0;
        while(nm[j++] == fle[i].usrnm[j++] && nm[j] != 0);
        if(nm[j] == 0 && fle[i].usrnm[j]==0) return 0;
    }
    return 1;
}

void add_rand(user *fle, int to_add){
    int i, j, lngth, alph, f;
    srand(time(NULL));
    for(i=0; i<to_add; i++){
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
            f = chck(fle, name);
        }while(f==0);
        for(j=0; j<100; j++){
            if(fle.fre==0){
                strcpy(fle[j].usrnm, name);
                break;
            }
        }
    }
}

int main() {
    user fle[101];
    srand(time(NULL));

    return 0;
}
