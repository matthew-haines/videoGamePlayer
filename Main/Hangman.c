#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "query-dictionary.h"
#define MAX_L 8

int gss(char lttr, int rtrn, int *hlth);
void print_word();
void print_wrong(char *bnk);

void w0(){
    printf(""
    " ____   \n"
    " |  |   \n"
    " |      \n"
    " |      \n"
    " |      \n"
    " |      \n"
    " |      \n"
    "---     \n");
}
void w1(){
    printf(""
    " ____   \n"
    " |  |   \n"
    " |  0   \n"
    " |      \n"
    " |      \n"
    " |      \n"
    " |      \n"
    "---     \n");
}

void w2(){
    printf(""
    " ____   \n"
    " |  |   \n"
    " |  0   \n"
    " |  |   \n"
    " |      \n"
    " |      \n"
    " |      \n"
    "---     \n");
}

void w3(){
    printf(""
    " ____   \n"
    " |  |   \n"
    " |  0   \n"
    " | -|-  \n"
    " |      \n"
    " |      \n"
    " |      \n"
    "---     \n");
}

void w4(){
    printf(""
    " ____   \n"
    " |  |   \n"
    " |  0   \n"
    " | -|-  \n"
    " |  |   \n"
    " |      \n"
    " |      \n"
    "---     \n");
}

void w5(){
    printf(""
    " ____   \n"
    " |  |   \n"
    " |  0   \n"
    " | -|-  \n"
    " |  |   \n"
    " | /    \n"
    " |      \n"
    "---     \n");
}

void w6(){
    printf(""
    " ____   \n"
    " |  |   \n"
    " |  0   \n"
    " | -|-  \n"
    " |  |   \n"
    " | / \\ \n"
    " |      \n"
    "---     \n");
}

void dead(){
    printf(""
    " ____   \n"
    " |  |   \n"
    " |      \n"
    " |      \n"
    " |      \n"
    " |  | //\n"
    " | o--  \n"
    "--- | \  \n");
}


void print_man(int num){
    switch (num){
        case 0:
            w0();
            break;
        case 1:
            w1();
            break;
        case 2:
            w2();
            break;
        case 3:
            w3();
            break;
        case 4:
            w4();
            break;
        case 5:
            w5();
            break;
        case 6:
            w6();
            break;
        case 7:
            dead();
            break;
        default:
            break;
    }
    printf("\n");
    return;
}

int lngth;
char bnk[50];
int i, j;
int k;
int sim;
int lvs = 0;
char outpt[50];
char word[50];

int main(){
    /*HANGMAN GAME*/
    //char ** p;
    //p = getDict();
    char lst[][50] = {"hangman", "matthew is not my daddy", "armageddon", "today was not a good day", "hello world"};
    int num = 0;
    char inpt;
    int ran;
    time_t t;

    t = time(NULL);
    srand((unsigned) t);
    rand();

    printf("Welcome to HANGMAN!\n");
    system("pause");
    system("cls");

    strcpy(word, lst[1]);

    lngth = strlen(word);

    for(i=0; i<lngth; i++){
        if(word[i] == ' ') outpt[i] = ' ';
        else outpt[i] = '-';
    }

    //printf("The word is:");

    while(num != 1){
        print_man(lvs);
        print_wrong(bnk);
        print_word();
        printf("Enter guess:");
        fflush(stdin);
        inpt = getchar();
        gss(inpt, num, &lvs);
        system("pause");
        system("cls");
    }

    if(lvs != MAX_L){
        printf("\nCongratualations, you got it: ");
        puts(word);
    }

    return 0;
}

void print_word(){
    printf("Word is:");
    for(j=0; j<lngth; j++)printf("%c", outpt[j]);
    printf("\n");
}

void print_wrong(char *bnk){
    int j;
    printf("Wrong Characters: ");
    for(j=0; j<k; j++) printf("%c ", bnk[j]);
    printf("\n\n");
    return;
}

int gss(char lttr, int rtrn, int *hlth){
    rtrn = 1;
    int no = 0;
    sim = 0;

    for(j=0; j<k; j++){
        if(lttr == bnk[j]){
            sim = 1;
            break;
        }
    }

    for(j=0; j<lngth; j++){
        if(lttr == outpt[j]){
            sim = 1;
            break;
        }

        if(lttr == word[j]){
            outpt[j] = lttr;
            no = 1;
        }
    }

    if (sim == 1)printf("\nYou have already guessed: %c\n",lttr);
    else if (no == 0){
        printf("\n'%c' is not in the word\n", lttr);
        *hlth += 1;
        bnk[k] = lttr;
        k += 1;
    }else if (no == 1) printf("\n'%c' is in the word\n", lttr);

    printf("Lives left: %d \n", (5-*hlth));

    if (*hlth == MAX_L){
        printf("Sorry, you have ran out of lives. Please try again.\n");
        rtrn = -1;
        return rtrn;
    }

    for(i=0; i<lngth; i++){
        if(outpt[i] == '-') rtrn = 0;
    }

    return rtrn;
}



