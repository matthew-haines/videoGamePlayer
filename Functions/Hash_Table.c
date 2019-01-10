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

typedef struct {
    char usrnm[10];
    int pswrd;
    double salt;
    dob birth;
    int tpSc;
    int fre;
} user;

int search(user * Target, char * Find){ //Search for specified username 0 is not found, 1 is found
    int i = 0;
    while(Target[i].usrnm[0] > 0){
        if(strcmp(Target[i].usrnm, Find) == 0) return 1;
        i++;
    }
    return 0;
}
void create(user * Target){
    int found;
    int len;
    char temp[10];
    do{
        printf("Enter Username:");
        scanf("%s", temp);
        
        found = search(Target, temp);
        len = strlen(temp);
        if(found == 1 || len > 8 || len < 6) printf("invalid try again\n");
    }while(found == 1);
    int i = 0;
    while(Target[i].usrnm[0] > 0) i++; //get past used data;
    strcpy(Target[i].usrnm, temp);
    scanf("%d", &Target[i].pswrd); //need to place restrictions
    scanf("%d %d %d", &Target[i].birth.mth, &Target[i].birth.dy, &Target[i].birth.yr);
}
void load(FILE * Source, user * Target){
    int i = 0;
    while(!eof(Source)){
        fread(Target,sizeof(user),1,Source);
    }
}
//struct Hash{
//    size_t data;
//    size_t key;
//};
//size_t hashCode(size_t key){
//    return key;
//}

int main(){
    FILE * Data = fopen("/Users/Wu/Downloads/ONLYvalues.txt", "rb+");
    user Users[10];
    load(Data, Users);
    char temp[10];
}
