

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
    printf("Enter the value you want to delete:");
    scanf("%d", &y);
    user na;
    na.tpSc = y;
    strcpy(na.usrnm, "DUMMY:)))");

    insert(Temp,na,compare_score);
    RecurDel_Ts(Head, Temp);
    if(Temp->lc){
      Head->value = Temp->lc->value;
      Head->rc = Temp->lc->rc;
      Head->lc = Temp->lc->lc;
    }else{
      printf("Should Delete all");
      Head->value.usrnm[0] = 0;
      Head->rc = NULL;
      Head->lc = NULL;
    }
}



void del_id(struct node * Head){
    char del[100];
    user temp;
    printf("Enter name to delete:");
    scanf("%s", temp.usrnm); //try to use gets
    fflush(stdin);
    reSort(Head, compare_usrnm);
    delNode(Head, temp, compare_usrnm);
}
