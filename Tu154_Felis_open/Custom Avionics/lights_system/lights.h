typedef struct {

    int mid_left_panel_int_set; // регулятор встроенного освещения передней панели КВС
    int left_panel_int_set; // регулятор встроенного освещения левой панели
    int right_panel_int_set; // регулятор встроенного освещения правой панели
    int mid_right_panel_int_set; // регулятор встроенного освещения передней панели 2П
    int ovhd_panel_int_set; // регулятор встроенного освещения верхней панели
    int cabinl_flood_set; // выключатель освещения кабины
    int azs_panel_flood_set; // выключатель освещения панели АЗС
    int day_night_set; // переключатель день - ночь. 0 - день, 1 - ночь. приглушает яркость сигнальных ламп.
    int cargo_light_1_set; // выключатель освещения грузового отсека
    int cargo_light_2_set; // выключатель освещения грузового отсека
    int tech_light_set; // выключатель освещения технического отсека
    int gear_nacelle_light_set; // выключатель освещения гондол шасси
    int nav_lights_set; // выключатель нав огней
    int strobe_set; // выключатель строб огней
    int wing_light_left_set; // выключатель подсвета крыла
    int wing_light_right_set; // выключатель подсвета крыла
    int tail_light_set; // выключатель подсвета хвоста
    int wing_light_left; // подсветка крыла лев
    int wing_light_right; // подсветка крыла прав
    int tail_light; // подсветка хвоста
    int landing_ext_set_L; // выпуск фар лев
    int landing_ext_set_R; // выпуск фар прав
    int landing_mode_set_L; // режим фар лев. -1 - рулежный, 0 - выкл, +1 - посадочный
    int landing_mode_set_R; // режим фар прав
    int light_signal_set; // сигнал в полете
    int landing_light_off; // выключатель фар
    int landing_light_off_cap; // выключатель фар
    int white_light_left; // светимость левого белого огня на крыле
    int white_light_right; // светимость правого белого огня на крыле
    int beacon_light_B; // светимость красного маяка внизу
    int beacon_light_T; // светимость красного маяка вверху

    float no_LIT; // переменная для отключения светимости у объектов, которые имеют LIT текстуру, но светиться не должны
    float left_panel_flood_set; // регулятор яркости заливающего света левой панели
    float right_panel_flood_set; // регулятор яркости заливающего света правой панели
    float mid_panel_flood_set; // регулятор яркости заливающего света центральной панели
    float front_panel_flood_set; // регулятор яркости заливающего света передней панели
    float ovhd_front_panel_flood_set; // регулятор яркости заливающего света передней части оверхеда
    float ovhd_back_panel_flood_set; // регулятор яркости заливающего света заднией части оверхеда
    float eng_panel_flood_set; // регулятор яркости освещения панели БИ
    float cabin_2d_light; // яркость 2D подсветки в салоне
    float exit_lamp; // лампа выхода
    float fasten_seatbelts_lamp; // лампа пристегните ремни
    float nosmoking_lamp; // лампа не курить
    float toilet_busy_lamp; // лампа туалет занят
    float seats_leters_lamp; // лампы с буквами кресел
    float mid_left_panel_int; // яркость свечения пъедестала
    float left_panel_int; // яркость свечения встроенного освещения панели КВС
    float right_panel_int; // яркость свечения встроенного освещения панели 2П
    float mid_right_panel_int; // яркость свечения встроенного освещения средней передней панели
    float ovhd_panel_int; // яркость свечения встроенного освещения верхней панели
    float left_panel_flood; // яркость заливающего света левой панели
    float right_panel_flood; // яркость заливающего света правой панели
    float mid_panel_flood; // яркость заливающего света центральной панели
    float front_panel_flood; // яркость заливающего света передней панели
    float ovhd_front_panel_flood; // яркость заливающего света передней части оверхеда
    float ovhd_back_panel_flood; // яркость заливающего света задней части оверхеда
    float eng_panel_flood; // яркость освещения панели БИ
    float azs_panel_flood; // освещение панели АЗС
    float cargo_light_1; // освещение грузового отсека 1
    float cargo_light_2; // освещение грузового отсека 2
    float tech_light; // отсвещение тех-отсека
    float gear_nacelle_light; // освещение гондол шасси
    float left_spotlight_flood; // яркость левого фонарика
    float ark1_left_lit; // подсветка левой части АРК 1
    float ark1_right_lit; // подсветка правой части АРК 1
    float ark1_all_lit; // подсветка АРК 1
    float ark2_left_lit; // подсветка левой части АРК 2
    float ark2_right_lit; // подсветка правой части АРК 2
    float ark2_all_lit; // подсветка АРК 2
    float tks_mode_lit_mk; // лампочка режима ТКС - МК
    float tks_mode_lit_ak; // лампочка режима ТКС - АК
    float tks_mode_lit_gpk; // лампочка режима ТКС - ГПК
    float to_not_ready; // к взлету не готов
    float wrong_trimm; // ложное триммирование
    float controll_roll; // управляй креном
    float controll_pitch; // управляй тангажом
    float yoke_sign; // сигнализация ухода на второй круг в штурвальном режиме
    float triangle; // интегральный сигнальный огонь
    float controll_thrust; // управляй тягой
    float course_lim; // выход за пределы курса
    float gs_lim; // выход за пределы глиссады
    float fire; // ПОЖАР
    float no_ag_controll; // нет контроля АГ
    float fuel_less_2500; // остаток топлива 2500
    float sso_danger; // ССО опасно
    float sso_connect; // ССО связь
    float speed_high; // предел скорости
    float roll_left_high; // крен лев велик
    float roll_right_high; // крен прав велик
    float alpha_high; // предельный УА
    float g_force_high; // передельная перегрузка
    float auasp_lamp; // лампа на АУАСП
    float toga; // уход
    float decision_height; // ССО связьвысота принятия решения Н
    float course; // КУРС
    float glideslope; // ГЛИСС
    float zk_lamp; // ЗК
    float thrust_automat; // автомат тяги
    float stab_roll; // стабилизация боков
    float stab_pitch; // стабилизация продольная
    float nvu_lamp; // НВУ
    float vor_lamp; // VOR
    float stab_h; // стаб H
    float stab_v; // стаб V
    float stab_m; // стаб M
    float marker_1; // маркер 1
    float marker_2; // маркер 2
    float marker_3; // маркер 3
    float pull_up; // тяни вверх
    float check_alt_left; // проверь Н
    float check_alt_right; // проверь Н
    float sns_lamp; // СНС
    float fp_eng_fail_1; // двиг. неиспр 1 на передней панели
    float fp_eng_fail_2; // двиг. неиспр 2 на передней панели
    float fp_eng_fail_3; // двиг. неиспр 3 на передней панели
    float fp_reverse_1; // створки реверса 1 на передней панели
    float fp_reverse_3; // створки реверса 3 на передней панели
    float stab_work; // стабилиз включен
    float flaps_1_valve; // закрылки 1 ПК
    float flaps_2_valve; // закрылки 2 ПК
    float spoilers_mid_left; // интерцепторы средн лев
    float spoilers_mid_right; // интерцепторы средн прав
    float spoilers_inn_left; // интерцепторы внутр лев
    float spoilers_inn_right; // интерцепторы внутр прав
    float gears_not_ext; // шасси не выпущенны
    float gears_red_left; // красная лампа шасси
    float gears_red_front; // красная лампа шасси
    float gears_red_right; // красная лампа шасси
    float gears_green_left; // зеленая лампа шасси
    float gears_green_front; // зеленая лампа шасси
    float gears_green_right; // зеленая лампа шасси
    float gears_red_left_eng; // красная лампа шасси на панели БИ
    float gears_red_front_eng; // красная лампа шасси на панели БИ
    float gears_red_right_eng; // красная лампа шасси на панели БИ
    float gears_green_left_eng; // зеленая лампа шасси на панели БИ
    float gears_green_front_eng; // зеленая лампа шасси на панели БИ
    float gears_green_right_eng; // зеленая лампа шасси на панели БИ
    float flaps_unsync; // рассинхр закрылки
    float slats_unsync; // рассинхр предкр
    float slats_extended; // предкрылки выпущены
    float to_rudder; // взлет-посадка РН
    float to_elevator; // взлет-посадка РВ
    float trimm_zero_course; // нетрально курс
    float trimm_zero_roll; // нетрально крен
    float trimm_zero_pitch; // нетрально тангаж
    float damper_course; // демпер курс
    float damper_roll; // демпер крен
    float damper_pitch; // демпер тангаж
    float no_reserve_c; // нет резерва К
    float no_reserve_g; // нет резерва Г
    float pitch_control_fail; // продол управл
    float roll_control_fail; // боков управл
    float ga_main_fail; // отказ ГА осн
    float ga_reserve_fail; // отказ ГА контр
    float msg_lamp; // MSG
    float wpt_lamp; // WPT
    float stuard_call; // вызов БП
    float mgv_control_fail; // отказ МГВ контр
    float sns_lamp; // СНС
    float correct_on; // коррекция включ
    float change_ch_o; // смена ЧО
    float warning_terrain; // внимание земля
    float gs_low; // глиссада низко
    float cockpit_p_low; // Р каб мало
    float nvu_fail; // отаказ НВУ
    float nvu_vor_automat; // НВУ-VOR автомат
    float dist_autonom; // дист автоном
    float diss_memory; // память ДИСС
    float azimuth_autonom; // азимут автоном
    float srpbz_fail; // отказ СРПБЗ
    float tcas_ident; // лампа идентификации ТКАС
    float other_hatches; // лампа для незадействованных люков
    float left_front_pax_door; // левая передняя дверь открыта
    float left_mid_pax_door; // левая средняя дверь открыта
    float right_mid_pax_door; // средняя средняя дверь открыта
    float cargo_front_door; // передний багажный люк
    float cargo_back_door; // передний багажный люк
    float turn63_lamp; // разворот 63
    float nosewheel_turn_off; // поворот не включен
    float busters_off; // лампа бустера
    float water_level_1; // уровень воды 1
    float water_level_12; // уровень воды 1/2
    float water_level_14; // уровень воды 1/4
    float water_level_0; // уровень воды 0
    float ra56_roll_fail_1; // отказ РА56 крен
    float ra56_roll_fail_2; // отказ РА56 крен
    float ra56_roll_fail_3; // отказ РА56 крен
    float ra56_pitch_fail_1; // отказ РА56 тангаж
    float ra56_pitch_fail_2; // отказ РА56 тангаж
    float ra56_pitch_fail_3; // отказ РА56 тангаж
    float ra56_course_fail_1; // отказ РА56 курс
    float ra56_course_fail_2; // отказ РА56 курс
    float ra56_course_fail_3; // отказ РА56 курс
    float nvu_no_reserve; // резерва НВУ нет
    float absu_work; // испр АБСУ
    float sard_panel_lit; // светимость панели САРД
    float nvu_1_active; // светимость активной панели НВУ
    float nvu_2_active; // светимость активной панели НВУ
    float oil_qty_work_1; // светимость лампы на масломере
    float oil_qty_work_2; // светимость лампы на масломере
    float oil_qty_work_3; // светимость лампы на масломере
    float gns430_lit; // светимость панели ГНС

    lights_fire_t* fire;
    lights_apu_t* apu;
    lights_eng_t* eng;
    lights_small_t* small;
    lights_button_t* button;

} lights_t;

typedef struct {

    float smoke_1; // дым в отсеках
    float smoke_2; // дым в отсеках
    float smoke_zone2_left; // дым в отсеках
    float smoke_zone2_right; // дым в отсеках
    float smoke_zone3; // дым в отсеках
    float smoke_zone4; // дым в отсеках
    float smoke_zone5_left; // дым в отсеках
    float smoke_zone5_right; // дым в отсеках
    float smoke_zone6; // дым в отсеках
    float fire_eng_1; // пожар в двигателе
    float fire_eng_2; // пожар в двигателе
    float fire_eng_3; // пожар в двигателе
    float overheat_eng_1; // перегрев двигателя
    float overheat_eng_2; // перегрев двигателя
    float overheat_eng_3; // перегрев двигателя
    float fuel_off_eng_1; // топливо закрыто
    float fuel_off_eng_2; // топливо закрыто
    float fuel_off_eng_3; // топливо закрыто
    float check_overheat; // проверь перегрев и дым
    float fire_apu; // пожар ВСУ
    float turn_on_spz; // включи СПЗ

} lights_fire_t;

typedef struct {
    float low_oil; // масла мало
    float low_oil_press; // Р масла
    float high_temp; // предельная температура
    float high_rpm; // предельные обороты
    float pta6_fail; // ПТА 6А неисправн
    float doors_open; // створки открыты
    float fuel_press; // Р топлива
    float start_ready; // Готов к запуску
    float work_mode; // Выход на режим
    float start_apu; // запусти ВСУ
} lights_apu_t;

typedef struct {
    
    float eng1_dangerous_vibro; // опасная вибрация
    float eng1_oil_level; // уровень масла
    float eng1_oil_p; // давление масла
    float eng1_bypass_valve; // клапаны перепуска
    float eng1_vna33; // ВНА 33
    float eng1_reverse_lock; // замок реверса
    float eng1_high_vibro; // вибрация велика
    float eng1_chips; // стружка в масле
    float eng1_fuel_p; // давление топлива
    float eng1_filter_fail; // фильтр засорен
    float eng1_vna0; // ВНА 0
    float eng1_reverse_doors; // створки реверса
    float eng2_dangerous_vibro; // опасная вибрация
    float eng2_oil_level; // уровень масла
    float eng2_oil_p; // давление масла
    float eng2_bypass_valve; // клапаны перепуска
    float eng2_vna33; // ВНА 33
    float eng_at_on; // АТ включен
    float eng2_high_vibro; // вибрация велика
    float eng2_chips; // стружка в масле
    float eng2_fuel_p; // давление топлива
    float eng2_filter_fail; // фильтр засорен
    float eng2_vna0; // ВНА 0
    float eng_block; // расстоп сектора
    float eng3_dangerous_vibro; // опасная вибрация
    float eng3_oil_level; // уровень масла
    float eng3_oil_p; // давление масла
    float eng3_bypass_valve; // клапаны перепуска
    float eng3_vna33; // ВНА 33
    float eng3_reverse_lock; // замок реверса
    float eng3_high_vibro; // вибрация велика
    float eng3_chips; // стружка в масле
    float eng3_fuel_p; // давление топлива
    float eng3_filter_fail; // фильтр засорен
    float eng3_vna0; // ВНА 0
    float eng3_reverse_doors; // створки реверса

} lights_eng_t;

typedef struct {

    float transponder1_fail; // левая панель. отказ передатчика
    float transponder1_kd; // левая панель. КД
    float transponder1_kp; // левая панель. КП
    float leftside_yellow; // желтая лампа слева
    float turn_on_aux; // включи запасной
    float front_hydr_fail_1; // низкое давление ГС 1. передняя панель
    float front_hydr_fail_2; // низкое давление ГС 2. передняя панель
    float front_hydr_fail_3; // низкое давление ГС 3. передняя панель
    float front_hydr_fail_4; // низкое давление ГС аварийн. передняя панель
    float rv5_left_dh; // ВПР на левом РВ5
    float rv5_right_dh; // ВПР на правом РВ5
    float vd15_lamp; // лампа возле высотомера на передней панели
    float bkk_ok; // лампа исправности БКК на верхней панели
    float heat_ok_1; // лампа исправности обогрева
    float heat_ok_2; // лампа исправности обогрева
    float heat_ok_3; // лампа исправности обогрева
    float sp50_c1; // панель СП50 - курс 1
    float sp50_g1; // панель СП50 - глисс 1
    float sp50_c2; // панель СП50 - курс 2
    float sp50_g2; // панель СП50 - глисс 2
    float transponder_red; // красная лампа на ответчике
    float transponder_green; // зеленая лампа на ответчике
    float tks_main_fail; // отказ осн ГА на ТКС
    float tks_contr_fail; // отказ контр ГА на ТКС
    float rls_ready; // РЛС готов
    float rls_weather; // РЛС метео
    float stu_roll; // СТУ бок
    float stu_pitch; // СТУ прод
    float stu_toga; // УХОД
    float at_2; // AT 2
    float at_1; // AT 1
    float nvu_on; // НВУ испр
    float nvu_corr; // НВУ КОРР
    float nav_1_to; // NAV 1 НА
    float nav_1_from; // NAV 1 ОТ
    float nav_2_to; // NAV 2 НА
    float nav_2_from; // NAV 2 ОТ
    float apu_gen_on; // РАП подключен
    float bus_npk_1; // сети НПК лев на 3
    float bus_npk_2; // сети НПК прав на 1
    float emerg_inv_115; // аварийный преобразов. 115в
    float gen_fail_1; // генератор не работает
    float gen_fail_2; // генератор не работает
    float gen_fail_3; // генератор не работает
    float bus_connected; // сети соединены
    float left_bus_use_bat; // левая сеть от батарей
    float right_bus_use_bat; // правая сеть от батарей
    float turn_off_bat_1; // выключи батарею
    float turn_off_bat_3; // выключи батарею
    float turn_off_bat_2; // выключи батарею
    float turn_off_bat_4; // выключи батарею
    float vu_on_1; // ВУ1
    float vu_on_2; // ВУ1
    float left_bus_on_tr2; // левая сеть на тр 2
    float right_bus_on_tr1; // правая сеть на тр 1
    float pts250_n1; // ПТС 250 не работает
    float pts250_n2; // ПТС 250 на сеть
    float throttle_1_fire; // лампа пожара на РУД
    float throttle_2_fire; // лампа пожара на РУД
    float throttle_3_fire; // лампа пожара на РУД
    float oil_meter_1; // зеленая масла на уровнях масла
    float oil_meter_2; // зеленая масла на уровнях масла
    float oil_meter_3; // зеленая масла на уровнях масла
    float starter_high_rpm_1; // опасные обороты стартера
    float starter_high_rpm_2; // опасные обороты стартера
    float starter_high_rpm_3; // опасные обороты стартера
    float fuel_2500; // остаток топлива 2500
    float fuel_tank1_used; // расход из бака 1
    float fuel_tank3_left_fail; // красная лампа бака 3 лев
    float fuel_tank2_left_fail; // красная лампа бака 2 лев
    float fuel_tank2_right_fail; // красная лампа бака 2 прав
    float fuel_tank3_right_fail; // красная лампа бака 3 прав
    float fuel_pump_left_5; // насос бака 5 лев
    float fuel_pump_left_6; // насос бака 6 лев
    float fuel_pump_left_7; // насос бака 7 лев
    float fuel_pump_left_8; // насос бака 8 лев
    float fuel_pump_left_9; // насос бака 9 лев
    float fuel_pump_right_5; // насос бака 5 прав
    float fuel_pump_right_6; // насос бака 6 прав
    float fuel_pump_right_7; // насос бака 7 прав
    float fuel_pump_right_8; // насос бака 8 прав
    float fuel_pump_right_9; // насос бака 9 прав
    float fuel_pump_10; // насос бака 10
    float fuel_pump_11; // насос бака 11
    float fuel_pump_1; // насос бака 1
    float fuel_pump_2; // насос бака 2
    float fuel_pump_3; // насос бака 3
    float fuel_pump_4; // насос бака 4
    float fuel_cut_off_1; // перекрывные краны
    float fuel_cut_off_2; // перекрывные краны
    float fuel_cut_off_3; // перекрывные краны
    float fuel_flow_from_2; // порядок расхода
    float fuel_flow_from_3; // порядок расхода
    float fuel_flow_from_4; // порядок расхода
    float fuel_flow_auto_fail; // автомат расхода не работает
    float fuel_reserv_trans_left; // резервная перекачка в бак 1
    float fuel_reserv_trans_right; // резервная перекачка в бак 1
    float fuel_porc_reserv; // порцевание
    float fuel_level_automat; // автомат выравнивания
    float skv_overheat; // перегрев СКВ
    float skv_overpress_left; // превышение давления
    float skv_overpress_right; // превышение давления
    float skv_tail_temp; // температура хв отсека велика
    float skv_bleed_fail_1; // отказ отбора
    float skv_bleed_fail_2; // отказ отбора
    float skv_bleed_fail_3; // отказ отбора
    float skv_bleed_closed_1; // отбор закрыт
    float skv_bleed_closed_2; // отбор закрыт
    float skv_bleed_closed_3; // отбор закрыт
    float apd_work_1; // АПД работает
    float apd_work_2; // АПД работает
    float apd_work_3; // АПД работает
    float eng_hydr_fail_1; // низкое давление ГС 1.панель БИ
    float eng_hydr_fail_2; // низкое давление ГС 2. панель БИ
    float eng_hydr_fail_3; // низкое давление ГС 3. панель БИ
    float eng_hydr_fail_4; // низкое давление ГС аварийн. панель БИ
    float tail_temp_high; // тем. хв. отсека велика
    float lavatory_heat; // обогрев слива туалета
    float galley_heat; // обогрев слива кухни
    float msrp_mlp_main; // МСРП. МЛП ОСН
    float msrp_mlp_aux; // МСРП. МЛП ДОП
    float msrp_up2; // МСРП. УП2
    float msrp_mars; // МСРП. МАРС
    float srd_low_press; // давление кабины мало
    float srd_overpress; // перенаддув кабины
    float soi_work; // СОИ исправен
    float soi_ice_detected; // СОИ обледенение
    float antiice_slats; // заслонки продивообледенителей
    float antiice_eng_1; // заслонки продивообледенителей
    float antiice_eng_2; // заслонки продивообледенителей
    float antiice_eng_3; // заслонки продивообледенителей
    float antiice_wings; // заслонки продивообледенителей
    float close_toilet; // закройте туалет
    float pnp_sp_left; // лампа СП на ПНП лев
    float pnp_vor_left; // лампа VOR на ПНП лев
    float pnp_nv_left; // лампа HB на ПНП лев
    float pnp_rsbn_left; // лампа РСБН на ПНП лев
    float pnp_sp_right; // лампа СП на ПНП прав
    float pnp_vor_right; // лампа VOR на ПНП прав
    float pnp_nv_right; // лампа HB на ПНП прав
    float pnp_rsbn_right; // лампа РСБН на ПНП прав
    float dme_mile_left; // лампа мили на ДМЕ лев
    float dme_km_left; // лампа км на ДМЕ лев
    float dme_mile_right; // лампа мили на ДМЕ прав
    float dme_km_right; // лампа км на ДМЕ прав

} lights_small_t;

typedef struct {

    float absu_zk; // АБСУ ЗК
    float absu_reset; // АБСУ сброс
    float absu_nvu; // АБСУ НВУ
    float absu_az1; // АБСУ АЗ1
    float absu_az2; // АБСУ АЗ2
    float absu_app; // АБСУ заход
    float absu_gz; // АБСУ глисс
    float absu_stab_m; // АБСУ стаб М
    float absu_stab_v; // АБСУ стаб V
    float absu_stab_h; // АБСУ стаб H
    float absu_stab; // АБСУ стаб H
    float absu_stab_spd; // АБСУ стаб скорости
    float absu_thro1; // АБСУ откл Г1
    float absu_thro2; // АБСУ откл Г2
    float absu_thro3; // АБСУ откл Г3
    float dejur_contr; // дежур контр
    float sound_off; // откл звук
    float fire_eng_1; // тушение пожара двиг 1
    float fire_eng_2; // тушение пожара двиг 2
    float fire_eng_3; // тушение пожара двиг 3
    float fire_apu; // тушение пожара ВСУ
    float fire_ng; // тушение пожара НГ
    float fire_turn_3; // тушение пожара очередь 3
    float fire_turn_2; // тушение пожара очередь 2
    float fire_turn_1; // тушение пожара очередь 1

} lights_button_t;