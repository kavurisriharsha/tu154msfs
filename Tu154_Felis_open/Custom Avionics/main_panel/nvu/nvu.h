typedef struct {

    int diss_mode; // режим ДИСС. 0 - выкл, 1 - работа, 2 - память
    int nvu_mode; // режим НВУ. 0 = выкл, 1 = готов, 2 = счисление, 3 = коррекция
    int nvu_active; // активный комплект НВУ. 1 - 2
    int nvu_changing_ort; // смена ЧО
    int nvu_fail; // отказ или недостаточно систем для НВУ
    
    float diss_wind_course; // курс ветра по ДИСС
    float diss_wind_spd; // скорость ветра по ДИСС
    float diss_groundspeed; // путевая скорость по ДИСС
    float diss_slip_angle; // угол сноса по ДИСС
    float current_Z1; // Z1
    float current_S1; // S1
    float next_Z1; // Z1
    float next_S1; // S1
    float current_Z2; // Z2
    float current_S2; // S2
    float next_Z2; // Z2
    float next_S2; // S2
    float zpu1; // Z2
    float zpu2; // S2
    float nvu_res_course; // курс полета по НВУ
    float nvu_res_z; // смещение от курса полета НВУ
    float nvu_cc; // потребление тока НВУ
    float diss_cc; // потребление от ДИСС
    float current_Z1_1; // Z1
    float current_Z1_10; // Z1
    float current_Z1_100; // Z1
    float current_Z1_1000; // Z1
    float current_Z1_min_1; // Z1
    float current_Z1_min_10; // Z1
    float current_Z1_min_100; // Z1
    float current_Z1_min_1000; // Z1
    float current_S1_1; // S1
    float current_S1_10; // S1
    float current_S1_100; // S1
    float current_S1_1000; // S1
    float current_S1_min_1; // S1
    float current_S1_min_10; // S1
    float current_S1_min_100; // S1
    float current_S1_min_1000; // S1
    float next_Z1_1; // Z1
    float next_Z1_10; // Z1
    float next_Z1_100; // Z1
    float next_Z1_1000; // Z1
    float next_Z1_min_1; // Z1
    float next_Z1_min_10; // Z1
    float next_Z1_min_100; // Z1
    float next_Z1_min_1000; // Z1
    float next_S1_1; // S1
    float next_S1_10; // S1
    float next_S1_100; // S1
    float next_S1_1000; // S1
    float next_S1_min_1; // S1
    float next_S1_min_10; // S1
    float next_S1_min_100; // S1
    float next_S1_min_1000; // S1
    float current_Z2_1; // Z2
    float current_Z2_10; // Z2
    float current_Z2_100; // Z2
    float current_Z2_1000; // Z2
    float current_S2_1; // S2
    float current_S2_10; // S2
    float current_S2_100; // S2
    float current_S2_1000; // S2
    float next_Z2_1; // Z2
    float next_Z2_10; // Z2
    float next_Z2_100; // Z2
    float next_Z2_1000; // Z2
    float next_S2_1; // S2
    float next_S2_10; // S2
    float next_S2_100; // S2
    float next_S2_1000; // S2
    float current_Z2_min_1; // Z2
    float current_Z2_min_10; // Z2
    float current_Z2_min_100; // Z2
    float current_Z2_min_1000; // Z2
    float current_S2_min_1; // S2
    float current_S2_min_10; // S2
    float current_S2_min_100; // S2
    float current_S2_min_1000; // S2
    float next_Z2_min_1; // Z2
    float next_Z2_min_10; // Z2
    float next_Z2_min_100; // Z2
    float next_Z2_min_1000; // Z2
    float next_S2_min_1; // S2
    float next_S2_min_10; // S2
    float next_S2_min_100; // S2
    float next_S2_min_1000; // S2
    float zpu1_01; // ZPU
    float zpu1_1; // ZPU
    float zpu1_10; // ZPU
    float zpu1_100; // ZPU
    float zpu2_01; // ZPU
    float zpu2_1; // ZPU
    float zpu2_10; // ZPU
    float zpu2_100; // ZPU
    float z1_minus_cap; // digits cap
    float z1_plus_cap; // digits cap
    float s1_minus_cap; // digits cap
    float s1_plus_cap; // digits cap
    float z2_minus_cap; // digits cap
    float z2_plus_cap; // digits cap
    float s2_minus_cap; // digits cap
    float s2_plus_cap; // digits cap
    float z1_next_minus_cap; // digits cap
    float z1_next_plus_cap; // digits cap
    float s1_next_minus_cap; // digits cap
    float s1_next_plus_cap; // digits cap
    float z2_next_minus_cap; // digits cap
    float z2_next_plus_cap; // digits cap
    float s2_next_minus_cap; // digits cap
    float s2_next_plus_cap; // digits cap

} acf_t;