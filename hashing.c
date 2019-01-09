#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
/* Secure Storage Algorithm
 * 
 * Each time a new user is made, generate a salt (random sequence of characters)
 * 
 * The salt string is prepended to the username and it is hashed and added to a 
 * struct of type user
 *
 * The salt string is prepended to the password and it is hashed and added to a
 * struct of type user
 *
 * The salt string is added to a struct of type user
 *
 * Other stuff is added to struct of type user, we dont really need to hash DOB
 *
 * Everytime the user tries to log on, their credentials are hashed and compared
 * against their previously hashed credentials, if they are a match, the user 
 * is authenticated and they are allowed to log on.
 */
typedef struct {
    int month;
    int day;
    int year;
} dob;

typedef struct {
    int username;
    int password;
    float salt;
    dob birth;
    int topScore;
} user;

const int salt_len = 8;
user users[512];
unsigned int userCount = 0;

int r(int min, int max){
    // go online to determine what the rand function does
	return rand()%(max-min+1) + min;
}

void generate_salt(char * target) {
    // 8 Char salt
    srand(time(NULL));
    for (int i = 0; i < salt_len; i++) {
        target[i] = r('a', '9');
    }
}

void concatenate(char * s1, char * s2, char * output) {
    int i = 0;   
    while (s1[i]) {
        output[i] = s1[i];
        i++;
    }
    int j = 0;
    while (s2[j]) {
        output[i] = s2[j];  
        i++;
        j++;
    }
}

int hash(char * input) {
    // djb2 algorithm
    unsigned long hash = 5381; // Prime
    int i;

    while (i = *input++) {
        hash = ((hash << 5) + hash) + i;
    }
    return hash;
}   

void writeDB() {
    FILE *dbfile;
    dbfile = fopen("playerDB.dat", "w+");
    for (int i = 0; i < userCount; i++) {
        fwrite(, sizeof(user), 1, dbfile);
    }
}

void loadDB() {
    FILE *dbfile;
    dbfile = fopen("playerDB.dat", "r");
    for (int i = 0; i < 512; i++) {
        user *temp = malloc(sizeof(user));
        fread(temp, sizeof(user), 1, dbfile);
        users[i] = *temp;
    }
    user *temp = malloc(sizeof(user));
    fread(temp, sizeof(user), 512, dbfile);
    
}

int main() {
    users[0].username = 512;
    writeDB();
}
