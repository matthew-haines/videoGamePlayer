#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "structure.h"
#include "Sort_Dob.h"
#include "Sort_Top_Score.h"
#include "Sort_Username.h"
#include "Add_Rand_Player.h"
#include "Add_User_Player.h"
#include "Output_Player.h"
#include "User_Interface.h"
#include "Normal.h"

int main() {
    user p[200];
    int n = 0;
    int x = 1;
    int i;

    while(x==1) x = menu_options(p, &n);
    return 0;
}
