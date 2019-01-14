void menu_options(user *fle, int n){
    int inpt;
    printf("Menu Options:\n1: Add random numbers."
"\n2: Output Players.\n3: Add Player."
"\n4: Delete Player by LoginID"
"\n5: Delete Players by Top Score"
"\n6: Sort Players by LoginID"
"\n7: Sort Players by Date of Birth"
"\n8: Sort Players by Top Score"
"\n9: Find Players by LoginID"
"\n10: Quit");
    scanf(" %d", &inpt);
    switch(n){
        case 1:
                add_rand_player(fle);
                break;
        case 2:
                //output();
                break;
        case 3:
                add_user_player(fle, &fle[n], n);
                break;
        case 4:
                //del_id();
                break;
        case 5:
                //del_ts();
                break;
        case 6:
                usrnm_qcksort(fle, 0, n-1);
                break;
        case 7:
                age_user_ar(fle, n);
                dob_qcksort(fle, 0, n-1);
                break;
        case 8:
                ts_qcksort(fle, 0, n-1);
                break;
        case 9:
                //find_id();
                break;
        case 10:
                return;
        default:
                break;
    }

}
