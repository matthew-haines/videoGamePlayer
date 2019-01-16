#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "Normal.h"
#include "structure.h"
#include "Add_Rand_Player.h"
#include "Add_User_Player.h"
#include "Output_Player.h"
#include "User_Interface.h"

int main() {
    user p[200];
    int n = 0;
    int x = 1;
    int i;

    while(x == 1) x = menu_options(p, &n);
    return 0;
}
