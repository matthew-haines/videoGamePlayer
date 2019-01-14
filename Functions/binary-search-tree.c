#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef struct {
    int mth;
    int dy;
    int yr;
} dob;

typedef struct {
    char usrnm[10];
    char pswrd[10];
    double salt;
    dob birth;
    int tpSc;
    int fre;
} user;

struct node{
    user value;
    user * lc;
    user * rc;
};

int compare_usrnm(struct node parent, struct node child) {
    if(strcmp(parent.value.usrnm,child.value.usrnm) < 0) return 1; //go right
    if(strcmp(parent.value.usrnm,child.value.usrnm) > 0) return 0; //go left;
    return -1;
}

int sum_dob(dob input)  {
    return (input.yr << (4+5) + input.mth) << 5 + input.dy;
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

int search(struct node target, user find){
    if(strcmp(target.value.usrnm,find.usrnm) == 0){
        return 1; //found;
    }
    if(strcmp(target.value.usrnm,find.usrnm) < 0 && target.rc) return search(*target.rc, find);
    else{
        if(target.lc) return search(*target.lc,find);
    }
    return 0; //not found
}

int main(){
    struct node Head;
    user ins;
    user ins2;
    user ins3;
    Head.lc = NULL;
    Head.rc = NULL;
    strcpy(ins3.usrnm, "TEST2");
    strcpy(ins.usrnm, "Hello");
    Head.value = ins;
    
   strcpy(ins2.usrnm, "Z");
   insert(&Head,ins2);
    
    strcpy(ins.usrnm, "LA");
    insert(&Head,ins);
    
    printf("%d %d %d %d\n", search(Head,ins), search(Head,Head.value), search(Head,ins2), search(Head,ins3));
    //printf("%d %d\n", Bye.rc->value, Bye.rc->rc->value);
}
