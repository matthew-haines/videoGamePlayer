void ts_qcksort(user *ar, int l, int h){
    if(l<h){
        int pvt = ts_partition(ar, l, h);
        ts_qcksort(ar, l, pvt-1);
        ts_qcksort(ar, pvt+1, h);
    }
}
int ts_partition(user *ar, int l, int h){
    int i = l;
    int j;
    user temp;

    for(j=l; j<h; j++){
        if(ar[j].tpSc>=ar[h].tpSc){
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
