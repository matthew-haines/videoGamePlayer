typedef struct {
    int mnth;
    int dy;
    int yr;
} dte;

typedef struct {
    char usrnm[10];
    char pswrd[10];
    double salt;
    dte birth;
    int tpSc;
    int fre; //1 if spot is free, 0 if taken
    int dys_old; //days old for comparison (not accurate)
} user;
