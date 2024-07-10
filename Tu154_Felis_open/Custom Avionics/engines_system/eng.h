typedef struct {

    int apu_system_on; // включение системы ВСУ
    float apu_n1; // обороты ВСУ
    float apu_oil_t; // температура масла ВСУ
    float apu_oil_q; // количество масла ВСУ
    float apu_oil_p; // давление масла ВСУ
    float apu_fuel_p; // давление топлива ВСУ
    float apu_egt; // температура выходных газов ВСУ
    float apu_air_press; // давление воздуха для запуска двигателей
    float apu_air_doors; // положение створок для накачки воздуха
    float vibration_1; // вибрация двигателя
    float vibration_2; // вибрация двигателя
    float vibration_3; // вибрация двигателя

} eng_t;