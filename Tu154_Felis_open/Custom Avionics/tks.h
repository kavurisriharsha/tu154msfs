typedef struct {
    int tks_on_1; // TKS switch 1
    int tks_on_2; // TKS switch 2
    int tks_heat; // GA heating
    int tks_corr_1; // BGMK 2 - 1 correction
    int tks_corr_2; // BGMK 2 - 2 correction
    
    int tks_signal_off; // TKS signal unlock
    
    int tks_mode; // TKS mode 0 - MK1 - GPK2 - AK
    int tks_mode_left; // Left GA mode. 0 - control1 - main
    int tks_mode_right; // Right GA mode
    int tks_lat_mode; // Latitude setting mode. 0 - auto1 - manual
    int tks_course_set; // Course setter
    int tks_corrr_button; // Coordination button
    int fail_left; // Failure flag
    int fail_right; // Failure flag

    float course_mk_1; // Course to MK5
    float course_mk_2; // Course to MK5
    float course_ga_1; // Course to GA1
    float course_ga_2; // Course to GA1
    float course_bgmk_1; // Course to BGMK1
    float course_bgmk_2; // Course to BGMK1
    float course_gpk; // Resulting course TKS - GPK
    float course_gmk; // Resulting course TKS - GMK


    float km5_1_cc; // Current consumption KM5
    float km5_2_cc; // Current consumption KM5
    float ga_1_cc; // Current consumption GA
    float ga_2_cc; // Current consumption GA
    float ga_heat_cc; // Current consumption GA heating
    float bgmk_1_cc; // Current consumption BGMK
    float bgmk_2_cc; // Current consumption BGMK
    float ush_cc; // Current consumption USH
    

    float tks_lat_set; // Latitude setting knob
    
    float tks_mode_lit_mk; // TKS mode light - MK
    float tks_mode_lit_ak; // TKS mode light - AK
    float tks_mode_lit_gpk; // TKS mode light - GPK
    
    float tks_main_fail; // Main GA failure on TKS
    float tks_contr_fail; // Control GA failure on TKS
    
} tks_t;