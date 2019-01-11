#include "hashing.h"
#include "general.h"
#include <string.h>

#ifndef DATABASEOPS_H_
#define DATABASEOPS_H_

void writeDB(user * users) {
    // Writes array of users to file
	FILE *dbfile;
	dbfile = fopen("playerDB.txt", "w+");
    fprintf(dbfile, "%d\n", userCount);
	for (int i = 0; i < userCount; i++) {
	    fprintf(dbfile, "%s %d %f %d %d %d %d\n", 
			users[i].username, users[i].password, 
			users[i].salt, users[i].dob.day,
            users[i].dob.month, users[i].dob.year, 
			users[i].topScore);
	}
    fclose(dbfile);
}

int loadDB(user * users) {
    // Returns the user count and loads array of users
	FILE *dbfile;
    printf("Reading from DB...\n");
	dbfile = fopen("playerDB.txt", "r");
    if (dbfile) { // Checks if file exists
        fscanf(dbfile, "%d\n", &userCount);
        printf("%d users found\n", userCount);
        for (int i = 0; i < userCount; i++) {
            fscanf(dbfile, "%s %d %f %d %d %d %d\n", 
                &users[i].username, &users[i].password, 
                &users[i].salt, &users[i].dob.day, 
                &users[i].dob.month, &users[i].dob.year, 
                &users[i].topScore); 
        }
        fclose(dbfile);
        return userCount;
    }
    else {
        return -1;
    }
}

int checkTaken(char * username, user * users) {
    for (int i = 0; i < userCount; i++) {
        if (strncmp(username, users[i].username, 16)) return 1;
    }
    return 0;
}

void addUser(user newUser, user * users) {
    strncpy(users[*userCount].username, newUser.username, 16);
    users[*userCount].password = newUser.password;
    users[*userCount].salt = newUser.salt;
    users[*userCount].dob = newUser.dob;
    users[*userCount].topScore = newUser.topScore;
    userCount++;
}
#endif