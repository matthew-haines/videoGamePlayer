typedef struct {
    int mth;
    int dy;
    int yr;
} dte;

typedef struct {
    char usrnm[10];
    char pswrd[10];
    double salt;
    dte birth;
    int tpSc;
    int fre;
} user;
