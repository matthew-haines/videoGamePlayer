#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
//#include "Hangman.h"
#include "Structure.h"
#include "box-muller.h"
#include "BST.h"
#include "DeletePlayer.h"
#include "DB.h"
#include "Add_User_Player.h"
#include "Add_Rand_Player.h"
#include "Find.h"
#include "User_Interface.h"


int main() {
    struct node Head;
    Head.lc = NULL;
    Head.rc = NULL;
    Head.value.usrnm[0] = 0;

    FILE * Source;
    char fileName[100];
    strcpy(fileName, "StorePlayers.txt");
    //ReadDb(Source, fileName, &Head);
    user ad;
    ad.birth.dy = 0;
    ad.birth.mth = 0;
    ad.birth.yr = 0;
    ad.tpSc = 0;
    strcpy(ad.pswrd, "admin");
    strcpy(ad.usrnm, "admin");

    insert(&Head, ad, compare_usrnm);

    int x = 1;

    while(x == 1) x = menu_options(&Head);
    Source = NULL;
    WriteDb(Source, fileName, &Head);

    return 0;
}
