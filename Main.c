#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef struct {
    int mth;
    int dy;
    int yr;
} dob;

struct tm {
   int tm_sec;         /* seconds,  range 0 to 59          */
   int tm_min;         /* minutes, range 0 to 59           */
   int tm_hour;        /* hours, range 0 to 23             */
   int tm_mday;        /* day of the month, range 1 to 31  */
   int tm_mon;         /* month, range 0 to 11             */
   int tm_year;        /* The number of years since 1900   */
   int tm_wday;        /* day of the week, range 0 to 6    */
   int tm_yday;        /* day in the year, range 0 to 365  */
   int tm_isdst;       /* daylight saving time             */
};

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
