dte cur(){ //current date
    struct tm *t;
    time_t now;
    time(&now);
    t = localtime(&now);
    return (dte){t->tm_mon+1, t->tm_mday, t->tm_year+1900};
}

void f_age(user *p){ //finding age in days; works don't touch
    dte today = cur();
    p->dys_old = 0;
    printf("%d T%d\n", today.yr, p->fre);
    if((today.mnth-1)*31+today.dy >= (p->birth.mnth-1)*31+p->birth.dy) p->dys_old += (today.mnth-1)*31+today.dy-(p->birth.mnth-1)*31-p->birth.dy;
    else{
        printf("%d T%d\n", today.yr, p->fre);
        p->dys_old += 31-p->birth.dy + (12-(p->birth.mnth))*31;
        p->dys_old += (today.mnth-1)*31+today.dy;
        today.yr -= 1;
    }
    printf("%d T%d\n", today.yr, p->fre);

    p->dys_old += 365*(today.yr-p->birth.yr);
    printf("%d %d %d: %d %d %d: %d\n", today.yr, today.mnth, today.dy, p->birth.yr, p->birth.mnth, p->birth.dy, p->dys_old);
}

void age_user_ar(user *fle, int n){ //Calculates age of user
    int i;
    for(i=0; i<n; i++) f_age(&fle[i]);
}

void dob_qcksort(user *ar, int l, int h){
    if(l<h){
        int pvt = dob_partition(ar, l, h);
        dob_qcksort(ar, l, pvt-1);
        dob_qcksort(ar, pvt+1, h);
    }
}
int dob_partition(user *ar, int l, int h){
    int i = l;
    int j;
    user temp;

    for(j=l; j<h; j++){
        if(ar[j].dys_old>=ar[h].dys_old){
            temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
            i++;
        }
    }

    temp = ar[i];
    ar[i] = ar[h];
    ar[h] = temp;

    return i;
}
