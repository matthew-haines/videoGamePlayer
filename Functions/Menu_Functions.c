#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "databaseOps.h"
#include "hashing.h"
// #include <ncurses.h> For pong


static const int maxUsers = 100;
static const int saltLen = 8;
static const int minUsernameLen = 6;
static const int maxUsernameLen = 8;
int userCount;

user users[maxUsers];

int getUsername(char * output) {
    int valid = 0;
    while (!valid) {
        printf("Input a desired username: ");
        char prehashed[maxUsernameLen];
        gets(prehashed);
        if (strlen(prehashed) < minUsernameLen) {
            printf("Username is less than %d characters, try again.\n", minUsernameLen);
            continue;
        }
        else if (checkTaken(prehashed, users)) {
            printf("Username is already taken, sorry, try again\n");
            continue;
        }
        else {
            valid = 1;
        }
    }
}

int addPlayer() {
    user temp;
    getUsername(temp.username);
    // Do the rest later
}

int main() {
    int userCount;
    int fileExists = loadDB(users);
    if (!fileExists) {
        userCount = 0;
    }
    else {
        userCount = fileExists;
    }

    while (1) { // Menu loop
        printf("Welcome to the game, there are currently %d registered users.\n", userCount);
        
    }
}
