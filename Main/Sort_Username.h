void usrnm_qcksort(user *ar, int l, int h){
    if(l<h){
        int pvt = usrnm_partition(ar, l, h);
        usrnm_qcksort(ar, l, pvt-1);
        usrnm_qcksort(ar, pvt+1, h);
    }
}
int usrnm_partition(user *ar, int l, int h){
    int i = l;
    int j;
    user temp;
    int n;

    for(j=l; j<h; j++){
        n = strcmp(ar[j].usrnm, ar[h].usrnm);
        if(n < 0){
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
