typedef struct {

    int eng_fuel_press_1; // топливо может быть подано в двигатель. без учета стоп-кранов
    int eng_fuel_press_2; // топливо может быть подано в двигатель. без учета стоп-кранов
    int eng_fuel_press_3; // топливо может быть подано в двигатель. без учета стоп-кранов
    int pump_tank2_left_work; // насосы бака 2
    int pump_tank2_right_work; // насосы бака 2
    int pump_tank3_left_work; // насосы бака 3
    int pump_tank3_right_work; // насосы бака 3
    int pump_tank4_work; // насосы бака 4
    int pump_tank1_1_work; // насосы бака 1
    int pump_tank1_2_work; // насосы бака 1
    int pump_tank1_3_work; // насосы бака 1
    int pump_tank1_4_work; // насосы бака 1
    int reserv_trans; // резервная перекачка включена
    int auto_tanks_turn; // рабочие очередные баки. 0, 1 - не работает, 2, 3, 4
    int auto_tank_level_2; // выравнивание в баках 2. -1 = L, 0 = none, +1 = R
    int auto_tank_level_3; // выравнивание в баках 3. -1 = L, 0 = none, +1 = R

    float fire_vlv_open_1; // пожарный кран открыт
    float fire_vlv_open_2; // пожарный кран открыт
    float fire_vlv_open_3; // пожарный кран открыт
    
} fuel_t;