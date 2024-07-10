typedef struct {
    
    int parking_brake; // ручка фиксации тормоза
    int emerg_gear_ext; // ручка аварийного выпуска шасси
    int gear_lever; // ручка выпуска шасси. -1 - уборка, 0 - нейтр, +1 - выпуск
    int elev_trimm_switcher; // ручка управления триммером РВ. -1 - пикирование, 0 - нейтр, +1 кабрирование
    int stab_man_cap; // крышка управления стабилизатором
    int stab_manual; // ручное уплавение стабилизатором. 0 - нейтр, +1 - кабрирование
    int stab_setting; // положение центровки для стаба. 0 - З, 1 - С, 2 - П
    int ail_trimm_sw; // переключатель триммера элеронов
    int rudd_trimm_sw; // переключатель триммера РН
    int contr_force_cap; // крышка переключателя загружателя РВ РН
    int contr_force_set; // переключатель загружателя РВ РН. -1 - полет, 0 авто, +1 - взлет-посадка

    float ctr_27_L_cc; // нагрузка на сеть
    float ctr_27_R_cc; // нагрузка на сеть
    float ctr_115_1_cc; // нагрузка на сеть
    float ctr_115_2_cc; // нагрузка на сеть
    float ctr_115_3_cc; // нагрузка на сеть
    float ctr_36L_cc; // нагрузка на сеть
    float ctr_36R_cc; // нагрузка на сеть
    float flaps_lever; // ручка выпуска закрылок. 0-45
    float nosewheel_lever; // рычаг поворота передней ноги
    float yoke_pitch; // поворот штурвала ко тангажу
    float yoke_roll; // поворот штурвала по крену
    float pedals; // поворот педалей
    float brake_L; // тормоз педалей лев
    float brake_R; // тормоз педалей прав
    float brake_emerg; // аварийный тормоз
    float brake_emerg_L; // аварийный тормоз лев
    float brake_emerg_R; // аварийный тормоз прав
    float spoilers_lever; // рычаг интерцепторов
    float throttle_1; // РУД 1
    float throttle_2; // РУД 2
    float throttle_3; // РУД 3
    float throttle_1_ENG; // РУД 1 БИ
    float throttle_2_ENG; // РУД 2 БИ
    float throttle_3_ENG; // РУД 3 БИ
    float revers_L; // рычаг реверса лев
    float revers_R; // рычаг реверса прав
    float fuel_cutoff_1; // рычаг пожарного крана 1
    float fuel_cutoff_2; // рычаг пожарного крана 2
    float fuel_cutoff_3; // рычаг пожарного крана 3
    float throttle_lock; // рычаг фиксации РУД
    float control_force_pos; // положение загружателя РВ. 0 - выклчюен, 1 - подключен
    float control_force_pos_rud; // положение загружателя РН. 0 - выклчюен, 1 - подключен

} controls_t;