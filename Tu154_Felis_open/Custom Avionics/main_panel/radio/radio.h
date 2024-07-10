typedef struct {

    int nav1_cs_flag; // курсовой флаг
    int nav2_cs_flag; // курсовой флаг
    int nav1_gs_flag; // глиссадный флаг
    int nav2_gs_flag; // глиссадный флаг
    
    float adf_bear_1; // направление на маяк ADF
    float adf_bear_2; // направление на маяк ADF
    float vor_bear_1; // направление на маяк VOR
    float vor_bear_2; // направление на маяк VOR
    float vor_dme_1; // дистанция к VOR
    float vor_dme_2; // дистанция к VOR
    float nav1_cs; // отклонение курсовой планки
    float nav1_gs; // отклонение глиссадной планки
    float nav2_cs; // отклонение курсовой планки
    float nav2_gs; // отклонение глиссадной планки
    float vhf1_cc; // потребление тока радиостанцией
    float vhf2_cc; // потребление тока радиостанцией
    float ark15_L_cc; // потребление тока АРК
    float ark15_R_cc; // потребление тока АРК
    float nav1_pow_cc; // потребление тока от КурсМП
    float nav2_pow_cc; // потребление тока от КурсМП
    float radar_cc; // потребление тока от РЛС Гроза
    float rsbn_cc; // потребление тока от РСБН
    
} radio_t;