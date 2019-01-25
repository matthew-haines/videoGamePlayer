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
        printf("%s found here are the detail:\n Top score: %d \n Date of Birth: %d/%d/%d\n", a->value.usrnm, a->value.tpSc, a->value.birth.mth, a->value.birth.dy, a->value.birth.yr);
        return 1;
    }
}
