typedef struct {
    int ice_detected; // обнаружен лед
    int ice_detect_ok; // система СОИ работает
    int wing_heating; // работает обогрев крыла
    int slat_heating; // работает обогрев крыла
    int eng_heat_open_1; // открыта заслонка обогрева двигателя
    int eng_heat_open_2; // открыта заслонка обогрева двигателя
    int eng_heat_open_3; // открыта заслонка обогрева двигателя
    int ppd_3_heat_fail; // отказ обогрева ППД-3

    float wing_heat_t; // температура обогрева крыла
    float stab_heat_t; // температура обогрева стабилизатора
    float ai_27_L_cc; // нагрузка на сеть
    float ai_27_R_cc; // нагрузка на сеть
    float ai_115_1_cc; // нагрузка на сеть
    float ai_115_2_cc; // нагрузка на сеть
    float ai_115_3_cc; // нагрузка на сеть
    
        
} antiice_t;