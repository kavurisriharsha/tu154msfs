typedef struct {

    int failures_enabled; // общий выключатель отказов
    int lan_lamp_fail_FL; // отказ фар
    int lan_lamp_fail_FR; // отказ фар
    int lan_lamp_fail_WL; // отказ фар
    int lan_lamp_fail_WR; // отказ фар
    int lan_lamp_fail_signal; // отказ фар
    int acs1_fail; // отказ часов
    int acs2_fail; // отказ часов
    int acs3_fail; // отказ часов
    int bat_1_kz; // КЗ или тепловой разгон батареи
    int bat_2_kz; // КЗ или тепловой разгон батареи
    int bat_3_kz; // КЗ или тепловой разгон батареи
    int bat_4_kz; // КЗ или тепловой разгон батареи
    int bat_1_fail; // отказ батареи. не дает напряжения и не заряжается
    int bat_2_fail; // отказ батареи. не дает напряжения и не заряжается
    int bat_3_fail; // отказ батареи. не дает напряжения и не заряжается
    int bat_4_fail; // отказ батареи. не дает напряжения и не заряжается
    int vu1_fail; // отказ ВУ1
    int vu2_fail; // отказ ВУ2
    int vu3_fail; // отказ ВУ3
    int tr1_fail; // отказ ТР1
    int tr2_fail; // отказ ТР1
    int pts250_1_fail; // отказ ПТС250
    int pts250_2_fail; // отказ ПТС250
    int inv115_fail; // отказ преобразователя 115в
    int hydro_leak_1; // утечка в гидросистеме
    int hydro_leak_2; // утечка в гидросистеме
    int hydro_leak_3; // утечка в гидросистеме
    int hydro_leak_4; // утечка в гидросистеме
    int tth_left_fail; // отказ турбохолодильника
    int tth_right_fail; // отказ турбохолодильника
    int sard_valve_fail; // отказ выпускного клапана
    int psvp_fail_left; // отказ ПСВП
    int psvp_fail_right; // отказ ПСВП
    int airbleed_1; // отказ отбора воздуха от двигателя
    int airbleed_2; // отказ отбора воздуха от двигателя
    int airbleed_3; // отказ отбора воздуха от двигателя
    int apu_start_fail; // отказ стартера ВСУ
    int apu_gen_fail; // отказ генератора ВСУ
    int apu_fail_oilt; // отказ по перегреву масла
    int apu_fail_egt; // отказ по превышению ТВГ
    int apu_fail_fuel_left; // отказ по остатку топлива в камере
    int apu_fail; // отказ ВСУ
    int apu_press_fail; // отказ отбора воздуха ВСУ
    int rio_fail; // отказ датчика обледенения
    int window_heat_fail_1; // отказ обогрева окон
    int window_heat_fail_2; // отказ обогрева окон
    int window_heat_fail_3; // отказ обогрева окон
    int ail_fail_left; // отказ датчика обледенения
    int ail_fail_right; // отказ датчика обледенения
    int fail_spoil_inn_left; // отказ датчика обледенения
    int fail_spoil_inn_right; // отказ датчика обледенения
    int fail_spoil_mid_left; // отказ датчика обледенения
    int fail_spoil_mid_right; // отказ датчика обледенения
    int fail_spoil_out_left; // отказ датчика обледенения
    int fail_spoil_out_right; // отказ датчика обледенения
    int flap_fail_left; // отказ датчика обледенения
    int flap_fail_right; // отказ датчика обледенения
    int stab_eng_fail; // отказ датчика обледенения
    int stab_automatic_fail; // отказ датчика обледенения
    int rudder_fail; // отказ датчика обледенения
    int elev_fail_left; // отказ датчика обледенения
    int elev_fail_right; // отказ датчика обледенения
    int trim_emerg_elv_fail; // отказ датчика обледенения
    int slats_fail; // отказ датчика обледенения
    int engn_oil_leak_1; // утечка масла
    int engn_oil_leak_2; // утечка масла
    int engn_oil_leak_3; // утечка масла
    int eng_fuel_pmp_fail_1; // отказ топливного насоса двигателя
    int eng_fuel_pmp_fail_2; // отказ топливного насоса двигателя
    int eng_fuel_pmp_fail_3; // отказ топливного насоса двигателя
    int fuel_pump_2l_fail; // отказ топливного насоса
    int fuel_pump_2r_fail; // отказ топливного насоса
    int fuel_pump_3l_fail; // отказ топливного насоса
    int fuel_pump_3r_fail; // отказ топливного насоса
    int fuel_pump_1_fail; // отказ топливного насоса
    int fuel_pump_4_fail; // отказ топливного насоса
    int fuel_auto_fail; // отказ автоматики
    int fuel_level_fail; // отказ выравнивания
    int fuel_porc_fail; // отказ порцевания
    int fuel_meter_2l_fail; // отказ топливомера
    int fuel_meter_2r_fail; // отказ топливомера
    int fuel_meter_3l_fail; // отказ топливомера
    int fuel_meter_3r_fail; // отказ топливомера
    int fuel_meter_1_fail; // отказ топливомера
    int fuel_meter_4_fail; // отказ топливомера
    int fuel_meter_summ; // отказ топливомера
    int fuel_flowmeter_1_fail; // отказ расходомера
    int fuel_flowmeter_2_fail; // отказ расходомера
    int fuel_flowmeter_3_fail; // отказ расходомера
    int hydro_pump_fail_11; // отказ гидронасосов
    int hydro_pump_fail_12; // отказ гидронасосов
    int hydro_pump_fail_2; // отказ гидронасосов
    int hydro_pump_fail_3; // отказ гидронасосов
    int hydro_elec_fail_2; // отказ електронасосов
    int hydro_elec_fail_3; // отказ електронасосов
    int main_alarm_fail; // отказ сирены
    int speaker_alarm_fail; // отказ сирены
    int absu_ra56_roll_fail; // отказ ra56
    int absu_ra56_pitch_fail; // отказ ra56
    int absu_ra56_yaw_fail; // отказ ra56
    int absu_at1_fail; // отказ AT
    int absu_at2_fail; // отказ AT
    int absu_damp_roll_fail; // отказ демперов крена
    int absu_damp_pitch_fail; // отказ демперов тангажа
    int absu_damp_yaw_fail; // отказ демперов курса
    int absu_contr_roll_fail; // отказ бокового управления
    int absu_contr_pitch_fail; // отказ продольного управления
    int absu_calc_toga_fail; // отказ вычислителя УХОД
    int absu_calc_roll_fail; // отказ бокового канала СТУ
    int absu_calc_pitch_fail; // отказ продольного канала СТУ
    int nav1_fail; // отказ курсМП
    int nav2_fail; // отказ курсМП
    int dme1_fail; // отказ СД72
    int dme2_fail; // отказ СД72
    int diss_fail; // отказ дисс
    int nvu_fail; // отказ нву
    int radar_fail; // отказ радара
    int mrp_fail; // отказ МРП
    int rsbn_fail; // отказ РАСБН
    int taws_fail; // отказ СРПБЗ
    int tks_km1_fail; // отказ ТКС
    int tks_km2_fail; // отказ ТКС
    int tks_bgmk1_fail; // отказ ТКС
    int tks_bgmk2_fail; // отказ ТКС
    int agr_fail; // отказ АГР
    int bkk_fail; // отказ БКК
    int mgv_fail; // отказ МГВ
    int rv1_fail; // отказ РВ5
    int rv2_fail; // отказ РВ5
    int uvid15_fail; // отказ УВИД
    int pitot1; // отказ Пито
    int pitot2; // отказ Пито
    int static1; // отказ полного давления
    int static2; // отказ полного давления
    int AOA; // отказ УА

    float apu_runtime; // наработка ВСУ
    float apu_oil_qty; // остаток масла ВСУ
    float brake_heat_left; // Температура тормозов
    float brake_heat_right; // Температура тормозов
    float brake_runtime_left; // Наработка тормозных колодок
    float brake_runtime_right; // Наработка тормозных колодок
    float engine_runtime_1; // ресурс двигателя
    float engine_runtime_2; // ресурс двигателя
    float engine_runtime_3; // ресурс двигателя
    float engn_oil_qty_1; // остаток масла
    float engn_oil_qty_2; // остаток масла
    float engn_oil_qty_3; // остаток масла
    
} failures_t;