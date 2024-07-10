typedef struct {

    int fail_left; // флаг отказа
    int fail_right; // флаг отказа
    
    float course_mk_1; // курс на MK5
    float course_mk_2; // курс на MK5
    float course_ga_1; // курс на ГА1
    float course_ga_2; // курс на ГА1
    float course_bgmk_1; // курс на БГМК1
    float course_bgmk_2; // курс на БГМК1
    float course_gpk; // результирующий курс ТКС - ГПК
    float course_gmk; // результирующий курс ТКС - ГМК
    float km5_1_cc; // потребление тока КМ5
    float km5_2_cc; // потребление тока КМ5
    float ga_1_cc; // потребление тока ГА
    float ga_2_cc; // потребление тока ГА
    float ga_heat_cc; // потребление тока подогрева ГА
    float bgmk_1_cc; // потребление тока БГМК
    float bgmk_2_cc; // потребление тока БГМК
    float ush_cc; // потребление тока УШ

} tks_t;