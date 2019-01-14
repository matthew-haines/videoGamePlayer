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
        if(num < 1 && num > 12) printf("Year is invalid. Please try again.\n");
    }while(num < 1 && num > 12);
    p->birth.mnth = num;
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

void get_usrnm(user *fle, user *p, int n){
    int chk;
    char name[20];
    do{
        chk = 1;
        printf("Enter name:\n");
        scanf(" %s", name);
        if(chck_name(fle, name, n)==0){
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
    strcmp(p->usrnm, name);
}

void get_ts(user *p){
    int topSc;
    do{
        printf("Enter Top Score:");
        scanf(" %d", &topSc);
        if(topSc < 0) printf("Score is negative. Please try again.\n");
        else if(topSc > 500000) printf("Score is too high. Please try again.\n");
    }while(topSc < 0 || topSc > 500000);
    p->tpSc = topSc;
}

void get_pswrd(user *p){
    char pswrd[10];
    char pswrd2[10];
    int chk;
    do{
        chk = 0;
        printf("Enter password:");
        scanf(" %s", pswrd);

        if(strlen(pswrd) < 5){
            chk = 1;
            printf("Password is too short. Please try again.\n");
            continue;
        }else if(strlen(pswrd) > 10){
            chk = 1;
            printf("Password is too long. Please try again.\n");
            continue;
        }

        printf("Enter password again:");
        scanf(" %s", pswrd2);
        if(strcmp(pswrd, pswrd2) != 0){
            chk = 1;
            printf("Password do not match. Please try again.\n");
        }

    }while(chk!=0);
    strcmp(p->pswrd, pswrd);
}

void add_user_player(user *fle, user *p, int n){
    dte dob;
    int chk = 0;

    //get_usrnm(fle, p, n); WORKS
    n += 1;
    //get_ts(p); //WORKS
    //get_pswrd(p); //WORKS

    //get_yr(p);
    //get_mnth(p);
    //get_day(p->birth.yr, p->birth.mnth, p); //WORKS

    /***
        STILL NEED TO ADD TO DATABASE. WHERE??
    ***/
}
