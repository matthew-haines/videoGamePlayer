void menu_options(){
    int n;
    printf("Menu Options:\n1: Add random numbers."
"\n2: Output Players.\n3: Add Player."
"\n4: Delete Player by LoginID"
"\n5: Delete Players by Top Score"
"\n6: Sort Players by LoginID"
"\n7: Sort Players by Date of Birth"
"\n8: Sort Players by Top Score"
"\n9: Find Players by LoginID"
"\n10: Quit");
    scanf(" %d", &n);
    switch(n){
        case 1:
                add_rand();
                break;
        case 2:
                output();
                break;
        case 3:
                add_u();
                break;
        case 4:
                del_id();
                break;
        case 5:
                del_ts();
                break;
        case 6:
                sort_id();
                break;
        case 7:
                sort_dob();
                break;
        case 8:
                sort_ts();
                break;
        case 9:
                find_id();
                break;
        case 10:
                return;
        default:
                break;
    }

}
