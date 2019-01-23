#include "hashing.h"
#include "general.h"
#include <string.h>

#ifndef DATABASEOPS_H_
#define DATABASEOPS_H_

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

void addUser(user newUser, user * users) {
    strncpy(users[userCount].username, newUser.username, 16);
    users[userCount].password = newUser.password;
    users[userCount].salt = newUser.salt;
    users[userCount].dob = newUser.dob;
    users[userCount].topScore = newUser.topScore;
    userCount++;
}
#endif
