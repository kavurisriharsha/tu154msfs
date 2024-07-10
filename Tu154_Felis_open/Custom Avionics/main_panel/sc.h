typedef struct {

    int control_thro_other; // другой человек упраляет РУД-ами
    float yoke_pitch_ratio; // управление тангажом
    float yoke_roll_ratio; // управление креном
    float yoke_heading_ratio; // управление педалями
    float engine; // управление РУД
    float engine; // управление РУД
    float engine; // управление РУД
    float engine; // управление реверсом
    float engine; // управление реверсом
    float gear; // управление передней ногой
    float controls; // управление тормозами
    float controls; // управление тормозами
    float brakes; // управление тормозами
    float brakes; // управление тормозами
    float controls; // управление тормозами
    float GNS430_dtk; // курс на ГНС
    float GNS430_dev; // отклонение от курса на ГНС
    int GNS430_flag; // флаг на ГНС    

} sc_t;