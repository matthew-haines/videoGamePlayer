#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

int main() {
    char salt[salt_len];
    generate_salt(salt);
    char pass[8] = "pa";
    char to_be_hashed[16];
    concatenate(salt, pass, to_be_hashed);

    printf("%X", hash(to_be_hashed));
    //COMMENT IT MATT
}
