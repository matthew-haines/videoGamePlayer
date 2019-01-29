void RecurDel_Ts(struct node * source, struct node * Target){
    if(source->lc) RecurDel_Ts(source->lc, Target);
    insert(Target, source->value, compare_score);
    if(source->rc) RecurDel_Ts(source->rc, Target);
}

void del_ts(struct node * Head){
    struct node * Temp = (struct node *)malloc((sizeof(struct node)));
    Temp->lc = NULL;
    Temp->rc = NULL;
    int y;
    do{
    printf("Enter the minimum acceptable top score (Must be greater than 0) . All players below this value will be deleted:\n");
    scanf(" %d", &y);
        if(y <= 0) printf("Invalid, try again\n");
    }while(y <= 0);
    
    user na;
    na.tpSc = y+1;
    strcpy(na.usrnm, "DUMMY:)))");

    insert(Temp,na,compare_score);
    RecurDel_Ts(Head, Temp);
    
    if(Temp->lc){
      Head->value = Temp->lc->value;
      Head->rc = Temp->lc->rc;
      Head->lc = Temp->lc->lc;
    }else{
      printf("Deleting all players.\n");
      Head->value.usrnm[0] = 0;
      Head->rc = NULL;
      Head->lc = NULL;
    }
    na.birth.dy = 0;
    na.birth.mth = 0;
    na.birth.yr = 0;
    strcpy(na.usrnm, "admin");
    na.tpSc = 0;
    insert(Head, na, compare_usrnm); //reinsert admin since it will always be deleted
}

void del_id(struct node * Head){
    user temp;
    printf("Enter name to delete:");
    scanf("%s", temp.usrnm);
    if(strcmp(temp.usrnm, "admin") == 0){
        printf("Please do not attempt to delete admin\n");
        return;
    }
    fflush(stdin);
    reSort(Head, compare_usrnm);
    delNode(Head, temp, compare_usrnm);
}
