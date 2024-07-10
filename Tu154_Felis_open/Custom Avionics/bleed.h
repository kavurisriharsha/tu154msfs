typedef struct {
    
    float air_usage_L; // расход воздуха лев
    float air_usage_R; // расход воздуха лев
    float eng_airvalve_1; // открытие отбора воздуха от двигателя
    float eng_airvalve_2; // открытие отбора воздуха от двигателя
    float eng_airvalve_3; // открытие отбора воздуха от двигателя
    float hot_tube_t; // температура горячего воздуха в трубопроводе
    float door_heat_tube_t; // температура в трубопроводе обогрева дверей
    float cockpit_tube_t; // температура в трубопроводе в кабину
    float cabin1_tube_t; // температура в трубопроводе в салон 1
    float cabin2_tube_t; // температура в трубопроводе в салон 2
    float cold_tube1_t; // температура в трубопроводе1
    float cold_tube2_t; // температура в трубопроводе2
    float cockpit_temp; // температура в кабине
    float cabin_1_temp; // температура в салоне 1
    float cabin_2_temp; // температура в салоне 2

} bleed_t;