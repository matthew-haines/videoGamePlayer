int find_id(struct node Head){
    user what;
    printf("Enter A user to find:");
    scanf("%s", what.usrnm);
    reSort(&Head,compare_usrnm);
    struct node * a = search(&Head, what);
    if(a == (struct node *)-1){
        printf("This user was not found\n");
        return 0;
    }
    else{
        printf("User found. \nHere are the details:\nUsername: %s\nPassword: %s.\nTop score: %d \nDate of Birth: %d/%d/%d\n", a->value.usrnm, a->value.pswrd, a->value.tpSc, a->value.birth.mth, a->value.birth.dy, a->value.birth.yr);
        return 1;
    }
}
