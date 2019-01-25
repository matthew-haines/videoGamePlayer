
int compare_usrnm(struct node parent, struct node child) {
    if(strcmp(parent.value.usrnm,child.value.usrnm) < 0) return 1; //go right
    if(strcmp(parent.value.usrnm,child.value.usrnm) > 0) return 0; //go left;
    return -1;
}

int sum_dob(dob input)  {
    return (((input.yr << (9)) + input.mth) << 5) + input.dy;
}

int compare_dob(struct node parent, struct node child) {
    if(sum_dob(parent.value.birth) > sum_dob(child.value.birth)) return 1;
    if(sum_dob(parent.value.birth) < sum_dob(child.value.birth)) return 0;
    return -1;
}

int compare_score(struct node parent, struct node child) {
    if(parent.value.tpSc > child.value.tpSc) return 1;
    if(parent.value.tpSc < child.value.tpSc) return 0;
    return -1;
}

void insert(struct node * to, user what, int (*compare_func)(struct node parent, struct node child)){
    if(to->value.usrnm[0] == 0){
        to->value = what;
        return;
    }
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->value = what;
    temp->lc = NULL;
    temp->rc = NULL;
    if(compare_func(*to, *temp)){
        if(to->rc) insert(to->rc, temp->value, compare_func);
        else{
            to->rc = temp;
            return;
        }
    }else{
        if(to->lc) insert(to->lc, temp->value, compare_func);
        else{
            to->lc = temp;
            return;
        }
    }
    return;
}

struct node * search(struct node * target, user find){
    if(strcmp(target->value.usrnm,find.usrnm) == 0){
        return target; //found;
    }
    if(strcmp(target->value.usrnm,find.usrnm) < 0 && target->rc) return search(target->rc, find);
    else if(target->lc) return search(target->lc,find);
    
    return (struct node *)-1; //not found
}

void PrintBST(struct node * BST){
    if(BST->lc) PrintBST(BST->lc);
    printf("%s %d %d/%d/%d\n", BST->value.usrnm, BST->value.tpSc, BST->value.birth.mth, BST->value.birth.dy, BST->value.birth.yr);
    if(BST->rc) PrintBST(BST->rc);
}

void Recur(struct node * What,int (*compare_func)(struct node parent, struct node child), struct node * Dummy){
    if(Dummy->value.usrnm[0] == 0) Dummy->value = What->value;
    else insert(Dummy,What->value, compare_func);
    
    if(What->lc) Recur(What->lc,compare_func, Dummy);
    if(What->rc) Recur(What->rc,compare_func, Dummy);
}

void reSort(struct node * What,int (*compare_func)(struct node parent, struct node child)){
    struct node Dummy;
    Dummy.rc = NULL;
    Dummy.lc = NULL;
    Dummy.value.usrnm[0] = 0;
    Recur(What, compare_func, &Dummy);
    What->value = Dummy.value;
    What->rc = Dummy.rc;
    What->lc = Dummy.lc;
}

struct node * delNode(struct node * Head, user find, int (* compare_func)(struct node parent, struct node child)){
    if(Head == NULL) return Head;
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->value = find;
    temp->rc = NULL;
    temp->lc = NULL;
    if(compare_func(*Head,*temp) == 1){
       Head->rc = delNode(Head->rc, find, compare_func);
    }
    else if(compare_func(*Head,*temp) == 0){
       Head->lc = delNode(Head->lc, find, compare_func);
    }
    else{
        if(Head->rc == NULL){
            temp = Head->lc;
            return temp;
        }
        else if(Head->lc == NULL){
            temp = Head->rc;
            return temp;
        }
        struct node * current = Head->rc; //get minimum in right subtree
        while(current->lc != NULL) current = current->lc; //get min still
        Head->value = temp->value;
        Head->rc = delNode(Head->rc, temp->value, compare_func);
    }
    return Head;
}
