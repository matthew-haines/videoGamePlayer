void output(user *fle, int n){
    int i;
    printf("LoginID.Password.Date of Birth.Top Score:");
    for(i=0; i<n; i++) printf("%s.%s.%d/%d/%d.%d\n", fle[i].usrnm, fle[i].pswrd, fle[i].birth.mnth, fle[i].birth.dy, fle[i].birth.yr, fle[i].tpSc);
}