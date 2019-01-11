#include "hashing.h"
#include "string.h"

#ifndef DATABASEOPS_H_
#define DATABASEOPS_H_

void writeDB(user * users, int userCount) {
    // Writes array of users to file
	FILE *dbfile;
	dbfile = fopen("playerDB.txt", "w+");
    fprintf(dbfile, "%d\n", userCount);
	for (int i = 0; i < userCount; i++) {
	    fprintf(dbfile, "%s %d %f %d %d %d %d\n", 
			users[i].username, users[i].password, 
			users[i].salt, users[i].birth.month, 
			users[i].birth.day, users[i].birth.year, 
			users[i].topScore);
	}
    fclose(dbfile);
}

int loadDB(user * users) {
    // Returns the user count and loads array of users
	FILE *dbfile;
    printf("Reading from DB...\n");
	dbfile = fopen("playerDB.txt", "r");
    int userCount;
    fscanf(dbfile, "%d\n", &userCount);
    printf("%d users found\n", userCount);
	for (int i = 0; i < userCount; i++) {
		fscanf(dbfile, "%s %d %f %d %d %d %d\n", 
			&users[i].username, &users[i].password, 
			&users[i].salt, &users[i].birth.month, 
			&users[i].birth.day, &users[i].birth.year, 
			&users[i].topScore); 
	}
    fclose(dbfile);
    return userCount;
}

int checkTaken(char * username, user * users, int userCount) {
    for (int i = 0; i < userCount; i++) {
        if (strncmp(username, users[i].username, 16)) return 1;
    }
    return 0;
}

int addUser(user newUser, user * users, int userCount) {
    strncpy(users[userCount].username, newUser.username, 16);
    users[userCount].password = newUser.password;
    users[userCount].salt = newUser.salt;
}
#endif