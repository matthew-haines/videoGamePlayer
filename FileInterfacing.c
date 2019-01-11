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
    char pswrd[10];
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
        if(found == 1) printf("User Name Taken, try again\n");
        if(len > 8) printf("Please make a name lower than 8 characters in length\n");
    }while(found == 1);
    int i = 0;
    while(Target[i].usrnm[0] > 0) i++; //get past used data;
    strcpy(Target[i].usrnm, temp);
    
    scanf("%s", Target[i].pswrd); //need to place restrictions
    scanf("%d %d %d", &Target[i].birth.mth, &Target[i].birth.dy, &Target[i].birth.yr);
}

void load(FILE * Source, user * Target){
    int i = 0;
    while(!feof(Source)){
        fread(&(Target[i]),sizeof(user),1,Source); //reading
        i++;
    }
}

void printUsers(user * Source){
    int i = 0;
    while (Source[i].usrnm[0] > 0) {
        printf("%s\n", Source[i].usrnm);
        printf("%s\n", Source[i].pswrd);
        printf("%d %d %d\n", Source[i].birth.mth, Source[i].birth.dy, Source[i].birth.yr);
        i++;
    }
}

void updateFile(user * Source, FILE * Target){ //write database
        fwrite(Source,sizeof(user),sizeof(Source),Target);
}

//struct Hash{
//    size_t data;
//    size_t key;
//};git 
//size_t hashCode(size_t key){
//    return key;
//}

int main(){
    FILE * Data = fopen("/Users/Wu/Downloads/ONLYvalues.txt", "rb+"); //This was my file :) change it up when you use it :)
    user Users[10];
    load(Data, Users);
    printUsers(Users);
    for(int i = 0; i < 3;i++){
        create(Users);
    }
    fclose(Data);
    
    Data = fopen("/Users/Wu/Downloads/ONLYvalues.txt", "wb+");
    updateFile(Users,Data);
    fclose(Data);
}
