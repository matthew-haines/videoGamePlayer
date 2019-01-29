#define MAX_YEAR 2010
#define MIN_YEAR 1990
#define MAX_NAME 10
#define MIN_NAME 6
#define MAX_PSWRD 8
#define MIN_PSWRD 5

void get_yr(user *p){
    int num;
    printf("Please enter the year:\n");
    do{
        scanf(" %d", &num);
        if(num < MIN_YEAR || num > MAX_YEAR) printf("Year is invalid. Please try again.\n");
    }while(num < MIN_YEAR || num > MAX_YEAR);
    p->birth.yr = num;
}

void get_mnth(user *p){
    int num;
    printf("Please enter the month:\n");
    do{
        scanf(" %d", &num);
        if(num < 1 || num > 12) printf("Month is invalid. Please try again.\n");
    }while(num < 1 || num > 12);
    p->birth.mth = num;
}

void get_day(int yr, int mnth, user *p){
    int lng[7] = {1, 3, 5, 7, 8, 10, 12};
    int i;
    int num;
    int chk = 30;
    for(i=0; i<6; i++){
        if(mnth == lng[i]) chk = 31;
    }
    if(mnth == 2){
        if(yr % 4 == 0) chk = 29;
        else chk = 28;
    }

    printf("Please enter the day:\n");

    do{
        scanf(" %d", &num);
        if(num < 1 || num > chk) printf("Date is invalid. Please try again.\n");
    }while(num < 1 || num > chk);
    p->birth.dy = num;
}

int spaces(char *s){
    int i=0;
    while(s[i] != 0 && s[i] != ' ') i++;
    if(s[i] == 0) return 0;
    else return 1;
}

void get_usrnm(struct node * Head,user *p){
    int chk;
    char name[MAX_NAME+10];
    do{
        chk = 1;
        fflush(stdin);
        printf("Enter name (%d-%d characters) without spaces:\n", MIN_NAME, MAX_NAME);
        gets(name);
        strcpy(p->usrnm, name);
        if(search(Head,*p) != (struct node *)-1){
            chk = 0;
            printf("Username taken. Please try again.\n");
        }else if(strlen(name)< MIN_NAME){
            chk = 0;
            printf("Username too short. Please try again.\n");
        }else if(strlen(name) > MAX_NAME){
            chk = 0;
            printf("Username too long. Please try again.\n");
        }else if(spaces(name)==1){
            chk = 0;
            printf("Username has spaces. Please try again.\n");
        }
    }while(chk==0);
    strcpy(p->usrnm, name);
}

void get_ts(user *p){
    int topSc;
    do{
        printf("Enter Top Score [0-%d]:", MAX_TPSC);
        scanf(" %d", &topSc);
        fflush(stdin);
        if(topSc < 0) printf("Score is negative. Please try again.\n");
        else if(topSc > MAX_TPSC) printf("Score is too high. Please try again.\n");
    }while(topSc < 0 || topSc > MAX_TPSC);
    p->tpSc = topSc;
}

int pswrd_strength(char *s){
    int i, up, low, num;
    up = low = num = 0;
    for(i=0; s[i] != 0; i++){
        if(isupper((int)s[i])) up = 1;
        else if(islower((int)s[i])) low = 1;
        else if(isdigit((int)s[i])) num = 1;
    }
    return up+low+num;
}

void get_pswrd(user *p){
    char pswrd[MAX_PSWRD+10];
    char pswrd2[MAX_PSWRD+10];
    int chk;
    do{
        chk = 0;
        fflush(stdin);
        printf("Enter a strong %d-%d digit password (at least 1 lowercase, 1 uppercase and 1 numerical character):", MIN_PSWRD, MAX_PSWRD);
        gets(pswrd);
        if(strlen(pswrd) < MIN_PSWRD){
            chk = 1;
            printf("Password is too short. Please try again.\n");
            continue;
        }else if(strlen(pswrd) > MAX_PSWRD){
            chk = 1;
            printf("Password is too long. Please try again.\n");
            continue;
        }else if(pswrd_strength(pswrd) <=2){
            chk = 1;
            printf("That is a weak password.\n");
            continue;
        }

        printf("Enter password again:");
        fflush(stdin);
        gets(pswrd2);
        if(strcmp(pswrd, pswrd2) != 0){
            chk = 1;
            printf("Password do not match. Please try again.\n");
        }

    }while(chk!=0);
    strcpy(p->pswrd, pswrd);
}


void add_user_player(struct node * Head){
    int chk = 0;
    user p;
    get_usrnm(Head, &p); //WORKS
    get_ts(&p); //WORKS
    //p.tpSc = 0;
    get_pswrd(&p); //WORKS
    get_yr(&p);
    get_mnth(&p);
    get_day(p.birth.yr, p.birth.mth, &p); //WORKS
    reSort(Head, compare_usrnm);
    insert(Head, p, compare_usrnm);
}


int ask_add(){
    int num;
    printf("Enter how many players do you wish to add:");
    scanf(" %d", &num);
    return num;
}
