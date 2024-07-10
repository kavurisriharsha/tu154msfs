typedef struct {

    int mgv_contr_flag; // флаг отказа МГВ контр

    float mgv_contr_roll; // крен контрольного гироскопа
    float mgv_contr_pitch; // тангаж контрольного гироскопа
    float ahz_pitch_int_L; // тангаж на левом гироскопе
    float ahz_pitch_int_R; // тангаж на правом гироскопе

} gyro_t;