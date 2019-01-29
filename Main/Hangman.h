#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "query-dictionary.h"
#define MAX_L 7
#define DICT_LIST 8
#define START_SCORE 1000

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
    " |  |    \n"
    " | o--- < \n"
    "--- |     \n");
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

void print_word(int lngth, char *outpt){
    int j;
    printf("Word is:");
    for(j=0; j<lngth; j++)printf("%c", outpt[j]);
    printf("\n");
}

void print_wrong(char *bnk, int bnk_num){
    int j;
    printf("Wrong Characters: ");
    for(j=0; j<bnk_num; j++) printf("%c ", bnk[j]);
    printf("\n\n");
    return;
}

void guess(char lttr, int *rtrn, int *hlth, int lngth, char *bnk, int *bnk_num, char *word, char *outpt, int *score){
    int i, j;
    *rtrn = 1;
    int no = 0;
    int sim = 0;

    for(j=0; j<*bnk_num; j++){
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
            *score += 5000;
        }
    }

    if (sim == 1)printf("\nYou have already guessed: %c\n",lttr);
    else if (no == 0){
        printf("\n'%c' is not in the word\n", lttr);
        *hlth += 1;
        bnk[*bnk_num] = lttr;
        *bnk_num += 1;
        *score -= 100;
    }else if (no == 1) printf("\n'%c' is in the word\n", lttr);

    printf("Lives left: %d \n", (MAX_L-*hlth));

    if (*hlth >= MAX_L){
        printf("Sorry, you have ran out of lives. Please try again.\n");
        *score = 0;
        *rtrn = 1;
        return;
    }

    for(i=0; i<lngth; i++){
        if(outpt[i] == '-') *rtrn = 0;
    }
}

int hangman(){
    char lst[][50] = {"Girrafe", "Programming", "Lion", "Matthew is rawr", "Hangman", "Apple", "Hello", "Pineapple"};
    char bnk[50], word[50], outpt[50];
    int bnk_num, lvs, num;
    char inpt;
    int ran, lngth, i, j;
    int score = START_SCORE;
    char s[30];

    srand((unsigned)time(NULL));
    rand();


    /*FILE *f;
    f = fopen("Words.txt", "r");
    int n_line, ct;
    ct = 0;
    n_line = rand()%NUM_WORDS;


    if(f == NULL) return -1;

    while(fgets(s, WORD_LEN, f) && ++ct < n_line){}

    printf("%s", s);*/

    num = bnk_num = lvs = 0;

    printf("Welcome to HANGMAN!\n");
    system("pause");
    system("cls");

    strcpy(word, lst[rand()%DICT_LIST]);

    lngth = strlen(word);

    for(i=0; i<lngth; i++){
        if(word[i] == ' ') outpt[i] = ' ';
        else outpt[i] = '-';
    }

    while(num != 1){
        print_man(lvs);
        print_wrong(bnk, bnk_num);
        print_word(lngth, outpt);
        printf("SCORE:%d\n", score);
        fflush(stdin);
        printf("Enter guess:");
        inpt = getchar();
        guess(inpt, &num, &lvs, lngth, bnk, &bnk_num, word, outpt, &score);
        system("pause");
        system("cls");
    }

    if(lvs != MAX_L){
        printf("\nCongratualations, you got it: ");
        puts(word);
    }else dead();

    return score;
}



