typedef struct {

    int ext_used_1; // огнетушитель использован
    int ext_used_2; // огнетушитель использован
    int ext_used_3; // огнетушитель использован
    int ng_used; // НГ использован
    int valve_open_1; // кран тушения двиг 1
    int valve_open_2; // кран тушения двиг 2
    int valve_open_3; // кран тушения двиг 3
    int valve_open_4; // кран тушения ВСУ
    int fire_siren; // работа пожарной сирены
    int engine_fire_state_1; // состояние двигателя. 0 - норм, 1 - перегрев, 2 - пожар
    int engine_fire_state_2; // состояние двигателя. 0 - норм, 1 - перегрев, 2 - пожар
    int engine_fire_state_3; // состояние двигателя. 0 - норм, 1 - перегрев, 2 - пожар
    int engine_fire_state_4; // состояние ВСУ. 0 - норм, 1 - перегрев, 2 - пожар
    int engine_fuel_cut_1; // топливо перекрыто
    int engine_fuel_cut_2; // топливо перекрыто
    int engine_fuel_cut_3; // топливо перекрыто
    int fire_detected; // обнаружен пожар
    
    float fire_sys_cc; // потребление тока системой

} fire_t;