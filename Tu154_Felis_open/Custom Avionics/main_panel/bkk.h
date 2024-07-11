typedef struct {
    int left_roll_big; // сигнал с БКК - крен лев велик
    int right_roll_big; // сигнал с БКК - крен прав велик
    int mgv_contr_fail; // сигнал с БКК - отказ МГВ контр
    int no_contr_ag; // сигнал с БКК - нет контроля АГ
    int pkp_fail_left; // сигнал с БКК - отказ левого ПКП
    int pkp_fail_right; // сигнал с БКК - отказ левого 
    
    float pkp_roll_left; // крен на левом МГВ
    float pkp_roll_right; // крен на правом МГВ
    float pkp_left_power_cc; // отребление тока ПКП
    float pkp_right_power_cc; // отребление тока ПКП
    float mgv_ctr_power_cc; // отребление тока ПКП
    float bkk_pitch; // результирующий тангаж от БКК
    float bkk_roll; // результирующий крен от БКК
    
} bkk_t;