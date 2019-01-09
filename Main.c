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
}
