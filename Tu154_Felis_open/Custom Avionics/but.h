typedef struct {

    int lamp_test_front; // кнопка проверки ламп передней панели
    int lamp_test_upper_gear; // кнопка проверки ламп верхней панели шасси
    int lamp_test_eng_up_1; // кнопка проверки ламп на панели сливных насадок
    int lamp_test_eng_up_2; // кнопка проверки ламп на панели сливных насадок
    int lamp_test_msrp; // кнопка проверки ламп МСРП
    int lamp_test_pa56; // кнопка проверки ламп на панели гидропитания РА-56
    int lamp_test_fire_panel; // кнопка проверки ламп на пожарной панели
    int lamp_test_apu; // кнопка проверки ламп на панели ВСУ
    int lamp_test_engines; // кнопка проверки ламп на панели приборов двигателей
    int lamp_test_hydro; // кнопка проверки ламп на панели гидросистемы
    int lamp_test_srd; // кнопка проверки ламп на панели наддува
    int lamp_test_doors; // кнопка проверки ламп на панели индикации дверей и люков
    int clock_24_left; // левая кнопка 24-часовых часов. 0 - отжата, 1 - нажата (касается всех кнопок)
    int clock_24_right; // правая кнопка 24-часовых часов

    but_console_t* console;
    but_eng_t* eng;
    but_fuel_t* fuel;
    but_hydro_t* hydro;
    but_misc_t* misc;
    but_nvu_t* nvu;
    but_ovhd_t* ovhd;
    but_srpbz_t* srpbz;
    but_tcas_t* tcas;

} but_t;

typedef struct {

    int wind_course_left; // кнопка установки курса ветра
    int wind_course_ctr; // кнопка установки курса ветра
    int wind_course_right; // кнопка установки курса ветра
    int wind_spd_left; // кнопка установки скорости ветра
    int wind_spd_ctr; // кнопка установки скорости ветра
    int wind_spd_right; // кнопка установки скорости ветра
    int absu_zk; // кнопка ЗК на панели АБСУ
    int absu_reset; // кнопка сброс программы на панели АБСУ
    int absu_nvu; // кнопка НВУ на панели АБСУ
    int absu_az1; // кнопка АЗ 1 на панели АБСУ
    int absu_az2; // кнопка АЗ 2 на панели АБСУ
    int absu_app; // кнопка заход на панели АБСУ
    int absu_gs; // кнопка глиссада на панели АБСУ
    int absu_stab_m; // кнопка M на панели АБСУ
    int absu_stab_v; // кнопка V на панели АБСУ
    int absu_stab_h; // кнопка H на панели АБСУ
    int absu_stab; // кнопка СТАБ на панели АБСУ
    int absu_stab_speed; // кнопка C на панели АБСУ
    int absu_throt_off_1; // кнопка откл Г1 на панели АБСУ
    int absu_throt_off_2; // кнопка откл Г2 на панели АБСУ
    int absu_throt_off_3; // кнопка откл Г3 на панели АБСУ
    int absu_speed_test_1; // кнопка првоерки СТУ нижняя
    int absu_speed_test_2; // кнопка првоерки СТУ верхняя
    int absu_arrest; // кнопки арретирования
    int absu_arrest_cap; // крышка кнопок арретирования
    int radio; // кнопка радио на пъедестале
    int pdu406_control; // кнопка дежур-контроль
    int pdu406_sound_off; // кнопка отключение звука

} but_console_t;

typedef struct {

    int tail_temp_signal_control_1; // контроль сигнала температуры хвостового отсека
    int tail_temp_signal_control_2; // контроль сигнала температуры хвостового отсека
    int fire_ext_1; // очередь тушения пожара
    int fire_ext_2; // очередь тушения пожара
    int fire_ext_3; // очередь тушения пожара
    int cold_eng_1; // подача хладона
    int cold_eng_2; // подача хладона
    int cold_eng_3; // подача хладона
    int cold_apu; // подача хладона
    int neutral_gas; // нейтральный газ
    int smoke_test; // подача хладона
    int ext_test; // подача хладона
    int srd_buzzer_test; // проверка сирены СРД
    int soi21_test; // проверка СОИ 21
    int apu_start; // кнопка старта ВСУ
    int apu_stop; // кнопка стоп ВСУ
    int control_ut; // кнопка контроль УТ
    int control_vibro_1; // кнопка контроль вибрации
    int control_vibro_2; // кнопка контроль вибрации
    int control_vibro_3; // кнопка контроль вибрации
    int starter_start; // кнопка запуска
    int starter_stop; // кнопка преркащения запуска
    int flight_start_1; // запуск в полете
    int flight_start_2; // запуск в полете
    int flight_start_3; // запуск в полете
    int reserv_pump_test; // проверка резерв топл насоса

} but_eng_t;

typedef struct {

    int fuel_meter_summ_zero; // сумарная масса топлива. кнопка нуля
    int fuel_meter_summ_max; // сумарная масса топлива. кнопка P
    int fuel_meter_tank2_zero; // топливомер бака 2. кнопка нуля
    int fuel_meter_tank2_max; // топливомер бака 2. кнопка P
    int fuel_meter_tank3_zero; // топливомер бака 3. кнопка нуля
    int fuel_meter_tank3_max; // топливомер бака 3. кнопка P
    int fuel_meter_tank4_zero; // топливомер бака 4. кнопка нуля
    int fuel_meter_tank4_max; // топливомер бака 4. кнопка P

} but_fuel_t;

typedef struct {

    int qty_test_12; // контроль уровня
    int qty_test_3; // контроль уровня
    int accum_fill; // зарядка аккумулятора

} but_hydro_t;

typedef struct {

    int gforce_reset; // кнопка сброса стрелок максимальных перегрузок
    int fuel_front_zero; // индикатор топлива на передней панели.кнопка нуля
    int fuel_front_max; // индикатор топлива на передней панели.кнопка макс

} but_misc_t;

typedef struct {

    int nvu_left_btn; // левая кнопка НВУ
    int nvu_ctr_btn; // центр кнопка НВУ
    int nvu_right_btn; // правая кнопка НВУ
    int zpu_1_left_btn; // левая кнопка ЗПУ
    int zpu_1_ctr_btn; // центр кнопка ЗПУ
    int zpu_1_right_btn; // правая кнопка ЗПУ
    int zpu_2_left_btn; // левая кнопка ЗПУ
    int zpu_2_ctr_btn; // центр кнопка ЗПУ
    int zpu_2_right_btn; // правая кнопка ЗПУ

} but_nvu_t;

typedef struct {

    int svs_contr; // кнопка контроля СВС
    int tks_signal_off; // снятие блокировки сигнала ТКС
    int egpws_control; // кнопка контроля СРПБЗ
    int egpws_contr_gs; // контроль СРПБЗ глиссада
    int rsbn_control_strobe; // контроль строба РСБН
    int rsbn_control_azimuth; // контроль нуля азимут РСБН
    int rsbn_control_distance; // контроль нуля дальность РСБН
    int rsbn_ch_ten; // ручка установки десятков канала
    int rsbn_ch_one; // ручка установки единиц канала
    int transponder_control; // кнопка контроль
    int transponder_sign; // кнопка знак
    int transponder_but_1; // кнопка 1
    int transponder_but_2; // кнопка 2
    int transponder_but_3; // кнопка 3
    int transponder_but_4; // кнопка 4
    int transponder_emerg; // кнопка авария
    int transponder_emerg_cap; // крышка кнопки аварии
    int tks_corrr_button; // кнопка согласования
    int ark_1_ramka; // кнопка рамки
    int ark_2_ramka; // кнопка рамки
    int nav_1_but_1; // кнопка 1
    int nav_1_but_2; // кнопка 2
    int nav_1_but_3; // кнопка 3
    int nav_2_but_1; // кнопка 1
    int nav_2_but_2; // кнопка 2
    int nav_2_but_3; // кнопка 3

} but_ovhd_t;

typedef struct {

    int but_view; // кнопка ВИД
    int but_empty; // кнопка -
    int but_down; // кнопка масштаб вниз
    int but_up; // кнопка масштаб вверх

} but_srpbz_t;

typedef struct {

    int tcas_ident_btn; // кнопка IDENT
    int tcas_fcn_btn; // кнопка FCN
    int tcas_left_btn; // кнопка <
    int tcas_right_btn; // кнопка >
    int tcas_ent_btn; // кнопка ENT
    int tcas_atc_btn; // кнопка ATC
    int tcas_alt_btn; // кнопка ALT
    int tcas_rng_dn_btn; // кнопка RNG DN
    int tcas_rng_up_btn; // кнопка RNG UP

} but_tcas_t;
