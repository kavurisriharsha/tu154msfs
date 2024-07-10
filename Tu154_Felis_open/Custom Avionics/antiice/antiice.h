typedef struct {
    int eng_heat_open_1;
    int eng_heat_open_2;
    int eng_heat_open_3;
    int antiice_slats;
    int antiice_eng_1;
    int antiice_eng_2;
    int antiice_eng_3;
    int antiice_wing;
    int ice_detected;
    int ice_detect_ok;
    int wing_heating;
    int slat_heating;

    float wing_heat_t;
    float stab_heat_t;
    
    float ai_27_L_cc;
    float ai_27_R_cc;
    float ai_115_1_cc;
    float ai_115_2_cc;
    float ai_115_3_cc;
    
    float antiice_slats;
    float antiice_eng_1;
    float antiice_eng_2;
    float antiice_eng_3;
    float antiice_wings;
    
} antiice_t;