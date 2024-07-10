typedef struct {

    float vvi_left; // показания вариометра
    float vvi_right; // показания вариометра
    float clock_24_hours; // часовая стрелка
    float clock_24_mins; // минутная стрелка
    float clock_24_red; // красная 

    gauges_acs_t* acs;
    gauges_ahz_t* ahz;
    gauges_airbleed_t* airbleed;
    gauges_alt_t* alt;
    gauges_compass_t* compass;
    gauges_console_t* console;
    gauges_engines_t* engines;
    gauges_fuel_t* fuel;
    gauges_hydro_t* hydro;
    gauges_misc_t* misc;
    gauges_speed_t* speed;
    gauges_vsi_t* vsi;

} gauges_t;

typedef struct {

    int left_knob_press; // левая кнопка часов АЧС1 КВС
    int right_knob_press; // правая кнопка часов АЧС1 КВС
    int flag_pos; // красно-белый флажок АЧС1 КВС. -1 - белый, 0 - бело-красный, +1 - красный

    float needle_hours; // часовая стрелка АЧС1 КВС
    float needle_mins; // минутная стрелка АЧС1 КВС
    float needle_secs; // секундная стрелка АЧС1 КВС
    float flight_timer_hours; // часовая стрелка таймера полета
    float flight_timer_mins; // минутная стрелка таймера полета
    float stopwatch_mins; // минутная стрелка секундомера

} gauges_acs_t;

typedef struct {

    int ahz_flag_L; // флаг отказа АГД КВС
    int dir_roll_flag_L; // флаг отказа директора крена АГД КВС
    int dir_pitch_flag_L; // флаг отказа директора тангажа АГД КВС
    int ahz_flag_R; // флаг отказа АГД КВС
    int dir_roll_flag_R; // флаг отказа директора крена АГД КВС
    int dir_pitch_flag_R; // флаг отказа директора тангажа АГД КВС
    int ahz_flag_C; // флаг АГР

    float roll_L; // крен на АГД КВС + в право
    float pitch_L; // тангаж на АГД КВС + нос вверх
    float dir_roll_L; // директор крена АГД КВС + в право
    float dir_pitch_L; // директор тангажа на АГД КВС + вверх
    float course_plank_L; // курсовая планка АГД КВС + в право
    float gs_plank_L; // глиссадная планка АГД КВС + вверх
    float speed_plank_L; // изменение скорости АГД КВС + вверх
    float pitch_corr_L; // коррекция тангаа на АГД КВС + вправо
    float roll_R; // крен на АГД 2П + в право
    float pitch_R; // тангаж на АГД 2П + нос вверх
    float dir_roll_R; // директор крена АГД 2П + в право
    float dir_pitch_R; // директор тангажа на АГД 2П + вверх
    float course_plank_R; // курсовая планка АГД 2П + в право
    float gs_plank_R; // глиссадная планка АГД 2П + вверх
    float speed_plank_R; // изменение скорости АГД 2П + вверх
    float pitch_corr_R; // коррекция тангаа на АГД 2П + вправо
    float roll_C; // крен на АГР + в право
    float pitch_C; // тангаж на АГР + нос вверх
    float pitch_corr_C; // коррекция тангажа на АГР + вправо

} gauges_ahz_t;

typedef struct {

    float cabin_alt; // высота в кабине
    float cabin_diff; // перепад давления
    float cabin_vvi; // кабинный вариометр. угол
    float cockpit_temp; // температура в кабине
    float cabin_temp; // температура в салонах
    float system_temp; // температура в трубопроводе
    float air_flow_1; // расход воздуха. угол
    float air_flow_2; // расход воздуха. угол

} gauges_airbleed_t;

typedef struct {

    int radioalt_button_left; // кнопка тест радиовысотомера КВС
    int radioalt_button_right; // кнопка тест радиовысотомера 2П
    int vbe_press_left; // давление на ВБЭ лев
    int vbe_press_knob_left; // ручка набора давления на ВБЭ лев
    int vbe_fl_knob_left; // ручка набора эшелона на ВБЭ лев
    int vbe_mode_but_left; // кнопка выбора режимов на ВБЭ лев
    int vbe_mode_left; // режим на ВБЭ лев
    int vbe_std_left; // включение стандартного давления
    int vbe_press_right; // давление на ВБЭ прав
    int vbe_press_knob_right; // ручка набора давления на ВБЭ прав
    int vbe_fl_knob_right; // ручка набора эшелона на ВБЭ прав
    int vbe_mode_but_right; // кнопка выбора режимов на ВБЭ прав
    int vbe_mode_right; // режим на ВБЭ прав
    int vbe_std_right; // включение стандартного давления

    float var75; // выриометр 75 КВС
    float var30; // выриометр 30 БИ
    float radioalt_needle_left; // стрелка радиовысотомера КВС
    float radioalt_dh_left; // стрелка ВПР радиовысотомера КВС
    float radioalt_flag_left; // флаг радиовысотомера КВС
    float radioalt_needle_right; // стрелка радиовысотомера 2П
    float radioalt_dh_right; // стрелка ВПР радиовысотомера 2П
    float radioalt_flag_right; // флаг радиовысотомера 2П
    float uvid_needle_left; // стрелка высотомера УВИД КВС
    float uvid_feet_counter; // барабанчик счета удиниц футов
    float uvid_hundreads_counter; // барабанчик счета сотен футов
    float uvid_thousands_counter; // барабанчик счета тысяч футов.
    float uvid_tens_thousands_counter; // барабанчик счета десятков тысяч футов.
    float uvid_pressure_knob; // ручка установки давления
    float uvid_pressure_one; // единицы давления
    float uvid_pressure_ten; // десятки давления
    float uvid_pressure_hund; // сотни давления
    float uvid_pressure_thous; // тысячи давления
    float vd15_alt_left; // высота на ВД15 КВС
    float vd15_tri_needle_left; // стрелка коррекции на ВД15 КВС
    float vd15_pressure_left; // давление на ВД15 КВС
    float vd15_alt_right; // высота на ВД15 2П
    float vd15_tri_needle_right; // стрелка коррекции на ВД15 2П
    float vd15_pressure_right; // давление на ВД15 2П
    float vd15_alt_eng; // высота на ВД15 БИ
    float vd15_tri_needle_eng; // стрелка коррекции на ВД15 БИ
    float vd15_pressure_eng; // давление на ВД15 БИ
    float vbe_alt_left; // высота на ВБЭ лев
    float vbe_brt_left; // яркость на ВБЭ лев
    float vbe_alt_right; // высота на ВБЭ прав
    float vbe_brt_right; // яркость на ВБЭ прав
    float vbe_flightlevel_left; // установленная высота на ВБЭ
    float vbe_flightlevel_right; // установленная высота на ВБЭ

} gauges_alt_t;

typedef struct {

    int source_1_switch_left; // переключатель стрелки 1 радиокомпаса КВС. 0 - пусто, 1 - АРК1, 2 - АРК2, 3 - VOR1, 4 - VOR2, 5 - РСБН
    int source_2_switch_left; // переключатель стрелки 2 радиокомпаса КВС
    int pkp_course_flag_L; // флаг отказа курсовой планки
    int pkp_gs_flag_L; // флаг отказа глиссадной планки
    int pkp_main_flag_L; // флаг отказа курса
    int pkp_obs_flag_L; // флаг отказа счетчика курса
    int source_1_switch_right; // переключатель стрелки 1 радиокомпаса 2П. 0 - пусто, 1 - АРК1, 2 - АРК2, 3 - VOR1, 4 - VOR2, 5 - РСБН
    int source_2_switch_right; // переключатель стрелки 2 радиокомпаса 2П
    int pkp_course_flag_R; // флаг отказа курсовой планки
    int pkp_gs_flag_R; // флаг отказа глиссадной планки
    int pkp_main_flag_R; // флаг отказа курса
    int pkp_obs_flag_R; // флаг отказа счетчика курса

    float radiocomp_scale_left; // шкала курса на радиокомпасе КВС
    float bearing_1_left; // стрелка направления 1 радиокомпаса КВС
    float bearing_2_left; // стрелка направления 2 радиокомпаса КВС
    float radiocomp_scale_right; // шкала курса на радиокомпасе 2П
    float bearing_1_right; // стрелка направления 1 радиокомпаса 2П
    float bearing_2_right; // стрелка направления 2 радиокомпаса 2П
    float big_knob; // поворот руски ЗК на большом компасе
    float big_course_needle; // стрелка "самолетик"
    float big_true_course_needle; // стрелка ПУ
    float big_tri_needle; // треугольная стрелка
    float pkp_gyro_course_L; // курс гироскопа ПКП КВС
    float pkp_obs_L; // курс полета на ПКП КВС
    float pkp_helper_course_L; // устанвока курса желтой стрелкой на ПКП КВС
    float pkp_slip_angle_L; // угол сноса на ПКП КВС
    float pkp_course_plank_L; // курсовая планка ПКП КВС + отклонение планки вправо
    float pkp_gs_plank_L; // глиссадная планка ПКП КВС + отклонение планки вверх
    float pkp_obs_one_L; // счетчик курса. единицы
    float pkp_obs_ten_L; // счетчик курса. десятки
    float pkp_obs_hundr_L; // счетчик курса. сотни
    float pkp_obs_knob_L; // ручка настройки курса
    float pkp_obs_set_L; // курс ПНП
    float pkp_gyro_course_R; // курс гироскопа ПКП 2П
    float pkp_obs_R; // курс полета на ПКП 2П
    float pkp_helper_course_R; // устанвока курса желтой стрелкой на ПКП 2П
    float pkp_slip_angle_R; // угол сноса на ПКП 2П
    float pkp_course_plank_R; // курсовая планка ПКП 2П + отклонение планки вправо
    float pkp_gs_plank_R; // глиссадная планка ПКП 2П + отклонение планки вверх
    float pkp_obs_one_R; // счетчик курса. единицы
    float pkp_obs_ten_R; // счетчик курса. десятки
    float pkp_obs_hundr_R; // счетчик курса. сотни
    float pkp_obs_knob_R; // ручка настройки курса
    float pkp_obs_set_R; // курс ПНП

} gauges_compass_t;

typedef struct {

    int absu_roll_mode; // режим работы АБСУ. 0 - выкл, 1 - штурвальный, 2 - стаб
    int absu_pitch_mode; // режим работы АБСУ. 0 - выкл, 1 - штурвальный, 2 - стаб
    float gear_brake_press_L; // давление тормозов лев
    float gear_brake_press_R; // давление тормозов прав
    float map_angle; // угол карты

} gauges_console_t;

typedef struct {

    float fuel_temp_1; // температура топлива
    float fuel_temp_2; // температура топлива
    float oil_qty_1; // количество масла
    float oil_qty_2; // количество масла
    float oil_qty_3; // количество масла
    float km5_scale_1; // поворот шкалы на КМ5
    float km5_needle_1; // стрелка КМ5
    float km5_knob_1; // крутилка на КМ5
    float km5_scale_2; // поворот шкалы на КМ5
    float km5_needle_2; // стрелка КМ5
    float km5_knob_2; // крутилка на КМ5
    float water_pressure; // давление воды
    float stab_temp; // температура стабилизатора
    float wing_temp; // температура крыла
    float bus115_freq; // частотомер сети 115в - угол
    float bus115_volt; // вольтметр сети 115в - угол
    float bus115_amp; // амерметр сети 115в - угол
    float bus36_volt; // вольтметр сети 36в - угол
    float bus27_volt; // вольтметр сети 27в - угол
    float bus27_amp1; // амперметр сети 27в - угол
    float bus27_amp2; // амперметр сети 27в - угол
    float apu_rpm; // обороты ВСУ
    float apu_egt; // ТВГ ВСУ
    float apu_oil_temp; // температура масла ВСУ
    float egt_1; // ТВГ двиг 1
    float egt_2; // ТВГ двиг 2
    float egt_3; // ТВГ двиг 3
    float fuel_press_1; // давление топлива двиг 1
    float fuel_press_2; // давление топлива двиг 2
    float fuel_press_3; // давление топлива двиг 3
    float oil_press_1; // давление масла двиг 1
    float oil_press_2; // давление масла двиг 2
    float oil_press_3; // давление масла двиг 3
    float oil_temp_1; // температура масла двиг 1
    float oil_temp_2; // температура масла двиг 2
    float oil_temp_3; // температура масла двиг 3
    float fuel_flow_1; // расход топлива двиг 1
    float fuel_flow_2; // расход топлива двиг 2
    float fuel_flow_3; // расход топлива двиг 3
    float vibra_1; // вибрация двиг 1
    float vibra_2; // вибрация двиг 2
    float vibra_3; // вибрация двиг 3
    float starter_press; // давление в системе запуска
    float rpm_low_1; // обороты турбины низкого давления №1
    float rpm_low_2; // обороты турбины низкого давления №2
    float rpm_low_3; // обороты турбины низкого давления №3
    float rpm_high_1; // обороты турбины высокого давления №1
    float rpm_high_2; // обороты турбины высокого давления №2
    float rpm_high_3; // обороты турбины высокого давления №3

} gauges_engines_t;

typedef struct {

    float fuel_meter_summ; // сумарная масса топлива
    float fuel_meter_tank1; // масса топлива в баке 1
    float fuel_meter_tank2_left; // масса топлива в баке 2
    float fuel_meter_tank2_right; // масса топлива в баке 2
    float fuel_meter_tank3_left; // масса топлива в баке 3
    float fuel_meter_tank3_right; // масса топлива в баке 3
    float fuel_meter_tank4; // масса топлива в баке 4
    float fuel_meter_mech; // расходомер

} gauges_fuel_t;

typedef struct {

    float qty_12; // гидробаки
    float qty_3; // гидробаки
    float pressure_ind_1; // индикатор давления гидросистемы 1
    float pressure_ind_2; // индикатор давления гидросистемы 2
    float pressure_ind_3; // индикатор давления гидросистемы 3
    float pressure_ind_emerg; // индикатор давления аварийного торможения

} gauges_hydro_t;

typedef struct {

    float thermo_outside; // индикатор температуры за бортом
    float turn_rate_ind; // индикатор разворота
    float slip_rate_ind; // индикатор скольжения
    float rudder_pos_ind; // индикатор положения РН
    float aileron_pos_ind; // индикатор положения элеронов
    float elevator_pos_ind; // индикатор положения РВ
    float fuel_front_ind; // индикатор топлива на передней панели
    float rsbn_azimuth_ind; // азимут РСБН
    float rsbn_distance_km; // дистанция РСБН
    float rsbn_km_one; // барабанчик единиц км
    float rsbn_km_ten; // барабанчик десятков км
    float rsbn_km_hun; // барабанчик сотен км
    float compas_big_needle; // длинная стрелка на компасе 2П
    float compas_small_needle; // короткая стрелка на компасе 2П
    float compas_knob; // крутилка на компасе 2П
    float diss_abs_angle_1; // барабанчик единиц угла
    float diss_abs_angle_10; // барабанчик десятков угла
    float diss_abs_angle_100; // барабанчик сотен угла
    float diss_plus_angle_1; // барабанчик единиц угла
    float diss_plus_angle_10; // барабанчик десятков угла
    float diss_minus_angle_1; // барабанчик единиц угла
    float diss_minus_angle_10; // барабанчик десятков угла
    float diss_wind_spd_1; // барабанчик единиц скорости ветра
    float diss_wind_spd_10; // барабанчик десятков скорости ветра
    float diss_wind_spd_100; // барабанчик сотен скорости ветра
    float stab_ind; // индикатор положения стаб
    float elevator_ind; // индикатор положения РВ
    float flap_left_ind; // индикатор положения левого закрылка
    float flap_right_ind; // индикатор положения правого закрылка
    float aoa_ind; // индикатор угла атаки
    float aoa_sector; // сектор индикатора угла атаки
    float gforce_ind; // индикатор перегрузки
    float gforce_max; // индикатор макс перегрузки
    float gforce_min; // индикатор мин перегрузки

} gauges_misc_t;

typedef struct {

    float kus_ias_left; // приборная скорость на КУС730 КВС
    float kus_tas_left; // истинная скорость на КУС730 КВС
    float kus_ias_right; // приборная скорость на КУС730 2П
    float kus_tas_right; // истинная скорость на КУС730 2П
    float kus_ias_eng; // приборная скорость на КУС730 БИ
    float kus_tas_eng; // истинная скорость на КУС730 БИ
    float ias_left; // приборная скорость КВС
    float ias_yellow_left; // желтый маркер на индкиторе скорости КВС
    float ias_right; // приборная скорость 2П
    float ias_yellow_right; // желтый маркер на индкиторе скорости 2П
    float mach_left; // скорость маха КВС
    float mach_right; // скорость маха 2П
    float speed_mid_needle; // стрелка индикатора скорости в центре
    int speed_mid_flag; // флажок индикатора скорости в центре 0 - возд, 1 - пут

} gauges_speed_t;

typedef struct {

    float vsi_brt_left; // яркость экрана VSI
    float vsi_brt_right; // яркость экрана VSI

} gauges_vsi_t;
