typedef struct {
    /*int  bat_on_bus; // battery connected to the network
    int  bat_source; // battery is the source
    int  bat_fail; // battery failure
    int  bat_kz; // thermal runaway
    int  sim_bat_on; // sim battery on
    int vu_res_to_L; // reserve VU connected to the left network
    int vu_res_to_R; // reserve VU connected to the right network
    int bus27_source_left; // power source of the left network. 0 - nothing. 1 - VU1, 2 - VU reserve, 3 - batteries 1 and 3, 4- bat 1, 5 - bat 2
    int bus27_source_right; // power source of the right network. 0 - nothing. 1 - VU2, 2 - VU reserve, 3 - batteries 1 and 3, 4- bat 1, 5 - bat 2

    // battery is the source
    int bat_is_source_1;
    int bat_is_source_2;
    int bat_is_source_3;
    int bat_is_source_4;
    int bus_connected; // networks are connected
    int bus36_tr1_work; // transformer 1 works
    int bus36_tr2_work; // transformer 2 works
    int bus36_pts1_work; // PTS250 1 works
    int bus36_pts2_work; // PTS250 2 works
    int bus36_src_L; // source of the left network. 0 = TR1, 1 = TR2
    int bus36_src_R; // source of the right network. 0 = TR2, 1 = TR1
    int gen1_work; // generator 1 works
    int gen2_work; // generator 2 works
    int gen3_work; // generator 3 works
    int gen4_work; // APU generator works
    int gpu_work; // GPU works
    int gen1_overload; // generator 1 overload
    int gen2_overload; // generator 2 overload
    int gen3_overload; // generator 3 overload
    int gen4_overload; // APU generator works
    int gpu_overload; // GPU overload
    int apu_start_seq; // APU start process is ongoing
    
    float  bus_volt; // напряжение в сети

    float  cockpit_temp; // температура в кабине

    // other datarefs
    float  frame_time; // flight time

    float  bat_amp_bus; // нагрузка батареи
    float  bat_amp_cc; // ток заряда батареи
    float  bat_volt_bus; // напряжение батареи
    float  bat_thermo; // напряжение батареи

    float bat_volt_1;
    float bat_volt_2;
    float bat_volt_3;
    float bat_volt_4;
    float bat_amp_1;
    float bat_amp_2;
    float bat_amp_3;
    float bat_amp_4;
    float bat_cc_1;
    float bat_cc_2;
    float bat_cc_3;
    float bat_cc_4;
    float bat_therm_1;
    float bat_therm_2;
    float bat_therm_3;
    float bat_therm_4;
    float vu1_volt;
    float vu2_volt;
    float vu_res_volt;
    float vu1_amp;
    float vu2_amp;
    float vu_res_amp;



    float bus27_volt_left;
    float bus27_amp_left;
    float bus27_amp_right;
    float bus27_volt_right;

    float bus36_volt_left;
    float bus36_volt_right;
    float bus36_volt_pts250_1;
    float bus36_volt_pts250_2;
    float bus36_amp_left;
    float bus36_amp_right;
    float bus36_amp_pts250_1;
    float bus36_amp_pts250_2;

    float gen1_volt;
    float gen2_volt;
    float gen3_volt;
    float gen4_volt;
    float gpu_volt;
    float bus115_1_volt;
    float bus115_2_volt;
    float bus115_3_volt;
    float bus115_em_1_volt;
    float bus115_em_2_volt;
    float bus115_1_amp;
    float bus115_2_amp;
    float bus115_3_amp;
    float bus115_em_1_amp;
    float bus115_em_2_amp;
    float gen1_amp;
    float gen2_amp;
    float gen3_amp;
    float gen4_amp;
    float gpu_amp;
    float apu_start_bus;
    float apu_start_cc;
    
    float apu_burning_fuel;
    float cockpit_light_cc_left;
    float cockpit_light_cc_right;
    float cockpit_light_cc_115;
    float ext_light_cc_left;
    float ext_light_cc_right;
    float ext_light_cc_115;
    float fuel_pumps_115_1_cc;
    float fuel_pumps_115_3_cc;
    float fuel_pumps_27_cc;
    float auasp_pow27_cc;
    float auasp_pow115_cc;
    float rv5_left_cc;
    float rv5_right_cc;*/

    int vu_res_to_L; // резервное ВУ подключено на лев сеть
    int vu_res_to_R; // резервное ВУ подключено на прав сеть
    int bus27_source_left; // источник питания левой сети. 0 - ничего. 1 - ВУ1, 2 - ВУрезерв, 3 - батареи 1 и 3, 4- бат 1, 5 - бат 2
    int bus27_source_right; // источник питания правой сети. 0 - ничего. 1 - ВУ2, 2 - ВУрезерв, 3 - батареи 1 и 3, 4- бат 1, 5 - бат 2
    int bat_is_source_1; // батарея является источником
    int bat_is_source_2; // батарея является источником
    int bat_is_source_3; // батарея является источником
    int bat_is_source_4; // батарея является источником
    int bus_connected; // сети соеденены
    int bus36_tr1_work; // трансформатор 1 работает
    int bus36_tr2_work; // трансформатор 2 работает
    int bus36_pts1_work; // ПТС250 1 работает
    int bus36_pts2_work; // ПТС250 2 работает
    int bus36_src_L; // источник левой сети. 0 = ТР1, 1 = ТР2
    int bus36_src_R; // источник правой сети. 0 = ТР2, 1 = ТР1
    int gen1_work; // генератор 1 работает
    int gen2_work; // генератор 2 работает
    int gen3_work; // генератор 3 работает
    int gen4_work; // генератор ВСУ работает
    int gpu_work; // РАП работает
    int gen1_overload; // генератор 1 перегрузка
    int gen2_overload; // генератор 2 перегрузка
    int gen3_overload; // генератор 3 перегрузка
    int gen4_overload; // генератор ВСУ работает
    int gpu_overload; // РАП перегрузка
    int apu_start_seq; // идет процесс запуска ВСУ
    
    float bat_volt_1; // напряжение батареи
    float bat_volt_2; // напряжение батареи
    float bat_volt_3; // напряжение батареи
    float bat_volt_4; // напряжение батареи
    float bat_amp_1; // ток батареи
    float bat_amp_2; // ток батареи
    float bat_amp_3; // ток батареи
    float bat_amp_4; // ток батареи
    float bat_cc_1; // ток заряда батареи
    float bat_cc_2; // ток заряда батареи
    float bat_cc_3; // ток заряда батареи
    float bat_cc_4; // ток заряда батареи
    float bat_therm_1; // температура батареи
    float bat_therm_2; // температура батареи
    float bat_therm_3; // температура батареи
    float bat_therm_4; // температура батареи
    float vu1_volt; // работа ВУ
    float vu2_volt; // работа ВУ
    float vu_res_volt; // работа ВУ
    float vu1_amp; // ток ВУ
    float vu2_amp; // ток ВУ
    float vu_res_amp; // ток ВУ
    float bus27_volt_left; // напряжение левой сети 27
    float bus27_amp_left; // напряжение левой сети 27
    float bus27_amp_right; // ток правой сети 27
    float bus27_volt_right; // ток правой сети 27
    float bus36_volt_left; // напряжение левой сети 36
    float bus36_volt_right; // напряжение правой сети 36
    float bus36_volt_pts250_1; // напряжение сети 36 ПТС 1
    float bus36_volt_pts250_2; // напряжение сети 36 ПТС 2
    float bus36_amp_left; // ток левой сети 36
    float bus36_amp_right; // ток правой сети 36
    float bus36_amp_pts250_1; // ток ПТС250 сети 36 1
    float bus36_amp_pts250_2; // ток ПТС250 сети 36 2
    float gen1_volt; // напряжение на генераторе
    float gen2_volt; // напряжение на генераторе
    float gen3_volt; // напряжение на генераторе
    float gen4_volt; // напряжение на генераторе
    float gpu_volt; // напряжение на генераторе
    float bus115_1_volt; // напряжение на сети 115в
    float bus115_2_volt; // напряжение на сети 115в
    float bus115_3_volt; // напряжение на сети 115в
    float bus115_em_1_volt; // напряжение на аварийной сети 115в
    float bus115_em_2_volt; // напряжение на аварийной сети 115в
    float bus115_1_amp; // ток в сети 115в
    float bus115_2_amp; // ток в сети 115в
    float bus115_3_amp; // ток в сети 115в
    float bus115_em_1_amp; // ток в сети 115в
    float bus115_em_2_amp; // ток в сети 115в
    float gen1_amp; // нагрузка на генератор
    float gen2_amp; // нагрузка на генератор
    float gen3_amp; // нагрузка на генератор
    float gen4_amp; // нагрузка на генератор
    float gpu_amp; // нагрузка на генератор
    float apu_start_bus; // напряжение в сети ВСУ
    float apu_start_cc; // ток стартера ВСУ
    float apu_burning_fuel; // ток стартера ВСУ
    float cockpit_light_cc_left; // нагрузка на левую сеть от освещения в кабине
    float cockpit_light_cc_right; // нагрузка на правую сеть от освещения в кабине
    float cockpit_light_cc_115; // нагрузка на сеть 115 от освещения в кабине
    float ext_light_cc_left; // нагрузка на левую сеть от внешнего освещения
    float ext_light_cc_right; // нагрузка на левую сеть от внешнего освещения
    float ext_light_cc_115; // нагрузка на левую сеть от внешнего освещения
    float fuel_pumps_115_1_cc; // нагрузка на сеть 1 от топливных насосов
    float fuel_pumps_115_3_cc; // нагрузка на сеть 3 от топливных насосов
    float fuel_pumps_27_cc; // нагрузка на сеть 27в от топливных насосов
    float auasp_pow27_cc; // ток, потребляемый АУАСП
    float auasp_pow115_cc; // ток, потребляемый АУАСП
    float rv5_left_cc; // ток, потребляемый RV-5
    float rv5_right_cc; // ток, потребляемый RV-5

} elec_t;