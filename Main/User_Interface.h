int menu_options(user * fle, int * n){
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
    scanf(" %d", &inpt);
    switch(inpt){
        case 1:
			//printf("%d %d", n, *n);
			//add_rand_player(fle, n);
			break;
        case 2:
			//output(fle, *n);
			break;
		case 3:
			add_user_player(fle, &fle[*n], *n); //works?
			//printf("A");
			*n += 1;
			break;
        case 4:
			//del_id();
			break;
        case 5:
			//del_ts();
			break;
        case 6:
			break;
        case 7:
			//age_user_ar(fle, *n);
			break;
        case 8:
			break;
        case 9:
			//find_id();
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
