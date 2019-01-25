
void add_rand_name(struct node * fle, user *p, int sd){
    int i, j, lngth, alph, f;
    srand(sd);
    lngth = rand()%3+6;
    user temp;
    char name[lngth+1];
    do{
        for(j=0; j<lngth; j++){
            alph = rand()%2;
            if(alph==0) name[j] = rand()%10+48;
            else name[j] = rand()%26+97;
        }
        name[j]=0;
        strcpy(temp.usrnm, name);
        struct node * f = search(fle, temp);
    }while(f==-1);
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
    p->tpSc = (int)normal(MEAN_TPSC, STD_DEV_TPSC,sd);
}

void add_dob(user *p, int sd){
    srand(sd);
    int i;
    int ar[7] = {1, 3, 5, 7, 8, 10, 12};
    p->birth.yr = rand()%21+1990;
    p->birth.mth = rand()%12+1;
    p->birth.dy = 0;
    for(i=0; i<6; i++){
        if(p->birth.mth == ar[i]) p->birth.dy = -1;
    }
    if(p->birth.dy==-1) p->birth.dy = rand()%31+1;
    else if(p->birth.mth==2 && p->birth.yr%4==0) p->birth.dy = rand()%29+1;
    else if(p->birth.mth == 2) p->birth.dy = rand()%28+1;
    else p->birth.dy = rand()%30+1;
}

void add_rand_player(struct node * Head){
    int i, j;
    int chk = 0;
    int sd;
    srand(time(NULL));
    int num = ask_add();
    user ins;
    for(i=0; i<num; i++){
        sd = rand();
        add_rand_name(Head, &ins, sd);
        add_pswrd(&ins, sd); //WORKS
        add_tpSc(&ins, sd); //WORKS
        add_dob(&ins, sd);
        insert(Head,ins,compare_usrnm);
    }
}
