#define MAX_N 100
#define MAX_TPSC 500000

int ask_add(){
    int num;
    printf("Enter how many players you wish to add:");
    scanf(" %d", &num);
    return num;
}

int chck_name(user *fle, char nm[]){ //Slow algorithm for checking duplicate user names
    int i, j;
    for(i=0; i<=MAX_N; i++){
        j = 0;
        while(nm[j] == fle[i].usrnm[j] && nm[j] != 0) j++;
        if(nm[j] == 0 && fle[i].usrnm[j]==0) return 0;
    }
    return 1;
}

void add_rand_name(user *fle, user *p, int sd){
    int i, j, lngth, alph, f;
    srand(sd);
    lngth = rand()%3+6;

    char name[lngth+1];
    do{
        for(j=0; j<lngth; j++){
            alph = rand()%2;
            if(alph==0) name[j] = rand()%10+48;
            else name[j] = rand()%26+97;
        }
        name[j]=0;
        f = chck_name(fle, name);
    }while(f==0);
    strcpy(p->usrnm, name);
}

void add_pswrd(user *p, int sd){
    srand(sd);
    int tp; //0 for digit, 1 for lower case, 2 for upper case
    int lngth, i;
    lngth = rand()%6+5;
    char password[lngth];
    for(i=0; i<lngth; i++){
        tp = rand()%3;
        if(tp==0) password[i] = rand()%10+48;
        else if(tp==1) password[i] = rand()%26+65;
        else password[i] = rand()%26+97;
    }
    password[i] = 0;
    strcpy(p->pswrd, password);
}

void add_tpSc(user *p, int sd){
    srand(sd);
    p->tpSc = rand()%(MAX_TPSC+1);
}

void add_dob(user *p, int sd){
    srand(sd);
    int i;
    int ar[6] = {1, 3, 5, 7, 8, 10, 12};
    p->birth.yr = rand()%21+1990;
    p->birth.mnth = rand()%12+1;
    p->birth.dy = 0;
    for(i=0; i<6; i++){
        if(p->birth.mnth == ar[i]) p->birth.dy = -1;
    }
    if(p->birth.dy==-1) p->birth.dy = rand()%31+1;
    else if(p->birth.mnth==2 && p->birth.yr%4==0) p->birth.dy = rand()%29+1;
    else if(p->birth.mnth == 2) p->birth.dy = rand()%28+1;
    else p->birth.dy = rand()%30+1;
}

void add(user *fle){
    int i, j;
    int chk = 0;
    int sd;
    srand(time(NULL));
    int n = ask_add();
    for(i=0; i<n; i++){
        chk = 0;
        for(j=i; j<MAX_N && chk == 0; j++){
            if(fle[j].fre==0){
                sd = rand();
                add_rand_name(fle, &fle[j], sd);
                //printf("%s\n", fle[j].usrnm);
                add_pswrd(&fle[j], sd); //WORKS
                //printf("%s\n", fle[j].pswrd);
                add_tpSc(&fle[j], sd); //WORKS
                //printf("%d ", fle[j].tpSc);
                add_dob(&fle[j], sd);
                printf("%s, %s, %d, %d\\%d\\%d\n", fle[j].usrnm, fle[j].pswrd, fle[j].tpSc, fle[j].birth.mnth, fle[j].birth.dy, fle[j].birth.yr);
                chk = 1;
            }
        }
    }
}
