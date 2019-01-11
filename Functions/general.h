#include <stdlib.h>
#include <string.h>

#ifndef GENERAL_H_
#define GENERAL_H_

typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    char username[16];
    int password;
    float salt;
    date dob;
    int topScore;
} user;

/* 

I realized after writing this that the user would input an integer, not a string, oof

typedef struct {
    char key[16];
    int value;
    dictElement * next;
} dictElement;
// I was bored so I made a linked list dictionary thingy
dictElement december = {"december", 31, NULL};
dictElement november = {"november", 30, &december};
dictElement october = {"october", 31, &november};
dictElement september = {"september", 30, &october};
dictElement august = {"august", 31, &september};
dictElement july = {"july", 31, &august};
dictElement june = {"june", 30, &july};
dictElement may = {"may", 31, &june};
dictElement april = {"april", 30, &may};
dictElement march = {"march", 31, &april};
dictElement february = {"february", 28, &march};
dictElement january = {"january", 31, &february};

int find(char * lookup, dictElement * node) { // Recursive search
    if (strncmp(lookup, node->key, 9) == 0) {
        return node->value;
    }
    return find(lookup, node);
}
*/ 

int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int r(int min, int max){
	// go online to determine what the rand function does
	return rand()%(max-min+1) + min;
}

#endif