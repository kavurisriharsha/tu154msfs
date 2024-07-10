typedef struct {

    int spu_1_power; // переключатель питания на СПУ КВС.  -1 - сеть 2, 0 - выкл, 1 - сеть 1
    int spu_1_mode; // переключатель режимов на СПУ КВС. 0 - радио, 1 - СПУ
    int spu_1_source; // переключатель источников на СПУ КВС
    int spu_2_power; // переключатель питания на СПУ 2П
    int spu_2_mode; // переключатель режимов на СПУ 2П
    int spu_2_source; // переключатель источников на СПУ 2П
    int spu_3_power; // переключатель питания на СПУ ШТ
    int spu_3_mode; // переключатель режимов на СПУ ШТ
    int spu_3_source; // переключатель источников на СПУ ШТ
    int spu_4_power; // переключатель питания на СПУ БИ
    int spu_4_mode; // переключатель режимов на СПУ БИ
    int spu_4_source; // переключатель источников на СПУ БИ
    int nosewheel_turn_enable; // выключатель поворота передней стойки на штурвале
    int nosewheel_turn_sel; // переключатель угла поворота передней стойки. 0 - 10, 1 - 63
    int nosewheel_turn_cap; // крышка переключателя угла поворота
    int slat_man; // ручное управление предкрылками. -1 - уборка, 0 выкл, +1 - выпуск
    int slat_man_cap; // крышка ручного урпавления предкрылками
    int flaps_sel; // выбор режимов работы закрылков. -1 - выкл, 0 - авт, +1 - ручное
    int flaps_sel_cap; // крышка выбора работы закрылков
    int gears_retr_lock; // блокировка уборки шасси
    int gears_retr_lock_cap; // крышка блокировки уборки шасси
    int gears_ext_3GS; // выпуск шасси от 3ГС
    int gears_ext_3GS_cap; // крышка выпуска шасси от 3ГС
    int ZK_select; // тумблер "ввод ЗК" на передней панели. 0-лев, 1-прав
    int nav_select; // тумблер НВУ-СНС 0 - НВУ, 1 - СНС
    int vbe_select; // тумблер ВБЭ. 0-лев, 1-прав
    int nav_1_mode; // режим НАВ1. Захват - VOR-DME
    int nav_1_man_auto; // режим ручной - автомат
    int nav_1_mile_km; // режим мили - км
    int nav_2_mode; // режим НАВ1. Захват - VOR-DME
    int nav_2_man_auto; // режим ручной - автомат
    int nav_2_mile_km; // режим мили - км.
    int wiper_left; // переключатель работы стеклоочистителя. -1 - медленно, 0 - выкл, +1 - быстро
    int wiper_right; // переключатель работы стеклоочистителя. -1 - медленно, 0 - выкл, +1 - быстро
    int kln_knob_out; // вытягивание ручки КЛН
    int kln_power_knob; // вдавливание ручки питания КЛН

    swc_airbleed_t* airbleed;
    swc_console_t* console;
    swc_eng_t* eng;
    swc_fuel_t* fuel;
    swc_hydro_t* hydro;
    swc_ovh_t* ovh;
    swc_sard_t* sard;
    swc_tcas_t* tcas;

} swc_t;

typedef struct {

    int var_left; // оерхед. вар лев
    int var_right; // оерхед. вар прав
    int uvid_on; // выключатель УВИД
    int auasp_on; // оерхед. АУАСП
    int auasp_contr; // оерхед. АУАСП контроль
    int eup_on; // выключатель ЭУП
    int agr_on; // выключатель АГР
    int bkk_contr_cap; // крышка тумблера контроля БКК
    int bkk_contr; // контроль БКК. -1 - 2, 0 - выкл, +1 - 1
    int bkk_on_cap; // крышка выключателя БКК
    int bkk_on; // выключатель БКК
    int sau_stu_on; // САУ СТУ выключатель
    int sau_stu_cap; // крышка выключателя САУ СТУ
    int pkp_left_cap; // крылка ПКП лев
    int pkp_left_on; // ПКП лев
    int pkp_right_cap; // крышка ПКП прав
    int pkp_right_on; // ПКП прав
    int mgv_contr_cap; // контроль МГВ крышка
    int mgv_contr; // контроль МГВ
    int tks_on_1; // выключатель ТКС 1
    int tks_on_2; // выключатель ТКС 2
    int tks_heat; // обогрев ГА
    int tks_corr_1; // коррекция БГМК 2 - 1
    int tks_corr_2; // коррекция БГМК 2 - 2
    int curs_pnp_mode_1; // режим курс ПНП. 0 - ГМК, 1 - ГПК
    int curs_pnp_mode_2; // режим курс ПНП. 0 - ГМК, 1 - ГПК
    int svs_on; // выключатель СВС
    int svs_heat; // обогрев СВС
    int kln_on; // выключатель КЛН
    int tcas_on; // выключатель TCAS
    int emerg_light_cap; // крышка аварийного освещения
    int emerg_light_on; // аварийное освещение
    int vbe_1_on; // ВБЭ 1
    int vbe_2_on; // ВБЭ 2
    int curs_np_on_1; // курс МП 1
    int curs_np_on_2; // курс МП 2
    int tra_67_on; // ТРА 67
    int rsbn_on; // РСБН питание
    int rsbn_recon; // РСБН опознавание
    int rv5_1_on; // РВ5 1
    int rv5_2_on; // РВ5 2
    int vhf_1_on; // УКВ 1
    int vhf_2_on; // УКВ 2
    int stabil_ga_main; // стабилизация ГА по крену осн
    int stabil_ga_reserv; // стабилизация ГА резерв
    int micron_1_on; // микрон 1
    int micron_2_on; // микрон 2
    int spu_on; // СПУ
    int sgs_on; // СГС
    int sd75_1_on; // СД75 1
    int sd75_2_on; // СД75 2
    int mars_on; // МАРС
    int diss_on; // питание ДИСС
    int diss_mode; // режим дисс. 0 - море, 1 - суша
    int nvu_calc_set; // счисление. -1 - контроль ДИСС в полете, 0 - НВУ по СВС, 1 - НВУ по ДИСС
    int vent_1; // вентилятор КВС
    int vent_2; // вентилятор 2П
    int vent_3; // вентилятор БИ
    int sign_belts; // транспарант пристегните ремни
    int sign_nosmoke; // транспарант не курить
    int sign_exit; // транспарант выход
    int window_heat_1; // обогрев стекол. -1 - слабо, 0 - выкл, 1 - сильно
    int window_heat_2; // обогрев стекол. -1 - слабо, 0 - выкл, 1 - сильно
    int window_heat_3; // обогрев стекол. -1 - слабо, 0 - выкл, 1 - сильно
    int pitot_heat_1; // обогрев ППД лев
    int pitot_heat_2; // обогрев ППД прав
    int pitot_heat_3; // обогрев ППД АБСУ
    int arm406; // АРМ 406
    int ushdb_mode_1; // УШДБ и СПУ 1. 0 - АРК, 1 - VOR
    int ushdb_mode_2; // обогрев ППД
    int egpws_alarm_1; // сигнализация СРПБЗ общ
    int egpws_alarm_2; // сигнализация СРПБЗ
    int egpws_alarm_1_cap; // сигнализация СРПБЗ общ
    int egpws_alarm_2_cap; // сигнализация СРПБЗ
    int egpws_relief; // рельеф
    int egpws_mode; // QNH - QFE
    int transponder_mode; // режим ответчика. 0 откл, 1 готов, 2 рсп, 3 увд, 4 увд-м, 5 ас, 6 а.
    int tks_mode; // режим ТКС 0 - МК, 1 - ГПК, 2 - АК
    int tks_mode_left; // режим левого ГА. 0 - контр, 1 - осн
    int tks_mode_right; // режим правого ГА
    int tks_lat_mode; // режим установки широты. 0 - авто, 1 - ручн
    int tks_course_set; // задатчик курса
    int ark_1_mode; // режим АРК 1 0 - выкл, 1 - комп, 2 - ант, 3 - рам
    int ark_1_channel; // канал АРК 1
    int ark_1_hundr_left; // сотни частоты 1 - 17
    int ark_1_tens_left; // десятки частоты 1 - 10 (0)
    int ark_1_ones_left; // единицы частоты 0 - 9
    int ark_1_hundr_right; // сотни частоты 1 - 17
    int ark_1_tens_right; // десятки частоты 1 - 10 (0)
    int ark_1_ones_right; // единицы частоты 0 - 9
    int ark_2_mode; // режим АРК 2
    int ark_2_channel; // канал АРК 2
    int ark_2_hundr_left; // сотни частоты 1 - 17
    int ark_2_tens_left; // десятки частоты 1 - 10 (0)
    int ark_2_ones_left; // единицы частоты 0 - 9
    int ark_2_hundr_right; // сотни частоты 1 - 17
    int ark_2_tens_right; // десятки частоты 1 - 10 (0)
    int ark_2_ones_right; // единицы частоты 0 - 9
    int sp50_mode; // режим СП50. 0 - ILS, 1 - Katet, 2 - SP-50
    int sp50_nav_mode; // режим СП50. посадка - маршрут
    int sp50_night_day; // режим СП50. ночь - день
    int sp50_dme_rsbn; // режим СП50. DME - РСБН

} swc_ovh_t;

typedef struct {

    int wing_light; // габаритные наземные огни на крыле
    int door_heat; // обогрев дверей
    int gear_fan; // вентиляция шасси
    int galley_heat; // обогрев слива кухни
    int lavatory_heat; // обогрев слива туалетов
    int water_meter; // уровень воды в баке
    int water_compressor_1; // обогрев слива кухни
    int water_compressor_2; // обогрев слива кухни
    int tail_temp_signal; // сигнал температуры хвостового отсека
    int tail_temp_heat; // обогрев АРД
    int msrp_date_ten; // МРСП дата число десятки
    int msrp_date_one; // МРСП дата число единицы
    int msrp_month_ten; // МРСП дата месяц десятки
    int msrp_month_one; // МРСП дата месяц единицы
    int msrp_year_ten; // МРСП дата год десятки
    int msrp_year_one; // МРСП дата год единицы
    int msrp_route_hun; // МРСП рейс. сотни
    int msrp_route_ten; // МРСП рейс. десятки
    int msrp_route_one; // МРСП рейс. единицы
    int msrp_mlp_1; // МРСП млп осн
    int msrp_mlp_2; // МРСП млп доп
    int msrp_night_day; // МРСП ночь - день
    int msrp_main_switch; // МРСП главный выключатель
    int hydro_trimm_rud_1; // триммирование РВ 1
    int hydro_trimm_rud_2; // триммирование РВ 2
    int hydro_trimm_rud_1_cap; // триммирование РВ 1
    int hydro_trimm_rud_2_cap; // триммирование РВ 2
    int emerg_gen_on_1; // аварийное включение генераторов
    int emerg_gen_on_2; // аварийное включение генераторов
    int emerg_gen_on_3; // аварийное включение генераторов
    int emerg_gen_on_1_cap; // аварийное включение генераторов
    int emerg_gen_on_2_cap; // аварийное включение генераторов
    int emerg_gen_on_3_cap; // аварийное включение генераторов
    int hydro_ra56_rud_1; // гидропитание РА56 курс
    int hydro_ra56_rud_2; // гидропитание РА56 курс
    int hydro_ra56_rud_3; // гидропитание РА56 курс
    int hydro_ra56_ail_1; // гидропитание РА56 крен
    int hydro_ra56_ail_2; // гидропитание РА56 крен
    int hydro_ra56_ail_3; // гидропитание РА56 крен
    int hydro_ra56_elev_1; // гидропитание РА56 тангаж
    int hydro_ra56_elev_2; // гидропитание РА56 тангаж
    int hydro_ra56_elev_3; // гидропитание РА56 тангаж
    int hydro_circuit_auto_man; // кольцевание автомат - ручное
    int hydro_long_control; // продольная управляемость
    int hydro_circuit_auto_man_cap; // кольцевание автомат - ручное
    int hydro_long_control_cap; // продольная управляемость
    int fire_sensor_sel; // выбор группы датчиков
    int fire_place_sel; // выбор отсека
    int fire_main_switch; // выключатель пожарной системы
    int fire_buzzer; // пожарная сирена
    int fire_buzzer_cap; // пожарная сирена
    int srd_buzzer; // СРД сирена
    int srd_buzzer_cap; // СРД сирена
    int fuel_buzzer; // сирена остатка топлива 2500кг
    int fuel_buzzer_cap; // сирена остатка топлива 2500кг
    int soi21_on; // выключатель СОИ 21
    int antiice_slats; // противообледенители
    int antiice_eng_1; // противообледенители
    int antiice_eng_2; // противообледенители
    int antiice_eng_3; // противообледенители
    int antiice_wing; // противообледенители
    int sard_disable; // перекрытие клапана сброса воздуха
    int sard_disable_cap; // перекрытие клапана сброса воздуха
    int gpu_on; // выключатель РАП
    int apu_gen_on; // выключатель ген ВСУ
    int bus115_volt_sel; // переключатель источника вольтметра
    int bus115_volt_phase_sel; // переключатель источника вольтметра
    int bus115_amp_sel; // переключатель источника амерметра
    int bus115_amp_phase_sel; // переключатель источника амерметра
    int gen_1_on; // выключатель генератора 1. -1 - проверка, 0 - выкл, +1 - вкл.
    int gen_2_on; // выключатель генератора 2. -1 - проверка, 0 - выкл, +1 - вкл.
    int gen_3_on; // выключатель генератора 3. -1 - проверка, 0 - выкл, +1 - вкл.
    int emerg_inv115; // аварийн. преобраз 115в
    int emerg_inv115_cap; // аварийн. преобраз 115в
    int bus36_volt_sel; // переключатель вольтметра 36в
    int pts250_sel; // переключатель ПТС250. 0 - №1, 1 - №2
    int bus36_tr_left_to_right; // лев сеть на тр2. 0 - авто, 1 - ручное
    int bus36_tr_right_to_left; // прав сеть на тр1
    int pts250_on; // выключатель ПТС250
    int pts250_mode; // режим ПТС250. авто - ручное
    int pts250_on_cap; // выключатель ПТС250
    int pts250_mode_cap; // режим ПТС250. авто - ручное
    int bus27_volt_sel; // переключатель вольтметра 27в
    int bus27_amp1_sel; // переключатель амперметра 27в
    int bus27_amp2_sel; // переключатель амперметра 27в
    int bus27_connect; // соединение сетей 27в
    int bus27_connect_cap; // соединение сетей 27в
    int bus27_vu1; // ВУ1. -1 - резерв, 0 - выкл, +1 - вкл.
    int bus27_vu2; // ВУ2. -1 - резерв, 0 - выкл, +1 - вкл.
    int bat1_on; // батарея 1
    int bat2_on; // батарея 2
    int bat3_on; // батарея 3
    int bat4_on; // батарея 4
    int apu_main_switch; // выключатель ВСУ
    int apu_start_mode; // режим запуска ВСУ
    int apu_air_bleed; // переключение заслонки отбора воздуха. -1 - закрыть, 0 - нейтр, +1 - открыть
    int vibro_sel_1; // переключатель прибора вибрации
    int vibro_sel_2; // переключатель прибора вибрации
    int vibro_sel_3; // переключатель прибора вибрации
    int starter_cap; // крышка панели запуска
    int starter_switch; // выключатель запуска
    int starter_eng_select; // выбор двигателя
    int starter_mode; // режим запуска
    int gauges_on_1; // приборы контроля двигателей
    int gauges_on_2; // приборы контроля двигателей
    int gauges_on_3; // приборы контроля двигателей
    int gauges_on_1_cap; // приборы контроля двигателей
    int gauges_on_2_cap; // приборы контроля двигателей
    int gauges_on_3_cap; // приборы контроля двигателей

} swc_eng_t;

typedef struct {

    int pump_tank2_left; // насосы бака 2
    int pump_tank2_right; // насосы бака 2
    int pump_tank3_left; // насосы бака 3
    int pump_tank3_right; // насосы бака 3
    int pump_tank4; // насосы бака 4
    int pump_tank1_1; // насосы бака 1
    int pump_tank1_2; // насосы бака 1
    int pump_tank1_3; // насосы бака 1
    int pump_tank1_4; // насосы бака 1
    int fuel_trans; // краны резервой перекачки
    int fuel_trans_cap; // краны резервой перекачки
    int fuel_porc; // принуд порц
    int fuel_porc_cap; // принуд порц
    int fuel_level; // автомат выравнивания
    int fuel_flow_mode; // режим расходомера. ручное - автомат
    int fuel_flow_on; // автомат расхода
    int fuel_flow_on_cap; // автомат расхода
    int fuel_meter_on; // топливомер
    int fuel_meter_mech_on; // расходомер
    int fire_valve_1; // пожарный кран
    int fire_valve_2; // пожарный кран
    int fire_valve_3; // пожарный кран
    int fire_valve_1_cap; // пожарный кран
    int fire_valve_2_cap; // пожарный кран
    int fire_valve_3_cap; // пожарный кран

} swc_fuel_t;

typedef struct {

    int connect2to1; // подключение 2 ГС на 1 ГС
    int connect2to1_cap; // подключение 2 ГС на 1 ГС
    int pump_2; // гидронасосы 2
    int pump_3; // гидронасосы 3

} swc_hydro_t;

typedef struct {

    int cabin_sel; // выбор салона
    int cockpit_temp_set; // установка температуры кабины
    int cabin1_temp_set; // установка температуры салона
    int cabin2_temp_set; // установка температуры салона
    int cockpit_mode_set; // установка режима обогрева. 0 - нейтр. 1 - авто, 2 - хол, 3 - гор
    int cabin1_mode_set; // установка режима обогрева
    int cabin2_mode_set; // установка режима обогрева
    int heat_close; // прекращение обогрева
    int heat_close_cap; // прекращение обогрева
    int left_sys_temp_set; // установка температуры левой магистрали
    int right_sys_temp_set; // установка температуры правой магистрали
    int left_sys_mode_set; // установка режима левой магистрали
    int right_sys_mode_set; // установка режима правой магистрали
    int ground_cond_on; // наземное кондиционирование
    int ground_cond_on_cap; // наземное кондиционирование
    int skv_faster_work; // -1 - охлаждение ГК, 0 - выкл, +1 - ускоренноые режимы обогрева
    int skv_faster_work_cap; // крышка
    int sys_temp_select; // переключение источников термометра. 0 - обогрев дверей, 1 - экип, 2 - салон 1, 3 - салон 2, 4 - маг лев, 5 - маг прав
    int psvp_left_on; // ПСВП лев
    int psvp_right_on; // ПСВП прав
    int psvp_left_on_cap; // ПСВП лев
    int psvp_right_on_cap; // ПСВП прав
    int air_valve_left; // краны наддува. -1 закр, 0 - нейтр, +1 откр
    int air_valve_right; // краны наддува. -1 закр, 0 - нейтр, +1 откр
    int air_valve_both; // краны наддува. -1 закр, 0 - нейтр, +1 откр
    int emerg_decompress; // сброс давления
    int emerg_decompress_cap; // сброс давления
    int eng_valve_1; // отбор воздуха от двигателей
    int eng_valve_2; // отбор воздуха от двигателей
    int eng_valve_3; // отбор воздуха от двигателей
    int dubler_on; // дублер
    int dubler_on_cap; // дублер

} swc_airbleed_t;

typedef struct {

    int buster_on_1; // выключатель бустера
    int buster_on_2; // выключатель бустера
    int buster_on_3; // выключатель бустера
    int busters_cap; // крышка выключателей бустеров
    int rls_on; // выключатель РЛС
    int rls_mode; // режимы РЛС. 0 -готов, 1 - метео
    int rls_distance; // дистанции РЛС
    float rls_brt; // яркость РЛС
    float rls_contr; // контраст РЛС
    float rls_signs; // яркость меток РЛС
    int absu_zpu_sel; // переключатель ЗПУ. лев - прав
    int absu_nav_on; // стрелки навигация
    int absu_landing_on; // стрелки посадка
    int absu_needles_on; // стрелки
    int absu_speed_mode; // режим СТУ. 0 - откл, 1 - нву, 2 - аз1, 3 - аз2, 4 - пос
    int absu_speed_change; // ручка изменения скорости.
    int absu_speed_off; // отключение 1 и 2
    int absu_speed_prepare; // подготовка
    int absu_speed_off_cap; // отключение 1 и 2
    int absu_speed_prepare_cap; // подготовка
    int absu_speed_us_right_left; // подготовка
    int absu_turn_handle; // ручка поворота
    float absu_pitch_wheel; // колесико спуска, подъема
    int absu_roll_ch_on; // выключатель канал крена
    int absu_pitch_ch_on; // выключатель канала тангажа
    int absu_smooth_on; // выключатель "в болтанку"
    int absu_smooth_on_cap; // выключатель "в болтанку"
    int absu_pitch_wheel_dir; // направление колесика спуска, подъема
    int nvu_param_sel; // ручка выбора вводимого параметра НВУ. -4 - Z, -3 - S, -2 - Zm, -1 - Sm, 0 - off, 1 - Sn, 2 - Zn, 3 - S, 4 - Z
    int nvu_turn_sel; // ручка выбора радиуса разворота, -1 - принуд, 0 - выкл, 1 - 5, 2 - 10, 3 - 15, 4 - 20, 5 - 25
    int nvu_power_on; // питание НВУ
    int nvu_calc_on; // счисление НВУ
    int nvu_corr_on; // коррекция НВУ
    int emerg_elev_trimm; // аварийное управление триммером
    int emerg_elev_trimm_cap; // аварийное управление триммером

} swc_console_t;

typedef struct {

    float sard_cabin_press_set; // установка давления в кабине
    float sard_abs_press_set; // установка абсолютного давления
    float sard_diff_set; // установка перепада давлений
    float sard_spd_set; // установка скорости работы САРД

} swc_sard_t;

typedef struct {

    int tcas_mode; // режим TCAS. -1 = test, 0 - stby, 1 = alt off, 2 = alt on, 3 = TA, 4 = TARA
    int tcas_rot_big; // большая вертелка
    int tcas_rot_small; // малая вертелка

} swc_tcas_t;

