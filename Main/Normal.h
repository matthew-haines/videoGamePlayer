int haha(char *s){
    int n;
    n = strcmp(s, "Raymond");
    if(n==0){
        printf("no, that name is sacred. NO ONE CAN USE THAT NAME\n");
        return 1;
    }
    else return 0;
}
