

void get_yr(user *p){
    int num;
    printf("Please enter the year:\n");
    do{
        scanf(" %d", &num);
        if(num < 1990 || num > 2010) printf("Year is invalid. Please try again.\n");
    }while(num < 1990 || num > 2010);
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

void get_usrnm(struct node * Head,user *p){
    int chk;
    char name[20];
    do{
        chk = 1;
        fflush(stdin);
        printf("Enter name:\n");
        gets(name);
        strcpy(p->usrnm, name);
        if(search(Head,*p) != (struct node *)-1){
            chk = 0;
            printf("Username taken. Please try again.\n");
        }else if(strlen(name)<6){
            chk = 0;
            printf("Username too short. Please try again.\n");
        }else if(strlen(name) > 10){
            chk = 0;
            printf("Username too long. Please try again.\n");
        }
    }while(chk==0);
    strcpy(p->usrnm, name);
}
/*
void get_ts(user *p){
    int topSc;
    do{
        printf("Enter Top Score:");
        scanf(" %d", &topSc);
        fflush(stdin);
        if(topSc < 0) printf("Score is negative. Please try again.\n");
        else if(topSc > 500000) printf("Score is too high. Please try again.\n");
    }while(topSc < 0 || topSc > 500000);
    p->tpSc = topSc;
}*/

int pswrd_strength(char *s){
    int i, up, low, num, other;
    up = low = num = other = 0;
    for(i=0; s[i] != 0; i++){
        if(isupper((int)s[i])) up = 1;
        else if(islower((int)s[i])) low = 1;
        else if(isdigit((int)s[i])) num = 1;
        else other = 1;
    }
    return up+low+num+other;
}

void get_pswrd(user *p){
    char pswrd[10];
    char pswrd2[10];
    int chk;
    do{
        chk = 0;
        fflush(stdin);
        printf("Enter password:");
        gets(pswrd);
        if(strlen(pswrd) < 5){
            chk = 1;
            printf("Password is too short. Please try again.\n");
            continue;
        }else if(strlen(pswrd) > 10){
            chk = 1;
            printf("Password is too long. Please try again.\n");
            continue;
        }else if(pswrd_strength(pswrd) <=2){
            chk = 1;
            printf("THATT PASSWORD IS WEAKKKKKKKK. MAKE ANOTHER ONE.\n");
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
    //dte dob;
    int chk = 0;
    user p;
    get_usrnm(Head, &p); //WORKS
    //get_ts(&p); //WORKS
    p.tpSc = 0;
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
