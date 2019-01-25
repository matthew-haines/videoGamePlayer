int menu_options(struct node * Tree){
    int inpt;
    int i;
    printf("Menu Options:\n1: Add random numbers."
           "\n2: Output Players.\n3: Add Player."
           "\n4: Delete Player by LoginID"
           "\n5: Delete Players by Top Score"
           "\n6: Sort Players by LoginID"
           "\n7: Sort Players by Date of Birth"
           "\n8: Sort Players by Top Score"
           "\n9: Find Players by LoginID"
           "\n10: Quit\n");
    scanf("%d", &inpt);
    fflush(stdin);
    switch(inpt){
        case 1:
            add_rand_player(Tree);
            break;
        case 2:
            PrintBST(Tree);
            break;
        case 3:
            add_user_player(Tree); //works?
            break;
        case 4:
            del_id(Tree);
            break;
        case 5:
            del_ts(Tree);
            break;
        case 6:
            reSort(Tree, compare_usrnm);
            break;
        case 7:
            reSort(Tree,compare_dob);
            break;
        case 8:
            reSort(Tree,compare_score);
            break;
        case 9:
            find_id(*Tree);
            break;
        case 10:
            return -1;
        default:
            break;
    }
      system("pause");
      system("cls");
    return 1;
}
