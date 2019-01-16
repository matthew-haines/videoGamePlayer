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