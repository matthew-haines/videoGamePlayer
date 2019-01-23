#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include "Hangman.h"
// #include "box-muller.h"  if we really want to, we can put functions into .h files
// #include "Structure.h"
// #include "Add_Rand_Player.h"
// #include "Add_User_Player.h"
// #include "Output_Player.h"
// #include "User_Interface.h"
#define NUM_WORDS 5
#define WORD_LEN 20
#define MAX_N 100
#define MAX_TPSC 100000
#define MEAN_TPSC 50000
#define STD_DEV_TPSC 10000

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

struct node{
    user value;
    struct node * lc;
    struct node * rc;
};

double normal(double mu, double sigma, int sd) {
    // Performs box-muller transform on uniform random variables and returns
    // random variable in normal distribution with mean mu and standard deviation sigma
    srand(sd);
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    
    double rand_norm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return rand_norm * sigma + mu;
}

int compare_usrnm(struct node parent, struct node child) {
    if(strcmp(parent.value.usrnm,child.value.usrnm) < 0) return 1; //go right
    if(strcmp(parent.value.usrnm,child.value.usrnm) > 0) return 0; //go left;
    return -1;
}

int sum_dob(dob input)  {
    return (((input.yr << (9)) + input.mth) << 5) + input.dy;
}

int compare_dob(struct node parent, struct node child) {
    if(sum_dob(parent.value.birth) > sum_dob(child.value.birth)) return 1;
    if(sum_dob(parent.value.birth) < sum_dob(child.value.birth)) return 0;
    return -1;
}

int compare_score(struct node parent, struct node child) {
    if(parent.value.tpSc > child.value.tpSc) return 1;
    if(parent.value.tpSc < child.value.tpSc) return 0;
    return -1;
}

void insert(struct node * to, user what, int (*compare_func)(struct node parent, struct node child)){
    if(to->value.usrnm[0] == 0){
        to->value = what;
        return;
    }
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->value = what;
    temp->lc = NULL;
    temp->rc = NULL;
    if(compare_func(*to, *temp)){
        if(to->rc) insert(to->rc, temp->value, compare_func);
        else{
            to->rc = temp;
            return;
        }
    }else{
        if(to->lc) insert(to->lc, temp->value, compare_func);
        else{
            to->lc = temp;
            return;
        }
    }
    return;
}

struct node * search(struct node * target, user find){
    if(strcmp(target->value.usrnm,find.usrnm) == 0){
        return target; //found;
    }
    if(strcmp(target->value.usrnm,find.usrnm) < 0 && target->rc) return search(target->rc, find);
    else if(target->lc) return search(target->lc,find);
    
    return (struct node *)-1; //not found
}

void PrintBST(struct node * BST){
    if(BST->lc) PrintBST(BST->lc);
    printf("%s %d %d/%d/%d\n", BST->value.usrnm, BST->value.tpSc, BST->value.birth.mth, BST->value.birth.dy, BST->value.birth.yr);
    if(BST->rc) PrintBST(BST->rc);
}

void Recur(struct node * What,int (*compare_func)(struct node parent, struct node child), struct node * Dummy){
    if(Dummy->value.usrnm[0] == 0) Dummy->value = What->value;
    else insert(Dummy,What->value, compare_func);
    
    if(What->lc) Recur(What->lc,compare_func, Dummy);
    if(What->rc) Recur(What->rc,compare_func, Dummy);
}

void reSort(struct node * What,int (*compare_func)(struct node parent, struct node child)){
    struct node Dummy;
    Dummy.rc = NULL;
    Dummy.lc = NULL;
    Dummy.value.usrnm[0] = 0;
    Recur(What, compare_func, &Dummy);
    What->value = Dummy.value;
    What->rc = Dummy.rc;
    What->lc = Dummy.lc;
}

void get_yr(user *p){
    int num;
    printf("Please enter the year:\n");
    do{
        scanf(" %d", &num);
        if(num < 1990 || num > 2010) printf("Year is invalid. Please try again.\n");
    }while(num < 1990 || num > 2010);
    p->birth.yr = num;
}

void get_mnth(user *p){
    int num;
    printf("Please enter the month:\n");
    do{
        scanf(" %d", &num);
        if(num < 1 || num > 12) printf("Month is invalid. Please try again.\n");
    }while(num < 1 || num > 12);
    p->birth.mth = num;
}

void get_day(int yr, int mnth, user *p){
    int lng[7] = {1, 3, 5, 7, 8, 10, 12};
    int i;
    int num;
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
        scanf(" %d", &num);
        if(num < 1 || num > chk) printf("Date is invalid. Please try again.\n");
    }while(num < 1 || num > chk);
    p->birth.dy = num;
}

void get_usrnm(struct node * Head,user *p){
    int chk;
    char name[20];
    do{
        chk = 1;
        fflush(stdin);
        printf("Enter name:\n");
        gets(name);
        strcpy(p->usrnm, name);
        if(search(Head,*p) != (struct node *)-1){
            chk = 0;
            printf("Username taken. Please try again.\n");
        }else if(strlen(name)<6){
            chk = 0;
            printf("Username too short. Please try again.\n");
        }else if(strlen(name) > 10){
            chk = 0;
            printf("Username too long. Please try again.\n");
        }
    }while(chk==0);
    strcpy(p->usrnm, name);
}

/*
void get_ts(user *p){  //user must play game in order to get top score
    int topSc;
    do{
        printf("Enter Top Score:");
        scanf(" %d", &topSc);
        fflush(stdin);
        if(topSc < 0) printf("Score is negative. Please try again.\n");
        else if(topSc > 500000) printf("Score is too high. Please try again.\n");
    }while(topSc < 0 || topSc > 500000);
    p->tpSc = topSc;
}*/

int pswrd_strength(char *s){
    int i, up, low, num, other;
    up = low = num = other = 0;
    for(i=0; s[i] != 0; i++){
        if(isupper((int)s[i])) up = 1;
        else if(islower((int)s[i])) low = 1;
        else if(isdigit((int)s[i])) num = 1;
        else other = 1;
    }
    return up+low+num+other;
}

void get_pswrd(user *p){
    char pswrd[10];
    char pswrd2[10];
    int chk;
    do{
        chk = 0;
        fflush(stdin);
        printf("Enter password:");
        gets(pswrd);
        if(strlen(pswrd) < 5){
            chk = 1;
            printf("Password is too short. Please try again.\n");
            continue;
        }else if(strlen(pswrd) > 10){
            chk = 1;
            printf("Password is too long. Please try again.\n");
            continue;
        }else if(pswrd_strength(pswrd) <=2){
            chk = 1;
            printf("THATT PASSWORD IS WEAKKKKKKKK. MAKE ANOTHER ONE.\n");
            continue;
        }
        
        printf("Enter password again:");
        fflush(stdin);
        gets(pswrd2);
        if(strcmp(pswrd, pswrd2) != 0){
            chk = 1;
            printf("Password do not match. Please try again.\n");
        }
        
    }while(chk!=0);
    strcpy(p->pswrd, pswrd);
}


void add_user_player(struct node * Head){
    //dte dob;
    int chk = 0;
    user p;
    get_usrnm(Head, &p); //WORKS
    //get_ts(&p); //WORKS
    p.tpSc = 0;
    get_pswrd(&p); //WORKS
    get_yr(&p);
    get_mnth(&p);
    get_day(p.birth.yr, p.birth.mth, &p); //WORKS
    reSort(Head, compare_usrnm);
    insert(Head, p, compare_usrnm);
}


int ask_add(){
    int num;
    printf("Enter how many players do you wish to add:");
    scanf(" %d", &num);
    return num;
}


void add_rand_name(struct node * fle, user *p, int sd){
    int i, j, lngth, alph, f;
    srand(sd);
    lngth = rand()%3+6;
    user temp;
    char name[lngth+1];
    do{
        for(j=0; j<lngth; j++){
            alph = rand()%2;
            if(alph==0) name[j] = rand()%10+48;
            else name[j] = rand()%26+97;
        }
        name[j]=0;
        strcpy(temp.usrnm, name);
        struct node * f = search(fle, temp);
    }while(f==-1);
    strcpy(p->usrnm, name);
}

void add_pswrd(user *p, int sd){
    srand(sd);
    int tp; //0 for digit, 1 for lower case, 2 for upper case
    int lngth, i;
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

void add_tpSc(user *p, int sd){
    p->tpSc = (int)normal(MEAN_TPSC, STD_DEV_TPSC,sd);
}

void add_dob(user *p, int sd){
    srand(sd);
    int i;
    int ar[7] = {1, 3, 5, 7, 8, 10, 12};
    p->birth.yr = rand()%21+1990;
    p->birth.mth = rand()%12+1;
    p->birth.dy = 0;
    for(i=0; i<6; i++){
        if(p->birth.mth == ar[i]) p->birth.dy = -1;
    }
    if(p->birth.dy==-1) p->birth.dy = rand()%31+1;
    else if(p->birth.mth==2 && p->birth.yr%4==0) p->birth.dy = rand()%29+1;
    else if(p->birth.mth == 2) p->birth.dy = rand()%28+1;
    else p->birth.dy = rand()%30+1;
}

void add_rand_player(struct node * Head){
    int i, j;
    int chk = 0;
    int sd;
    srand(time(NULL));
    int num = ask_add();
    user ins;
    for(i=0; i<num; i++){
        sd = rand();
        add_rand_name(Head, &ins, sd);
        add_pswrd(&ins, sd); //WORKS
        add_tpSc(&ins, sd); //WORKS
        add_dob(&ins, sd);
        insert(Head,ins,compare_usrnm);
    }
}

int find_id(struct node Head){
    user what;
    printf("Enter A user to find:");
    scanf("%s", what.usrnm);
    reSort(&Head,compare_usrnm);
    struct node * a = search(&Head, what);
    if(a == (struct node *)-1){
        printf("This user was not found\n");
        return 0;
    }
    else{
        printf("%s found here are the detail:\n Top score: %d \n Date of Birth: %d/%d/%d\n", a->value.usrnm, a->value.tpSc, a->value.birth.mth, a->value.birth.dy, a->value.birth.yr);
        return 1;
    }
}



void RecurDel_Ts(struct node * source, struct node * Target){
    if(source->lc) RecurDel_Ts(source->lc, Target);
    insert(Target, source->value, compare_score);
    if(source->rc) RecurDel_Ts(source->rc, Target);
}

void del_ts(struct node * Head){
    struct node * Temp = (struct node *)malloc((sizeof(struct node)));
    Temp->lc = NULL;
    Temp->rc = NULL;
    int y;
    printf("Enter the value you want to delete:");
    scanf("%d", &y);
    user na;
    na.tpSc = y;
    strcpy(na.usrnm, "DUMMY:)))");

    insert(Temp,na,compare_score);
    RecurDel_Ts(Head, Temp);

    Head->value = Temp->lc->value;
    Head->rc = Temp->lc->rc;
    Head->lc = Temp->lc->lc;
}

struct node * delNode(struct node * Head, user find, int (* compare_func)(struct node parent, struct node child)){
    if(Head == NULL) return Head;
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->value = find;
    temp->rc = NULL;
    temp->lc = NULL;
    if(compare_func(*Head,*temp) == 1){
       Head->rc = delNode(Head->rc, find, compare_func);
    }
    else if(compare_func(*Head,*temp) == 0){
       Head->lc = delNode(Head->lc, find, compare_func);
    }
    else{
        if(Head->rc == NULL){
            temp = Head->lc;
            return temp;
        }
        else if(Head->lc == NULL){
            temp = Head->rc;
            return temp;
        }
        struct node * current = Head->rc; //get minimum in right subtree
        while(current->lc != NULL) current = current->lc; //get min still
        Head->value = temp->value;
        Head->rc = delNode(Head->rc, temp->value, compare_func);
    }
    return Head;
}

void del_id(struct node * Head){
    char del[100];
    user temp;
    printf("Enter name to delete:");
    scanf("%s", temp.usrnm); //try to use gets
    fflush(stdin);
    reSort(Head, compare_usrnm);
    delNode(Head, temp, compare_usrnm);
}
void ReadDb(FILE * Source, char *Name, struct node * Head){
  Source = fopen(Name, "rb+");
  user temp;
  while(!feof(Source)){
    fread(&temp, sizeof(user), 1, Source);
    if(temp.usrnm[0] != 0) //make sure it is a user (sometimes things get left over for some reason)
    insert(Head, temp, compare_usrnm);
  }
  fclose(Source);
}

void WriteDb(FILE * Source, char *Name, struct node * Head){
   if(Source == NULL) Source = fopen(Name, "wb+");
   fwrite(&Head->value, sizeof(user), 1, Source);

   if(Head->lc) WriteDb(Source,Name,Head->lc); //traverse BST
   if(Head->rc) WriteDb(Source,Name,Head->rc); //traverse BST

}
int menu_options(struct node * Tree){
    int inpt;
    int i;
    printf("Menu Options:\n1: Add random numbers."
           "\n2: Output Players.\n3: Add Player."
           "\n4: Delete Player by LoginID"
           "\n5: Delete Players by Top Score"
           "\n6: Sort Players by LoginID"
           "\n7: Sort Players by Date of Birth"
           "\n8: Sort Players by Top Score"
           "\n9: Find Players by LoginID"
           "\n10: Quit\n");
    scanf("%d", &inpt);
    fflush(stdin);
    switch(inpt){
        case 1:
            add_rand_player(Tree);
            break;
        case 2:
            PrintBST(Tree);
            break;
        case 3:
            add_user_player(Tree); //works?
            break;
        case 4:
            del_id(Tree);
            break;
        case 5:
            del_ts(Tree);
            break;
        case 6:
            reSort(Tree, compare_usrnm);
            break;
        case 7:
            reSort(Tree,compare_dob);
            break;
        case 8:
            reSort(Tree,compare_score);
            break;
        case 9:
            find_id(*Tree);
            break;
        case 10:
            return -1;
        default:
            break;
    }
      system("pause");
      system("cls");
    return 1;
}

int main() {
    struct node Head;
    Head.lc = NULL;
    Head.rc = NULL;
    Head.value.usrnm[0] = 0;


    
    FILE * Source;
    char fileName[100];
    strcpy(fileName, "StorePlayers.txt");
    ReadDb(Source, fileName, &Head);

    int x = 1;

    while(x == 1) x = menu_options(&Head);
    Source = NULL;
    WriteDb(Source, fileName, &Head);
    
    return 0;
}


int main() {
    user p[200];
    int n = 0;
    int x = 1;
    int i;

    while(x == 1) x = menu_options(p, &n);
    return 0;
}
