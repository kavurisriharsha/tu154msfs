typedef struct {
    int bkk_contr_cap; // BKK control cap
    int bkk_contr; // BKK control. -1 - 20 - off+1 - 1
    int bkk_on_cap; // BKK switch cap
    int bkk_on; // BKK switch

    float bkk_ok; // BKK status light on overhead panel
    float bkk_pitch; // Resulting pitch from BKK
    float bkk_roll; // Resulting roll from BKK
    
} bkk_t;